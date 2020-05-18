const   MAX_N = 30010;
        MAX_M = 100010;
        oo = 1000000000000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            w:ll;
            link:longint;
        end;

var fi,fo:text;
    n,nE,top:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,h,pos,res:array[0..MAX_N] of longint;
    d,c,f,a:array[0..MAX_N] of ll;


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
var i,m,u,v,w:longint;
begin
    nE:=0;
    read(fi,n,m);
    for i:=1 to n do head[i]:=0;
    for i:=1 to m do begin
        read(fi,u,v,w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    end;
end;


procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;


function    cmp(i,j:longint):longint;   begin   exit(d[h[i]]-d[h[j]]);  end;


procedure   up_heap(i:longint);
var j:longint;
begin
    j:=i shr 1;
    if (j < 1) or (cmp(j,i) <= 0) then exit;
    swap(pos[h[j]],pos[h[i]]);
    swap(h[j],h[i]);
    up_heap(j);
end;

procedure   down_heap(i:longint);
var j:longint;
begin
    j:=i shl 1;
    if (j < top) and (cmp(j+1,j) < 0) then inc(j);
    if (j > top) or (cmp(j,i) >= 0) then exit;
    swap(pos[h[j]],pos[h[i]]);
    swap(h[j],h[i]);
    down_heap(j);
end;

procedure   push(u:longint);
begin
    if pos[u] = -1 then begin
        inc(top);
        h[top]:=u;
        pos[u]:=top;
        up_heap(top);
        exit;
    end;
    up_heap(pos[u]);
end;


procedure   pop(var u:longint);
begin
    u:=h[1];
    pos[u]:=-1;
    h[1]:=h[top];
    pos[h[1]]:=1;
    dec(top);
    down_heap(1);
end;


procedure   dijkstra(s:longint);
var i,u:longint;
    t:ll;
begin
    for i:=1 to n do begin
        d[i]:=oo;
        c[i]:=0;
        pos[i]:=-1;
    end;
    d[s]:=0;    c[s]:=1;

    top:=0;
    push(s);
    repeat
        pop(u);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            t:=d[u]+w;
            if t < d[y] then begin
                d[y]:=t;
                c[y]:=c[u];
                push(y);
            end
            else if t = d[y] then c[y]:=c[y]+c[u];
            i:=link;
        end;
    until top = 0;
end;


procedure   solve();
var i,nR:longint;
begin
    dijkstra(1);
    for i:=1 to n do begin
        f[i]:=d[i];
        a[i]:=c[i];
    end;
    dijkstra(n);

    nR:=0;
    for i:=1 to n do
        if (f[i]+d[i] <> f[n]) or (a[i]*c[i] <> a[n]) then begin
            inc(nR);
            res[nR]:=i;
        end;
    writeln(fo,nR);
    for i:=1 to nR do writeln(fo,res[i]);
end;


begin
    assign(fi,'centre28.in');   reset(fi);
    assign(fo,'centre28.out');  rewrite(fo);
    enter();
    solve();
    close(fo);
    close(fi);
end.