const   MAX_N = 100010;

var fi,fo:text;
    n,b,i:longint;
    a:array[0..MAX_N] of longint;

function    solve1():longint;
var i:longint;
begin
    for i:=1 to n do
        if a[i] >= b then exit(0);
    for i:=2 to n do
        if a[i] > a[1] then exit(1);
    exit(2);
end;


function    solve2():longint;
var i:longint;
begin
    a[0]:=1;    a[1]:=1;
    for i:=2 to n+1 do
        a[i]:=(a[i-1]+a[i-2]) mod 1000000000;
    exit(a[n+1]);
end;

begin
    assign(fi,'c11pf.in');  reset(fi);
    assign(fo,'c11pf.out'); rewrite(fo);
    readln(fi,n,b);
    for i:=1 to n do read(fi,a[i]);
    i:=solve1();
    writeln(fo,i);
    if i = 0 then writeln(fo,0)
    else writeln(fo,solve2());
    close(fo);
    close(fi);
end.