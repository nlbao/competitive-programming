const
    INPUT = 'V8ORG.inp';
    OUTPUT = 'V8ORG.out';
    MAX_N = 10000;
    MAX_M = 10000;
    MAX_K = 10000;

var
    fi,fo:text;
    N,K,QSize,Res:longint;
    head:array[1..MAX_N+1] of longint;
    adj:array[1..MAX_M] of longint;
    parent,Q,nChildren:array[1..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i:longint;
begin
    read(fi,K); read(fi,N);
    for i:=1 to N+1 do head[i]:=0;
    parent[1]:=1;
    for i:=2 to N do
        begin
            read(fi,parent[i]);
            inc(head[parent[i]]);
        end;
    for i:=2 to N+1 do head[i]:=head[i]+head[i-1];
    for i:=2 to N do
        begin
            adj[head[parent[i]]]:=i;
            dec(head[parent[i]]);
        end;
end;
{---------------------------------------------------------------------------}
procedure   BFS(u:longint);
var
    i,j:longint;
begin
    QSize:=1;
    Q[1]:=u;
    i:=0;
    repeat
        i:=i+1;
        u:=Q[i];
        for j:=head[u]+1 to head[u+1] do
            begin
                QSize:=QSize+1;
                Q[QSize]:=adj[j];
            end;
    until QSize = i;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,u:longint;
begin
    BFS(1);
    for u:=1 to N do nChildren[u]:=1;
    Res:=0;
    for i:=QSize downto 1 do
        begin
            u:=Q[i];
            if nChildren[u] >= K then
                begin
                    nChildren[u]:=0;
                    inc(Res);
                end;
            inc(nChildren[parent[u]],nChildren[u]);
        end;
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