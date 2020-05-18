const   MAX_N = 310;
        MAX_C = 10010;
        oo = 1000000000;

var fi,fo:text;
    n,m,top:longint;
    c:array[0..MAX_N,0..MAX_N] of longint;
    hu,hj:array[0..MAX_N*2*MAX_C] of longint;
    d,pos:array[0..MAX_N,-MAX_C..MAX_C] of longint;
    avail:array[0..MAX_N,-MAX_C..MAX_C] of boolean;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

procedure   enter;
var i,j,u,v:longint;
begin
    readln(fi,n,j);
    for u:=1 to n do
        for v:=1 to n do c[u][v]:=oo;
    for i:=1 to j do
        readln(fi,u,v,c[u][v],c[v][u]);
end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   swapH(x,y:longint);
begin
    swap(pos[hu[x]][hj[x]],pos[hu[y]][hj[y]]);
    swap(hu[x],hu[y]);
    swap(hj[x],hj[y]);
end;

function    cmp(x,y:longint):longint;   begin   exit(d[hu[x]][hj[x]]-d[hu[y]][hj[y]]);  end;

procedure   up_heap(i:longint);
var r:longint;
begin
    r:=i shr 1;
    if (r < 1) or (cmp(r,i) <= 0) then exit;
    swapH(r,i);
    up_heap(r);
end;

procedure   down_heap(i:longint);
var c:longint;
begin
    c:=i shl 1;
    if (c < top) and (cmp(c+1,c) < 0) then inc(c);
    if (c > top) or (cmp(c,i) >= 0) then exit;
    swapH(c,i);
    down_heap(c);
end;

procedure   push(u,j:longint);
begin
    inc(top);
    hu[top]:=u; hj[top]:=j;
    pos[u][j]:=top;
    up_heap(top);
end;

procedure   pop(var u,j:longint);
begin
    u:=hu[1];   j:=hj[1];
    pos[u][j]:=-1;
    swapH(1,top);
    dec(top);
    if top > 0 then down_heap(1);
end;

procedure   Dijkstra(s:longint);
var i,j,k,u,v:longint;
begin
    for i:=1 to n do
        for j:=-MAX_C to MAX_C do begin
            d[i][j]:=oo;
            if i = s then avail[i][j]:=false
            else avail[i][j]:=true;
            pos[i][j]:=-1;
        end;
    top:=0;
    d[s][0]:=0;
    push(s,0);
    repeat
        pop(u,j);
        avail[u][j]:=false;
        for v:=1 to n do begin
            k:=j+c[u][v];
            if (k >= -MAX_C) and (k <= MAX_C) and (avail[v][k]) then begin
                d[v][k]:=min(d[v][k],d[u][j]+1);
                if pos[v][k] = -1 then push(v,k)
                else begin
                    k:=pos[v][k];
                    up_heap(k);
                    down_heap(k);
                end;
            end;
        end;
    until top < 1;
    for i:=1 to n do
        if i <> s then
            for j:=MAX_C-1 downto -MAX_C do
                d[i][j]:=min(d[i][j],d[i][j+1]);
end;

procedure   solve;
var i,j,k,res:longint;
begin
    res:=oo;
    for i:=1 to n do begin
        Dijkstra(i);
        for j:=1 to n do
            if (j <> i) and (c[j][i] < oo) then begin
                if c[j][i] > 0 then k:=0
                else k:=abs(c[j][i])+1;
                if k <= MAX_C then res:=min(res,d[j][k]+1);
                {writeln('!!! ',res,'    ',i,' ',j,' ',k,'   ',d[j][k]);}
            end;
    end;
    if res = oo then res:=0;
    writeln(fo,res);
end;

begin
    assign(fi,'147B.in');   reset(fi);
    assign(fo,'147B.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.