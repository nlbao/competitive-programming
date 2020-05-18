{$M+ 16777216}
uses    math;

const   MAX_N = 1003;
        MAX_M = 100010;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            c,f:longint;
            link:longint;
        end;

var fi,fo:text;
    nTest,test_id,n,m,nE,s,t,maxW:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head,pos,q,d:array[0..MAX_N] of longint;


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
    maxW:=0;
    read(fi,n,m,s,t);
    inc(s); inc(t);
    nE:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to m do begin
        read(fi,u,v,c);
        inc(u); inc(v);
        add_edge(u,v,c);
        maxW:=max(maxW,c);
    end;
end;

function    find_path():boolean;
var i,l,r,u:longint;
begin
    for i:=1 to n do d[i]:=-1;
    d[s]:=0;
    l:=1;   r:=1;
    q[1]:=s;
    while l <= r do begin
        u:=q[l]; inc(l);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if (d[y] = -1) and (f < c) then begin
                d[y]:=d[u]+1;
                if y = t then exit(true);
                inc(r); q[r]:=y;
            end;
            i:=link;
        end;
    end;
    exit(false);
end;


function    incflow(u,flow:longint):longint;
var delta:longint;
begin
    if u = t then exit(flow);
    if flow = 0 then exit(0);
    while pos[u] <> 0 do with e[pos[u]] do begin
        if d[y] = d[u]+1 then begin
            delta:=incflow(y,min(flow,c-f));
            if delta > 0 then begin
                with e[pos[u]] do f:=f+delta;
                with e[-pos[u]] do f:=f-delta;
                exit(delta);
            end;
        end;
        pos[u]:=link;
    end;
    exit(0);
end;


function    bfs(limit:longint):boolean;
var l,r,u,i:longint;
begin
    for i:=1 to n do d[i]:=-1;
    d[s]:=0;
    l:=1;   r:=1;
    q[1]:=s;
    while l <= r do begin
        u:=q[l]; inc(l);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if (i > 0) and (d[y] = -1) and (c >= limit) then begin
                if y = t then exit(true);
                d[y]:=d[u]+1;
                inc(r); q[r]:=y;
            end;
            i:=link;
        end;
    end;
    exit(false);
end;


function    solve():double;
var i,flow,delta:longint;
    l,r,mid:longint;
begin
    flow:=0;
    while find_path() do begin
        for i:=1 to n do pos[i]:=head[i];
        repeat
            delta:=incflow(s,oo);
            flow:=flow+delta;
        until delta = 0;
    end;

    delta:=0;
    l:=1;   r:=maxW;
    while l <= r do begin
        mid:=(l+r) shr 1;
        if bfs(mid) then begin
            delta:=mid;
            l:=mid+1;
        end
        else r:=mid-1;
    end;
    if delta = 0 then exit(0);
    exit(double(flow)/double(delta));
end;


begin
    assign(fi,'5804.in');    reset(fi);
    assign(fo,'5804.out');   rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        read(fi,test_id);
        enter();
        writeln(fo,test_id,' ',solve():0:3);
        dec(nTest);
    end;
    close(fi);
    close(fo);
end.