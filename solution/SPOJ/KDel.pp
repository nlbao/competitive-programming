const
    INPUT = 'KDel.inp';
    OUTPUT = 'KDel.out';
    MAX_N = 800000;

var
    fi,fo:text;
    N,K:longint;
    S:ansiString;
    is_prime:array[2..MAX_N] of boolean;

{---------------------------------------------------------------------------}
procedure   init;
var
    i,j,count:longint;
    tmp:ansiString;
    p,q:pChar;
begin
    S:='';
    count:=0;
    for i:=2 to MAX_N do is_prime[i]:=true;
    for i:=2 to MAX_N do
        if is_prime[i] then begin
            str(i,tmp);
            S:=S+tmp;
            inc(count);
            if count = N then break;
            j:=i+i;
            while j <= MAX_N do begin
                is_prime[j]:=false;
                j:=j+i;
            end;
        end;
end;
{---------------------------------------------------------------------------}
procedure   solve(N,K:longint);
var
    i,j:longint;
begin
    i:=1;
    repeat
        while (i < length(S)) and (ord(S[i]) >= ord(S[i+1])) do inc(i);
        if i = length(S) then break;
{delte doan j+1..i}
        j:=i;
        inc(i);
        while (j > 0) and (S[j] < S[i]) do begin
            dec(j);
            dec(K);
            if K = 0 then break;
        end;
        delete(S,j+1,i-j-1);
        dec(i,i-j-1);
    until K = 0;

    if K > 0 then   {day S la day giam dan}
        delete(S,length(S)-K+1,K);
    writeln(fo,S);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N,K);
    init;
    solve(N,K);
    close(fo);
    close(fi);
end.
