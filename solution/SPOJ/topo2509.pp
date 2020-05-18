const   MAX_N = 510;
        MAX_M = sqr(MAX_N) div 2;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,c:longint;
    head,f:array[0..MAX_N] of longint;
    e:array[0..2*MAX_M] of recEdge;
    ok:array[0..MAX_N] of boolean;

procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        link:=head[x];
        head[x]:=m;
    end;
end;

procedure   enter;
var i,j,u,v:longint;
begin
    readln(fi,n,j);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        readln(fi,u,v);
        add_edge(u,v);
    end;
end;

procedure   dfs(u:longint);
var i:longint;
begin
    ok[u]:=false;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if ok[y] then dfs(y);
        i:=link;
    end;
    f[u]:=c;
    dec(c);
end;

procedure   solve;
var i:longint;
begin
    for i:=1 to n do ok[i]:=true;
    c:=n;
    for i:=1 to n do
        if ok[i] then dfs(i);
    for i:=1 to n do writeln(fo,f[i]);
end;

begin
    assign(fi,'topo2509.in');      reset(fi);
    assign(fo,'topo2509.out');     rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.