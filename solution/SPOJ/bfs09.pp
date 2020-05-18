const   MAX_N = 510;
        MAX_M = sqr(MAX_N) div 2;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,l,r:longint;
    head,q:array[0..MAX_N] of longint;
    e:array[0..2*MAX_M] of recEdge;
    ok:array[0..MAX_N] of boolean;
    x,y:array[0..MAX_M] of longint;

procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        link:=head[x];
        head[x]:=m;
    end;
end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   sort(l,r:longint);
var i,j,p1,p2:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p1:=x[i];   p2:=y[i];
    i:=l;   j:=r;
    repeat
        while (x[i] < p1) or ((x[i] = p1) and (y[i] < p2)) do inc(i);
        while (x[j] > p1) or ((x[j] = p1) and (y[j] > p2)) do dec(j);
        if i <= j then begin
            swap(x[i],x[j]);
            swap(y[i],y[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j); sort(i,r);
end;

procedure   enter;
var i,j:longint;
begin
    readln(fi,n,j);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do
        readln(fi,x[i],y[i]);
    for i:=j downto 1 do begin
        add_edge(x[i],y[i]);
        add_edge(y[i],x[i]);
    end;
end;


procedure   push(u:longint);    begin   inc(r); q[r]:=u;    ok[u]:=false;   end;

procedure   pop(var u:longint); begin   u:=q[l];    inc(l); end;

procedure   bfs;
var i,u:longint;
begin
    l:=1;   r:=0;
    push(1);
    repeat
        repeat
            pop(u);
            writeln(fo,u);
            i:=head[u];
            while i <> 0 do with e[i] do begin
                if ok[y] then push(y);
                i:=link;
            end;
        until l > r;
        for i:=1 to n do if ok[i] then begin
            push(i);
            break;
        end;
    until l > r;
end;

procedure   dfs(u:longint);
var i:longint;
begin
    writeln(fo,u);
    ok[u]:=false;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if ok[y] then dfs(y);
        i:=link;
    end;
end;

procedure   solve;
var i:longint;
begin
    for i:=1 to n do ok[i]:=true;
    bfs;
    //for i:=1 to n do if ok[i] then dfs(i);
end;

begin
    assign(fi,'bfs09.in');      reset(fi);
    assign(fo,'bfs09.out');     rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.