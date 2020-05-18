const
    INPUT = 'KQuery.inp';
    OUTPUT = 'KQuery.out';
    MAX_N = 30000;

var
    fi,fo:text;
    N,nT:longint;
    A,T:array[1..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i:longint;
begin
    read(fi,N);
    for i:=1 to N do read(fi,A[i]);
end;
{---------------------------------------------------------------------------}
procedure   Init;
var
    i,tmp:longint;
begin
    nT:=1;
    T[1]:=1;
    tmp:=A[1];
    for i:=2 to N do
        if A[i] < tmp then
            begin
                tmp:=A[i];
                inc(nT);
                T[nT]:=i;
            end;
end;
{---------------------------------------------------------------------------}
function    Count(P,Q,X:longint):longint;
begin
    mid:=-1;
    l:=1;   r:=nT;
    while l <= r do
        begin
            m:=(l+r) div 2;
            if A[T[m]] <
        end;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,M,P,Q,X:longint;
begin
    read(fi,M);
    for i:=1 to M do
        begin
            read(fi,P,Q,X);
            writeln(fo,Count(P,Q,X));
        end;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    Init;
    Solve;
    close(fo);
    close(fi);
end.