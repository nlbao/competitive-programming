const   INPUT = '9A.in';
        OUTPUT = '9A.out';

var fi,fo:text;
    a,b:longint;

function    GCD(x,y:longint):longint;
begin
    if (x = 0) or (y = 0) then exit(x or y)
    else exit(GCD(y,x mod y));
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,a,b);
    if b > a then a:=b;
    a:=6-a+1;
    b:=GCD(a,6);
    writeln(fo,a div b,'/',6 div b);
    close(fo);
    close(fi);
end.


