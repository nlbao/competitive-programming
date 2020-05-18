uses    math;

const   MAX_S = 33;
        MAX_N = MAX_S*MAX_S;
        MAX_M = 4*MAX_N;
        oo = 1000000000;
        dx:array[1..4] of longint = (0,0,+1,-1);
        dy:array[1..4] of longint = (+1,-1,0,0);

type    ll = int64;
        recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    n,nE,top:longint;
    s:array[0..MAX_S] of ansiString;
    id:array[0..MAX_S,0..MAX_S] of longint;
    cost:array[0..1] of longint;
    e:array[0..MAX_M] of recEdge;
    head,d,h,pos:array[0..MAX_N] of longint;


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


{procedure   gen_test(var c:longint);
var i,j:longint;
begin
    randomize;
    n:=30;
    c:=0;
    for i:=1 to n do begin
        s[i]:='';
        for j:=1 to n do begin
            c:=c+1;
            id[i][j]:=c;
            if random(MAX_N) mod 2 = 0 then s[i]:=s[i]+'('
            else s[i]:=s[i]+')';
        end;
    end;
    for i:=0 to 1 do cost[i]:=random(1000000)+1;
end; }


procedure   enter();
var i,j,k,c,x,y:longint;
begin
    readln(fi,n,cost[0],cost[1]);
    fillchar(id,sizeof(id),0);
    c:=0;
    for i:=1 to n do begin
        readln(fi,s[i]);
        for j:=1 to n do begin
            c:=c+1;
            id[i][j]:=c;
        end;
    end;

    //gen_test(c);

    nE:=0;
    for i:=1 to c do head[i]:=0;
    for i:=1 to n do
        for j:=1 to n do
            for k:=1 to 4 do begin
                x:=i+dx[k];
                y:=j+dy[k];
                if id[x][y] = 0 then continue;
                add_edge(id[i][j],id[x][y],cost[longint(s[i][j] <> s[x][y])]);
            end;
    n:=c;
end;


procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   swapH(i,j:longint);
begin
    swap(pos[h[i]],pos[h[j]]);
    swap(h[i],h[j]);
end;

function    cmp(i,j:longint):longint;   begin   exit(d[h[i]]-d[h[j]]);  end;

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


function    dijkstra(u:longint):longint;
var i,t,res:longint;
begin
    res:=0;
    for i:=1 to n do begin
        d[i]:=oo;
        pos[i]:=-1;
    end;
    d[u]:=0;

    top:=0; push(u);
    repeat
        pop(u);
        res:=max(res,d[u]);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            t:=d[u]+w;
            if t < d[y] then begin
                d[y]:=t;
                push(y);
            end;
            i:=link;
        end;
    until top = 0;
    exit(res);
end;

procedure   solve();
var i,res:longint;
begin
    res:=0;
    for i:=1 to n do
        res:=max(res,dijkstra(i));
    writeln(fo,res);
end;


begin
    assign(fi,'distant.in');    reset(fi);
    assign(fo,'distant.out');   rewrite(fo);
    enter();
    solve();
    close(fi);
    close(fo);
end.