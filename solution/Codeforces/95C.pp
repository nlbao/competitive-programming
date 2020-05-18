const
    INPUT = '95C.inp';
    OUTPUT = '95C.out';
    MAX_N = 1010;
    MAX_M = 4000000;
    MAX_INT = 10000000000000;

type
    pEdge = ^recEdge;
    recEdge = record
        x,y:longint;
        w:int64;
        link:pEdge;
    end;
    arrHead = array[0..MAX_N] of pEdge;

var
    fi,fo:text;
    N,M,S,F,heap_size:longint;
    head,head2:arrHead;
    d,t,c:array[0..MAX_N] of int64;
    avail:array[0..MAX_N] of boolean;
    heap,pos:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
function    min(x,y:int64):int64;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint;   weight:int64;   var head:arrHead);
var
    p:pEdge;
begin
    new(p);
    with p^ do begin
        x:=u; y:=v;
        w:=weight;
        link:=head[u];
    end;
    head[u]:=p;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,u,v:longint;
    w:int64;
begin
    readln(fi,N,M);
    readln(fi,S,F);
    for i:=1 to N do head[i]:=nil;
    for i:=1 to M do begin
        readln(fi,u,v,w);
        add_edge(u,v,w,head);
        add_edge(v,u,w,head);
    end;
    for i:=1 to N do
        readln(fi,t[i],c[i]);
end;
{---------------------------------------------------------------------------}
procedure   swap(var x,y:longint);
var
    tmp:longint;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   up_heap(i:longint);
var
    r:longint;
begin
    r:=i div 2;
    if (r < 0) or (d[heap[r]] <= d[heap[i]]) then exit;
    swap(pos[heap[i]],pos[heap[r]]);
    swap(heap[i],heap[r]);
    up_heap(r);
end;
{---------------------------------------------------------------------------}
procedure   down_heap(i:longint);
var
    c:longint;
begin
    c:=i*2;
    if (c < heap_size) and (d[heap[c+1]] < d[heap[c]]) then inc(c);
    if (c >= heap_size) or (d[heap[c]] >= d[heap[i]]) then exit;
    swap(pos[heap[i]],pos[heap[c]]);
    swap(heap[i],heap[c]);
    down_heap(c);
end;
{---------------------------------------------------------------------------}
procedure   push(u:longint);
begin
    inc(heap_size);
    heap[heap_size]:=u;
    pos[u]:=heap_size;
    up_heap(heap_size);
end;
{---------------------------------------------------------------------------}
function    pop:longint;
var
    u:longint;
begin
    u:=heap[1];
    pos[u]:=-1;
    heap[1]:=heap[heap_size];
    dec(heap_size);
    if heap_size > 0 then begin
        pos[heap[1]]:=1;
        down_heap(1);
    end;
    exit(u);
end;
{---------------------------------------------------------------------------}
procedure   Dijkstra1(s:longint);
var
    u:longint;
    p:pEdge;
begin
    for u:=1 to N do begin
        d[u]:=MAX_INT;
        avail[u]:=true;
        pos[u]:=-1;
    end;
    d[s]:=0;
    heap_size:=0;
    push(s);
    repeat
        u:=pop;
        avail[u]:=false;
        if (u <> s) and (d[u] <= t[s]) then add_edge(s,u,c[s],head2);
        p:=head[u];
        while p <> nil do
            with p^ do begin
                if (avail[y]) and (d[u]+w < d[y]) then begin
                    d[y]:=d[u]+w;
                    if pos[y] = -1 then push(y)
                    else up_heap(pos[y]);
                end;
                p:=link;
            end;
    until heap_size = 0;
end;
{---------------------------------------------------------------------------}
procedure   Dijkstra2(s,f:longint;  var head:arrHead);
var
    u:longint;
    p:pEdge;
begin
    for u:=1 to N do begin
        d[u]:=MAX_INT;
        avail[u]:=true;
        pos[u]:=-1;
    end;
    d[s]:=0;
    heap_size:=0;
    push(s);
    repeat
        u:=pop;
        avail[u]:=false;
        p:=head[u];
        while p <> nil do
            with p^ do begin
                if (avail[y]) and (d[u]+w < d[y]) then begin
                    d[y]:=d[u]+w;
                    if pos[y] = -1 then push(y)
                    else up_heap(pos[y]);
                end;
                p:=link;
            end;
    until (u = f) or (heap_size = 0);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
begin
    for i:=1 to N do head2[i]:=nil;
    for i:=1 to N do
        Dijkstra1(i);
    Dijkstra2(S,F,head2);
    if d[F] = MAX_INT then writeln(fo,-1)
    else writeln(fo,d[F]);
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