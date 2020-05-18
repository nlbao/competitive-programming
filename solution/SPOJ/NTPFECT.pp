const
    INPUT = 'NTPFECT.inp';
    OUTPUT = 'NTPFECT.out';
    MAX_N = 1001;
    MAX_M = 2*MAX_N;
    MAX_INT = 1000000000;

type
    recEdge = record
        x,y:longint;
        next:longint;
    end;

var
    fi,fo:text;
    N,M:longint;
    e:array[0..MAX_M] of recEdge;
    head,parent,min_f12:array[0..MAX_N] of longint;
    f:array[0..MAX_N,0..2] of longint;

{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint);  inline;
begin
    inc(M);
    with e[M] do begin
        x:=u; y:=v;
        next:=head[u];
        head[u]:=M;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,u,v:longint;
begin
    M:=0;
    for i:=1 to N do head[i]:=0;
    for i:=1 to N-1 do begin
        readln(fi,u,v);
        add_edge(u,v);
        add_edge(v,u);
    end;
end;
{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;   inline;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var
    i:longint;
begin
{f[u,0] f[u,1]}
    f[u,0]:=0;  f[u,2]:=1;
    i:=head[u];
    while i <> 0 do
        with e[i] do begin
            if parent[y] = -1 then begin
                parent[y]:=u;
                DFS(y);
                inc(f[u,0],min_f12[y]);
                inc(f[u,2],min(f[y,0],min_f12[y]));
            end;
            i:=next;
        end;
{f[u,1]}
    f[u,1]:=MAX_INT;
    i:=head[u];
    while i <> 0 do
        with e[i] do begin
            if parent[y] = u then
                f[u,1]:=min(f[u,1],f[u,0]-min_f12[y]+f[y,2]);
            i:=next;
        end;
    min_f12[u]:=min(f[u,1],f[u,2]);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
begin
    for i:=2 to N do parent[i]:=-1;
    parent[1]:=0;
    DFS(1);
    writeln(fo,min_f12[1]);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    repeat
        readln(fi,N);
        if N = 0 then break;
        enter;
        solve;
    until N = 0;
    close(fo);
    close(fi);
end.