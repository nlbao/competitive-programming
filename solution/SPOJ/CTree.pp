const
    INPUT = 'CTree.inp';
    OUTPUT = 'CTree.out';
    MAX_N = 10000;
    MAX_M = 2*MAX_N;
    MAX_COLOR = 4;

var
    fi,fo:text;
    N,Res:longint;
    head:array[1..MAX_N+1] of longint;
    adj:array[1..MAX_M] of longint;
    avail:array[1..MAX_N] of boolean;
    F:array[1..MAX_N,1..MAX_COLOR] of longint;
    T:array[1..MAX_N,1..MAX_COLOR,1..MAX_COLOR] of boolean;
    A:array[1..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i:longint;
    u,v:array[1..MAX_M] of longint;
begin
    read(fi,N);
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
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var
    i,j,k,v,tmp,tmp_k:longint;
begin
    avail[u]:=false;
    for i:=1 to MAX_COLOR do F[u,i]:=i;
    for i:=1 to MAX_COLOR do
        for j:=1 to MAX_COLOR do
            T[u,i,j]:=false;
    for i:=head[u]+1 to head[u+1] do
        begin
            v:=adj[i];
            if avail[v] then
                begin
                    DFS(v);
                    for j:=1 to MAX_COLOR do
                        begin
                            tmp:=MAXLONGINT;
                            for k:=1 to MAX_COLOR do
                                if (k <> j) and (F[v,k] < tmp) then
                                    begin
                                        tmp:=F[v,k];
                                        tmp_k:=k;
                                    end;
                            F[u,j]:=F[u,j]+tmp;
                            T[v,tmp_k,j]:=true;
                        end;
                end;
        end;
end;
{---------------------------------------------------------------------------}
procedure   Trace(u,c:longint);
var
    i,j,v:longint;
begin
    avail[u]:=false;
    A[u]:=c;
    for i:=head[u]+1 to head[u+1] do
        begin
            v:=adj[i];
            if avail[v] then
                for j:=1 to MAX_COLOR do
                    if T[v,j,c] = true then
                        begin
                            Trace(v,j);
                            break;
                        end;
        end;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,c:longint;
begin
    for i:=1 to N do avail[i]:=true;
    DFS(1);
    Res:=MAXLONGINT;
    for i:=1 to MAX_COLOR do
        if F[1,i] < Res then
            begin
                Res:=F[1,i];
                c:=i;
            end;
    for i:=1 to N do avail[i]:=true;
    Trace(1,c);
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    i:longint;
begin
    writeln(fo,Res);
    for i:=1 to N do
        writeln(fo,A[i]);
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