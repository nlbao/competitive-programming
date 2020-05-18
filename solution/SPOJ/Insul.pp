const
    INPUT = 'Insul.inp';
    OUTPUT = 'Insul.out';
    MAX_N = 100000;

var
    N,Res:longint;
    A:array[1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,N);
    for i:=1 to N do read(fi,A[i]);
    close(fi);
end;

procedure   Quick_sort(l,r:longint);
var
    i,j,p,tmp:longint;
begin
    i:=l;   j:=r;
    p:=A[(i+j) div 2];
    repeat
        while A[i] < p do inc(i);
        while A[j] > p do dec(j);
        if i <= j then
            begin
                tmp:=A[i];
                A[i]:=A[j];
                A[j]:=tmp;
                inc(i); dec(j);
            end;
    until i >=j;
    if l < j then Quick_sort(l,j);
    if i < r then Quick_sort(i,r);
end;

procedure   Find;
var
    i,j:longint;
begin
    Res:=0;
    for i:=1 to N do
        Res:=Res+A[i];
    i:=1;   j:=N;
    while i < j do
        begin
            Res:=Res+(A[j]-A[i]);
            inc(i); dec(j);
        end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,Res);
    close(fo);
end;

begin
    Enter;
    Quick_sort(1,N);
    Find;
    Print_result;
end.