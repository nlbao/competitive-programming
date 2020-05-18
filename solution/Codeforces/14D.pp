const
    INPUT = '14D.inp';
    OUTPUT = '14D.out';
    MAX_N = 300;
    MAX_M = 2*MAX_N;

type
    recEdge = record
        x,y:longint;
        link:longint;
        avail:boolean;
    end;

var
    fi,fo:text;
    N,M:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head:array[0..MAX_N] of longint;
    d:array[0..MAX_N] of longint;
    free:array[0..MAX_N] of boolean;

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
    with  e[M] do begin
        x:=u;   y:=v;
        avail:=true;
        link:=head[u];
        head[u]:=M;
    end;
    with e[-M] do begin
        x:=v;   y:=u;
        avail:=true;
        link:=head[v];
        head[v]:=-M;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,u,v:longint;
begin
    readln(fi,N);
    M:=0;
    for i:=1 to N do head[i]:=0;
    for i:=1 to N-1 do begin
        readln(fi,u,v);
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
            if (avail) and (d[y] = -1) then begin
                d[y]:=d[u]+1;
                DFS(y);
            end;
            i:=link;
        end;
end;
{---------------------------------------------------------------------------}
function    longest_path(u:longint):longint;
var
    i:longint;
begin
    for i:=0 to N do d[i]:=-1;
    d[u]:=0;
    DFS(u);
    for i:=1 to N do
        if d[i] > d[0] then begin
            d[0]:=d[i];
            u:=i;
        end;
    for i:=0 to N do d[i]:=-1;
    d[u]:=0;
    DFS(u);
    for i:=1 to N do d[0]:=max(d[0],d[i]);
    exit(d[0]);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,res:longint;
begin
    res:=0;
    for i:=1 to M do begin
        e[i].avail:=false;
        e[-i].avail:=false;
        res:=max(res,longest_path(e[i].x)*longest_path(e[i].y));
        e[-i].avail:=true;
        e[i].avail:=true;
    end;
    writeln(fo,res);
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