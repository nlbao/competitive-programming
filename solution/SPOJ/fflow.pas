uses    math;

const   MAX_N = 5003;
        MAX_M = 2*30004;
        oo = 2000000000;

type    ll = int64;

var fi,fo:text;
    n,m,nE,s,t:longint;
    e,link,c,f:array[-MAX_M..MAX_M] of longint;
    head,q,d,pos:array[0..MAX_N] of longint;


procedure   add_edge(u,v,cc:longint);
begin
    inc(nE);
    e[nE]:=v;
    c[nE]:=cc;  f[nE]:=0;
    link[nE]:=head[u];
    head[u]:=nE;

    e[-nE]:=u;
    c[-nE]:=0;  f[-nE]:=0;
    link[-nE]:=head[v];
    head[v]:=-nE;
end;


procedure   enter();
var i,u,v,c:longint;
begin
    nE:=0;
    read(fi,n,m);
    s:=1;   t:=n;
    for i:=1 to n do head[i]:=0;
    for i:=1 to m do begin
        read(fi,u,v,c);
        add_edge(u,v,c);
        add_edge(v,u,c);
    end;
end;

function    bfs():boolean;
var l,r,i,u,v:longint;
begin
    for i:=1 to n do d[i]:=-1;
    d[s]:=0;
    l:=1;   r:=1;
    q[1]:=s;
    repeat
        u:=q[l];    inc(l);
        i:=head[u];
        while i <> 0 do begin
            v:=e[i];
            if (d[v] = -1) and (f[i] < c[i]) then begin
                d[v]:=d[u]+1;
                if v = t then exit(true);
                inc(r); q[r]:=v;
            end;
            i:=link[i];
        end;
    until l > r;
    exit(false);
end;


function    dfs(u,flow:longint):longint;
var i,v,delta:longint;
begin
    if flow = 0 then exit(0);
    if u = t then exit(flow);
    while pos[u] <> 0 do begin
        i:=pos[u];
        v:=e[i];
        if d[v] = d[u]+1 then begin
            delta:=dfs(v,min(flow, c[i]-f[i]));
            if delta > 0 then begin
                f[i]:=f[i]+delta;
                f[-i]:=f[-i]-delta;
                exit(delta);
            end;
        end;
        pos[u]:=link[i];
    end;
    exit(0);
end;


procedure   solve();
var i:longint;
    delta,res:ll;
begin
    res:=0;
    while bfs() do begin
        for i:=1 to n do pos[i]:=head[i];
        repeat
            delta:=dfs(s,oo);
            if delta > 0 then res:=res+delta;
        until delta <= 0;
    end;
    writeln(fo,res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'FFLOW.in');   reset(fi);
    assign(fo,'FFLOW.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.
