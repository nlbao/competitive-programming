uses    math;

const   MAX_N = 510;
        MAX_M = sqr(MAX_N);

type    recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    nTest,n,nE,m:longint;
    head,p,h,f:array[0..MAX_N] of longint;
    x,y,w:array[0..MAX_M] of longint;
    e:array[0..2*MAX_M] of recEdge;
    ok:array[0..MAX_M] of boolean;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   add_edge(u,v,w0:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        w:=w0;
        link:=head[x];
        head[x]:=m;
    end;
end;

procedure   enter;
var i:longint;
begin
    readln(fi,n,nE);
    for i:=1 to nE do
        readln(fi,x[i],y[i],w[i]);
end;

procedure   sort(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    p:=w[l+random(r-l)];
    i:=l;   j:=r;
    repeat
        while w[i] < p do inc(i);
        while w[j] > p do dec(j);
        if i <= j then begin
            swap(x[i],x[j]);
            swap(y[i],y[j]);
            swap(w[i],w[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j); sort(i,r);
end;

function    get_root(u:longint):longint;
begin
    if p[u] < 0 then exit(u);
    p[u]:=get_root(p[u]);
    exit(p[u]);
end;

procedure   dfs(u:longint);
var i:longint;
begin
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if p[y] = -1 then begin
            p[y]:=u;
            h[y]:=h[u]+1;
            f[y]:=w;
            dfs(y);
        end;
        i:=link;
    end;
end;

function    find(u,v:longint):longint;
var t:longint;
begin
    if h[u] > h[v] then exit(find(v,u));
    t:=0;
    while h[v] > h[u] do begin
        t:=max(t,f[v]);
        v:=p[v];
    end;
    while u <> v do begin
        t:=max(t,max(f[u],f[v]));
        u:=p[u];
        v:=p[v];
    end;
    exit(t);
end;

procedure   solve;
var i,t,r1,r2,res:longint;
begin
    randomize;
    sort(1,nE);
    m:=0;
    res:=0;
    for i:=1 to n do begin
        p[i]:=-1;
        head[i]:=0;
    end;
    for i:=1 to nE do ok[i]:=false;
    for i:=1 to nE do begin
        r1:=get_root(x[i]);
        r2:=get_root(y[i]);
        if r1 <> r2 then begin
            ok[i]:=true;
            res:=res+w[i];
            add_edge(x[i],y[i],w[i]);
            add_edge(y[i],x[i],w[i]);
            p[r1]:=p[r1]+p[r2];
            p[r2]:=r1;
        end;
    end;
    write(fo,res,' ');

    for i:=1 to n do p[i]:=-1;
    p[1]:=0; h[1]:=1;
    dfs(1);
    t:=1000000000;
    for i:=1 to nE do
        if not ok[i] then
            t:=min(t,w[i]-find(x[i],y[i]));
    writeln(fo,res+t);
end;

begin
    assign(fi,'10600.in');  reset(fi);
    assign(fo,'10600.out'); rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.