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
    n,x,y,a,b,i,j:longint;
    c,d:array[0..111*111] of longint;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'242A.in');    reset(fi);
    assign(fo,'242A.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,x,y,a,b);
    n:=0;
    for i:=a to x do
        for j:=b to min(i-1,y) do begin
            n:=n+1;
            c[n]:=i;    d[n]:=j;
        end;
    writeln(fo,n);
    for i:=1 to n do writeln(fo,c[i],' ',d[i]);
    close(fi);
    close(fo);
end.

