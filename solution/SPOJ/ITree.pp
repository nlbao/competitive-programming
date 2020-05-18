const
    INPUT = 'ITree.inp';
    OUTPUT = 'ITree.out';
    MAX_N = 1000;
    MAX_M = 2*MAX_N;

type
    recE = record
        u,v:longint;
        w:double;
    end;

var
    fi,fo:text;
    T,N,i:longint;
    head:array[1..MAX_N+1] of longint;
    adj:array[1..MAX_M] of longint;
    adjW:array[1..MAX_M] of double;
    F:array[1..MAX_N,0..1] of double;

procedure   Enter;
var
    i:longint;
    E:array[1..MAX_M] of recE;
begin
    readln(fi,N);
    for i:=1 to N+1 do head[i]:=0;
    for i:=2 to N do
        begin
            E[i].v:=i;
            readln(fi,E[i].u,E[i].w);
            inc(head[E[i].u]);
        end;
    for i:=2 to N+1 do head[i]:=head[i]+head[i-1];
    for i:=2 to N do
        begin
            adj[head[E[i].u]]:=E[i].v;
            adjW[head[E[i].u]]:=E[i].w;
            dec(head[E[i].u]);
        end;
end;

function    min(x,y:double):double;
begin
    if x < y then exit(x)
    else exit(y);
end;

procedure   DFS(u:longint);
var
    i,v:longint;
begin
    F[u,0]:=0;
    if head[u]+1 <= head[u+1] then F[u,1]:=0
    else F[u,1]:=MAXLONGINT;
    for i:=head[u]+1 to head[u+1] do
        begin
            v:=adj[i];
            DFS(v);
            F[u,0]:=F[u,0]+F[v,0];
            F[u,1]:=F[u,1]+min(F[v,1],F[v,0]+adjW[i]);
        end;
end;

procedure   Solve;
begin
    DFS(1);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    read(fi,T);
    for i:=1 to T do
        begin
            Enter;
            Solve;
            writeln(fo,F[1,1]:0:2);
        end;
    close(fo);
    close(fi);
end.