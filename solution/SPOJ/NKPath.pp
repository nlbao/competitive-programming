const   INPUT = 'NKPath.in';
        OUTPUT = 'NKPath.out';
        MAX_M = 110;
        MAX_N = 110;
        MODUN = 1000000000;

var fi,fo:text;
    m,n:longint;
    a,f:array[0..MAX_M,0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var i,j:longint;
begin
    readln(fi,m,n);
    for i:=1 to m do
        for j:=1 to n do read(fi,a[i][j]);
end;
{---------------------------------------------------------------------------}
function    GCD(x,y:longint):longint;   {Binary GCD}
var i,j:longint;
begin
    if (x = 0) or (y = 0) then exit(x or y);
{Let i := lg K, where K is the greatest power of 2 dividing both x and y.}
    i:=0;
    while ((x or y) and 1) = 0 do begin
        inc(i);
        x:=x shr 1;     y:=y shr 1;
    end;
    while (x and 1) = 0 do x:=x shr 1;
{From here on, x is always odd.}
    repeat
        while (y and 1) = 0 do y:=y shr 1;
{Now x and y are both odd, so diff(x, y) is even.
    Let x = min(x, y), y = diff(x, y)/2.}
        if x < y then y:=y-x
        else begin
            j:=x-y;
            x:=y;
            y:=j;
        end;
        y:=y shr 1;
    until y = 0;
    exit(x shl i);
end;
{---------------------------------------------------------------------------}
procedure   update(i,j,k,t:longint);
begin
    if GCD(a[i][j],a[k][t]) > 1 then
        f[k][t]:=(f[k][t]+f[i][j]) mod MODUN;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,j,k,t,res:longint;
begin
    for i:=1 to m do begin
        f[i][1]:=1;
        for j:=2 to n do f[i][j]:=0;
    end;
    for i:=1 to m do
        for j:=1 to n-1 do begin
            for t:=j+1 to n do update(i,j,i,t);
            for k:=i+1 to m do update(i,j,k,j);
            for k:=i+1 to m do
                for t:=j+1 to n do
                    update(i,j,k,t);
        end;
    res:=0;
    for i:=1 to m do res:=(res+f[i][n]) mod MODUN;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.