uses    math;

const   MAX_N = 10010;
        MAX_M = 100010;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,nE,c,top,res:longint;
    e:array[0..MAX_M] of recEdge;
    head,stt,num,low,q:array[0..MAX_N] of longint;


procedure   add_edge(u,v:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        link:=head[x];
        head[x]:=nE;
    end;
end;

procedure   enter();
var i,m,u,v:longint;
begin
    nE:=0;
    read(fi,n,m);
    for i:=1 to n do head[i]:=0;
    for i:=1 to m do begin
        read(fi,u,v);
        add_edge(u,v);
    end;
end;


procedure   dfs(u:longint);
var i:longint;
begin
    stt[u]:=0;
    inc(c);
    num[u]:=c;  low[u]:=MAX_N+10;
    inc(top);   q[top]:=u;

    i:=head[u];
    while i <> 0 do with e[i] do begin
        if stt[y] < 1 then
            if stt[y] = -1 then begin
                dfs(y);
                low[u]:=min(low[u],low[y]);
            end
            else low[u]:=min(low[u],num[y]);
        i:=link;
    end;

    if low[u] >= num[u] then begin
        inc(res);
        repeat
            i:=q[top];
            dec(top);
            stt[i]:=1;
        until i = u;
    end;
end;


procedure   solve();
var i:longint;
begin
    res:=0;
    c:=0;   top:=0;
    for i:=1 to n do stt[i]:=-1;
    for i:=1 to n do
        if stt[i] = -1 then dfs(i);
    writeln(fo,res);
end;


begin
    assign(fi,'tjalg.in');  reset(fi);
    assign(fo,'tjalg.out'); rewrite(fo);
    enter();
    solve();
    close(fo);
    close(fi);
end.