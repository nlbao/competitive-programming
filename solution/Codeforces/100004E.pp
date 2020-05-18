const   MAX_N = 26;
        MAX_M = 1010;
        oo = 1000000000000000000;

type    int = int64;

var fi,fo:text;
    nTest,n,m:longint;
    p,e,f:array[0..MAX_N,0..MAX_M] of int;
    l:int;

function    min(x,y:int):int;   begin   if x < y then exit(x);  exit(y);    end;

procedure   enter;
var i,j:longint;
begin
    read(fi,n,m,l);
    for i:=1 to n do
        for j:=1 to m do
            read(fi,p[i][j],e[i][j]);
end;

procedure   solve;
var i,j,jj:longint;
    res:int;
begin
    res:=oo;
    for j:=1 to m do
        f[1][j]:=e[1][j]+p[1][j];
    for i:=2 to n do
        for j:=1 to m do begin
            f[i][j]:=oo;
            for jj:=1 to m do
                f[i][j]:=min(f[i][j],f[i-1][jj]+abs(p[i][j]-p[i-1][jj]));
            f[i][j]:=f[i][j]+e[i][j];
        end;
    for j:=1 to m do
        res:=min(res,f[n][j]+abs(p[n][j]-l));
    writeln(fo,res);
end;

begin
    assign(fi,'100004E.in');    reset(fi);
    assign(fo,'100004E.out');   rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
