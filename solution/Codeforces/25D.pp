const
    INPUT = '25D.inp';
    OUTPUT = '25D.out';
    MAX_N = 1010;
    MAX_M = 2*MAX_N;

type
    recEdge = record
        x,y:longint;
        avail:boolean;
        link:longint;
    end;

var
    fi,fo:text;
    N,M:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head,parent:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint);
begin
    inc(M);
    with e[M] do begin
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
            if (avail) and (parent[y] = -1) then begin
                avail:=false;
                e[-i].avail:=false;
                parent[y]:=u;
                DFS(y);
            end;
            i:=link;
        end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,top:longint;
    stack:array[0..MAX_N] of longint;
begin
    top:=-1;
    for i:=1 to N do parent[i]:=-1;
    for i:=1 to N do
        if parent[i] = -1 then begin
            inc(top);
            stack[top]:=i;
            parent[i]:=0;
            DFS(i);
        end;
    writeln(fo,top);
    for i:=1 to M do
        with e[i] do
            if avail then begin
                writeln(fo,x,' ',y,' ',1,' ',stack[top]);
                dec(top);
            end;
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