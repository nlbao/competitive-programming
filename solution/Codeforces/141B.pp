var fi,fo:text;
    a,x0,y0,c:longint;

function    ok(x1,y1,x2,y2:longint):boolean;
begin
    inc(c);
    if ((x1 < x0) and (y1 < y0)) and ((x2 > x0) and (y2 > y0)) then exit(true);
    exit(false);
end;

function    solve:longint;
var y,j,aa:longint;
begin
    aa:=(a+1) div 2;    c:=0;
    if ok(-aa,0,aa,a) then exit(1);
    y:=a;   j:=1;
    repeat
        inc(j);
        if j mod 2 = 1 then begin
            if ok(-a,y,0,y+a) then exit(c);
            if ok(0,y,a,y+a) then exit(c);
        end
        else if ok(-aa,y,aa,y+a) then exit(c);
        y:=y+a;
    until y > y0;
    exit(-1);
end;

begin
    assign(fi,'141B.in');   reset(fi);
    assign(fo,'141B.out');  rewrite(fo);
    readln(fi,a,x0,y0);
    writeln(fo,solve);
    close(fo);
    close(fi);
end.