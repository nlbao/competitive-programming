const
    INPUT = 'QBSchool.inp';
    OUTPUT = 'QBSchool.out';
    MAX_N = 5000;
    MAX_M = 40000;
    MAX_W = MAX_M*32000+1;

type
    recE = record
        u,v,w:longint;
    end;

var
    N,M,HeapSize:longint;
    head:array[1..MAX_N+1] of longint;
    adj,W:array[1..MAX_M] of longint;
    D,Pos,Heap:array[1..MAX_N] of longint;
    C:array[1..MAX_N] of int64;


{---------------------------------------------------------------------------}
procedure   Enter;
var
    fi:text;
    i,j,k:longint;
    E:array[1..MAX_M] of recE;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,M);
    for i:=1 to N+1 do head[i]:=0;
    j:=0;
    for i:=1 to M do
        begin
            inc(j);
            readln(fi,k,E[j].u,E[j].v,E[j].w);
            inc(head[E[j].u]);
            if k = 2 then
                begin
                    inc(j);
                    E[j].u:=E[j-1].v;   E[j].v:=E[j-1].u;
                    E[j].w:=E[j-1].w;
                    inc(head[E[j].u]);
                end;
        end;
    close(fi);
    for i:=2 to N+1 do head[i]:=head[i]+head[i-1];
    M:=j;
    for i:=1 to M do
        begin
            adj[head[E[i].u]]:=E[i].v;
            W[head[E[i].u]]:=E[i].w;
            dec(head[E[i].u]);
        end;
end;
{---------------------------------------------------------------------------}
procedure   Update(v:longint);
var
    child,parent:longint;
begin
    child:=Pos[v];
    if child = 0 then
        begin
            inc(HeapSize);
            child:=HeapSize;
        end;
    parent:=child div 2;
    while (parent > 0) and (D[Heap[parent]] > D[v]) do
        begin
            Heap[child]:=Heap[parent];
            Pos[Heap[child]]:=child;
            child:=parent;
            parent:=child div 2;
        end;
    Heap[child]:=v;
    Pos[v]:=child;
end;
{---------------------------------------------------------------------------}
function    Pop:longint;
var
    r,c,v:longint;
begin
    Pop:=Heap[1];
    v:=Heap[HeapSize];
    dec(HeapSize);
    r:=1;   c:=2*r;
    while c <= HeapSize do
        begin
            if (c < HeapSize) and (D[Heap[c+1]] < D[Heap[c]]) then inc(c);
            if D[v] <= D[Heap[c]] then break;
            Heap[r]:=Heap[c];
            Pos[Heap[r]]:=r;
            r:=c;
            c:=2*r;
        end;
    Heap[r]:=v;
    Pos[v]:=r;
end;
{---------------------------------------------------------------------------}
procedure   Dijkstra(S,T:longint);
var
    i,j,u,v,tmp:longint;
    avail:array[1..MAX_N] of boolean;
begin
    for i:=1 to N do
        begin
            D[i]:=MAX_W;
            C[i]:=0;
            Pos[i]:=0;
            avail[i]:=true;
        end;
    D[S]:=0;    C[S]:=1;
    HeapSize:=0;
    Update(S);
    repeat
        u:=Pop;
        if u = T then break;
        avail[u]:=false;
        for j:=head[u]+1 to head[u+1] do
            begin
                v:=adj[j];
                tmp:=D[u]+W[j];
                if avail[v] then
                    if tmp < D[v] then
                        begin
                            D[v]:=tmp;
                            Update(v);
                            C[v]:=C[u];
                        end
                    else
                        if tmp = D[v] then C[v]:=C[v]+C[u];
            end;
    until HeapSize = 0;
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,D[N],' ',C[N]);
    close(fo);
end;
{---------------------------------------------------------------------------}

begin
    Enter;
    Dijkstra(1,N);
    Print_result;
end.