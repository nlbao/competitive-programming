uses    math;

var fi,fo:text;

function    ok(x,y,k:longint):boolean;
var i:longint;
begin
    i:=max(1,x div k)*k;
    while i < x do i:=i+k;
    exit(i+1 <= y);
end;

procedure   solve();
var i,m:longint;
    x,y,res:longint;
begin
    readln(fi,m);
    for i:=1 to m do begin
        read(fi,x,y);
        res:=-1;
        if y-x+1 >= 32 then res:=((y-x+1) div 16)*16
        else if (ok(x,y,8)) or (ok(x,y,16)) then res:=2;
        writeln(fo,res);
    end;
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'fibval.in');    reset(fi);
    assign(fo,'fibval.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    solve();
    close(fi);
    close(fo);
end.