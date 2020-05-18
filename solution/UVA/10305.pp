const   MAX_N = 110;
        MAX_M = sqr(MAX_N) div 2;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,count:longint;
    head,f:array[0..MAX_N] of longint;
    e:array[0..MAX_M] of recEdge;
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
    readln(fi,j);
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
    f[count]:=u;
    dec(count);
end;

procedure   solve;
var i:longint;
begin
    count:=n;
    for i:=1 to n do ok[i]:=true;
    for i:=1 to n do
        if ok[i] then dfs(i);
    for i:=1 to n-1 do write(fo,f[i],' ');
    writeln(fo,f[n]);
end;


begin
    assign(fi,'10305.in');  reset(fi);
    assign(fo,'10305.out'); rewrite(fo);
    read(fi,n);
    while n > 0 do begin
        enter;
        solve;
        read(fi,n);
    end;
    close(fo);
    close(fi);
end.

