const
    INPUT = 'PBCSEQ.inp';
    OUTPUT = 'PBCSEQ.out';
    MAX_N = 100000;
    MAX_B = 1000000;

var
    N,Res:longint;
    A,B,F:array[1..MAX_N] of longint;

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
procedure   Find;
var
    i,k,l,r,mid:longint;
    F:array[1..MAX_N] of longint;
begin
    F[1]:=1;
    k:=1;
    for i:=2 to N do
        begin
            if A[i] > A[F[1]] then
                F[1]:=i
            else
                if A[i] <= A[F[k]] then
                    begin
                        inc(k);
                        F[k]:=i;
                    end
                else
                    begin
                        l:=1;   r:=k;
                        while l <= r do
                            begin
                                mid:=(l+r) div 2;
                                if A[i] < A[F[mid]] then l:=mid+1
                                else r:=mid-1;
                            end;
                        mid:=(l+r) div 2;
                        F[mid]:=i;
                    end;
        end;
    Res:=k;
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
