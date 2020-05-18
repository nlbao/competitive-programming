uses    math;

const   MAX_N = 110;
        MAX_M = 110;
        oo = 1000000000;

var fi,fo:text;
    n,m,i,j,res:longint;
    a,f:array[0..MAX_N,0..MAX_M] of longint;

begin
    assign(fi,'qbmax.in');  reset(fi);
    assign(fo,'qbmax.out'); rewrite(fo);
    readln(fi,m,n);
    for i:=1 to m do
        for j:=1 to n do
            read(fi,a[i][j]);
    for i:=0 to m+1 do
        for j:=0 to n+1 do f[i][j]:=-oo;
    for i:=1 to m do f[i][1]:=a[i][1];
    for j:=2 to n do
        for i:=1 to m do
            f[i][j]:=a[i][j]+max(f[i-1][j-1],max(f[i][j-1],f[i+1][j-1]));
    res:=-oo;
    for i:=1 to m do res:=max(res,f[i][n]);
    writeln(fo,res);
    close(fo);
    close(fi);
end.