var fi,fo:text;
    r1,s:longint;

begin
    assign(fi,'r2.in');     reset(fi);
    assign(fo,'r2.out');    rewrite(fo);
    readln(fi,r1,s);
    writeln(fo,2*s-r1);
    close(fo);
    close(fi);
end.
