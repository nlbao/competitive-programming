const
    INPUT = ''{'x3.inp'};
    OUTPUT = ''{'x3.out'};
    MAX_N = 1000010;

var
    fi,fo:text;
    N:longint;
    a:array[0..MAX_N] of longint;

procedure   enter;
var
    i:longint;
begin
    readln(fi,N);
    for i:=1 to N do readln(fi,a[i]);
end;

procedure   solve;
var
    i,j:longint;
    res:int64;
begin
    res:=0;
    for i:=1 to N-1 do
        for j:=i+1 to N do
            res:=res+(a[i] xor a[j]);
    writeln(fo,res);
end;


begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
