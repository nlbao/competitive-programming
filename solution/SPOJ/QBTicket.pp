const
    INPUT = 'QBTicket.inp';
    OUTPUT = 'QBTicket.out';
    MAX_N = 100000;
    MAX = 1000000000000000000;

var
    N,L1,L2,L3,C1,C2,C3,P,Q,Res:int64;
    A,idx:array[1..MAX_N] of int64;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,L1,L2,L3,C1,C2,C3);
    readln(fi,N);
    readln(fi,P,Q);
    A[1]:=0;
    for i:=2 to N do read(fi,A[i]);
    close(fi);
end;
{---------------------------------------------------------------------------}
function    min(x,y:int64):int64;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   Swap(var x,y:int64);
var
    tmp:int64;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   Quick_sort(l,r:longint);
var
    i,j:longint;
    p:int64;
begin
    i:=l;   j:=r;
    p:=A[(i+j) div 2];
    repeat
        while A[i] < p do inc(i);
        while A[j] > p do dec(j);
        if i <= j then
            begin
                Swap(A[i],A[j]);
                Swap(idx[i],idx[j]);
                inc(i); dec(j);
            end;
    until i >= j;
    if l < j then Quick_sort(l,j);
    if i < r then Quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   Init;
var
    i:longint;
begin
    for i:=1 to N do idx[i]:=i;
    Quick_sort(1,N);
    for i:=1 to N do
        if idx[i] = P then P:=i
        else
            if idx[i] = Q then Q:=i;
    if P > Q then Swap(P,Q);
end;
{---------------------------------------------------------------------------}
procedure   Find;
var
    i,T1,T2,T3:int64;
    F:array[1..MAX_N] of int64;
begin
    Res:=0;
    if P = Q then exit;
    i:=P;   F[P]:=0;
    T3:=P;  T2:=P;  T1:=P;
    repeat
        inc(i);
        while (A[i]-A[T3] > L3) and (T3 < i-1) do inc(T3);
        while (A[i]-A[T2] > L2) and (T2 < i-1) do inc(T2);
        while (A[i]-A[T1] > L1) and (T1 < i-1) do inc(T1);
        F[i]:=MAX;
        if A[i]-A[T3] <= L3 then F[i]:=min(F[i],F[T3]+C3);
        if A[i]-A[T2] <= L2 then F[i]:=min(F[i],F[T2]+C2);
        if A[i]-A[T1] <= L1 then F[i]:=min(F[i],F[T1]+C1);
        if F[i] = MAX then exit;
    until i = Q;
    Res:=F[Q];
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,Res);
    close(fo);
end;
{---------------------------------------------------------------------------}

begin
    Enter;
    Init;
    Find;
    Print_result;
end.