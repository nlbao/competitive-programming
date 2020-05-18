uses    math;

const   MAX_N = 310;
        oo = 1000000000;

var fi,fo:text;
    n,m,nT,i,x,y,z:longint;
    f:array[0..MAX_N,0..MAX_N] of longint;

begin
    assign(fi,'hurdles.in');    reset(fi);
    assign(fo,'hurdles.out');   rewrite(fo);
    readln(fi,n,m,nT);
    for x:=1 to n do begin
        for y:=1 to n do f[x][y]:=oo;
        f[x][x]:=0;
    end;
    for i:=1 to m do begin
        readln(fi,x,y,z);
        f[x][y]:=min(f[x][y],z);
    end;
    for y:=1 to n do
        for x:=1 to n do
            for z:=1 to n do
                f[x][z]:=min(f[x][z],max(f[x][y],f[y][z]));
    for i:=1 to nT do begin
        readln(fi,x,y);
        if f[x][y] = oo then writeln(fo,-1)
        else writeln(fo,f[x][y]);
    end;
    close(fo);
    close(fi);
end.
