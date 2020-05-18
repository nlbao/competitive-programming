uses    math;

const   MAX_N = 10002;
        MAX_M = MAX_N;
        MAX_C = 102;
        MAX_LOG = 14;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nE,nC,logn,maxC:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,h,c,g,idC,pos,list:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;
    d:array[0..MAX_N,0..MAX_C] of longint;
    p:array[0..MAX_N,0..MAX_LOG] of longint;


procedure   add_edge(u,v:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        link:=head[x];
        head[x]:=nE;
    end;
end;


procedure   enter();
var i,u,v:longint;
begin
    nE:=0;
    fillchar(head,sizeof(head),0);
    read(fi,n);
    for i:=1 to n-1 do begin
        read(fi,u,v);
        add_edge(u,v);
        add_edge(v,u);
    end;
    read(fi,nC);
    for i:=1 to nC do g[i]:=0;
    for i:=1 to n do begin
        read(fi,c[i]);
        inc(g[c[i]]);
    end;
end;


procedure   sort(l,r:longint);
var i,j,p,t:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=g[idC[i]];
    i:=l;   j:=r;
    repeat
        while g[idC[i]] > p do inc(i);
        while g[idC[j]] < p do dec(j);
        if i <= j then begin
            t:=idC[i]; idC[i]:=idC[j];  idC[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;

procedure   dfs_1(u,parent:longint);
var i,j:longint;
begin
    ok[u]:=false;
    for i:=1 to maxC do d[u][i]:=min(d[u][i],d[parent][i]+1);
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if ok[y] then begin
            dfs_1(y,u);
            for j:=1 to maxC do d[u][j]:=min(d[u][j],d[y][j]+1);
        end;
        i:=link;
    end;
end;

procedure   init();
var i,j,u,x:longint;
begin
    for i:=1 to nC do idC[i]:=i;
    randomize;
    sort(1,nC);
    maxC:=0;
    for i:=1 to nC do begin
        pos[idC[i]]:=i;
        if g[idC[i]] >= MAX_C then maxC:=i;
    end;

    for i:=1 to n do begin
        ok[i]:=true;
        for j:=1 to maxC do
            if c[i] = idC[j] then d[i][j]:=0
            else d[i][j]:=oo;
    end;
    for j:=1 to maxC do d[0][j]:=oo;
    dfs_1(1,0);
    for i:=1 to n do ok[i]:=true;
    dfs_1(1,0);

    for i:=1 to nC do h[i]:=g[i];
    for i:=0 to maxC do g[i]:=0;
    for i:=maxC+1 to nC do g[i]:=g[i-1]+h[idC[i]];
    g[nC+1]:=g[nC];
    for i:=1 to n do begin
        j:=pos[c[i]];
        if j > maxC then begin
            list[g[j]]:=i;
            dec(g[j]);
        end;
    end;
end;


procedure   dfs(u:longint);
var i:longint;
begin
    for i:=1 to logn do
        if h[u]-(1 shl i) < 1 then p[u][i]:=-1
        else p[u][i]:=p[p[u][i-1]][i-1];
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if h[y] = -1 then begin
            p[y][0]:=u;
            h[y]:=h[u]+1;
            dfs(y);
        end;
        i:=link;
    end;
end;


function    getLCA(u,v:longint):longint;
var i:longint;
begin
    if h[u] < h[v] then exit(getLCA(v,u));
    if h[u] > h[v] then
        for i:=logn downto 0 do
            if h[u]-(1 shl i) >= h[v] then
                u:=p[u][i];
    if u = v then exit(u);
    for i:=logn downto 0 do
        if p[u][i] <> p[v][i] then begin
            u:=p[u][i];
            v:=p[v][i];
        end;
    exit(p[u][0]);
end;


procedure   solve();
var i,j,u,v,r,x,res:longint;
begin
    logn:=1;
    while (1 shl logn) <= n do inc(logn);
    for i:=1 to n do h[i]:=-1;
    p[1][0]:=-1;
    h[1]:=1;
    dfs(1);

    read(fi,m);
    for i:=1 to m do begin
        read(fi,u,x);
        if pos[x] <= maxC then writeln(fo,d[u][pos[x]])
        else begin
            res:=oo;
            for j:=g[pos[x]]+1 to g[pos[x]+1] do begin
                v:=list[j];
                r:=getLCA(u,v);
                res:=min(res,h[u]+h[v]-2*h[r]);
            end;
            writeln(fo,res);
        end;
    end;
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'KTREEC.in');    reset(fi);
    assign(fo,'KTREEC.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    init();
    solve();
    close(fi);
    close(fo);
end.