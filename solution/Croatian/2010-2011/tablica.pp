const   INPUT = 'tablica.in';
        OUTPUT = 'tablica.out';

var fi,fo:text;
    a,b,c,d,t,v:double;
    res,i:longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,a,b);
    readln(fi,c,d);
    res:=0;     v:=a/c+b/d;
    for i:=1 to 3 do begin
        t:=c;
        c:=d;   d:=b;   b:=a;   a:=t;
        if a/c+b/d > v then begin
            v:=a/c+b/d;
            res:=i;
        end;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.