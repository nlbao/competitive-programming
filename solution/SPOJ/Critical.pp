uses    math;

const   MAX_N = 20010;
        MAX_M = 200010;

type    int = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,count:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,p,q,d,g,num,low,f:array[0..MAX_N] of longint;
    res:int;

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
        add_edge(v,u);
    end;
end;

procedure   bfs(u:longint);
var l,r,i:longint;
begin
    l:=1;   r:=1;
    q[1]:=u;    p[u]:=1;
    repeat
        u:=q[l];    inc(l);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if p[y] = 0 then begin
                p[y]:=1;
                inc(r); q[r]:=y;
            end;
            i:=link;
        end;
    until l > r;
    for i:=1 to r do g[q[i]]:=r;
end;

procedure   dfs(u:longint);
var i:longint;
    s,t:int;
begin
    inc(count);
    num[u]:=count;  low[u]:=count;
    f[u]:=1;
    s:=0;   t:=0;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if (y <> p[u]) then
            if (num[y] = 0) then begin
                p[y]:=u;
                dfs(y);
                f[u]:=f[u]+f[y];
                if low[y] >= num[u] then s:=s+f[y];
                low[u]:=min(low[u],low[y]);
            end
            else low[u]:=min(low[u],num[y]);
        i:=link;
    end;
    i:=head[u];
    while (i <> 0) do with e[i] do begin
        if (p[y] = u) and (low[y] >= num[u]) then
            t:=t+f[y]*(s-f[y]);
        i:=link;
    end;
    res:=res+s*(g[u]-s-1)+(t div 2);
end;

procedure   solve;
var i:longint;
    t1,t2:double;
begin
    res:=0;
    fillchar(p,sizeof(p),0);
    for i:=1 to n do
        if p[i] = 0 then bfs(i);
    fillchar(p,sizeof(p),0);
    fillchar(num,sizeof(num),0);
    for i:=1 to n do
        if p[i] = 0 then begin
            count:=0;
            dfs(i);
        end;
    t1:=res;    t2:=n;
    writeln(fo,t1/t2:0:2);
end;

begin
    assign(fi,'Critical.in');   reset(fi);
    assign(fo,'Critical.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
