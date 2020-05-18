const
    INPUT = 'NKLEXIC.inp';
    OUTPUT = 'NKLEXIC.out';
    MAX_N = 26;
    MAX_P = 2000000000;

var
    fi,fo:text;
    T,N,M,i,j:longint;
    ch:char;
    check:boolean;
    A:array[1..MAX_N] of longint;
    F:array[0..MAX_N] of double;
    P:double;

{---------------------------------------------------------------------------}
procedure   Init;
var
    i:longint;
begin
    F[0]:=1;
    for i:=1 to MAX_N do F[i]:=F[i-1]*i;
end;
{---------------------------------------------------------------------------}
procedure   FindP;
var
    S:string;
    i,j:longint;
    avail:array[1..MAX_N] of boolean;
    C:array[1..MAX_N] of double;
begin
    readln(fi,S);
    delete(S,1,1);
    if length(S) <> M then exit;
    for i:=1 to N do avail[i]:=true;
    for i:=1 to M do
        begin
            A[i]:=ord(S[i])-ord('a')+1;

            if (A[i] < 1) or (A[i] > N) then exit;
            if not avail[A[i]] then exit;

            C[i]:=0;
            for j:=1 to N do
                if j = A[i] then break
                else
                    if avail[j] then C[i]:=C[i]+1;
            avail[A[i]]:=false;
        end;
    P:=1;
    for i:=1 to M do
        begin
            P:=P+C[i]*(F[N-i]/F[N-M]);
            if P > MAX_P then exit;
        end;
    check:=true;
end;
{---------------------------------------------------------------------------}
procedure   FindA;
var
    i,j:longint;
    avail:array[1..MAX_N] of boolean;
    tmp:double;
begin
    readln(fi,P);
    if (P < 1) or (P > MAX_P) then exit;
    for i:=1 to N do avail[i]:=true;
    for i:=1 to M do
        begin
            A[i]:=0;
            tmp:=F[N-i]/F[N-M];
            for j:=1 to N do
                if avail[j] then
                    if P <= tmp then
                        begin
                            A[i]:=j;
                            avail[j]:=false;
                            break;
                        end
                    else P:=P-tmp;
            if A[i] = 0 then exit;
        end;
    check:=true;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Init;
    read(fi,T);
    for i:=1 to T do
        begin
            check:=false;
            readln(fi,N,M);
            read(fi,ch);
            if ch = 'P' then
                begin
                    FindP;
                    if check = true then writeln(fo,P:0:0);
                end
            else
                begin
                    FindA;
                    if check = true then
                        begin
                            for j:=1 to M do write(fo,chr(A[j]+ord('a')-1));
                            writeln(fo);
                        end;
                end;
            if check = false then writeln(fo,'Incorrect data');
        end;
    close(fo);
    close(fi);
end.
