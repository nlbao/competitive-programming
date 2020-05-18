uses    math;

const   MAX_A = 260;
        MAX_N = 4*MAX_A;
        MAX_M = 2*sqr(MAX_A)+3*MAX_A;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            c,f:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nA,nE,s,t:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    id:array[0..4,0..MAX_A] of longint;
    head,q,d,pos:array[0..MAX_N] of longint;


procedure   add_edge(u,v,cc:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        c:=cc;  f:=0;
        link:=head[x];
        head[x]:=nE;
    end;
    with e[-nE] do begin
        x:=v;   y:=u;
        c:=0;   f:=0;
        link:=head[x];
        head[x]:=-nE;
    end;
end;

procedure   push(var x:longint);    begin   inc(n); x:=n;   end;

procedure   enter();
var i,j:longint;
begin
    readln(fi,nA,m);
    n:=2;   nE:=0;
    s:=1;   t:=2;
    for i:=1 to nA do push(id[1][i]);
    for i:=1 to m do push(id[2][i]);
    for i:=1 to m do push(id[3][i]);
    for i:=1 to nA do push(id[4][i]);
    for i:=1 to n do head[i]:=0;

    for i:=1 to m do add_edge(id[2][i],id[3][i],1);

    for i:=1 to nA do begin
        add_edge(s,id[1][i],1);
        while not eoln(fi) do begin
            read(fi,j);
            add_edge(id[1][i],id[2][j],1);
        end;
        readln(fi);
    end;

    for i:=1 to nA do begin
        add_edge(id[4][i],t,1);
        while not eoln(fi) do begin
            read(fi,j);
            add_edge(id[3][j],id[4][i],1);
        end;
        readln(fi);
    end;
end;


function    bfs():boolean;
var l,r,i,u:longint;
begin
    for i:=1 to n do d[i]:=-1;
    d[s]:=0;
    l:=1;   r:=1;
    q[1]:=s;
    repeat
        u:=q[l];    inc(l);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if (d[y] = -1) and (f < c) then begin
                d[y]:=d[u]+1;
                inc(r); q[r]:=y;
            end;
            i:=link;
        end;
    until l > r;
    exit(d[t] <> -1);
end;


function    dfs(u,flow:longint):longint;
var delta:longint;
begin
    if flow = 0 then exit(0);
    if u = t then exit(flow);
    while pos[u] <> 0 do with e[pos[u]] do begin
        if d[y] = d[u]+1 then begin
            delta:=dfs(y,min(flow,c-f));
            if delta > 0 then begin
                f:=f+delta;
                with e[-pos[u]] do f:=f-delta;
                exit(delta);
            end;
        end;
        pos[u]:=link;
    end;
    exit(0);
end;


procedure   solve();
var i,res,delta:longint;
    a,b:array[0..MAX_A] of longint;
begin
    res:=0;
    while bfs() do begin
        for i:=1 to n do pos[i]:=head[i];
        repeat
            delta:=dfs(s,oo);
            res:=res+delta;
        until delta = 0;
    end;

    if res <> nA then begin
        writeln(fo,-1);
        exit;
    end;
    for i:=1 to m do begin
        a[i]:=0;
        b[i]:=0;
    end;

    for i:=1 to nE do with e[i] do
        if (x <> s) and (y <> t) and (f > 0) then
            if x < id[2][1] then a[y-2-nA]:=x-2
            else if (id[3][1] <= x) and (x <= id[3][m]) then
                b[x-2-nA-m]:=y-2-nA-m-m;
    for i:=1 to m do writeln(fo,a[i],' ',b[i]);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'FLOW1.in');   reset(fi);
    assign(fo,'FLOW1.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.

