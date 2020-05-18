const   INPUT = '77C.in';
        OUTPUT = '77C.out';
        MAX_N = 100010;
        MAX_M = MAX_N;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,s,nT:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,parent:array[0..MAX_N] of longint;
    k,c,f,t:array[0..MAX_N] of int64;

{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        link:=head[u];
        head[u]:=m;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i,u,v:longint;
begin
    readln(fi,n);
    for i:=1 to n do begin
        read(fi,k[i]);
        c[i]:=k[i]-1;
    end;
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to n-1 do begin
        readln(fi,u,v);
        add_edge(u,v);
        add_edge(v,u);
    end;
    readln(fi,s);
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var i,j:longint;
    p,tmp:int64;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=f[t[(i+j) div 2]];
    repeat
        while f[t[i]] > p do inc(i);
        while f[t[j]] < p do dec(j);
        if i <= j then begin
            tmp:=t[i]; t[i]:=t[j];  t[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var i,j,limit:longint;
begin
    i:=head[u];
    while i <> 0 do
        with e[i] do begin
            if parent[y] = -1 then begin
                parent[y]:=u;
                DFS(y);
            end;
            i:=link;
        end;
    nT:=0;
    i:=head[u];
    while i <> 0 do
        with e[i] do begin
            if (parent[y] = u) and (f[y] > 0) then begin
                inc(nT);
                t[nT]:=y;
            end;
            i:=link;
        end;
    quick_sort(1,nT);
    limit:=min(c[u],nT);
    f[u]:=limit+1;
    for i:=1 to limit do inc(f[u],f[t[i]]);
    c[u]:=c[u]-limit;
    for i:=1 to limit do begin
        if c[u] <= 0 then break;
        if c[t[i]] > 0 then begin
            j:=min(c[u],c[t[i]]);
            inc(f[u],2*j);
            dec(c[u],j);
        end
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i:longint;
begin
    for i:=1 to n do parent[i]:=-1;
    parent[s]:=0;
    inc(c[s]);
    DFS(s);
    writeln(fo,f[s]-1);
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