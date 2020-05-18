const
    INPUT = 'MaxNum.inp';
    OUTPUT = 'MaxNum.out';
    MAX_N = 30000;

type
    arr = array[1..MAX_N] of longint;

var
    fi,fo:text;
    N,K,nP:longint;
    p:arr;

{---------------------------------------------------------------------------}
procedure   Sang_SNT;
var
    i,j:longint;
    is_prime:array[1..MAX_N] of boolean;
begin
    nP:=0;
    for i:=2 to MAX_N do is_prime[i]:=true;
    for i:=2 to MAX_N do
        if is_prime[i] then begin
            inc(nP);
            p[nP]:=i;
            j:=i+i;
            while j <= MAX_N do begin
                is_prime[j]:=false;
                j:=j+i;
            end;
        end;
end;
{---------------------------------------------------------------------------}
procedure   PhanTich(N:longint; var X:arr);
var
    i:longint;
begin
    for i:=1 to nP do
        if p[i] > sqrt(N) then break
        else
            while (N mod p[i]) = 0 do begin
                X[p[i]]:=X[p[i]]+1;
                N:=N div p[i];
            end;
    if N > 1 then inc(X[N]);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,tmp,Res:longint;
    A,B:arr;
begin
    fillchar(A,sizeof(A),0);
    for i:=1 to N do
        PhanTich(i,A);
    fillchar(B,sizeof(B),0);
    PhanTich(K,B);
    Res:=MAXLONGINT;
    for i:=1 to MAX_N do
        if B[i] > 0 then begin
            tmp:=A[i] div B[i];
            if tmp < Res then Res:=tmp;
        end;
    writeln(fo,Res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N,K);
    Sang_SNT;
    Solve;
    close(fo);
    close(fi);
end.
