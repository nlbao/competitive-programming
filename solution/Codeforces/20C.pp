const
    INPUT = '20C.inp';
    OUTPUT = '20C.out';
    MAX_N = 100010;
    MAX_M = 2*MAX_N;
    MAX_INT = 1000000000000;

type
    recEdge = record
        x,y:longint;
        w:int64;
        link:longint;
    end;

var
    fi,fo:text;
    N,M,heap_size:longint;
    e:array[0..MAX_M] of recEdge;
    head,trace,pos:array[0..MAX_N] of longint;
    d:array[0..MAX_N] of int64;
    avail:array[0..MAX_N] of boolean;
    heap:array[0..2*MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   add_edge(u,v,c:longint);
begin
    inc(M);
    with e[M] do begin
        x:=u; y:=v;
        w:=c;
        link:=head[u];
    end;
    head[u]:=M;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j,u,v,c:longint;
begin
    readln(fi,N,j);
    M:=0;
    for i:=1 to N do head[i]:=0;
    for i:=1 to j do begin
        readln(fi,u,v,c);
        add_edge(u,v,c);
        add_edge(v,u,c);
    end;
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
    if (i = 1) or (d[heap[r]] <= d[heap[i]]) then exit;
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
    if (c < heap_size) and (d[heap[c+1]] <= d[heap[c]]) then inc(c);
    if (c > heap_size) or (d[heap[c]] >= d[heap[i]]) then exit;
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
procedure   Dijkstra(S,T:longint);
var
    i,u:longint;
begin
    for i:=1 to N do begin
        d[i]:=MAX_INT;
        trace[i]:=-1;
        pos[i]:=-1;
        avail[i]:=true;
    end;
    d[S]:=0;
    heap_size:=0;
    push(S);
    repeat
        u:=pop;
        avail[u]:=false;
        i:=head[u];
        while i <> 0 do
            with e[i] do begin
                if (avail[y]) and (d[u]+w < d[y]) then begin
                    d[y]:=d[u]+w;
                    trace[y]:=u;
                    if pos[y] = -1 then push(y)
                    else up_heap(pos[y]);
                end;
                i:=link;
            end;
    until (u = T) or (heap_size = 0);
end;
{---------------------------------------------------------------------------}
procedure   print_result;
var
    i:longint;
    res:array[0..MAX_N] of longint;
begin
    if trace[N] = -1 then begin
        writeln(fo,-1);
        exit;
    end;
    res[0]:=1;
    res[1]:=N;
    i:=N;
    while trace[i] <> -1 do begin
        i:=trace[i];
        inc(res[0]);
        res[res[0]]:=i;
    end;
    for i:=res[0] downto 1 do write(fo,res[i],' ');
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    Dijkstra(1,N);
    print_result;
    close(fo);
    close(fi);
end.
