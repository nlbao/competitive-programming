const   INPUT = '129A.in';
        OUTPUT = '129A.out';
        MAX_N = 110;

var fi,fo:text;
    n,i,s,res:longint;
    a:array[0..MAX_N] of longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    s:=0;
    readln(fi,n);
    for i:=1 to n do begin
        read(fi,a[i]);
        inc(s,a[i]);
    end;
    res:=0;
    for i:=1 to n do
        if (s-a[i]) mod 2 = 0 then inc(res);
    writeln(fo,res);
    close(fo);
    close(fi);
end.