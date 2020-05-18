{$M+ 2000000,0,2000000}
uses    math;

const   MAX_N = 100005;
        MAX_M = 100005;
        oo = 1000000000000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            w:ll;
            link:longint;
        end;

var fi,fo:text;
    n,m,nE,top:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,pos,h,f,p:array[0..MAX_N] of longint;
    d:array[0..MAX_N] of ll;
    portal:array[0..MAX_N] of boolean;


procedure   add_edge(u,v,ww:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        w:=ww;
        link:=head[x];
        head[x]:=nE;
    end;
end;


procedure   enter();
var i,k,u,v,w:longint;
begin
    nE:=0;
    readln(fi,n,m);
    for i:=1 to n do begin
        head[i]:=0;
        portal[i]:=false;
    end;
    for i:=1 to m do begin
        read(fi,u,v,w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    end;
    read(fi,k);
    for i:=1 to k do begin
        read(fi,u);
        portal[u]:=true;
    end;
end;


procedure   swapH(i,j:longint);
var t:ll;
begin
    t:=pos[h[i]];   pos[h[i]]:=pos[h[j]];   pos[h[j]]:=t;
    t:=h[i];        h[i]:=h[j];             h[j]:=t;
end;

function    cmp(i,j:longint):ll;    begin   exit(d[h[i]]-d[h[j]]);  end;

procedure   up_heap(i:longint);
var j:longint;
begin
    j:=i shr 1;
    if (j < 1) or (cmp(j,i) <= 0) then exit;
    swapH(i,j);
    up_heap(j);
end;

procedure   down_heap(i:longint);
var j:longint;
begin
    j:=i shl 1;
    if (j < top) and (cmp(j+1,j) < 0) then inc(j);
    if (j > top) or (cmp(j,i) >= 0) then exit;
    swapH(i,j);
    down_heap(j);
end;

procedure   push(u:longint);
begin
    if pos[u] = -1 then begin
        inc(top);
        h[top]:=u;
        pos[u]:=top;
    end;
    up_heap(pos[u]);
end;

procedure   pop(var u:longint);
begin
    u:=h[1];
    swapH(1,top);
    pos[u]:=-1;
    dec(top);
    down_heap(1);
end;


procedure   dijkstra();
var i,u:longint;
    tmp:ll;
begin
    top:=0;
    for i:=1 to n do begin
        pos[i]:=-1;
        if portal[i] then begin
            d[i]:=0;
            f[i]:=i;
            push(i);
        end
        else d[i]:=oo;
    end;

    repeat
        pop(u);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            tmp:=d[u] + w;
            if tmp < d[y] then begin
                d[y]:=tmp;
                f[y]:=f[u];
                push(y);
            end;
            i:=link;
        end;
    until top = 0;
end;


procedure   sort(l,r:longint);
var i,j:longint;
    p:ll;
    t:recEdge;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=e[i].w;

    i:=l;   j:=r;
    repeat
        while e[i].w < p do inc(i);
        while e[j].w > p do dec(j);
        if i <= j then begin
            t:=e[i];
            e[i]:=e[j];
            e[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;

function    get_root(u:longint):longint;
begin
    if p[u] < 1 then exit(u);
    p[u]:=get_root(p[u]);
    exit(p[u]);
end;

procedure   solve();
var i,u,v,r1,r2:longint;
    res:ll;
begin
    dijkstra();
    m:=0;
    for i:=1 to nE do
        if (i and 1) = 1 then with e[i] do begin
            inc(m);
            e[m].w:=d[x] + w + d[y];
            e[m].x:=f[x];
            e[m].y:=f[y];
        end;
    randomize;
    sort(1,m);

    if portal[1] then res:=0
    else res:=d[1];
    for i:=1 to n do p[i]:=-1;

    for i:=1 to m do with e[i] do begin
        r1:=get_root(x);
        r2:=get_root(y);
        if r1 = r2 then continue;
        res:=res + w;
        p[r1]:=p[r1]+p[r2];
        p[r2]:=r1;
    end;
    writeln(fo,res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'196E.in');    reset(fi);
    assign(fo,'196E.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.