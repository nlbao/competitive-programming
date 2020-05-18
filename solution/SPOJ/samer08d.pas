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



procedure   enter();
begin
    readln(fi,a);   n:=length(a);
    readln(fi,b);   m:=length(b);
end;


procedure   solve();
begin
    res:=0;
    fillchar(f,sizeof(f),0);
    for i:=1 to n do
        for j:=1 to m do
            if a[i] = b[j] then begin
                f[i][j]:=
            end


    writeln(fo,res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'SAMER08D.in');    reset(fi);
    assign(fo,'SAMER08D.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    readln(fi,n);
    while n > 0 do begin
        enter();
        solve();
        readln(fi,n);
    end;
    close(fo);
    close(fi);
end.