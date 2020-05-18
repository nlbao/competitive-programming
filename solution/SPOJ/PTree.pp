const
    INPUT = 'PTree.inp';
    OUTPUT = 'PTree.out';
    MAX_N = 200;
    MAX_M = 2*MAX_N;
    MAX_P = 200;
    MAX = 1000000000;

var
    fi,fo:text;
    N,P:longint;
    A:array[1..MAX_N] of longint;
    head:array[1..MAX_N+1] of longint;
    adj:array[1..MAX_M] of longint;
    F,T:array[1..MAX_N,1..MAX_P] of longint;
    avail:array[1..MAX_N] of boolean;
    parent:array[1..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i:longint;
    u,v:array[1..MAX_M] of longint;
begin
    read(fi,N,P);
    for i:=1 to N do read(fi,A[i]);
    for i:=1 to N+1 do head[i]:=0;
    for i:=1 to N-1 do
        begin
            read(fi,u[i],v[i]);
            inc(head[u[i]]);    inc(head[v[i]]);
        end;
    for i:=2 to N+1 do head[i]:=head[i]+head[i-1];
    for i:=1 to N-1 do
        begin
            adj[head[u[i]]]:=v[i];  dec(head[u[i]]);
            adj[head[v[i]]]:=u[i];  dec(head[v[i]]);
        end;
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var
    i,j,k,v:longint;
begin
    avail[u]:=false;
    for i:=1 to P do
        begin
            F[u,i]:=-MAX;
            T[u,i]:=0;
        end;
    F[u,1]:=A[u];
    for i:=head[u]+1 to head[u+1] do
        begin
            v:=adj[i];
            if avail[v] then
                begin
                    parent[v]:=u;
                    DFS(v);
                    for j:=P downto 1 do
                        for k:=1 to j-1 do
                            if F[u,k]+F[v,j-k] > F[u,j] then
                                begin
                                    F[u,j]:=F[u,k]+F[v,j-k];
                                    T[v,j]:=j-k;
                                end;
                end;
        end;
end;
{---------------------------------------------------------------------------}
procedure   Trace(u,k:longint);
var
    i,j,v:longint;
begin
    for i:=head[u+1] downto head[u]+1 do
        begin
            v:=adj[i];
            if parent[v] = u then
                if T[v,k] > 0 then
                    begin
                        Trace(v,T[v,k]);
                        k:=k-T[v,k];
                    end;
        end;
    write(fo,u,' ');
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,j:longint;
begin
    for i:=1 to N do avail[i]:=true;
    parent[1]:=-1;
    DFS(1);
    j:=1;
    for i:=2 to N do
        if F[i,P] > F[j,P] then j:=i;
    Trace(j,P);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    Solve;
    close(fo);
    close(fi);
end.