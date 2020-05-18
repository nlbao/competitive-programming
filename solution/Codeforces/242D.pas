{$R+, $I+}
{$M 16777216}

uses    math;

const   MAX_N = 100010;
        MAX_M = 100010;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,nE,top:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,deg,a,c,h,pos:array[0..MAX_N] of longint;
    press:array[0..MAX_N] of boolean;


procedure   add_edge(u,v:longint);
begin
    if u = v then exit;
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        link:=head[x];
        head[x]:=nE;
    end;
    inc(deg[u]);
end;


procedure   enter();
var i,m,u,v:longint;
begin
    nE:=0;
    read(fi,n,m);
    for i:=1 to n do begin
        head[i]:=0;
        deg[i]:=0;
    end;
    for i:=1 to m do begin
        read(fi,u,v);
        add_edge(u,v);
        add_edge(v,u);
    end;
    for i:=1 to n do read(fi,a[i]);
end;


procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;


procedure   swapH(i,j:longint);
begin
    swap(pos[h[i]],pos[h[j]]);
    swap(h[i],h[j]);
end;

function    cmp(i,j:longint):longint;   begin   exit(c[h[i]]-c[h[j]]);  end;


procedure   up_heap(i:longint);
var j:longint;
begin
    j:=i shr 1;
    if (j < 1) or (cmp(j,i) <= 0) then exit;
    swapH(j,i);
end;


procedure   down_heap(i:longint);
var j:longint;
begin
    j:=i shl 1;
    if (j < top) and (cmp(j+1,j) < 0) then inc(j);
    if (j > top) or (cmp(j,i) >= 0) then exit;
    swapH(j,i);
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
    dec(top);
    pos[u]:=-1;
    down_heap(1);
end;


function    solve():boolean;
var i,k,u:longint;
begin
    k:=0;
    top:=0;
    for i:=1 to n do begin
        c[i]:=0;
        press[i]:=false;
        pos[i]:=-1;
        push(i);
    end;

    while top > 0 do begin
        pop(u);
        if c[u] <> a[u] then continue;
        if c[u] = deg[u]+1 then exit(false);

        c[u]:=c[u]+1;
        press[u]:=true;
        k:=k+1;
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if c[y] = deg[y]+1 then exit(false);
            c[y]:=c[y]+1;
            if (c[y] = a[y]) and (not press[y]) then
                push(y);
            i:=link;
        end;
    end;

    writeln(fo,k);
    for i:=1 to n do
        if press[i] then write(fo,i,' ');
    exit(true);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'242D.in');    reset(fi);
    assign(fo,'242D.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    if not solve() then writeln(fo,-1);
    close(fi);
    close(fo);
end.