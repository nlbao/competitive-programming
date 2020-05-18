uses    math;

const   MAX_N = 10010;
        MAX_M = 50010;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,nE,c:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head,num,low,p,nChild:array[0..MAX_N] of longint;
    avail:array[-MAX_M..MAX_M] of boolean;
    isCut:array[0..MAX_N] of boolean;


procedure   add_edge(u,v:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        link:=head[x];
        head[x]:=nE;
    end;
    with e[-nE] do begin
        x:=v;   y:=u;
        link:=head[x];
        head[x]:=-nE;
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
    inc(c);
    num[u]:=c;  low[u]:=MAX_M+MAX_M;
    nChild[u]:=0;

    i:=head[u];
    while i <> 0 do with e[i] do begin
        if avail[i] then begin
            avail[i]:=false;
            avail[-i]:=false;
            if num[y] = -1 then begin
                p[y]:=u;
                inc(nChild[u]);
                dfs(y);
                low[u]:=min(low[u],low[y]);
            end
            else low[u]:=min(low[u],num[y]);
        end;
        i:=link;
    end;
end;

procedure   solve();
var i,j:longint;
begin
    c:=0;
    for i:=1 to n do begin
        p[i]:=-1;
        num[i]:=-1;
    end;
    fillchar(avail,sizeof(avail),true);
    for i:=1 to n do
        if p[i] = -1 then dfs(i);

    c:=0;
    for i:=1 to n do isCut[i]:=false;
    for i:=1 to n do begin
        j:=p[i];
        if (j > 0) and (low[i] >= num[j]) then
            isCut[j]:=isCut[j] or (p[j] > 0) or (nChild[j] > 1);
    end;
    for i:=1 to n do c:=c+longint(isCut[i]);
    write(fo,c,' ');

    c:=0;
    for i:=1 to n do
        if (p[i] > 0) and (low[i] >= num[i]) then inc(c);
    write(fo,c);
end;


begin
    assign(fi,'graph_.in');  reset(fi);
    assign(fo,'graph_.out'); rewrite(fo);
    enter();
    solve();
    close(fo);
    close(fi);
end.