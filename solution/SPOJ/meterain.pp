const   MAX_N = 5010;
        MAX_M = 5010;

type    int = int64;
        recPoint = record
            x,y:int;
        end;
        arrPoly = array[0..MAX_N] of recPoint;

var fi,fo:text;
    n,m,u,v,i:longint;
    p,t:arrPoly;

function    check(u,v:longint):string;
var i,j:longint;
    s:int;
begin
    for i:=1 to n do begin
        t[1]:=p[i];
        t[2].x:=u;  t[2].y:=v;
        t[3]:=p[i+1];
        t[4]:=t[1];
        s:=0;
        for j:=1 to 3 do
            s:=s+(t[j].x-t[j+1].x)*(t[j].y+t[j+1].y);
        if s >= 0 then exit('NO');
    end;
    exit('YES');
end;

begin
    assign(fi,'meterain.inp');  reset(fi);
    assign(fo,'meterain.out');  rewrite(fo);
    readln(fi,n);
    for i:=1 to n do read(fi,p[i].x,p[i].y);
    p[n+1]:=p[1];
    readln(fi,m);
    for i:=1 to m do begin
        readln(fi,u,v);
        writeln(fo,check(u,v));
    end;
    close(fo);
    close(fi);
end.