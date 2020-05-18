const
    INPUT = 'NUMCON.inp';
    OUTPUT = 'NUMCON.out';
    MAX_N = 100;

var
    N:longint;
    A:array[1..MAX_N] of string;

procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    N:=0;
    while not eof(fi) do
        begin
            inc(N);
            readln(fi,A[N]);
        end;
    close(fi);
end;

function    compare(a,b:string):longint;
var
    s1,s2:ansiString;
    i,l:longint;
begin
    //if a '>' b then exit -1
    s1:=a+b;    s2:=b+a;
    l:=length(a)+length(b);
    for i:=1 to l do
        if s1[i] > s2[i] then exit(-1)
        else
            if s1[i] < s2[i] then exit(1);
    exit(0);
end;

procedure   Quick_sort(l,r:longint);
var
    i,j:longint;
    p,tmp:string;
begin
    i:=l;   j:=r;
    p:=A[(i+j) div 2];
    repeat
        while compare(A[i],p) = -1 do inc(i);
        while compare(A[j],p) = 1 do dec(j);
        if i <= j then
            begin
                tmp:=A[i];
                A[i]:=A[j];
                A[j]:=tmp;
                inc(i); dec(j);
            end;
    until i >= j;
    if l < j then Quick_sort(l,j);
    if i < r then Quick_sort(i,r);
end;

procedure   Print_result;
var
    fo:text;
    i:longint;
    s:ansiString;
begin
    s:='';
    for i:=1 to N do
    s:=s+A[i];
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,s);
    close(fo);
end;

begin
    Enter;
    Quick_sort(1,N);
    Print_result;
end.