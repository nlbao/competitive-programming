{$R+, $I+}
{$M 16777216}

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
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'RAZGOVORI.in');    reset(fi);
    assign(fo,'RAZGOVORI.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}


    close(fi);
    close(fo);
end.

