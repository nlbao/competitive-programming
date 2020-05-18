const   MAX_N = 110;
        MAX_M = sqr(MAX_N);
        MAX_K = 10;
        MAX_STT = 150;
        oo = 1000000000;

type    recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;
        recHeap = record
            j,u:longint;
        end;

var fi,fo:text;
    n,m,k,top:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,p:array[0..MAX_N] of longint;
    h:array[0..MAX_N*MAX_STT] of recHeap;
    d,pos:array[0..MAX_STT,0..MAX_N] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

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
    m:=0;
    readln(fi,n,j,k);
    fillchar(head,sizeof(head),0);
    fillchar(p,sizeof(p),0);
    for i:=1 to k do begin
        read(fi,u);
        p[u]:=i;
    end;
    for i:=1 to j do begin
        readln(fi,u,v,w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    end;
end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   swapH(x,y:longint);
begin
    swap(pos[h[x].j][h[x].u],pos[h[y].j][h[y].u]);
    swap(h[x].j,h[y].j);
    swap(h[x].u,h[y].u);
end;

function    cmpH(x,y:longint):longint;
begin
    exit(d[h[x].j][h[x].u]-d[h[y].j][h[y].u]);
end;

procedure   up_heap(i:longint);
var r:longint;
begin
    r:=i shr 1;
    if (r < 1) or (cmpH(r,i) <= 0) then exit;
    swapH(r,i);
    up_heap(r);
end;

procedure   down_heap(i:longint);
var c:longint;
begin
    c:=i shl 1;
    if (c < top) and (cmpH(c+1,c) < 0) then inc(c);
    if (c > top) or (cmpH(c,i) >= 0) then exit;
    swapH(c,i);
    down_heap(c);
end;

procedure   push(j0,u0:longint);
begin
    if pos[j0][u0] = -1 then begin
        inc(top);
        h[top].j:=j0;
        h[top].u:=u0;
        pos[j0][u0]:=top;
    end;
    up_heap(pos[j0][u0]);
end;

procedure   pop(var j0,u0:longint);
begin
    j0:=h[1].j;
    u0:=h[1].u;
    swapH(1,top);
    pos[j0][u0]:=-1;
    dec(top);
    down_heap(1);
end;

procedure   update(j,u,value:longint);
begin
    if value >= d[j][u] then exit;
    d[j][u]:=value;
    push(j,u);
end;

procedure   solve;
var i,j,jj,u,limit,res:longint;
begin
    limit:=(1 shl k)-1;
    for j:=0 to limit do
        for u:=1 to n do begin
            d[j][u]:=oo;
            pos[j][u]:=-1;
        end;
    top:=0;
    for u:=1 to n do begin
        j:=0;
        if p[u] > 0 then j:=1 shl (p[u]-1);
        d[j][u]:=0;
        push(j,u);
    end;
    repeat
        pop(j,u);
        for jj:=0 to limit do
            update(j or jj,u,d[j][u]+d[jj][u]);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            jj:=j;
            if p[y] > 0 then jj:=j or (1 shl (p[y]-1));
            update(jj,y,d[j][u]+w);
            i:=link;
        end;
    until top < 1;
    res:=oo;
    for i:=1 to n do res:=min(res,d[limit][i]);
    if res = oo then res:=-1;
    writeln(fo,res);
end;

begin
    assign(fi,'NKBuild.in');    reset(fi);
    assign(fo,'NKBuild.out');   rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
