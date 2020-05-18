const   INPUT = '22E.in';
        OUTPUT = '22E.out';
        MAX_N = 100010;

type    pEdge = ^recEdge;
        recEdge = record
            x,y:longint;
            link:pEdge;
        end;

var fi,fo:text;
    n,nC,top,count,nRes:longint;
    head:array[0..MAX_N] of pEdge;
    stack,number,low,c,root,degI:array[0..MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;
    res:array[0..MAX_N,0..1] of longint;

{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint;   var head_u:pEdge);
var p:pEdge;
begin
    new(p);
    with p^ do begin
        x:=u;   y:=v;
        link:=head_u;
        head_u:=p;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i,j:longint;
begin
    readln(fi,n);
    for i:=1 to n do head[i]:=nil;
    for i:=1 to n do begin
        read(fi,j);
        add_edge(i,j,head[i]);
    end;
end;
{---------------------------------------------------------------------------}
procedure   DFS1(u:longint);
var p:pEdge;
    v:longint;
begin
    inc(top);   stack[top]:=u;
    inc(count);
    number[u]:=count;   low[u]:=count;
    p:=head[u];
    while p <> nil do
        with p^ do begin
            if avail[y] then
                if number[y] = -1 then begin
                    DFS1(y);
                    low[u]:=min(low[u],low[y]);
                end
                else low[u]:=min(low[u],number[y]);
            p:=link;
        end;
    avail[u]:=false;
    if low[u] = number[u] then begin
        inc(nC);
        repeat
            v:=stack[top];  dec(top);
            c[v]:=nC;
        until v = u;
        root[nC]:=u;
    end;
end;
{---------------------------------------------------------------------------}
procedure   add_res(u,v:longint);
begin
    inc(nRes);
    res[nRes][0]:=u;   res[nRes][1]:=v;
end;
{---------------------------------------------------------------------------}
procedure   DFS2(u:longint);
var p:pEdge;
begin
    writeln(u);
    avail[c[u]]:=false;
    p:=head[u];
    while p <> nil do
        with p^ do begin
            if (c[y] <> c[u]) and (avail[c[y]]) then begin
                add_res(root[y],root[u]);
                DFS2(root[y]);
            end;
            p:=link;
        end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i:longint;
begin
    count:=0;
    for i:=1 to n do begin
        avail[i]:=true;
        number[i]:=-1;
    end;
    for i:=1 to n do
        if avail[i] then begin
            top:=0;
            DFS1(i);
        end;
    for i:=2 to nC do avail[i]:=true;
    avail[1]:=false;
    DFS2(root[1]);
    for i:=1 to n do
        if avail[c[i]] then begin
            add_res(root[1],root[c[i]]);
            add_res(root[c[i]],root[1]);
            DFS2(root[c[i]]);
        end;
    writeln(fo,nRes);
    for i:=1 to nRes do writeln(fo,res[i][0],' ',res[i][1]);
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