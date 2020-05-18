const   INPUT = '29D.in';
        OUTPUT = '29D.out';
        MAX_N = 310;
        MAX_M = MAX_N;

type    pEdge = ^recEdge;
        recEdge = record
            x,y:longint;
            link:pEdge;
        end;

var fi,fo:text;
    n,nLeaf,nRes:longint;
    head:array[0..MAX_N] of pEdge;
    h,c:array[0..MAX_N] of longint;
    ans:array[0..MAX_N,0..10] of longint;
    res:array[0..2*MAX_N] of longint;

{---------------------------------------------------------------------------}
function    log(a,x:longint):double;
begin
    exit(ln(x)/ln(a));
end;
{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint;   var head_u:pEdge);
var p:pEdge;
begin
    new(p);
    with p^ do begin
        x:=u; y:=v;
        link:=head_u;
        head_u:=p;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i,u,v:longint;
begin
    readln(fi,n);
    for i:=1 to n do head[i]:=nil;
    for i:=1 to n-1 do begin
        readln(fi,u,v);
        add_edge(u,v,head[u]);
        add_edge(v,u,head[v]);
    end;
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var p:pEdge;
    is_leaf:boolean;
begin
    p:=head[u];
    is_leaf:=true;
    while p <> nil do
        with p^ do begin
            if ans[y][0] = -1 then begin
                is_leaf:=false;
                ans[y][0]:=u;
                h[y]:=h[u]+1;
                DFS(y);
            end;
            p:=p^.link;
        end;
    if is_leaf then inc(nLeaf);
end;
{---------------------------------------------------------------------------}
procedure   init_LCA;
var i,j,k:longint;
begin
    k:=trunc(log(2,n));
    for j:=1 to k do
        for i:=1 to n do
            if ans[i][j-1] < 1 then ans[i][j]:=-1
            else ans[i][j]:=ans[ans[i][j-1]][j-1];
end;
{---------------------------------------------------------------------------}
function    LCA(u,v:longint):longint;
var i:longint;
begin
    if h[u] < h[v] then exit(LCA(v,u));
    if h[u] > h[v] then
    for i:=trunc(log(2,h[u]-h[v])) downto 0 do
        if h[u]-(1 shl i) >= h[v] then
            u:=ans[u][i];
    if u = v then exit(u);
    for i:=trunc(log(2,h[u])) downto 0 do
        if ans[u][i] <> ans[v][i] then begin
            u:=ans[u][i];
            v:=ans[v][i];
        end;
    exit(ans[u][0]);
end;
{---------------------------------------------------------------------------}
function    add_to_res(u,v:longint):longint;
var i,p:longint;
begin
    p:=LCA(u,v);
    while u <> p do begin
        inc(c[u]);
        if c[u] > 2 then exit(-1);
        u:=ans[u][0];
        inc(nRes);
        res[nRes]:=u;
    end;
    inc(nRes,h[v]-h[p]);
    for i:=0 to h[v]-h[p]-1 do begin
        inc(c[v]);
        if c[v] > 2 then exit(-1);
        res[nRes-i]:=v;
        v:=ans[v][0];
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,u,v:longint;
begin
    nLeaf:=0;
    for i:=1 to n do begin
        ans[i][0]:=-1;
        c[i]:=0;
    end;
    ans[1][0]:=0;   h[1]:=0;
    DFS(1);
    init_LCA;
    nRes:=1;    res[1]:=1;
    u:=1;
    for i:=1 to nLeaf do begin
        read(fi,v);
        if add_to_res(u,v) = -1 then begin
            writeln(fo,-1);
            exit;
        end;
        u:=v;
    end;
    if add_to_res(v,1) = -1 then writeln(fo,-1)
    else for i:=1 to nRes do write(fo,res[i],' ');
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.