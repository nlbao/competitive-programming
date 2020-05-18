const   INPUT = '136B.in';
        OUTPUT = '136B.out';
        MAX_A = 1000000010;
        MAX_L = 10000;

type    int = int64;
        arr = array[0..MAX_L] of int;

var fi,fo:text;
    a,b,p,res:int;
    i,lx,ly:longint;
    x,y:arr;

function    mod3(x:int):int;    begin   while x < 0 do x:=x+3;  exit(x mod 3);  end;

procedure   to3(n:int;  var x:arr;  var lx:longint);
begin
    fillchar(x,sizeof(x),0);
    lx:=0;
    while n > 0 do begin
        inc(lx);
        x[lx]:=mod3(n);
        n:=n div 3;
    end;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,a,b);
    to3(a,x,lx); to3(b,y,ly);
    while lx < ly do inc(lx);
    while ly < lx do inc(ly);
    res:=0; p:=1;
    for i:=1 to lx do begin
        res:=res+mod3(y[i]-x[i])*p;
        p:=p*3;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.