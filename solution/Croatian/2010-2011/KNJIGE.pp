const   INPUT = 'KNJIGE.in';
        OUTPUT = 'KNJIGE.out';
        MAX_N = 300010;

var fi,fo:text;
    n:longint;
    a:array[0..MAX_N] of longint;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
end;

procedure   solve;
var i,j,res:longint;
begin
    res:=0;
    j:=n;
    for i:=n downto 1 do
        if a[i] <> j then inc(res)
        else dec(j);
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