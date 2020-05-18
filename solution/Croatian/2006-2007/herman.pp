
var fi,fo:text;
    r:double;


begin
    assign(fi,'herman.in');     reset(fi);
    assign(fo,'herman.out');    rewrite(fo);
    readln(fi,r);
    writeln(fo,r*r*pi:0:6);
    writeln(fo,2*r*r:0:6);
    close(fo);
    close(fi);
end.