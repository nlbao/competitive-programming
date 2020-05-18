{$N+}
const
    INPUT = 'Stable.inp';
    OUTPUT = 'Stable.out';
    MAX_N = 10000;
    MAX_M = 50000;

type
    recE = record
        u,v:longint;
    end;

var
    N,M,S,Res:longint;
    head:array[1..MAX_N+1] of longint;
    adj:array[1..MAX_M] of longint;
    lap:array[1..MAX_M] of boolean;
    C:array[1..MAX_N] of extended;

{**************************************************************************}
procedure   Enter;
var
    fi:text;
    i,j:longint;
    E:array[1..MAX_M] of recE;
    R:array[1..MAX_N] of boolean;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,N,M,S);
    for i:=1 to N+1 do head[i]:=0;
    for i:=1 to M do
        begin
            read(fi,E[i].u,E[i].v);
            inc(head[E[i].u]);
        end;
    for i:=2 to N+1 do head[i]:=head[i]+head[i-1];
    for i:=1 to M do
        begin
            adj[head[E[i].u]]:=E[i].v;
            dec(head[E[i].u]);
            lap[i]:=false;
        end;
    for i:=1 to N do
        begin
            for j:=1 to N do R[j]:=false;
            for j:=head[i]+1 to head[i+1] do
                if R[adj[j]] = false then R[adj[j]]:=true
                else
                    lap[j]:=true;
        end;
    close(fi);
end;
{**************************************************************************}
procedure   Find;
var
    i,j,u,v,QSize,tmp:longint;
    Q,D,T:array[1..MAX_N] of longint;
    avail:array[1..MAX_N] of boolean;
begin
    for i:=1 to N do
        begin
            avail[i]:=true;
            D[i]:=MAXLONGINT;
            C[i]:=0;
        end;
    C[S]:=1;
    D[S]:=0;
    QSize:=1;
    Q[1]:=S;
    T[1]:=1;
    avail[S]:=false;
    i:=0;
    repeat
        inc(i);
        u:=Q[i];
        for j:=head[u]+1 to head[u+1] do
            if not lap[j] then
                begin
                    v:=adj[j];
                    tmp:=T[i]+1;
                    if tmp <= D[v] then
                        begin
                            D[v]:=tmp;
                            C[v]:=C[u]+C[v];
                        end;
                    if avail[v] then
                        begin
                            inc(QSize);
                            Q[QSize]:=v;
                            T[QSize]:=tmp;
                            avail[v]:=false;
                        end;
                end;
    until QSize = i;
    C[S]:=0;
    Res:=0;
    for i:=1 to N do
        if C[i] >= 2 then inc(Res);
end;
{**************************************************************************}
procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,Res);
    close(fo);
end;
{**************************************************************************}

begin
    Enter;
    Find;
    Print_result;
end.
