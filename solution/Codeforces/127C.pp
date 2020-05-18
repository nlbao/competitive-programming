const   INPUT = '127C.in';
        OUTPUT = '127C.out';
        MAX_INT = 2000000000;

var fi,fo:text;
    t1,t2,x1,x2,t0,a1,a2,p,resY1,resY2:double;
    i,j:longint;

function    f(y1,y2:double):double;
var tmp:double;
begin
    tmp:=((a1*y1 + a2*y2)/(y1+y2));
    if tmp < 0 then tmp:=MAX_INT;
    exit(tmp);
end;

procedure   update(t,y1,y2:double);
begin
    p:=t;
    resY1:=y1;  resY2:=y2;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,t1,t2,x1,x2,t0);
    a1:=t1-t0;  a2:=t2-t0;
    if a1 = 0 then update(a1,x1,0)
    else update(a2,0,x2);
    writeln(p:0:6);
    if (a1 <> 0) and (a2 <> 0) then begin
        j:=trunc(x2) div 2;
        for i:=trunc(x1) downto 1 do begin
            if f(i,j) < p then update(f(i,j),i,j);
            if (j > 1) and (f(i,j-1) < p) then update(f(i,j-1),i,j-1);
            if (j < x2) and (f(i,j+1) < p) then update(f(i,j+1),i,j+1);
        end;
        i:=trunc(x1) div 2;
        for j:=trunc(x2) downto 1 do begin
            if f(i,j) < p then update(f(i,j),i,j);
            if (i > 1) and (f(i-1,j) < p) then update(f(i-1,j),i-1,j);
            if (j < x2) and (f(i+1,j) < p) then update(f(i+1,j),i+1,j);
        end;
    end;
    writeln(p:0:6);
    writeln(fo,resY1:0:0,' ',resY2:0:0);
    close(fo);
    close(fi);
end.