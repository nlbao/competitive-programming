const   MAX_N = 100010;
        MAX_M = 100010;

type    int = int64;
        recEdge = record
            x,y:longint;
            w:int;
        end;

var fi,fo:text;
    n,m:longint;
    e:array[0..MAX_M] of recEdge;
    p:array[0..MAX_N] of longint;

procedure   enter;
var i:longint;
begin
    readln(fi,n,m);
    for i:=1 to m do
        with e[i] do readln(fi,x,y,w);
end;

procedure   qsort(l,r:longint);
var i,j,p:longint;
    t:recEdge;
begin
    if l >= r then exit;
    p:=e[l+random(r-l+1)].w;
    i:=l;   j:=r;
    repeat
        while e[i].w > p do inc(i);
        while e[j].w < p do dec(j);
        if i <= j then begin
            t:=e[i];    e[i]:=e[j];     e[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    qsort(l,j); qsort(i,r);
end;

function    mmod(x:int):int;    begin   exit(x mod 1000000000); end;

function    get_root(u:longint):longint;
begin
    if p[u] < 0 then exit(u);
    p[u]:=get_root(p[u]);
    exit(p[u]);
end;

procedure   solve;
var i,u,v:longint;
    a,b,res:int;
begin
    randomize;
    qsort(1,m);
    for i:=1 to n do p[i]:=-1;
    res:=0;
    for i:=1 to m do with e[i] do begin
        u:=get_root(x); a:=abs(p[u]);
        v:=get_root(y); b:=abs(p[v]);
        if u <> v then begin
            res:=mmod(res+mmod(w*mmod(mmod(a*b)+mmod(a*(a-1) div 2)+mmod(b*(b-1) div 2))));
            p[u]:=p[u]+p[v];
            p[v]:=u;
        end
        else res:=mmod(res+mmod(w*mmod(a*(a-1) div 2)));
    end;
    writeln(fo,res);
end;

begin
    assign(fi,'KOICost.in');    reset(fi);
    assign(fo,'KOICost.out');   rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.