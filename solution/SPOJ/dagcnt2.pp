const   MAX_N = 20010;
        MAX_M = 500010;

type    int = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    nTest,n,m:longint;
    e:array[0..MAX_M] of recEdge;
    head,degI,p:array[0..MAX_N] of longint;
    w,f:array[0..MAX_N] of int;

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
    for i:=1 to n do begin
        head[i]:=0;
        degI[i]:=0;
        read(fi,w[i]);
    end;
    for i:=1 to j do begin
        readln(fi,u,v);
        if u = v then continue;
        add_edge(u,v);
        inc(degI[v]);
    end;
end;

procedure   dfs(u:longint);
var i:longint;
begin
    f[u]:=w[u];
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if p[y] = -1 then begin
            p[y]:=u;
            dfs(y);
            f[u]:=f[u]+f[y];
        end;
        i:=link;
    end;
end;

procedure   solve;
var i:longint;
begin
    for i:=1 to n do p[i]:=-1;
    for i:=1 to n do
        if degI[i] = 0 then dfs(i);
    for i:=1 to n do write(fo,f[i],' ');
    writeln(fo);
end;

begin
    assign(fi,'dagcnt2.in');    reset(fi);
    assign(fo,'dagcnt2.out');   rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.