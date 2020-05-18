const
    INPUT = 'KTreeC.inp';
    OUTPUT = 'KTreeC.out';
    MAX_N = 10000;
    MAX_M = 10000;
    MAX_C = 1000;
    MAX = MAX_N+1;

type
    recQ = record
        x,y:longint;
    end;

var
    fi,fo:text;
    N,M,nC:longint;
    head:array[1..MAX_N+1] of longint;
    adj:array[1..2*MAX_N] of longint;
    Q:array[1..MAX_M] of recQ;
    avail:array[1..MAX_N] of boolean;
    C,parent:array[1..MAX_N] of longint;
    d:array[1..MAX_N,1..MAX_C] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i:longint;
    u,v:array[1..MAX_N-1] of longint;
begin
    read(fi,N);
    for i:=1 to N+1 do head[i]:=0;
    for i:=1 to N-1 do begin
        read(fi,u[i],v[i]);
        inc(head[u[i]]);    inc(head[v[i]]);
    end;
    for i:=2 to N+1 do head[i]:=head[i]+head[i-1];
    read(fi,nC);
    for i:=1 to N do read(fi,C[i]);
    read(fi,M);
    for i:=1 to M do read(fi,Q[i].x,Q[i].y);
    for i:=1 to N-1 do begin
        adj[head[u[i]]]:=v[i];  adj[head[v[i]]]:=u[i];
        dec(head[u[i]]);    dec(head[v[i]]);
    end;
end;
{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var
    i,j,v:longint;
begin
    avail[u]:=false;
    for i:=1 to nC do d[u,i]:=min(d[u,i],d[parent[u],i]+1);
    for i:=head[u]+1 to head[u+1] do begin
        v:=adj[i];
        if avail[v] then begin
            parent[v]:=u;
            DFS(v);
            for j:=1 to nC do
                d[u,j]:=min(d[u,j],d[v,j]+1);
        end;
    end;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,j:longint;
begin
    for i:=1 to N do begin
        avail[i]:=true;
        parent[i]:=i;
    end;
    for i:=1 to N do
        for j:=1 to nC do
            if C[i] = j then d[i,j]:=0
            else d[i,j]:=MAX;
    DFS(1);
    for i:=1 to N do avail[i]:=true;
    DFS(1);
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    i:longint;
begin
    for i:=1 to M do
        writeln(fo,d[Q[i].x,Q[i].y]);
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
