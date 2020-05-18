const
    INPUT = 'Flow1.inp';
    OUTPUT = 'Flow1.out';
    MAX_N = 1000;
    MAX_M = 100000;
    MAX_INT = 1000000000;

type
    arrID = array[0..MAX_N] of longint;
    recEdge = record
        x,y:longint;
        c,f:longint;
    end;
    recQueue = record
        items:array[0..MAX_N] of longint;
        front,rear,nItems:longint;
    end;

var
    fi,fo:text;
    nA,nB,nC:longint;
    idA,idB,idC:arrID;
    N,M,S,T:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head:array[0..MAX_N] of longint;
    link:array[-MAX_M..MAX_M] of longint;
    queue:recQueue;
    inQueue:array[0..MAX_N] of boolean;
    trace:array[0..MAX_N] of longint;
    w:array[0..MAX_N,0..MAX_N] of boolean;

{---------------------------------------------------------------------------}
procedure   set_id(var id:arrID;    k:longint);
var
    i:longint;
begin
    for i:=1 to k do begin
        inc(N);
        id[i]:=N;
    end;
end;
{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint);  inline;
begin
    inc(M);
    with e[M] do begin
        x:=u; y:=v;
        c:=1; f:=0;
        link[M]:=head[u];
        head[u]:=M;
    end;
    with e[-M] do begin
        x:=v;   y:=u;
        c:=0;   f:=0;
        link[-M]:=head[v];
        head[v]:=link[-M];
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,nA,nC);
    nB:=nA;
    N:=0;   M:=0;
    set_id(idA,nA);
    set_id(idB,nB);
    set_id(idC,nC);
    S:=N+1; T:=N+2;
    inc(N,2);
    for i:=1 to N do head[i]:=0;
    for i:=1 to nA do add_edge(S,idA[i]);
    for i:=1 to nB do add_edge(idB[i],T);
    for i:=1 to nA do begin
        while not eoln(fi) do begin
            read(fi,j);
            add_edge(idA[i],idC[j]);
        end;
        readln(fi);
    end;
    for i:=1 to nB do begin
        while not eoln(fi) do begin
            read(fi,j);
            add_edge(idC[j],idB[i]);
        end;
        readln(fi);
    end;
end;
{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;   inline;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   init_queue; inline;
begin
    with queue do begin
        front:=0; rear:=-1;
        nItems:=0;
    end;
end;
{---------------------------------------------------------------------------}
procedure   push_to_queue(u:longint);   inline;
begin
    if inQueue[u] then exit;
    with queue do begin
        rear:=(rear+1) mod MAX_N;
        items[rear]:=u;
        inQueue[u]:=true;
        inc(nItems);
    end;
end;
{---------------------------------------------------------------------------}
function    pop_from_queue:longint;  inline;
begin
    with queue do begin
        pop_from_queue:=items[front];
        inQueue[items[front]]:=false;
        front:=(front+1) mod MAX_N;
        dec(nItems);
    end;
end;
{---------------------------------------------------------------------------}
function    find_path:boolean;
var
    i,u,v:longint;
begin
    for i:=1 to N do trace[i]:=0;
    trace[S]:=-1;
    with queue do begin
        items[1]:=S;
        front:=1;   rear:=1;
        repeat
            u:=items[front];    inc(front);
            i:=head[u];
            while i <> 0 do begin
                v:=e[i].y;
                if (trace[v] = 0) and (e[i].c > e[i].f) then begin
                    trace[v]:=i;
                    if v = T then exit(true);
                    inc(rear);
                    items[rear]:=v;
                end;
                i:=link[i];
            end;
        until front > rear;
    end;
    exit(false);
end;
{---------------------------------------------------------------------------}
procedure   incFlow;
var
    v,i,delta:longint;
begin
    delta:=MAX_INT;
    v:=T;
    repeat
        i:=trace[v];
        delta:=min(delta,e[i].c-e[i].f);
        v:=e[i].x;
    until v = S;
    v:=T;
    repeat
        i:=trace[v];
        e[i].f:=e[i].f+delta;
        e[-i].f:=e[-i].f-delta;
        v:=e[i].x;
    until v = S;
end;
{---------------------------------------------------------------------------}
procedure   Edmonds_Karp;
var
    i:longint;
begin
    for i:=-M to M do e[i].f:=0;
    while find_path = true do incFlow;
end;
{---------------------------------------------------------------------------}
function    check(u,l,r:longint):boolean;   inline;
begin
    exit((u > l) and (u <= r));
end;
{---------------------------------------------------------------------------}
procedure   print_result;
var
    i,u,v,tmp,x,y,z:longint;
    res:array[0..MAX_N,1..2] of longint;
    avail:array[0..MAX_N] of boolean;
begin
    for i:=1 to nC do begin
        res[i][1]:=0;
        res[i][2]:=0;
    end;
    for u:=1 to N do begin
        for v:=1 to N do w[u,v]:=false;
        avail[u]:=true;
    end;
    for i:=1 to M do
        with e[i] do
            if f > 0 then w[x,y]:=true;
    tmp:=nA+nB;
    with queue do begin
        init_queue;
        push_to_queue(S);
        avail[S]:=false;
        repeat
            u:=pop_from_queue;
            for v:=1 to N do
                if (w[u,v] = true) and (avail[v]) then begin
                    trace[v]:=u;
                    if v = T then begin
                        x:=trace[trace[u]];
                        y:=trace[u]-tmp;
                        z:=u-nA;
                        res[y][1]:=x;
                        res[y][2]:=z;
                    end
                    else begin
                        push_to_queue(v);
                        avail[v]:=false;
                    end;
                end;
        until nItems = 0;
    end;

    for i:=1 to nC do
        writeln(fo,res[i][1],' ',res[i][2]);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    Edmonds_Karp;
    print_result;
    close(fo);
    close(fi);
end.
