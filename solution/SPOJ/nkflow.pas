uses    math;

const   MAX_N = 1003;
        MAX_M = 100010;
        oo = 2000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            c,f:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nE,s,t:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
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


procedure   enter();
var i,u,v,c:longint;
begin
    nE:=0;
    read(fi,n,m,s,t);
    for i:=1 to n do head[i]:=0;
    for i:=1 to m do begin
        read(fi,u,v,c);
        add_edge(u,v,c);
        add_edge(v,u,c);
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
            delta:=dfs(y,min(flow, c-f));
            if delta <> 0 then begin
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
var i,delta,res:longint;
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
    assign(fi,'NKFLOW.in');   reset(fi);
    assign(fo,'NKFLOW.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.
