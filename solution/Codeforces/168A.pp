

var fi,fo:text;
    n,x,y,i:longint;

begin
    assign(fi,'168A.in');   reset(fi);
    assign(fo,'168A.out');  rewrite(fo);
    readln(fi,n,x,y);
    i:=(y*n-100*x) div 100;
    if i*100 < y*n-100*x then i:=i+1;
    if i < 0 then i:=0;
    writeln(fo,i);
    close(fo);
    close(fi);
end.