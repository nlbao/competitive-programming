const
    INPUT = 'KCollect.inp';
    OUTPUT = 'KCollect.out';
    MAX_HEIGHT = 110;
    MAX_WIDTH = 110;
    MAX_N = MAX_HEIGHT*MAX_WIDTH;
    MAX_M = 8*MAX_N;

type
    recEdge = record
        x,y:longint;
        link:longint;
    end;
    recStack = record
        top:longint;
        item:array[0..MAX_N] of longint;
    end;

var
    fi,fo:text;
    Height,Width,N,M,count:longint;
    map:array[0..MAX_HEIGHT,0..MAX_WIDTH] of char;
    e:array[0..MAX_M] of recEdge;
    head,value,number,low:array[0..MAX_N] of longint;
    nC,mC:longint;
    eC:array[0..MAX_M] of recEdge;
    c,headC,sumC,idC:array[0..MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;
    stack:recStack;

{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;   inline;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;   inline;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   push(u:longint);    inline;
begin
    with stack do begin
        inc(top);
        item[top]:=u;
    end;
end;
{---------------------------------------------------------------------------}
function    pop:longint;    inline;
begin
    with stack do begin
        pop:=item[top];
        dec(top);
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,Height,Width);
    for i:=0 to Height+1 do
        for j:=0 to Width+1 do
            map[i,j]:='#';
    for i:=1 to Height do begin
        for j:=1 to Width do read(fi,map[i,j]);
        readln(fi);
    end;
end;
{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint);  inline;
begin
    inc(M);
    with e[M] do begin
        x:=u; y:=v;
        link:=head[u];
    end;
    head[u]:=M;
end;
{---------------------------------------------------------------------------}
procedure   create_graph;
var
    i,j:longint;
    id:array[0..MAX_HEIGHT,0..MAX_WIDTH] of longint;
begin
    N:=0;
    for i:=1 to Height do
        for j:=1 to Width do
            if map[i,j] <> '#' then begin
                inc(N);
                id[i,j]:=N;
                head[N]:=0;
                if (map[i,j] = 'W') or (map[i,j] = 'N') then value[N]:=0
                else value[N]:=ord(map[i,j])-ord('0');
            end;
    M:=0;
    for i:=1 to Height do
        for j:=1 to Width do
            if map[i,j] <> '#' then begin
                if map[i,j+1] <> '#' then add_edge(id[i,j],id[i,j+1]);
                if map[i+1,j] <> '#' then add_edge(id[i,j],id[i+1,j]);
                if (map[i,j] = 'W') and (map[i,j-1] <> '#') then add_edge(id[i,j],id[i,j-1]);
                if (map[i,j] = 'N') and (map[i-1,j] <> '#') then add_edge(id[i,j],id[i-1,j]);
            end;

end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var
    i,v:longint;
begin
    push(u);
    inc(count);
    number[u]:=count;   low[u]:=count;
    i:=head[u];
    while i <> 0 do begin
        v:=e[i].y;
        if avail[v] then
            if number[v] = -1 then begin
                DFS(v);
                low[u]:=min(low[u],low[v]);
            end
            else low[u]:=min(low[u],number[v]);
        i:=e[i].link;
    end;
    if low[u] = number[u] then begin
        inc(nC);
        sumC[nC]:=0;
        repeat
            v:=pop;
            avail[v]:=false;
            c[v]:=nC;
            sumC[nC]:=sumC[nC]+value[v];
        until v = u;
    end;
end;
{---------------------------------------------------------------------------}
procedure   add_edgeC(u,v:longint); inline;
begin
    inc(mC);
    with eC[mC] do begin
        x:=u;   y:=v;
        link:=headC[u];
    end;
    headC[u]:=mC;
end;
{---------------------------------------------------------------------------}
procedure   Tarjan;
var
    i:longint;
begin
    count:=0;
    stack.top:=0;
    for i:=1 to N do begin
        avail[i]:=true;
        number[i]:=-1;
    end;
    for i:=1 to N do
        if avail[i] then DFS(i);

    mC:=0;
    for i:=1 to M do
        with e[i] do
            if c[x] <> c[y] then add_edgeC(c[x],c[y]);
end;
{---------------------------------------------------------------------------}
procedure   DFS_C(u:longint);
var
    i:longint;
begin
    avail[u]:=false;
    i:=headC[u];
    while i <> 0 do
        with eC[i] do
            begin
                if avail[y] then DFS_C(y);
                i:=link;
            end;
    idC[count]:=u;
    dec(count);
end;
{---------------------------------------------------------------------------}
procedure   Topo_sort;
var
    i:longint;
begin
    count:=nC;
    for i:=1 to nC do begin
        avail[i]:=true;
        idC[i]:=-1;
    end;
    DFS_C(c[1]);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,u,v,res:longint;
    f:array[0..MAX_N] of longint;
begin
    for i:=1 to nC do f[i]:=sumC[i];
    res:=f[c[1]];
    for i:=1 to nC do
        if idC[i] <> -1 then begin
            u:=idC[i];
            j:=headC[u];
            while j <> 0 do
                with eC[j] do begin
                    f[y]:=max(f[y],f[u]+sumC[y]);
                    res:=max(res,f[y]);
                    j:=link;
                end;
        end;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    create_graph;
    Tarjan;
    Topo_sort;
    solve;
    close(fo);
    close(fi);
end.