const
    INPUT = '34D.inp';
    OUTPUT = '34D.out';
    MAX_N = 6*10000;
    MAX_M = 2*MAX_N;

type
    recEdge = record
        x,y:longint;
        link:longint;
    end;

var
    fi,fo:text;
    N,M,R1,R2:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head,parent:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint);
begin
    inc(M);
    with e[M] do begin
        x:=u; y:=v;
        link:=head[u];
        head[u]:=M;
    end;
    with e[-M] do begin
         x:=v; y:=u;
         link:=head[v];
         head[v]:=-M;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,u,v:longint;
begin
    readln(fi,N,R1,R2);
    M:=0;
    for i:=1 to N do head[i]:=0;
    u:=0;
    for i:=1 to N-1 do begin
        inc(u);
        if u = R1 then inc(u);
        read(fi,v);
        add_edge(u,v);
    end;
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var
    i:longint;
begin
    i:=head[u];
    while i <> 0 do
        with e[i] do begin
            if parent[y] = -1 then begin
                parent[y]:=u;
                DFS(y);
            end;
            i:=link;
        end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
begin
    for i:=1 to N do parent[i]:=-1;
    parent[R2]:=0;
    DFS(R2);
    for i:=1 to N do
        if i <> R2 then write(fo,parent[i],' ');
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