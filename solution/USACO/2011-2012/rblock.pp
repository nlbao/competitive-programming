{
    PROB: rblock
    LANG: PASCAL
    ID: storm59061
}

const   INPUT = 'rblock.in';
        OUTPUT = 'rblock.out';
        MAX_N = 110;
        MAX_M = 10010;
        MAX_INT = 1000000000;

type    recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,heap_size:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head,pos,d:array[0..MAX_N] of longint;
    heap:array[0..2*MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;

function    min(x,y:longint):longint;   begin   if x < y then exit(x)   else exit(y);   end;

function    max(x,y:longint):longint;   begin   if x > y then exit(x)   else exit(y);   end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   add_edge(u,v,w0:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u;   y:=v;
        w:=w0;
        link:=head[x];
        head[x]:=m;
    end;
    with e[-m] do begin
        x:=v;   y:=u;
        w:=w0;
        link:=head[x];
        head[x]:=-m;
    end;
end;

procedure   enter;
var i,j,u,v,w:longint;
begin
    readln(fi,n,j);
    for i:=1 to n do head[i]:=0;
    m:=0;
    for i:=1 to j do begin
        readln(fi,u,v,w);
        add_edge(u,v,w);
    end;
end;

procedure   up_heap(i:longint);
var r:longint;
begin
    r:=i shr 1;
    if (r < 1) or (d[heap[r]] <= d[heap[i]]) then exit;
    swap(pos[heap[i]],pos[heap[r]]);
    swap(heap[i],heap[r]);
    up_heap(r);
end;

procedure   down_heap(i:longint);
var c:longint;
begin
    c:=i shl 1;
    if (c < heap_size) and (d[heap[c+1]] < d[heap[c]]) then inc(c);
    if (c > heap_size) or (d[heap[c]] >= d[heap[i]]) then exit;
    swap(pos[heap[i]],pos[heap[c]]);
    swap(heap[i],heap[c]);
    down_heap(c);
end;

procedure   push(u:longint);
begin
    inc(heap_size);
    heap[heap_size]:=u;
    pos[u]:=heap_size;
    up_heap(pos[u]);
end;

procedure   pop(var u:longint);
begin
    u:=heap[1];
    pos[u]:=-1;
    heap[1]:=heap[heap_size];
    pos[heap[1]]:=1;
    dec(heap_size);
    if heap_size > 0 then down_heap(1);
end;

function    Dijkstra(s,t:longint):longint;
var i,j,u:longint;
begin
    for i:=1 to n do begin
        d[i]:=MAX_INT;
        pos[i]:=-1;
        avail[i]:=true;
    end;
    d[s]:=0;
    heap_size:=0;
    push(s);
    repeat
        pop(u);
        avail[u]:=false;
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if (avail[y]) and (d[u]+w < d[y]) then begin
                d[y]:=d[u]+w;
                if pos[y] = -1 then push(y)
                else begin
                    j:=pos[y];
                    up_heap(j);
                    down_heap(j);
                end;
            end;
            i:=link;
        end;
    until (u = t) or (heap_size = 0);
    exit(d[t]);
end;

procedure   solve;
var i,dmin,res:longint;
begin
    dmin:=Dijkstra(1,n);
    res:=0;
    for i:=1 to m do begin
        e[i].w:=e[i].w*2;
        e[-i].w:=e[-i].w*2;
        res:=max(res,Dijkstra(1,n)-dmin);
        e[i].w:=e[i].w div 2;
        e[-i].w:=e[-i].w div 2;
    end;
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.