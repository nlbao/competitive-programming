const
    INPUT = 'PT07Z.inp';
    OUTPUT = 'PT07Z.out';
    MAX_N = 10000;
    MAX_M = 2*MAX_N;

type
    recE = record
        u,v:longint;
    end;

var
    fi,fo:text;
    N,M,Res:longint;
    head:array[1..MAX_N+1] of longint;
    adj:array[1..MAX_M] of longint;
    F:array[1..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i:longint;
    E:array[1..MAX_M] of recE;
begin
    readln(fi,N);
    for i:=1 to N+1 do head[i]:=0;
    M:=N-1;
    for i:=1 to M do
        begin
            read(fi,E[i].u,E[i].v);
            inc(head[E[i].u]);  inc(head[E[i].v]);
        end;
    for i:=2 to N+1 do head[i]:=head[i]+head[i-1];
    for i:=1 to M do
        begin
            adj[head[E[i].u]]:=E[i].v;  dec(head[E[i].u]);
            adj[head[E[i].v]]:=E[i].u;  dec(head[E[i].v]);
        end;
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var
    i,v:longint;
begin
    for i:=head[u]+1 to head[u+1] do
        begin
            v:=adj[i];
            if F[v] = -1 then
                begin
                    F[v]:=F[u]+1;
                    DFS(v);
                end;
        end;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,u,maxF:longint;
begin
    for i:=1 to N do F[i]:=-1;
    F[1]:=0;
    DFS(1);
    maxF:=0;    u:=1;
    for i:=1 to N do
        if F[i] > maxF then
            begin
                maxF:=F[i];
                u:=i;
            end;
    for i:=1 to N do F[i]:=-1;
    F[u]:=0;
    DFS(u);
    Res:=0;
    for i:=1 to N do
        if F[i] > Res then Res:=F[i];
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    Solve;
    writeln(fo,Res);
    close(fo);
    close(fi);
end.