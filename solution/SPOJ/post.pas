{$M 16777216}
uses    math;

var fi,fo:text;
    a,b:longint;

begin
{$IFDEF WINDOWS}
    assign(fi,'post.in');    reset(fi);
    assign(fo,'post.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,a,b);
    writeln(fo,a+b);
    close(fi);
    close(fo);
end.
