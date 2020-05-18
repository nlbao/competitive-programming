{$M 2000000,0,2000000}
uses    math;

const
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;





begin
{$IFDEF WINDOWS}
    assign(fi,'.in');    reset(fi);
    assign(fo,'.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}





    close(fo);
    close(fi);
end.
