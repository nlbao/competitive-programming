const
    INPUT = 'A.in';
    OUTPUT = 'A.out';

var
    fi,fo:text;
    h,t,v,x:int64;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,h,t,v,x);
    while t*x < h do inc(x);
    {if t*x < h then}
        writeln(fo,(t*x-h)/(x-v):0:6,' ',t/1:0:6);
    {else
        writeln(fo,0/1:0:6,' ',h/(x+0.000001):0:6);}
    close(fo);
    close(fi);
end.