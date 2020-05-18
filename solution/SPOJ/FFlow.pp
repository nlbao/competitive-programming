const
    INPUT = 'FFlow.inp';
    OUTPUT = 'FFlow.out';
    MAX_N = 5010;
    MAX_M = 60010;
    MAX_INT = 1000050000;

type
    recEdge = record
        x,y:longint;
        c,f:int64;
    end;
    recQueue = record
        items:array[0..MAX_N] of longint;
        front,rear:longint;
    end;

var
    fi,fo:text;
    N,M,S,T:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    link:array[-MAX_M..MAX_M] of longint;
    head:array[0..MAX_N] of longint;
    queue:recQueue;
    inQueue:array[0..MAX_N] of boolean;
    flow_in:array[0..MAX_N] of int64;
    h,current:array[0..MAX_N] of longint;
    count:array[0..2*MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint;   capacity:int64);
begin
    inc(M);
    with e[M] do begin
        x:=u;
        y:=v;
        c:=capacity;
        link[M]:=head[u];
        head[u]:=M;
    end;
    with e[-M] do begin
        x:=v;
        y:=u;
        c:=0;
        link[-M]:=head[v];
        head[v]:=-M;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,u,v:longint;
    capacity:int64;
begin
    readln(fi,N,M);
    S:=1;   T:=N;
    for i:=1 to N do head[i]:=0;
    i:=2*M;   M:=0;
    repeat
        readln(fi,u,v,capacity);
        add_edge(u,v,capacity);
        add_edge(v,u,capacity);
    until M = i;
end;

{---------------------------------------------------------------------------}
function    min(x,y:int64):int64;   inline;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
function    isEmpty:boolean;    inline;
begin
    with queue do
        exit(front = (rear+1) mod N);
end;
{---------------------------------------------------------------------------}
procedure   push_to_queue(u:longint);   inline;
begin
    if inQueue[u] then exit;
    with queue do begin
        rear:=(rear+1) mod N;
        items[rear]:=u;
    end;
    inQueue[u]:=true;
end;
{---------------------------------------------------------------------------}
function    pop_from_queue:longint; inline;
begin
    with queue do begin
        pop_from_queue:=items[front];
        inQueue[items[front]]:=false;
        front:=(front+1) mod N;
    end;
end;
{---------------------------------------------------------------------------}
function    over_flow(u:longint):boolean;   inline;
begin
    exit((u <> S) and (u <> T) and (flow_in[u] > 0));
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i,u:longint;
begin
    for i:=-M to M do e[i].f:=0;
    for u:=1 to N do flow_in[u]:=0;
    i:=head[S];
    while i <> 0 do
        with e[i] do begin
            f:=c;
            e[-i].f:=-c;
            flow_in[y]:=flow_in[y]+c;
            flow_in[S]:=flow_in[S]-c;
            i:=link[i];
        end;
    for u:=1 to N do h[u]:=1;
    h[S]:=N; h[T]:=0;
    for i:=0 to 2*MAX_N do count[i]:=0;
    count[N]:=1;    count[0]:=1;    count[1]:=N-2;
    queue.front:=0;
    queue.rear:=-1;
    for u:=1 to N do
        if over_flow(u) then
            push_to_queue(u);
end;
{---------------------------------------------------------------------------}
procedure   push(i:longint);
var
    delta:int64;
begin
    with e[i] do begin
        delta:=min(c-f,flow_in[x]);
        f:=f+delta;
        e[-i].f:=e[-i].f-delta;
        flow_in[x]:=flow_in[x]-delta;
        flow_in[y]:=flow_in[y]+delta;
    end;
end;
{---------------------------------------------------------------------------}
procedure   discharge(u:longint);
var
    i:longint;
begin
    i:=current[u];
    while i <> 0 do begin
        with e[i] do
            if (c > f) and (h[x] > h[y]) then begin
                push(i);
                if over_flow(y) then push_to_queue(y);
                if flow_in[u] = 0 then break;
            end;
        i:=link[i];
    end;
    current[u]:=i;
end;
{---------------------------------------------------------------------------}
procedure   set_h(u,newH:longint);  inline;
begin
    dec(count[h[u]]);
    h[u]:=newH;
    inc(count[newH]);
end;
{---------------------------------------------------------------------------}
procedure   perform_gap_heuristic(gap:longint);
var
    u:longint;
begin
    if (gap > 0) and (gap < N) and (count[gap] = 0) then
        for u:=1 to N do
            if (u <> S) and (h[u] > gap) and (h[u] <= N) then begin
                set_h(u,N+1);
                current[u]:=head[u];
            end;
end;
{---------------------------------------------------------------------------}
procedure   lift(u:longint);
var
    i,minH,oldH:longint;
begin
    minH:=2*MAX_N;
    i:=head[u];
    while i <> 0 do begin
        with e[i] do
            if c > f then minH:=min(minH,h[y]);
        i:=link[i];
    end;
    oldH:=h[u];
    set_h(u,minH+1);
    perform_gap_heuristic(oldH);
end;
{---------------------------------------------------------------------------}
procedure   preFlow_push;
var
    u:longint;
begin
    for u:=1 to N do current[u]:=head[u];
    while not isEmpty do begin
        u:=pop_from_queue;
        discharge(u);
        if flow_in[u] > 0 then begin
            lift(u);
            push_to_queue(u);
            current[u]:=head[u];
        end;
    end;
    writeln(fo,flow_in[T]);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init;
    preFlow_push;
    close(fo);
    close(fi);
end.
