const   INPUT = '87D.in';
        OUTPUT = '87D.out';
        MAX_N = 100010;
        MAX_M = MAX_N;
        MAX_INT = 1000000000;

type    pEdge = ^recEdge;
        recEdge = record
            x,y:longint;
            d:longint;
            id:longint;
            link:pEdge;
        end;

var fi,fo:text;
    n,m,nT:longint;
    head:array[0..MAX_N] of pEdge;
    parent,des,c,f,g,t,pos,sum:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   add_edge(u,v,d0,id0:longint);
var p:pEdge;
begin
    new(p);
    with p^ do begin
        x:=u;   y:=v;
        d:=d0;
        id:=id0;
        link:=head[u];
        head[u]:=p;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i,u,v,d:longint;
begin
    readln(fi,n);
    m:=0;
    for i:=0 to n do head[i]:=nil;
    for i:=1 to n-1 do begin
        readln(fi,u,v,d);
        inc(m);
        add_edge(u,v,d,m);
        add_edge(v,u,d,m);
    end;
end;
{---------------------------------------------------------------------------}
procedure   cal_f(u:longint);
var p:pEdge;
begin
    f[u]:=0;
    p:=head[u];
    while p <> nil do
        with p^ do begin
            if parent[y] = -1 then begin
                parent[y]:=u;
                c[y]:=d;
                pos[y]:=id;
                cal_f(y);
                if (u <> 1) and (c[y] <= c[u]) then inc(f[u],f[y]+1);
            end;
            p:=link;
        end;
    writeln('f ',u,' ',f[u]);
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var i,j,p,tmp:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=c[t[(i+j) shr 1]];
    repeat
        while c[t[i]] < p do inc(i);
        while c[t[j]] > p do dec(j);
        if i <= j then begin
            tmp:=t[i]; t[i]:=t[j];  t[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   cal_g(u:longint);
var p:pEdge;
    i,j:longint;
begin
    nT:=0;
    p:=head[u];
    while p <> nil do
        with p^ do begin
            if parent[y] = u then begin
                inc(nT);
                t[nT]:=y;
                g[y]:=1;
            end;
            p:=link;
        end;
    quick_sort(1,nT);
    t[0]:=0;    t[nT+1]:=0;
    for i:=1 to nT do
        if c[t[i]] >= c[u] then inc(g[t[i]],g[u]);
    sum[1]:=0;
    for i:=2 to nT do sum[i]:=sum[i-1]+f[t[i-1]]+1;
    for i:=1 to nT do begin
        if c[t[i]] = c[t[i-1]] then inc(g[t[i]],g[t[i-1]])
        else begin
            j:=i;
            while c[t[j+1]] = c[t[i]] do inc(j);
            inc(g[t[i]],sum[j]);
        end;
    end;
    for i:=1 to nT do cal_g(t[i]);
    writeln(u,' ',g[u]);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,count,maxS:longint;
begin
    for i:=1 to n do parent[i]:=-1;
    parent[1]:=0;
    c[0]:=-1;   c[1]:=MAX_INT;
    g[1]:=0;
    cal_f(1);
    cal_g(1);
    for i:=2 to n do begin
        sum[pos[i]]:=2*(f[i]*g[i]+g[i]);
        if sum[pos[i]] > maxS then maxS:=sum[pos[i]];
    end;
    count:=0;
    for i:=1 to n-1 do
        if sum[i] = maxS then inc(count);
    writeln(fo,maxS,' ',count);
    for i:=1 to n-1 do
        if sum[i] = maxS then write(fo,i,' ');
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.