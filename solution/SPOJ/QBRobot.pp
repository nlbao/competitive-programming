const
    INPUT = 'QBRobot.inp';
    OUTPUT = 'QBRobot.out';
    MAX_N = 500;
    MAX_M = 30000;
    MAX_C = 10000;
    MAX_W = MAX_N*MAX_C;

type
    recE = record
        u,v,t,c:longint;
    end;

var
    fi,fo:text;
    N,M,minW,HeapSize:longint;
    P:array[1..MAX_N] of longint;
    head:array[1..MAX_N+1] of longint;
    adj,adjT,adjC:array[1..2*MAX_M] of longint;
    Pos,d,c:array[1..MAX_N] of longint;
    Heap:array[1..MAX_M] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i:longint;
    E:array[1..MAX_M] of recE;
begin
    read(fi,N);
    for i:=1 to N do read(fi,P[i]);
    for i:=1 to N+1 do head[i]:=0;
    read(fi,M);
    for i:=1 to M do
        begin
            read(fi,E[i].u,E[i].v,E[i].t,E[i].c);
            inc(head[E[i].u]);  inc(head[E[i].v]);
        end;
    for i:=2 to N+1 do head[i]:=head[i]+head[i-1];
    for i:=1 to M do
        begin
            adj[head[E[i].u]]:=E[i].v;  adj[head[E[i].v]]:=E[i].u;
            adjT[head[E[i].u]]:=E[i].t; adjT[head[E[i].v]]:=E[i].t;
            adjC[head[E[i].u]]:=E[i].c; adjC[head[E[i].v]]:=E[i].c;
            dec(head[E[i].u]);  dec(head[E[i].v]);
        end;
end;
{---------------------------------------------------------------------------}
procedure   UpHeap(i:longint);
var
    tmp,root:longint;
begin
    tmp:=Heap[i];
    root:=i div 2;
    while (root > 0) and (d[Heap[root]] > d[tmp]) do
        begin
            Heap[i]:=Heap[root];
            Pos[Heap[i]]:=i;
            i:=root;
            root:=i div 2;
        end;
    Heap[i]:=tmp;
    Pos[tmp]:=i;
end;
{---------------------------------------------------------------------------}
procedure   DownHeap(i:longint);
var
    tmp,child:longint;
begin
    tmp:=Heap[i];
    child:=2*i;
    while child <= HeapSize do
        begin
            if (child < HeapSize) and (d[Heap[child+1]] < d[Heap[child]]) then child:=child+1;
            if d[Heap[child]] >= d[tmp] then break;
            Heap[i]:=Heap[child];
            Pos[Heap[i]]:=i;
            i:=child;
            child:=2*i;
        end;
    Heap[i]:=tmp;
    Pos[tmp]:=i;
end;
{---------------------------------------------------------------------------}
procedure   Push(u:longint);
begin
    HeapSize:=HeapSize+1;
    Heap[HeapSize]:=u;
    Pos[u]:=HeapSize;
    UpHeap(HeapSize);
end;
{---------------------------------------------------------------------------}
function    Pop:longint;
begin
    if HeapSize = 0 then exit(-1);
    Pop:=Heap[1];
    Pos[Heap[1]]:=-1;
    Heap[1]:=Heap[HeapSize];
    HeapSize:=HeapSize-1;
    DownHeap(1);
end;

{---------------------------------------------------------------------------}
function    Dijkstra(W:longint):longint;
var
    i,u,v,tmpD,tmpC:longint;
begin
    for i:=1 to N do
        begin
            Pos[i]:=-1;
            d[i]:=MAXLONGINT;
        end;
    d[1]:=0;   c[1]:=W;
    HeapSize:=0;
    Push(1);
    repeat
        u:=Pop;
        if (u = -1) or (u = N) then break;
        for i:=head[u]+1 to head[u+1] do
            begin
                v:=adj[i];
                tmpD:=d[u]+adjT[i];
                tmpC:=c[u]-adjC[i];
                if (tmpC >= 0) then
                    if (tmpD < d[v]) or ((tmpD = d[v]) and (tmpC+P[v]*W > c[v])) then
                        begin
                            c[v]:=tmpC+P[v]*W;
                            if c[v] > W then c[v]:=W;
                            d[v]:=tmpD;
                            if Pos[v] = -1 then Push(v)
                            else UpHeap(Pos[v]);
                        end;
            end;
    until u = N;
    exit(d[N]);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    l,r,w,minTime:longint;
begin
    minTime:=Dijkstra(MAX_W);
    l:=1;   r:=MAX_W;
    while l <= r do
        begin
            w:=(l+r) div 2;
            if Dijkstra(w) = minTime then
                begin
                    minW:=w;
                    r:=w-1;
                end
            else l:=w+1;
        end;
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
begin
    writeln(fo,minW);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    Solve;
    Print_result;
    close(fo);
    close(fi);
end.