const   INPUT = '9D.in';
        OUTPUT = '9D.out';
        MAX_N = 40;

var fi,fo:text;
    n:longint;
    res:int64;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    res:=9*1000000000000000000;
    writeln(res);
    close(fo);
    close(fi);
end.