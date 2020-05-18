const   INPUT = '118E.in';
        OUTPUT = '118E.out';
        MAX_N = 100010;
        MAX_M = 3*100010;

type    recEdge = record
            x,y:longint;
            avail:boolean;
            link:longint;
        end;

var fi,fo:text;
    n,m,count:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head,parent,number,low:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u;   y:=v;
        avail:=true;
        link:=head[u];
        head[u]:=m;
    end;
    with e[-m] do begin
        x:=v;   y:=u;
        avail:=true;
        link:=head[v];
        head[v]:=-m;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i,j,u,v:longint;
begin
    readln(fi,n,j);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        readln(fi,u,v);
        add_edge(u,v);
    end;
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var i:longint;
begin
    inc(count);
    number[u]:=count;   low[u]:=number[u];
    i:=head[u];
    while i <> 0 do
        with e[i] do begin
            if (avail) and (parent[y] = -1) then begin
                e[-i].avail:=false;
                if number[y] = -1 then begin
                    DFS(y);
                    low[u]:=min(low[u],low[y]);
                    parent[y]:=u;
                end
                else low[u]:=min(low[u],number[y]);
            end;
            i:=link;
        end;
end;
{---------------------------------------------------------------------------}
function    check:boolean;
var u,v:longint;
begin
    for v:=1 to n do begin
        u:=parent[v];
        if (u <> -1) and (low[v] > number[u]) then exit(false);
    end;
    exit(true);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i:longint;
begin
    for i:=1 to n do begin
        parent[i]:=-1;
        number[i]:=-1;
    end;
    DFS(1);
    if check = false then begin
        writeln(fo,0);
        exit;
    end;
    for i:=-m to m do
        with e[i] do
            if avail then writeln(fo,x,' ',y);
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