const   MAX_N = 210;
        MAX_M = sqr(MAX_N);
        MAX_STT = 150;
        oo = 1000000010;
        dx:array[1..4] of longint = (0,0,-1,+1);
        dy:array[1..4] of longint = (-1,+1,0,0);

type    recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;
        recHeap = record
            j,u:longint;
        end;

var fi,fo:text;
    nC,nR,n,m,k,top:longint;
    id:array[0..110,0..110] of longint;
    idX,idY,a:array[0..MAX_N] of longint;
    e:array[0..2*MAX_M] of recEdge;
    head,p:array[0..MAX_N] of longint;
    h:array[0..MAX_N*MAX_STT] of recHeap;
    d,pos:array[0..MAX_STT,0..MAX_N] of longint;
    ok:array[0..MAX_STT,0..MAX_N,0..MAX_N] of boolean;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

procedure   add_edge(u,v,w0:longint);
begin
    if (u < 1) or (v < 1) then exit;
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        w:=w0;
        link:=head[x];
        head[x]:=m;
    end;
end;

procedure   enter;
var i,j,x,y:longint;
begin
    fillchar(id,sizeof(id),0);
    fillchar(p,sizeof(p),0);
    readln(fi,nR,nC,k);
    for i:=1 to nR do
        for j:=1 to nC do begin
            inc(n);
            id[i][j]:=n;
            idX[n]:=i;  idY[n]:=j;
            read(fi,a[n]);
        end;
    for i:=1 to k do begin
        readln(fi,x,y);
        p[id[x][y]]:=i;
    end;
end;

procedure   init;
var i,j,t,x,y:longint;
begin
    m:=0;
    for i:=1 to nR do
        for j:=1 to nC do
            for t:=1 to 4 do begin
                x:=i+dx[t];
                y:=j+dy[t];
                add_edge(id[i][j],id[x][y],a[id[x][y]]);
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

procedure   update(j,u,value,j0,j1,u0:longint);
var i:longint;
begin
    if value >= d[j][u] then exit;
    d[j][u]:=value;
    push(j,u);
    for i:=1 to n do
        ok[j][u][i]:=ok[j0][u0][i] or ok[j1][u0][i];
end;

procedure   solve;
var i,j,jj,u,limit:longint;
begin
    limit:=(1 shl k)-1;
    for j:=0 to limit do
        for u:=1 to n do begin
            d[j][u]:=oo;
            pos[j][u]:=-1;
            for i:=1 to n do ok[j][u][i]:=false;
        end;
    top:=0;
    for u:=1 to n do begin
        j:=0;
        if p[u] > 0 then j:=1 shl (p[u]-1);
        d[j][u]:=a[u];
        ok[j][u][u]:=true;
        push(j,u);
    end;
    repeat
        pop(j,u);
        for jj:=0 to limit do
            update(j or jj,u,d[j][u]+d[jj][u]-a[u],j,jj,u);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            jj:=j;
            if p[y] > 0 then jj:=j or (1 shl (p[y]-1));
            update(jj,y,d[j][u]+w,j,j,u);
            ok[jj][y][y]:=true;
            i:=link;
        end;
    until top < 1;
end;

procedure   print;
var i,j,p1,p2,limit,res:longint;
begin
    limit:=(1 shl k)-1;
    res:=oo;
    for i:=1 to n do
        if d[limit][i] < res then begin
            res:=d[limit][i];
            p1:=limit;
            p2:=i;
        end;
    writeln(fo,res);
    for i:=1 to nR do begin
        for j:=1 to nC do
            if ok[p1][p2][id[i][j]] then write(fo,'X')
            else write(fo,'.');
        writeln(fo);
    end;
end;

begin
    assign(fi,'152E.in');   reset(fi);
    assign(fo,'152E.out');  rewrite(fo);
    enter;
    init;
    solve;
    print;
    close(fo);
    close(fi);
end.