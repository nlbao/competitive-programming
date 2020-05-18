
var fi,fo:text;


begin
    assign(fi,'155E.in');   reset(fi);
    assign(fo,'155E.out');  rewrite(fo);

    close(fo);
    close(fi);
end.