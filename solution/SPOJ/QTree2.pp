const   INPUT = 'QTree2.in';
        OUTPUT = 'QTree2.out';
        MAX_N = 10010;
        MAX_M = MAX_N;
        MAX_W = 100010;
        MAX_LOG = 13;

type    recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    nTest,n,m:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,h,sw:array[0..MAX_N] of longint;
    p:array[0..MAX_N,0..MAX_LOG] of longint;

function    log(a,x:double):double; begin   if x = 0 then exit(0) else exit(ln(x)/ln(a))   end;

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
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to n-1 do begin
        readln(fi,u,v,w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    end;
end;

procedure   DFS(u:longint);
var i:longint;
begin
    for i:=1 to trunc(log(2,n)) do
        if h[u]-(1 shl i) < 1 then break
        else p[u][i]:=p[p[u][i-1]][i-1];
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if y <> p[u][0] then begin
            p[y][0]:=u;
            h[y]:=h[u]+1;
            sw[y]:=sw[u]+w;
            DFS(y);
        end;
        i:=link;
    end;
end;

procedure   init;
begin
    fillchar(p,sizeof(p),0);
    h[1]:=1;    sw[1]:=0;
    DFS(1);
end;

function    LCA(u,v:longint):longint;
var i:longint;
begin
    if h[u] < h[v] then exit(LCA(v,u));
    if h[u] > h[v] then
        for i:=trunc(log(2,h[u]-h[v])) downto 0 do
            if h[u]-(1 shl i) >= h[v] then u:=p[u][i];
    if u = v then exit(u);
    for i:=trunc(log(2,h[u])) downto 0 do
        if p[u][i] <> p[v][i] then begin
            u:=p[u][i];
            v:=p[v][i];
        end;
    exit(p[u][0]);
end;

function    find_Kth(u,k:longint):longint;
var i,c:longint;
begin
    c:=1;
    for i:=trunc(log(2,h[u])) downto 0 do
        if (h[u]-(1 shl i) > 0) and (c+(1 shl i) <= k) then begin
            c:=c+(1 shl i);
            u:=p[u][i];
        end;
    if c <> k then exit(-1);
    exit(u);
end;

procedure   solve;
var ch1,ch2:char;
    i,k,u,v,r:longint;
begin
    read(fi,ch1,ch2);
    while not ((ch1 = 'D') and (ch2 = 'O')) do begin
        for i:=1 to 2 do read(fi,ch2);
        read(fi,u,v);
        r:=LCA(u,v);
        if ch1 = 'D' then writeln(fo,sw[u]+sw[v]-2*sw[r])
        else begin
            read(fi,k);
            if k <= h[u]-h[r]+1 then writeln(fo,find_Kth(u,k))
            else writeln(fo,find_Kth(v,h[u]+h[v]-2*h[r]-k+2));
        end;
        readln(fi);
        read(fi,ch1,ch2);
    end;
    writeln(fo);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi);
        enter;
        init;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.