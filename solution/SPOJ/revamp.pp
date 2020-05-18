const   MAX_K = 30;
        MAX_N = 10010;
        MAX_M = 50010;
        oo = 1000000000000000;

type    int = int64;
        recEdge = record
            x,y:longint;
            w:int;
            link:longint;
        end;
        recHeap = record
            u,j:longint;
        end;

var fi,fo:text;
    n,m,k,t,top:longint;
    e:array[0..2*MAX_M] of recEdge;
    head:array[0..MAX_N] of longint;
    h:array[0..MAX_N*MAX_K] of recHeap;
    pos:array[0..MAX_N,0..MAX_K] of longint;
    d:array[0..MAX_N,0..MAX_K] of int;

function    min(x,y:int):int;   begin   if x < y then exit(x);  exit(y);    end;

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
var i,j,u,v,w:longint;
begin
    readln(fi,n,j,k);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        readln(fi,u,v,w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    end;
end;

procedure   swapH(x,y:longint);
var t:recHeap;
begin
    pos[h[x].u][h[x].j]:=y;
    pos[h[y].u][h[y].j]:=x;
    t:=h[x];    h[x]:=h[y];     h[y]:=t;
end;

function    cmp(x,y:longint):int;   begin   exit(d[h[x].u][h[x].j]-d[h[y].u][h[y].j]);  end;

procedure   up_heap(i:longint);
var j:longint;
begin
    j:=i shr 1;
    if (j < 1) or (cmp(j,i) <= 0) then exit;
    swapH(j,i);
    up_heap(j);
end;

procedure   down_heap(i:longint);
var j:longint;
begin
    j:=i shl 1;
    if (j < top) and (cmp(j+1,j) < 0) then inc(j);
    if (j > top) or (cmp(j,i) >= 0) then exit;
    swapH(j,i);
    down_heap(j);
end;

procedure   push(u0,j0:longint);
begin
    if pos[u0][j0] = -1 then begin
        inc(top);
        h[top].u:=u0;   h[top].j:=j0;
        pos[u0][j0]:=top;
    end;
    up_heap(pos[u0][j0]);
end;

procedure   pop(var u0,j0:longint);
begin
    u0:=h[1].u; j0:=h[1].j;
    swapH(1,top);
    pos[u0][j0]:=-1;
    dec(top);
    down_heap(1);
end;

procedure   update(value:int;    u,j:longint);
begin
    if value >= d[u][j] then exit;
    d[u][j]:=value;
    push(u,j);
end;

procedure   dijkstra(s:longint);
var i,j,u:longint;
begin
    for i:=1 to n do
        for j:=0 to k do begin
            d[i][j]:=oo;
            pos[i][j]:=-1;
        end;
    d[s][0]:=0;
    top:=0; push(s,0);
    repeat
        pop(u,j);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            update(d[u][j]+w,y,j);
            if j < k then update(d[u][j],y,j+1);
            i:=link;
        end;
    until top < 1;
end;

procedure   solve;
var i:longint;
    res:int;
begin
    dijkstra(1);
    res:=oo;
    for i:=0 to k do res:=min(res,d[n][k]);
    writeln(fo,res);
end;

begin
    assign(fi,'revamp.in');     reset(fi);
    assign(fo,'revamp.out');    rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.