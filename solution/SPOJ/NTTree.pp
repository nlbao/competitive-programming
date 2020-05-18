const
    INPUT = 'NTTree.inp';
    OUTPUT = 'NTTree.out';
    MAX_N = 10010;
    MAX_M = 2*MAX_N;

type
    recEdge = record
        x,y:longint;
        w:int64;
    end;

var
    fi,fo:text;
    N,M:int64;
    e:array[0..MAX_M] of recEdge;
    link:array[0..MAX_M] of longint;
    head:array[0..MAX_N] of longint;
    c:array[0..MAX_N] of int64;
    avail:array[0..MAX_N] of boolean;
    res:int64;

{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint;   weight:int64);  inline;
begin
    inc(M);
    with e[M] do begin
        x:=u; y:=v;
        w:=weight;
    end;
    link[M]:=head[u];
    head[u]:=M;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,u,v:longint;
    w:int64;
begin
    readln(fi,N);
    M:=0;
    for i:=0 to N-1 do head[i]:=0;
    for i:=1 to N-1 do begin
        readln(fi,u,v,w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    end;
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var
    i,v:longint;
begin
    avail[u]:=false;
    c[u]:=1;
    i:=head[u];
    while i <> 0 do begin
        v:=e[i].y;
        if avail[v] then begin
            DFS(v);
            res:=res+c[v]*(N-c[v])*e[i].w;
            c[u]:=c[u]+c[v];
        end;
        i:=link[i];
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
begin
    res:=0;
    for i:=0 to N-1 do avail[i]:=true;
    DFS(0);
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