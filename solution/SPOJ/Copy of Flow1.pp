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
    i,u:longint;
begin
    init_queue;
    for u:=1 to N do begin
        inQueue[u]:=false;
        trace[u]:=0;
    end;
    push_to_queue(S);
    trace[S]:=-1;
    with queue do
        repeat
            u:=pop_from_queue;
            i:=head[u];
            while i <> 0 do begin
                with e[i] do
                    if (trace[y] = 0) and (c > f) then begin
                        trace[y]:=i;
                        if y = T then exit(true);
                        push_to_queue(y);
                    end;
                i:=link[i];
            end;
        until nItems = 0;
    exit(false);
end;
{---------------------------------------------------------------------------}
procedure   incFlow;
var
    i,v,delta:longint;
begin
    trace[S]:=0;
    delta:=MAX_INT;
    v:=T;
    while trace[v] <> 0 do
        with e[trace[v]] do begin
            if c > f then delta:=min(delta,c-f);
            v:=x;
        end;
    if delta = MAX_INT then exit;
    v:=T;
    while trace[v] <> 0 do
        with e[trace[v]] do begin
            inc(f,delta);
            dec(e[-trace[v]].f,delta);
            v:=x;
        end;
end;
{---------------------------------------------------------------------------}
procedure   Edmonds_Karp;
begin
    repeat
        if find_path = false then break;
        incFlow;
    until false;
end;
{---------------------------------------------------------------------------}
function    check(u,l,r:longint):boolean;   inline;
begin
    exit((u > l) and (u <= r));
end;
{---------------------------------------------------------------------------}
procedure   print_result;
var
    i,u,v,tmp:longint;
    res:array[0..MAX_N,1..2] of longint;
    avail:array[0..MAX_N] of boolean;
begin
    for i:=1 to nC do begin
        res[i][1]:=0;
        res[i][2]:=0;
    end;
    for i:=1 to N do avail[i]:=true;
    tmp:=nA+nB;
    for u:=1 to N do begin
        i:=head[u];
        while i <> 0 do begin
            if e[i].f > 0 then begin
                v:=e[i].y;
                if (check(u,0,nA) = true) and (check(v,tmp,tmp+nC) = true) then begin
                    if (res[v-tmp][1] = 0) and (avail[u]) then begin
                        res[v-tmp][1]:=u;
                        avail[u]:=false;
                    end;
                end
                else
                    if (check(u,tmp,tmp+nC) = true) and (check(v,nA,tmp) = true) then
                        if (res[u-tmp][2] = 0) and (avail[v]) then begin
                            res[u-tmp][2]:=v-nA;
                            avail[v]:=false;
                        end;
            end;
            i:=link[i];
        end;
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