const   MAX_N = 100010;
        MAX_M = 100010;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    nTest,n,m:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,h:array[0..MAX_N] of longint;
    p:array[0..MAX_N] of longint;

procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        link:=head[x];
        head[x]:=m;
    end;
end;

procedure   enter();
var i,j,u,v:longint;
begin
    readln(fi,n,j);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        read(fi,u,v);
        add_edge(u,v);
        add_edge(v,u);
    end;

end;

function    dfs(u:longint):longint;
var i:longint;
begin
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if p[y] = 0 then begin
            p[y]:=u;
            h[y]:=h[u]+1;
            if dfs(y) = 0 then exit(0);
        end
        else
            if (h[u]-h[y]+1) mod 2 = 1 then exit(0);
        i:=link;
    end;
    exit(1);
end;

function    solve():longint;
var i:longint;
begin
    for i:=1 to n do p[i]:=0;
    for i:=1 to n do
        if p[i] = 0 then begin
            p[i]:=-1;
            h[i]:=1;
            if dfs(i) = 0 then exit(0);
        end;
    exit(1);
end;

begin
    assign(fi,'VMRelate.in');   reset(fi);
    assign(fo,'VMRelate.out');  rewrite(fo);
    read(fi,nTest);
    while nTest > 0 do begin
        enter();
        writeln(fo,solve());
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
