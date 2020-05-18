const   INPUT = '';
        OUTPUT = '';
        MAX_N = 100010;
        MAX_M = MAX_N;
        MAX_LOG = 20;
        MAX_INT = 1000000000;

type    recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,log2_n,rmin,rmax:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,h:array[0..MAX_N] of longint;
    p,f,g:array[0..MAX_N,0..MAX_LOG] of longint;

function    min(x,y:longint):longint;   inline;   begin   if x < y then exit(x)   else exit(y);   end;

function    max(x,y:longint):longint;   inline;   begin   if x > y then exit(x)   else exit(y);   end;

function    log(a,x:double):longint;    begin   if x = 0 then exit(0)   else exit(trunc(ln(x)/ln(a)));  end;

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
var i,u,v,w:longint;
begin
    readln(fi,n);
    for i:=1 to n do head[i]:=0;
    m:=0;
    for i:=1 to n-1 do begin
        readln(fi,u,v,w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    end;
    log2_n:=log(2,n);
end;

procedure   DFS(u:longint);
var i:longint;
begin
    for i:=1 to log2_n do
        if h[u]-(1 shl i) < 1 then break
        else begin
            p[u][i]:=p[p[u][i-1]][i-1];
            f[u][i]:=min(f[u][i-1],f[p[u][i-1]][i-1]);
            g[u][i]:=max(g[u][i-1],g[p[u][i-1]][i-1]);
        end;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if y <> p[u][0] then begin
            h[y]:=h[u]+1;
            p[y][0]:=u;
            f[y][0]:=w; g[y][0]:=w;
            DFS(y);
        end;
        i:=link;
    end;
end;

procedure   init;
var i,j:longint;
begin
    h[1]:=1;    p[1][0]:=0;
    DFS(1);
end;

function    get(u,v:longint):longint;
var i:longint;
begin
    if h[u] < h[v] then exit(get(v,u));
    rmin:=MAX_INT;
    rmax:=-MAX_INT;
    if h[u] > h[v] then
        for i:=log2_n downto 0 do
            if h[u]-(1 shl i) >= h[v] then begin
                rmin:=min(rmin,f[u][i]);
                rmax:=max(rmax,g[u][i]);
                u:=p[u][i];
            end;
    if u = v then exit;
    for i:=log2_n downto 0 do
        if (h[u]-(1 shl i) > 0) and (p[u][i] <> p[v][i]) then begin
            rmin:=min(rmin,min(f[u][i],f[v][i]));
            rmax:=max(rmax,max(g[u][i],g[v][i]));
            u:=p[u][i]; v:=p[v][i];
        end;
    rmin:=min(rmin,min(f[u][0],f[v][0]));
    rmax:=max(rmax,max(g[u][0],g[v][0]));
end;

procedure   solve;
var i,q,u,v:longint;
begin
    readln(fi,q);
    for i:=1 to q do begin
        readln(fi,u,v);
        get(u,v);
        writeln(fo,rmin,' ',rmax);
    end;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init;
    solve;
    close(fo);
    close(fi);
end.
