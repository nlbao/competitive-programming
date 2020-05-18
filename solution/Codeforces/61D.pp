const
    INPUT = '61D.inp';
    OUTPUT = '61D.out';
    MAX_N = 100010;
    MAX_M = 2*MAX_N;

type
    recEdge = record
        x,y:longint;
        w:int64;
        link:longint;
    end;

var
    fi,fo:text;
    N,M:longint;
    e:array[0..MAX_M] of recEdge;
    head:array[0..MAX_N] of longint;
    d:array[0..MAX_N] of int64;

{---------------------------------------------------------------------------}
function    max(x,y:int64):int64;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   add_edge(u,v,c:longint);
begin
    inc(M);
    with e[M] do begin
        x:=u; y:=v;
        w:=c;
        link:=head[u];
    end;
    head[u]:=M;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,u,v,c:longint;
begin
    readln(fi,N);
    M:=0;
    for i:=1 to N do head[i]:=0;
    for i:=1 to N-1 do begin
        readln(fi,u,v,c);
        add_edge(u,v,c);
        add_edge(v,u,c);
    end;
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var
    i:longint;
begin
    d[u]:=0;
    i:=head[u];
    while i <> 0 do
        with e[i] do begin
            if d[y] = -1 then begin
                DFS(y);
                d[u]:=max(d[u],d[y]+w);
            end;
            i:=link;
        end
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
    res:int64;
begin
    res:=0;
    for i:=1 to M do res:=res+e[i].w;
    for i:=1 to N do d[i]:=-1;
    DFS(1);
    writeln(fo,res-d[1]);
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