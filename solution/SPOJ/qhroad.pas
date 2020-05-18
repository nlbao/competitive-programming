{$M+ 16777216}

uses    math;

const   MAX_N = 100005;
        oo = 1000000000;


var fi,fo:text;
    n,m,nQ,c,i:longint;
    x,y,p,q,res:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;


function    get_root(u:longint):longint;
begin
    if p[u] < 0 then exit(u);
    p[u]:=get_root(p[u]);
    exit(p[u]);
end;


function    union(u,v:longint):longint;
var r1,r2:longint;
begin
    r1:=get_root(u);
    r2:=get_root(v);
    if r1 = r2 then exit(0);
    p[r1]:=p[r1]+p[r2];
    p[r2]:=r1;
    exit(1);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'QHROAD.in');    reset(fi);
    assign(fo,'QHROAD.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n,m,nQ);
    for i:=1 to m do begin
        read(fi,x[i],y[i]);
        ok[i]:=true;
    end;
    for i:=1 to nQ do begin
        read(fi,q[i]);
        ok[q[i]]:=false;
    end;

    c:=n;
    for i:=1 to n do p[i]:=-1;
    for i:=1 to m do
        if ok[i] then
            c:=c-union(x[i],y[i]);

    for i:=nQ downto 1 do begin
        res[i]:=c;
        c:=c-union(x[q[i]],y[q[i]]);
    end;
    for i:=1 to nQ do writeln(fo,res[i]);
    close(fi);
    close(fo);
end.