const
    INPUT = '3A.inp';
    OUTPUT = '3A.out';
    MAX_N = 100;
    MAX_M = 2*sqr(MAX_N);
    MAX_INT = 10*MAX_M;

type
    recEdge = record
        x,y:longint;
        info:string;
        link:longint;
    end;

var
    fi,fo:text;
    N,M,S,T:longint;
    id:array[0..9,0..9] of longint;
    e:array[0..MAX_M] of recEdge;
    head:array[0..MAX_N] of longint;
    d,trace:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint;   s:string);
begin
    if (u < 1) or (v < 1) then exit;
    inc(M);
    with e[M] do begin
        x:=u; y:=v;
        info:=s;
        link:=head[u];
    end;
    head[u]:=M;
end;
{---------------------------------------------------------------------------}
procedure   create_graph;
var
    i,j:longint;
begin
    N:=0;
    for i:=0 to 9 do
        for j:=0 to 9 do
            id[i,j]:=-1;
    for i:=1 to 8 do
        for j:=1 to 8 do begin
            inc(N);
            id[i,j]:=N;
        end;
    M:=0;
    for i:=1 to N do head[i]:=0;
    for i:=1 to 8 do
        for j:=1 to 8 do begin
            add_edge(id[i,j],id[i-1,j],'D');
            add_edge(id[i,j],id[i+1,j],'U');
            add_edge(id[i,j],id[i,j-1],'L');
            add_edge(id[i,j],id[i,j+1],'R');
            add_edge(id[i,j],id[i-1,j-1],'LD');
            add_edge(id[i,j],id[i-1,j+1],'RD');
            add_edge(id[i,j],id[i+1,j-1],'LU');
            add_edge(id[i,j],id[i+1,j+1],'RU');
        end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    tmp:string;
begin
    readln(fi,tmp);
    S:=id[ord(tmp[2])-ord('0'),ord(tmp[1])-ord('a')+1];
    readln(fi,tmp);
    T:=id[ord(tmp[2])-ord('0'),ord(tmp[1])-ord('a')+1];
end;
{---------------------------------------------------------------------------}
procedure   Dijkstra(S,T:longint);
var
    i,u,v,tmp:longint;
    avail:array[0..MAX_N] of boolean;
begin
    for i:=1 to N do begin
        d[i]:=MAX_INT;
        trace[i]:=0;
        avail[i]:=true;
    end;
    d[S]:=0;
    repeat
        tmp:=MAX_INT;
        for i:=1 to N do
            if (avail[i]) and (d[i] < tmp) then begin
                tmp:=d[i];
                u:=i;
            end;
        if tmp = MAX_INT then exit;
        avail[u]:=false;
        i:=head[u];
        while i <> 0 do begin
            v:=e[i].y;
            if (avail[v]) and (d[u]+1 < d[v]) then begin
                d[v]:=d[u]+1;
                trace[v]:=i;
            end;
            i:=e[i].link;
        end;
    until u = T;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j:longint;
    res:array[0..MAX_M] of longint;
begin
    Dijkstra(S,T);
    if d[T] = MAX_INT then begin
        writeln(fo,-1);
        exit;
    end;
    j:=trace[T];
    for i:=d[T] downto 1 do begin
        res[i]:=j;
        j:=trace[e[j].x];
    end;
    writeln(fo,d[T]);
    for i:=1 to d[T] do
        writeln(fo,e[res[i]].info);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    create_graph;
    enter;
    solve;
    close(fo);
    close(fi);
end.
