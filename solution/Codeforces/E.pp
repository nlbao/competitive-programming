const
    INPUT = 'input.txt';
    OUTPUT = 'output.txt';
    MAX_N = 200;
    MAX_M = 2*MAX_N;

type
    recEdge = record
        x,y:longint;
        link:longint;
    end;

var
    fi,fo:text;
    nTree,N,M,res:longint;
    e:array[0..MAX_M] of recEdge;
    head,d:array[0..MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;

procedure   add_edge(u,v:longint);
begin
    inc(M);
    with e[M] do begin
        x:=u; y:=v;
        link:=head[u];
        head[u]:=M;
    end;
end;

procedure   enter;
var
    i,u,v:longint;
begin
    read(fi,N);
    M:=0;
    for i:=1 to N do head[i]:=0;
    for i:=1 to N-1 do begin
        read(fi,u,v);
        add_edge(u,v);
        add_edge(v,u);
    end;
end;

function    DFS(u:longint):longint;
var
    i,v:longint;
begin
    avail[u]:=false;
    i:=head[u];
    while i <> 0 do begin
        v:=e[i].y;
        if avail[v] then begin
            d[v]:=d[u]+1;
            DFS(v);
        end;
        i:=e[i].link;
    end;
end;

procedure   solve;
var
    i,max,u:longint;
begin
    for i:=1 to N do begin
        avail[i]:=true;
        d[i]:=0;
    end;
    DFS(1);
    max:=d[1];  u:=1;
    for i:=2 to N do
        if d[i] > max then begin
            max:=d[i];
            u:=i;
        end;

    for i:=1 to N do begin
        avail[i]:=true;
        d[i]:=0;
    end;
    DFS(u);
    max:=d[1];
    for i:=2 to N do
        if d[i] > max then max:=d[i];
    res:=res+max;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    res:=0;
    readln(fi,nTree);
    while nTree > 0 do begin
        enter;
        solve;
        dec(nTree);
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.