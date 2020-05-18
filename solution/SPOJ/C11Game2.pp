const   INPUT = 'C11Game2.in';
        OUTPUT = 'C11Game2.out';
        MAX_N = 210;
        MAX_A = 15;
        MAX_INT = 1000000000;

var fi,fo:text;
    n:longint;
    a,b:array[0..MAX_N] of longint;
    f:array[0..MAX_N,-MAX_A..MAX_A,-MAX_A..MAX_A] of longint;

function    max(x,y:longint):longint;   begin   if x > y then exit(x) else exit(y); end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
    for i:=1 to n do read(fi,b[i]);
end;

function    ok(x,y:longint):boolean;
begin
    if ((x = 0) and (y <> 0)) or ((x <> 0) and (y = 0)) then exit(true);
    exit(false);
end;

procedure   solve;
var i,j,x,y,z,t:longint;
    res:longint;
begin
    for x:=-10 to 10 do
        for y:=-10 to 10 do f[1][x][y]:=-MAX_INT;
    f[1][a[1]][b[1]]:=a[1]*b[1];
    writeln(a[1],' ',b[1],' ',f[1][-3][0]);

    for i:=2 to n do begin
        writeln(i);
        for x:=-10 to 10 do
            for y:=-10 to 10 do begin
                f[i][x][y]:=-MAX_INT;
                if (x = a[i]) and (y = b[i]) then
                    for z:=-10 to 10 do
                        for t:=-10 to 10 do if f[i-1][z][t] > -MAX_INT then
                            f[i][x][y]:=max(f[i][x][y],f[i-1][z][t]+a[i]*b[i]);

                if (x = -2) and (y = 2) then writeln('                  ',f[i][x][y]);

                if (x = a[i]) and (y <> b[i]) and (ok(y,b[i])) then
                    for z:=-10 to 10 do if f[i-1][z][y] > -MAX_INT then
                        f[i][x][y]:=max(f[i][x][y],f[i-1][z][y]-z*y+z*b[i]+a[i]*y);

                if (x <> a[i]) and (y = b[i]) and (ok(x,a[i])) then
                    for t:=-10 to 10 do if f[i-1][x][t] > -MAX_INT then
                        f[i][x][y]:=max(f[i][x][y],f[i-1][x][t]-x*t+x*b[i]+a[i]*t);

                if (ok(x,a[i])) and (ok(y,b[i])) and (f[i-1][x][y] > -MAX_INT) then
                    f[i][x][y]:=max(f[i][x][y],f[i-1][x][y]+a[i]*b[i]);

                if f[i][x][y] > 0 then writeln('     ',x,' ',y,' ',f[i][x][y]);
            end;
        readln;
    end;
    res:=-MAX_INT;
    for x:=-10 to 10 do
        for y:=-10 to 10 do
            res:=max(res,f[n][x][y]);
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