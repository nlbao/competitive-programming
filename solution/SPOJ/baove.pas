{$M+ 2000000}
{$R+, $I+, $Q+}

uses    math;

const   MAX_N = 5003;
        MAX_M = 10004;
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
    head,q,trace:array[0..MAX_N] of longint;


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
    readln(fi,n);
    s:=n;   t:=1;
    for i:=1 to n do head[i]:=0;
    while not eof(fi) do begin
        readln(fi,u,v,c);
        add_edge(u,v,c);
    end;
end;


function    find_path():boolean;
var i,u,l,r:longint;
begin
    for i:=1 to n do trace[i]:=-1;
    trace[s]:=0;
    l:=1;   r:=1;
    q[1]:=s;
    repeat
        u:=q[l];    inc(l);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if (trace[y] = -1) and (c > f) then begin
                trace[y]:=i;
                if y = t then exit(true);
                inc(r); q[r]:=y;
            end;
            i:=link;
        end;
    until l > r;
    exit(false);
end;


function    augment_flow():longint;
var u,delta:longint;
begin
    delta:=oo;
    u:=t;
    while u <> s do
        with e[trace[u]] do begin
            delta:=min(delta,c-f);
            u:=x;
        end;
    u:=t;
    while u <> s do
        with e[trace[u]] do begin
            f:=f+delta;
            with e[-trace[u]] do f:=f-delta;
            u:=x;
        end;
    exit(delta);
end;


function    solve():longint;
var res:longint;
begin
    if s = t then exit(0);
    res:=0;
    while find_path() do
        res:=res+augment_flow();
    exit(res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'BAOVE.in');   reset(fi);
    assign(fo,'BAOVE.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    enter();
    writeln(fo,solve());
    close(fi);
    close(fo);
end.

