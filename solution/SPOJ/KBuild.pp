const
    INPUT = 'KBuild.inp';
    OUTPUT = 'KBuild.out';
    MAX_N = 200000;
    MAX_M = 200000;
    MAX_E = 2*(MAX_M+MAX_N);

type
    recE = record
        u,v:longint;
    end;

var
    fi,fo:text;
    N,M,count,nBridges:longint;
    head:array[1..MAX_N+1] of longint;
    adj:array[1..MAX_E] of longint;
    number,low,parent:array[1..MAX_N] of longint;
    avail:array[1..MAX_N] of boolean;

procedure   Enter;
var
    i,j:longint;
    E:array[1..MAX_E] of recE;
begin
    read(fi,N);
    j:=N-1;
    for i:=1 to j do read(fi,E[i].u,E[i].v);
    read(fi,M);
    for i:=1 to M do
        begin
            inc(j);
            read(fi,E[j].u,E[j].v);
        end;
    for i:=1 to N+1 do head[i]:=0;
    for i:=1 to j do
        begin
            inc(head[E[i].u]);
            inc(head[E[i].v]);
        end;
    for i:=2 to N+1 do head[i]:=head[i]+head[i-1];
    for i:=1 to j do
        begin
            adj[head[E[i].u]]:=E[i].v;  dec(head[E[i].u]);
            adj[head[E[i].v]]:=E[i].u;  dec(head[E[i].v]);
        end;
end;

function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;

procedure   DFSVisit(u:longint);
var
    i,v:longint;
begin
    inc(count);
    number[u]:=count;   low[u]:=MAXLONGINT;
    for i:=head[u]+1 to head[u+1] do
        begin
            v:=adj[i];
            if avail[v] then
                if number[v] = -1 then
                    begin
                        parent[v]:=u;
                        DFSVisit(v);
                        low[u]:=min(low[u],low[v]);
                    end
                else
                    if parent[u] <> v then
                        low[u]:=min(low[u],number[v]);
        end;
    avail[u]:=false;
end;

procedure   Solve;
var
    i:longint;
begin
    count:=0;
    for i:=1 to N do
        begin
            avail[i]:=true;
            parent[i]:=-1;
            number[i]:=-1;
        end;
    for i:=1 to N do
        if avail[i] then
            DFSVisit(i);
    nBridges:=0;
    for i:=1 to N do
        if (parent[i] <> -1) and (low[i] >= number[i]) then
            inc(nBridges);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    Solve;
    writeln(fo,nBridges);
    close(fo);
    close(fi);
end.