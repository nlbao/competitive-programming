const   MAX_N = 100010;
        MAX_M = 100010;
        oo = 1000000000;

type    int = int64;
        recEdge = record
            x,y:longint;
            w:int;
            link:longint;
        end;

var fi,fo:text;
    n,m,s,top:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head,h,pos:array[0..MAX_N] of longint;
    d:array[0..MAX_N] of int;
    l:int;

procedure   add_edge(u,v,w0:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        w:=w0;
        link:=head[x];
        head[x]:=m;
    end;
    with e[-m] do begin
        x:=v; y:=u;
        w:=w0;
        link:=head[x];
        head[x]:=-m;
    end;
end;

procedure   enter;
var i,j,u,v,w:longint;
begin
    readln(fi,n,j,s);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        readln(fi,u,v,w);
        add_edge(u,v,w);
    end;
    readln(fi,l);
end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   swapH(x,y:longint);
begin
    swap(pos[h[x]],pos[h[x]]);
    swap(h[x],h[y]);
end;

function    cmpH(x,y:longint):longint;   begin   exit(d[h[x]]-d[h[y]]);  end;

procedure   up_heap(i:longint);
var j:longint;
begin
    j:=i shr 1;
    if (j < 1) or (cmpH(j,i) <= 0) then exit;
    swapH(j,i);
    up_heap(j);
end;

procedure   down_heap(i:longint);
var j:longint;
begin
    j:=i shl 1;
    if (j < top) and (cmpH(j+1,j) < 0) then inc(j);
    if (j > top) or (cmpH(j,i) >= 0) then exit;
    swapH(j,i);
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
    down_heap(pos[u]);
end;

procedure   pop(var u:longint);
begin
    u:=h[1];
    swapH(1,top);
    dec(top);
    pos[u]:=-1;
    down_heap(1);
end;

procedure   dijkstra(s:longint);
var i,u,tmp:longint;
begin
    for i:=1 to n do begin
        d[i]:=oo;
        pos[i]:=-1;
    end;
    d[s]:=0;
    top:=0; push(s);
    repeat
        pop(u);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            tmp:=d[u]+w;
            if tmp < d[y] then begin
                d[y]:=tmp;
                push(y);
            end;
            i:=link;
        end;
    until top < 1;
end;

procedure   solve;
var i,res:longint;
    a,b:int;
begin
    res:=0;
    dijkstra(s);
    for i:=1 to n do
        if d[i] = l then inc(res);
    for i:=1 to m do with e[i] do begin
        if (d[x] < l) and (l-d[x] < w) and (w-(l-d[x])+d[y] > l) then inc(res);
        if (d[y] < l) and (l-d[y] < w) and (w-(l-d[y])+d[x] > l) then inc(res);
        if (d[x] < l) and (d[y] < l) and (d[x]+d[y]+w = 2*l) then inc(res);
    end;
    writeln(fo,res);
end;

begin
    assign(fi,'144D.in');   reset(fi);
    assign(fo,'144D.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
