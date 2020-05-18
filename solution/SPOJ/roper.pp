uses    math;
const   MAX_N = 100010;
        MAX_M = MAX_N;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,nE,nQ,top,count,time,nC:longint;
    e:array[0..MAX_M] of recEdge;
    head,deg,stack,num,low,c:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;

procedure   add_edge(u,v:longint);
begin
    if u = v then exit;
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        inc(deg[y]);
        link:=head[x];
        head[x]:=nE;
    end;
end;


procedure   enter();
var i:longint;
begin
    nE:=0;
    read(fi,n,nQ);
    for i:=1 to n do begin
        head[i]:=0;
        deg[i]:=0;
    end;
    for i:=1 to n do begin
        read(fi,c[i]);
        add_edge(i,c[i]);
    end;
    add_edge(1,c[2]);
    add_edge(2,c[1]);
end;


procedure   dfs(u:longint);
var i:longint;
begin
    inc(top);
    stack[top]:=u;
    inc(count);
    num[u]:=count;  low[u]:=MAX_M+MAX_M;

    i:=head[u];
    while i <> 0 do with e[i] do begin
        if ok[y] then
            if num[y] = -1 then begin
                dfs(y);
                low[u]:=min(low[u],low[y]);
            end
            else low[u]:=min(low[u],num[y]);
        i:=link;
    end;

    if low[u] >= num[u] then begin
        inc(nC);
        repeat
            i:=stack[top];
            dec(top);
            c[i]:=nC;
            ok[i]:=false;
        until i = u;
    end;
    //ok[u]:=false;
end;


procedure   solve();
var i,u,v:longint;
begin
    top:=0; count:=0;   time:=0;    nC:=0;
    for i:=1 to n do begin
        ok[i]:=true;
        num[i]:=-1;
    end;

    for i:=1 to n do
        if deg[i] = 0 then dfs(i);
    for i:=1 to n do
        if ok[i] then dfs(i);

    for i:=1 to nQ do begin
        read(fi,u,v);
        if c[u] = c[v] then writeln(fo,'Yes')
        else writeln(fo,'No');
    end;
end;

begin
    assign(fi,'roper.in');  reset(fi);
    assign(fo,'roper.out'); rewrite(fo);
    enter();
    solve();
    close(fo);
    close(fi);
end.
