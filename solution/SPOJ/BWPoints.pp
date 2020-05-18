const
    INPUT = 'BWPoints.inp';
    OUTPUT = 'BWPoints.out';
    MAX_N = 200000;

var
    N,K:longint;
    A:array[1..MAX_N] of longint;
    T:array[1..MAX_N] of byte;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    for i:=1 to N do
        begin
            read(fi,A[i]);
            T[i]:=0;
        end;
    for i:=N+1 to 2*N do
        begin
            read(fi,A[i]);
            T[i]:=1;
        end;
    close(fi);
    N:=2*N;
end;

procedure   Swap(var x,y:longint);
var
    tmp:longint;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;

procedure   Quick_sort(l,r:longint);
var
    i,j,p:longint;
    tmp:byte;
begin
    i:=l;   j:=r;
    p:=A[(i+j) div 2];
    repeat
        while A[i] < p do inc(i);
        while A[j] > p do dec(j);
        if i <= j then
            begin
                Swap(A[i],A[j]);
                tmp:=T[i];
                T[i]:=T[j];
                T[j]:=tmp;
                inc(i); dec(j);
            end;
    until i >= j;
    if l < j then Quick_sort(l,j);
    if i < r then Quick_sort(i,r);
end;

procedure   Find;
var
    i,pre:longint;
begin
    K:=0;
    pre:=-1;
    for i:=1 to N do
        if pre = -1 then pre:=T[i]
        else
            if pre <> T[i] then
                begin
                    inc(K);
                    pre:=-1;
                end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,K);
    close(fo);
end;

begin
    Enter;
    Quick_sort(1,N);
    Find;
    Print_result;
end.