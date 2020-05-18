const   INPUT = 'PUZ.in';
        OUTPUT = 'PUZ.out';

var fi,fo:text;
    a,b,v,res:int64;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,a,b,v);
    res:=(v-a) div (a-b);
    if (v-a) mod (a-b) <> 0 then inc(res);
    writeln(fo,res+1);
    close(fo);
    close(fi);
end.