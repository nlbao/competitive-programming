const
    INPUT = 'NKSGame.inp';
    OUTPUT = 'NKSGame.out';
    MAX_N = 100000;
    MAX = 1000000000;

type
    arr = array[0..MAX_N] of longint;

var
    N,minS:longint;
    B,C:arr;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    for i:=1 to N do
        read(fi,B[i]);
    for i:=1 to N do
        read(fi,C[i]);
    close(fi);
end;

procedure   Swap(var x,y:longint);
var
    t:longint;
begin
    t:=x;
    x:=y;
    y:=t;
end;

procedure   Quick_sort(var A:arr;   l,r:longint);
var
    i,j,p:longint;
begin
    i:=l;   j:=r;
    p:=A[(i+j) div 2];
    repeat
        while A[i] < p do inc(i);
        while A[j] > p do dec(j);
        if i <= j then
            begin
                Swap(A[i],A[j]);
                inc(i);
                dec(j);
            end;
    until i >= j;
    if i < r then Quick_sort(A,i,r);
    if l < j then Quick_sort(A,l,j);
end;

procedure   Find;
var
    i,j:longint;
begin
    i:=1;   j:=N;
    minS:=abs(B[i]+C[j]);
    while (i < N) and (j > 1) do
        begin
            if abs(B[i] + C[j-1]) < abs(B[i+1] + C[j]) then
                dec(j)
            else
                inc(i);
            if abs(B[i] + C[j]) < minS then
                minS:=abs(B[i]+C[j]);
        end;
    while i < N do
        begin
            inc(i);
            if abs(B[i] + C[j]) < minS then
                minS:=abs(B[i]+C[j]);
        end;
    while j > 1 do
        begin
            dec(j);
            if abs(B[i] + C[j]) < minS then
                minS:=abs(B[i]+C[j]);
        end;

end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,minS);
    close(fo);
end;

begin
    Enter;
    Quick_sort(B,1,N);
    Quick_sort(C,1,N);
    Find;
    Print_result;
end.
