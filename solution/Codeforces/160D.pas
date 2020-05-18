{$M+ 2000000,0,2000000}
uses    math;

const   MAX_N = 100005;
        MAX_M = 100005;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            w,id:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nE,count:longint;
    list:array[0..MAX_M] of recEdge;
    e:array[-MAX_M..MAX_M] of recEdge;
    head,p,num,low:array[0..MAX_N] of longint;
    ok:array[-MAX_M..MAX_M] of boolean;
    res:array[0..MAX_M] of string[13];



procedure   add_edge(u,v,ww,i:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        w:=ww;  id:=i;
        link:=head[x];
        head[x]:=nE;
        ok[nE]:=true;
    end;
    with e[-nE] do begin
        x:=v;   y:=u;
        w:=ww;  id:=i;
        link:=head[x];
        head[x]:=-nE;
        ok[-nE]:=true;
    end;
end;


procedure   enter();
var i:longint;
begin
    readln(fi,n,m);
    for i:=1 to m do with list[i] do begin
        readln(fi,x,y,w);
        id:=i;
    end;
end;


procedure   sort(l,r:longint);
var i,j,p:longint;
    t:recEdge;
begin
    if l >= r then exit;
    i:=l+random(r-l+1);
    p:=list[i].w;

    i:=l;   j:=r;
    repeat
        while list[i].w < p do inc(i);
        while list[j].w > p do dec(j);
        if i <= j then begin
            t:=list[i];
            list[i]:=list[j];
            list[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


function    get_root(u:longint):longint;
begin
    if p[u] < 1 then exit(u);
    p[u]:=get_root(p[u]);
    exit(p[u]);
end;


procedure   dfs(u:longint);
var i:longint;
begin
    inc(count);
    num[u]:=count;  low[u]:=oo;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if ok[i] then begin
            ok[i]:=false;
            ok[-i]:=false;
            if num[y] = 0 then begin
                dfs(y);
                low[u]:=min(low[u],low[y]);
                if low[y] >= num[y] then
                    res[id]:='any';
            end
            else low[u]:=min(low[u],num[y]);
        end;
        i:=link;
    end;
end;


procedure   solve();
var i,l,r,u,v:longint;
begin
    randomize;
    sort(1,m);
    for i:=1 to n do begin
        head[i]:=0;
        p[i]:=-1;
        num[i]:=0;
    end;
    for i:=1 to m do res[i]:='at least one';

    l:=1;
    while l <= m do begin
        nE:=0; count:=0;
        r:=l;
        while (r < m) and (list[r+1].w = list[l].w) do inc(r);

        for i:=l to r do with list[i] do begin
            u:=get_root(x);
            v:=get_root(y);
            x:=u;   y:=v;
            if u = v then res[id]:='none'
            else add_edge(u,v,w,id);
        end;

        for i:=1 to nE do with e[i] do
            if num[x] = 0 then dfs(x);

        for i:=1 to nE do with e[i] do begin
            head[x]:=0;  num[x]:=0;
            head[y]:=0;  num[y]:=0;
            x:=get_root(x);
            y:=get_root(y);
            if x <> y then begin
                p[x]:=p[x]+p[y];
                p[y]:=x;
            end;
        end;
        l:=r+1;
    end;
    for i:=1 to m do writeln(fo,res[i]);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'160D.in');    reset(fi);
    assign(fo,'160D.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.