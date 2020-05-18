{
    PROB: ctiming
    LANG: PASCAL
    ID: storm59061
}

const   INPUT = 'ctiming.in';
        OUTPUT = 'ctiming.out';

var fi,fo:text;
    d,h,m,res:int64;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,d,h,m);
    res:=((d-11-1)*24+13+h)*60+m-11;
    if res < 0 then writeln(fo,-1)
    else writeln(fo,res);
    close(fo);
    close(fi);
end.