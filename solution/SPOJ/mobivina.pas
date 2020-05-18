uses    math;

const   MAX_N = 260;
        MAX_M = sqr(MAX_N)+2*MAX_N;
        oo = 1000000000;

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
var i,j,c:longint;
begin
    n:=2;   nE:=0;
    s:=1;   t:=2;
    fillchar(head,sizeof(head),0);
    read(fi,n);
    for i:=1 to n do begin
        read(fi,c);
        add_edge(s,i+2,c);
    end;
    for i:=1 to n do begin
        read(fi,c);
        add_edge(i+2,t,c);
    end;
    for i:=1 to n do
        for j:=1 to n do begin
            read(fi,c);
            if c > 0 then add_edge(i+2,j+2,c);
        end;
    n:=n+2;
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
var i,delta,res:longint;
begin
    res:=0;
    while find_path() do begin
        for i:=1 to n do pos[i]:=head[i];
        repeat
            delta:=augment_flow(s,oo);
            res:=res+delta;
        until delta = 0;
    end;
    writeln(fo,res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'MOBIVINA.in');   reset(fi);
    assign(fo,'MOBIVINA.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.