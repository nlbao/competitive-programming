uses    math;

const   MAX_N = 222;
        oo = 1000000000;

type    ll = longint;

var fi,fo:text;
    n:longint;
    a,f:array[0..MAX_N,0..MAX_N] of ll;

procedure   enter();
var i,j:longint;
begin
    read(fi,n);
    for i:=1 to n do
        for j:=1 to n do read(fi,a[i][j]);
    inc(n);
    for i:=1 to n do begin
        a[i][n]:=a[i][1];
        a[n][i]:=a[1][i];
    end;
    a[n][n]:=0;
end;


procedure   up(i,j:longint; v:ll);
begin   f[i][j]:=min(f[i][j], v);   end;

function    solve():longint;
var i,j,res:longint;
begin
    if n = 1 then exit(0);
    for i:=1 to n do
        for j:=1 to n do f[i][j]:=oo;
    f[1][1]:=0;
    for i:=1 to n do
        for j:=1 to i do begin
            up(i+1,j, f[i][j]+a[i][i+1]);
            up(i+1,i, f[i][j]+a[j][i+1]);
        end;
    res:=oo;
    for j:=1 to n do res:=min(res,f[n][j] + a[j][n]);
    exit(res);
end;


begin
    assign(fi,'disney2.in');    reset(fi);
    assign(fo,'disney2.out');   rewrite(fo);
    enter();
    writeln(fo,solve());
    close(fo);
    close(fi);
end.

