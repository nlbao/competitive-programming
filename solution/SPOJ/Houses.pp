const
    INPUT = 'Houses.inp';
    OUTPUT = 'Houses.out';
    MAX_N = 20;
    MAX_L = 100;

var
    fi,fo:text;
    L,N,M:longint;
    A:array[0..MAX_N] of longint;
    X:array[1..MAX_N+2] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i:longint;
begin
    readln(fi,L,N);
    for i:=1 to N do read(fi,A[i]);
end;
{---------------------------------------------------------------------------}
procedure   Swap(var x,y:longint);
var
    tmp:longint;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   InitX;
var
    i:longint;
begin
    A[0]:=L;
    for i:=1 to N do A[0]:=A[0]-A[i];
    M:=1;
    X[1]:=1;
    for i:=1 to A[0] do
        begin
            inc(M);
            X[M]:=0;
        end;
    for i:=2 to N do
        begin
            inc(M);
            X[M]:=i;
        end;
end;
{---------------------------------------------------------------------------}
procedure   SortX(l,r:longint);
var
    i,j:longint;
begin
    i:=l;   j:=r;
    while i < j do
        begin
            Swap(X[i],X[j]);
            inc(i); dec(j);
        end;
end;
{---------------------------------------------------------------------------}
procedure   PrintX;
var
    i,j:longint;
begin
    for i:=1 to M do
        if X[i] = 0 then write(fo,0,' ')
        else
            for j:=1 to A[X[i]] do
                write(fo,X[i],' ');
    writeln(fo);
end;
{---------------------------------------------------------------------------}
procedure   Find;
var
    i,j,count:longint;
    check:boolean;
begin
    InitX;
    PrintX;
    count:=1;
    X[M+1]:=-1;
    repeat
        inc(count);
        check:=false;
        for i:=M downto 2 do
            if X[i] > X[i-1] then
                begin
                    check:=true;
                    j:=i;
                    while X[j+1] > X[i-1] do inc(j);
                    Swap(X[j],X[i-1]);
                    SortX(i,M);
                    PrintX;
                    break;
                end;
    until (check = false) or (count = 1000);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    Find;
    close(fo);
    close(fi);
end.