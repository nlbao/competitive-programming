{$M+ 2000000}

uses    math;

const   MAX_N = 110;
        MAX_M = MAX_N*(MAX_N+1) div 2;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            c,f:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nE,s,t:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head,q,d,pos:array[0..MAX_N] of longint;
    res:array[0..MAX_M] of longint;


procedure   add_edge(u,v,ww:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        c:=1;   f:=0;
        w:=ww;
        link:=head[x];
        head[x]:=nE;
    end;
    with e[-nE] do begin
        x:=v;   y:=u;
        c:=0;   f:=0;
        w:=ww;
        link:=head[x];
        head[x]:=-nE;
    end;
end;


procedure   enter();
var i,u,v,w:longint;
begin
    nE:=0;
    fillchar(head,sizeof(head),0);
    read(fi,n,m);
    for i:=1 to m do begin
        read(fi,u,v,w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    end;
    read(fi,s,t);
end;


function    dfs(u,limit:longint):boolean;
var i:longint;
begin
    if u = t then exit(false);
    d[u]:=0;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if (d[y] = -1) and (w > limit) then
            if not dfs(y,limit) then exit(false);
        i:=link;
    end;
    exit(true);
end;

function    find_path():boolean;
var i,l,r,u:longint;
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

function    augment_flow(u,flow:longint):longint;
var delta:longint;
begin
    if flow = 0 then exit(0);
    if u = t then exit(flow);
    while pos[u] <> 0 do with e[pos[u]] do begin
        if d[y] = d[u]+1 then begin
            delta:=augment_flow(y,min(flow,c-f));
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
var i,j,l,r,mid,limit:longint;
begin
    limit:=-1;
    l:=0;   r:=100;
    while l <= r do begin
        mid:=(l+r) shr 1;
        for i:=1 to n do d[i]:=-1;
        if dfs(s,mid) then begin
            limit:=mid;
            r:=mid-1;
        end
        else l:=mid+1;
    end;

    for i:=1 to nE do with e[i] do
        if w <= limit then c:=1
        else c:=oo;

    while find_path() do begin
        for i:=1 to n do pos[i]:=head[i];
        while augment_flow(s,oo) > 0 do i:=1;
    end;

    m:=0;
    for i:=1 to nE do with e[i] do
        if (f > 0) and (w <= limit) then
            if (d[x] > -1) and (d[y] = -1) then begin
                inc(m);
                res[m]:=i;
            end;

    writeln(fo,m);
    for i:=1 to m do with e[res[i]] do
        writeln(fo,x,' ',y);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'NKNET.in');   reset(fi);
    assign(fo,'NKNET.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.