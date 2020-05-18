const
    INPUT = 'PBCSEQ.inp';
    OUTPUT = 'PBCSEQ.out';
    MAX_N = 100000;
    MAX_B = 1000000;

var
    N,Res:longint;
    A,B:array[1..MAX_N+1] of longint;
    F:array[1..MAX_B] of longint;

{************************************************************************************************}
procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,N);
    for i:=1 to N do read(fi,A[i],B[i]);
    close(fi);
end;
{************************************************************************************************}
function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;
{************************************************************************************************}
procedure   Swap(var x,y:longint);
var
    tmp:longint;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;
{************************************************************************************************}
procedure   Quick_sortB(l,r:longint);
var
    i,j,p:longint;
begin
    i:=l;   j:=r;
    p:=B[(i+j) div 2];
    repeat
        while B[i] < p do inc(i);
        while B[j] > p do dec(j);
        if i <= j then
            begin
                Swap(A[i],A[j]);
                Swap(B[i],B[j]);
                inc(i); dec(j);
            end;
    until i >= j;
    if l < j then Quick_sortB(l,j);
    if i < r then Quick_sortB(i,r);
end;
{************************************************************************************************}
procedure   Quick_sortA(l,r:longint);
var
    i,j,p:longint;
begin
    i:=l;   j:=r;
    p:=A[(i+j) div 2];
    repeat
        while A[i] > p do inc(i);
        while A[j] < p do dec(j);
        if i <= j then
            begin
                Swap(A[i],A[j]);
                Swap(B[i],B[j]);
                inc(i); dec(j);
            end;
    until i >= j;
    if l < j then Quick_sortA(l,j);
    if i < r then Quick_sortA(i,r);
end;
{************************************************************************************************}
procedure   Init;
var
    i,j:longint;
begin
    Quick_sortB(1,N);
    B[N+1]:=-1;
    i:=1;
    repeat
        j:=i;
        while B[j+1] = B[i] do inc(j);
        if j > i then Quick_sortA(i,j);
        i:=j+1;
    until i >= N;
end;
{************************************************************************************************}
procedure   UpdateF(value,i:longint);
begin
    if i > MAX_B then exit;
    F[i]:=max(F[i],value);
    UpdateF(value,i+i and (-i));
end;
{************************************************************************************************}
function    GetF(i:longint):longint;
begin
    if i = 0 then exit(0);
    exit(max(F[i],GetF(i-i and (-i))));
end;
{************************************************************************************************}
procedure   Find;
var
    i,tmp:longint;
begin
    for i:=1 to MAX_B do F[i]:=0;
    UpdateF(1,A[N]);
    for i:=N-1 downto 1 do
        begin
            tmp:=GetF(A[i])+1;
            UpdateF(tmp,A[i]);
        end;
    Res:=0;
    for i:=1 to MAX_B do Res:=max(Res,F[i]);
end;
{************************************************************************************************}
procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,Res);
    close(fo);
end;
{************************************************************************************************}
begin
    Enter;
    Init;
    Find;
    Print_result;
end.