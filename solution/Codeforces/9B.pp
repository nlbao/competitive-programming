const   INPUT = '9B.in';
        OUTPUT = '9B.out';
        MAX_N = 110;

var fi,fo:text;
    n,i,res:longint;
    vB,vS,xU,yU,len,time,l,t:double;
    x:array[0..MAX_N] of double;

function    d(x1,y1,x2,y2:double):double;
begin
    exit(sqrt(sqr(x1-x2)+sqr(y1-y2)));
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,n,vB,vS);
    for i:=1 to n do read(fi,x[i]);
    readln(fi,xU,yU);
    time:=1000000000;   len:=time;  res:=2;
    for i:=n downto 2 do begin
        l:=d(x[i],0,xU,yU);
        t:=d(0,0,x[i],0)/vB+l/vS;
        if (t < time) or ((t = time) and (l < len)) then begin
            time:=t;    len:=l;
            res:=i;
        end;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.