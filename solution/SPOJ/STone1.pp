const
    INPUT = 'STone1.inp';
    OUTPUT = 'STone1.out';
    MAX_N = 400;
    MAX_M = 2*MAX_N;

type
    arr = array[1..MAX_N] of longint;

var
    fi,fo:text;
    N:longint;
    c,head:array[1..MAX_N+1] of longint;
    adj:array[1..MAX_M] of longint;
    F:arr;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i,j,M:longint;
    u,v:array[1..MAX_N] of longint;
begin
    read(fi,N);
    for i:=1 to N+1 do begin
        head[i]:=0;
        c[i]:=0;
    end;
    M:=0;
    while not eof(fi) do begin
        read(fi,i,c[i]);
        for j:=1 to c[i] do begin
            inc(M);
            u[M]:=i;    read(fi,v[M]);
            inc(head[i]);
        end;
        readln(fi);
    end;
    for i:=2 to N+1 do head[i]:=head[i]+head[i-1];
    for i:=1 to M do begin
        adj[head[u[i]]]:=v[i];
        dec(head[u[i]]);
    end;
end;
{---------------------------------------------------------------------------}
procedure   QuickSort(var X:arr;    l,r:longint);
var
    i,j,p,tmp:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=X[(i+j) div 2];
    repeat
        while X[i] > p do i:=i+1;
        while X[j] < p do j:=j-1;
        if i <= j then
            begin
                tmp:=X[i];  X[i]:=X[j]; X[j]:=tmp;
                i:=i+1; j:=j-1;
            end;
    until i >= j;
    QuickSort(X,l,j); QuickSort(X,i,r);
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var
    i,v:longint;
    tmp:array[1..MAX_N] of longint;
begin
    F[u]:=1;
    for i:=head[u]+1 to head[u+1] do
        begin
            v:=adj[i];
            DFS(v);
            tmp[i-head[u]]:=F[v];
        end;
    QuickSort(tmp,1,c[u]);
    for i:=1 to c[u] do
        if tmp[i]+i-1 > F[u] then
            F[u]:=tmp[i]+i-1;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
begin
    DFS(1);
    writeln(fo,F[1]);
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