const
    INPUT = 'PWalk.inp';
    OUTPUT = 'PWalk.out';
    MAX_N = 1000;
    MAX_M = 2*MAX_N;
    MAX_Q = 1000;

type
    recE = record
        u,v,w:longint;
    end;

var
    fi,fo:text;
    N,Q,Res:longint;
    head:array[1..MAX_N+1] of longint;
    adj,W:array[1..MAX_M] of longint;
    cha,F:array[1..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i,M:longint;
    E:array[1..MAX_M] of recE;
begin
    readln(fi,N,Q);
    M:=N-1;
    for i:=1 to N+1 do head[i]:=0;
    for i:=1 to M do
        begin
            readln(fi,E[i].u,E[i].v,E[i].w);
            inc(head[E[i].u]);  inc(head[E[i].v]);
        end;
    for i:=2 to N+1 do head[i]:=head[i]+head[i-1];
    for i:=1 to M do
        begin
            adj[head[E[i].u]]:=E[i].v;
            W[head[E[i].u]]:=E[i].w;
            dec(head[E[i].u]);
            adj[head[E[i].v]]:=E[i].u;
            W[head[E[i].v]]:=E[i].w;
            dec(head[E[i].v]);
        end;
end;
{---------------------------------------------------------------------------}
procedure   Init;
var
    i,j,u,v,QSize:longint;
    Q:array[1..MAX_N] of longint;
    avail:array[1..MAX_N] of boolean;
begin
    for i:=1 to N do
        begin
            cha[i]:=0;
            F[i]:=0;
            avail[i]:=true;
        end;
    QSize:=1;
    Q[1]:=1;
    avail[1]:=false;
    i:=0;
    repeat
        inc(i);
        u:=Q[i];
        for j:=head[u]+1 to head[u+1] do
            begin
                v:=adj[j];
                if avail[v] then
                    begin
                        cha[v]:=u;
                        F[v]:=W[j];
                        inc(QSize);
                        Q[QSize]:=v;
                        avail[v]:=false;
                    end;
            end;
    until QSize = i;
end;
{---------------------------------------------------------------------------}
procedure   Find(S,T:longint);
var
    i:longint;
    avail:array[1..MAX_N] of boolean;
    d:array[1..MAX_N] of longint;
begin
    for i:=1 to N do avail[i]:=true;
    avail[S]:=false;
    d[S]:=0;
    while cha[S] <> 0 do
        begin
            d[cha[S]]:=d[S]+F[S];
            S:=cha[S];
            avail[S]:=false;
        end;
    Res:=0;
    while avail[T] do
        begin
            Res:=Res+F[T];
            T:=cha[T];
        end;
    Res:=Res+d[T];
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    i,p1,p2:longint;
begin
    for i:=1 to Q do
        begin
            readln(fi,p1,p2);
            Find(p1,p2);
            writeln(fo,Res);
        end;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    Init;
    Print_result;
    close(fo);
    close(fi);
end.