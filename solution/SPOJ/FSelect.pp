{$M 100000000}
{$R-}
const   INPUT = 'FSelect.in';
        OUTPUT = 'FSelect.out';
        MAX_N = 200010;
        MAX_M = 2*MAX_N;
        MAX_Q = MAX_N div 2;

type    pEdge = ^recEdge;
        recEdge = record
            x,y:longint;
            link:pEdge;
        end;

        pList = ^recList;
        recList = record
            id:longint;
            link:pList;
        end;

var
    fi,fo:text;
    n,m,nList,root:longint;
    list:array[0..MAX_Q] of pList;
    head:array[0..MAX_N] of pEdge;
    h,parent:array[0..MAX_N] of longint;
    ans:array[0..MAX_N,0..25] of longint;

{---------------------------------------------------------------------------}
function    log(x,i:longint):double;
begin
    exit(ln(x)/ln(i));
end;
{---------------------------------------------------------------------------}
procedure   swap(var x,y:longint);
var tmp:longint;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   add_to_list(u,i:longint);
var p:pList;
begin
    new(p);
    with p^ do begin
        id:=u;
        link:=list[i];
        list[i]:=p;
    end;
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
var i,x,y:longint;
begin
    readln(fi,n,nList);
    m:=0;
    for i:=1 to n do head[i]:=nil;
    for i:=1 to nList do list[i]:=nil;
    for i:=1 to n do begin
        readln(fi,x,y);
        if x <> 0 then add_to_list(i,x);
        if y = 0 then root:=i
        else begin
            add_edge(i,y,head[i]);
            add_edge(y,i,head[y]);
        end;
    end;
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var p:pEdge;
begin
    p:=head[u];
    while p <> nil do
        with p^ do begin
            if parent[y] = -1 then begin
                h[y]:=h[u]+1;
                parent[y]:=u;
                DFS(y);
            end;
            p:=link;
        end;
end;
{---------------------------------------------------------------------------}
procedure   init_LCA;
var i,j,k:longint;
begin
    k:=trunc(log(n,2));
    for i:=1 to n do
        for j:=0 to k do ans[i][j]:=-1;
    for i:=1 to n do ans[i][0]:=parent[i];
    for j:=1 to k do
        for i:=1 to n do
            ans[i][j]:=ans[ans[i][j-1]][j-1];
end;
{---------------------------------------------------------------------------}
function    LCA(u,v:longint):longint;
var i:longint;
begin
    if h[u] < h[v] then exit(LCA(v,u));
    if h[u] > h[v] then
        for i:=trunc(log(h[u]-h[v],2)) downto 0 do
            if h[u]-(1 shl i) >= h[v] then
                u:=ans[u][i];
    for i:=trunc(log(h[u],2)) downto 0 do
        if ans[u][i] <> ans[v][i] then begin
            u:=ans[u][i];
            v:=ans[v][i];
        end;
    exit(ans[u][0]);
end;
{---------------------------------------------------------------------------}
procedure   init;
var i:longint;
begin
    for i:=1 to n do parent[i]:=-1;
    parent[0]:=-MAX_N;
    h[0]:=MAXLONGINT;   h[root]:=0;
    DFS(root);
    init_LCA;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,u,v,tmp,res:longint;
    p:pList;
begin
    for i:=1 to nList do begin
        tmp:=0; u:=1;
        p:=list[i];
        while p <> nil do
            with p^ do begin
                if h[id] >= tmp then begin
                    tmp:=h[id];
                    u:=id;
                end;
                p:=link;
        end;
        res:=0;
        p:=list[i];
        while p <> nil do
            with p^ do begin
                v:=LCA(u,id);
                tmp:=h[u]+h[id]-2*h[v];
                if tmp > res then res:=tmp;
                p:=link;
            end;
        writeln(fo,res);
    end;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init;
    solve;
    close(fo);
    close(fi);
end.

