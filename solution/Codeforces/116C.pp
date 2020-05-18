const
    INPUT = '116C.inp';
    OUTPUT = '116C.out';
    MAX_N = 2001;
    MAX_M = 2*MAX_N;

var
    fi,fo:text;
    N,M:longint;
    head:array[0..MAX_N] of longint;
    adj,link:array[0..MAX_M] of longint;
    f:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint);
begin
    inc(M);
    adj[M]:=v;
    link[M]:=head[u];
    head[u]:=M;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,N);
    M:=0;
    for i:=1 to N+1 do head[i]:=0;
    for i:=1 to N do begin
        readln(fi,j);
        if j = -1 then j:=N+1;
        add_edge(j,i);
    end;
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var
    i:longint;
begin
    i:=head[u];
    while i <> 0 do begin
        DFS(adj[i]);
        f[u]:=max(f[u],f[adj[i]]);
        i:=link[i];
    end;
    inc(f[u]);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
begin
    for i:=1 to N+1 do f[i]:=0;
    DFS(N+1);
    writeln(fo,f[N+1]-1);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
