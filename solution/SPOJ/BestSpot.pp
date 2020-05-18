const   MAX_N = 510;
        MAX_M = 8010;
        MAX_INT = 1000000000;

type    recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nF,h_size:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,f,d,pos,h:array[0..MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   add_edge(u,v,w0:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u;   y:=v;
        w:=w0;
        link:=head[x];
        head[x]:=m;
    end;
end;

procedure   enter;
var i,j,u,v,w:longint;
begin
    readln(fi,n,nF,j);
    for i:=1 to nF do read(fi,f[i]);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        readln(fi,u,v,w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    end;
end;

procedure   up_heap(i:longint);
var r:longint;
begin
    r:=i shr 1;
    if (r < 1) or (d[h[r]] <= d[h[i]]) then exit;
    swap(pos[h[r]],pos[h[i]]);
    swap(h[r],h[i]);
    up_heap(r);
end;

procedure   down_heap(i:longint);
var c:longint;
begin
    c:=i shl 1;
    if (c < h_size) and (d[h[c+1]] < d[h[c]]) then inc(c);
    if (c > h_size) or (d[h[c]] >= d[h[i]]) then exit;
    swap(pos[h[c]],pos[h[i]]);
    swap(h[c],h[i]);
    down_heap(c);
end;

procedure   push(u:longint);
begin
    inc(h_size);
    h[h_size]:=u;
    pos[u]:=h_size;
    up_heap(h_size);
end;

procedure   pop(var u:longint);
begin
    u:=h[1];
    pos[u]:=-1;
    h[1]:=h[h_size];
    pos[h[1]]:=1;
    dec(h_size);
    if h_size > 0 then down_heap(1);
end;

procedure   Dijkstra(s:longint);
var i,j,u,tmp:longint;
begin
    for i:=1 to n do begin
        avail[i]:=true;
        d[i]:=MAX_INT;
        pos[i]:=-1;
    end;
    d[s]:=0;
    h_size:=0;  push(s);
    repeat
        pop(u);
        avail[u]:=false;
        i:=head[u];
        while i <> 0 do with e[i] do begin
            tmp:=d[u]+w;
            if (avail[y]) and (tmp < d[y]) then begin
                d[y]:=tmp;
                if pos[y] = -1 then push(y)
                else begin
                    j:=pos[y];
                    up_heap(j); down_heap(j);
                end;
            end;
            i:=link;
        end;
    until h_size = 0;
end;

procedure   solve;
var i,j,s,rd,rv:longint;
begin
    rd:=MAX_INT;    rv:=-1;
    for i:=1 to n do begin
        Dijkstra(i);
        s:=0;
        for j:=1 to nF do begin
            s:=s+d[f[j]];
            if s > MAX_INT then s:=MAX_INT;
        end;
        if s < rd then begin
            rd:=s;
            rv:=i;
        end;
    end;
    writeln(fo,rv);
end;

begin
    assign(fi,'BestSpot.in');   reset(fi);
    assign(fo,'BestSpot.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.