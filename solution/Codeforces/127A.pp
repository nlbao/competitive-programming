const   INPUT = '127A.in';
        OUTPUT = '127A.out';
        MAX_N = 110;

var fi,fo:text;
    n,i:longint;
    k,s:double;
    x,y:array[0..MAX_N] of double;


begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    s:=0;
    readln(fi,n,k);
    readln(fi,x[1],y[1]);
    for i:=2 to n do begin
        readln(fi,x[i],y[i]);
        s:=s+sqrt(sqr(x[i]-x[i-1])+sqr(y[i]-y[i-1]));
    end;
    s:=(s*k)/50;
    writeln(fo,s:0:9);
    close(fo);
    close(fi);
end.