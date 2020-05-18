const   MAX_N = 40;
        MAX_INT = 1000000000;

type    int = longint;

var fi,fo:text;
    nTest,n:longint;
    s,t:array[0..MAX_N,0..MAX_N,0..MAX_N] of int;

function    max(x,y:int):int;   begin   if x > y then exit(x)   else exit(y);   end;

procedure   enter;
var z,x,y:longint;
begin
    fillchar(s,sizeof(s),0);
    readln(fi,n);
    for z:=1 to n do
        for x:=1 to n do
            for y:=1 to n do
                read(fi,s[z][x][y]);

end;

procedure   init;
var x,y,z:longint;
begin
    for z:=1 to n do
        for x:=1 to n do
            for y:=1 to n do
                s[z][x][y]:=s[z][x][y]+s[z][x-1][y]+s[z][x][y-1]-s[z][x-1][y-1];
end;

function    cal(z,x1,y1,x2,y2:longint):int;
begin
    exit(s[z][x2][y2]-s[z][x1-1][y2]-s[z][x2][y1-1]+s[z][x1-1][y1-1]);
end;

procedure   solve;
var z,zz,x1,y1,x2,y2:longint;
    res:int;
    t:array[0..MAX_N] of int;
begin
    res:=-MAX_INT;
    for x1:=1 to n do
        for y1:=1 to n do
            for x2:=x1 to n do
                for y2:=y1 to n do if y2-y1 = x2-x1 then begin
                    fillchar(t,sizeof(t),0);
                    for z:=1 to n do begin
                        t[z]:=t[z-1]+cal(z,x1,y1,x2,y2);
                        zz:=z-(x2-x1);
                        if zz > 0 then res:=max(res,t[z]-t[zz-1]);
                    end;
                end;
    writeln(fo,res);
end;

begin
    assign(fi,'MaxCub.in');   reset(fi);
    assign(fo,'MaxCub.out');  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        init;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.