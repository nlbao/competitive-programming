const
    INPUT = '29C.inp';
    OUTPUT = '29C.out';
    MAX_N = 100010;
    MAX_M = MAX_N;

type
    recEdge = record
        x,y:longint;
        avail:boolean;
        link:longint;
    end;

var
    fi,fo:text;
    N,M:longint;
    e0,e:array[-MAX_M..MAX_M] of recEdge;
    a,head,parent,d:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint);
begin
    inc(M);
    with e[M] do begin
        x:=u;   y:=v;
        avail:=true;
        link:=head[u];
        head[u]:=M;
    end;
    with e[-M] do begin
        x:=v;   y:=u;
        avail:=true;
        link:=head[v];
        head[v]:=-M;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,M);
    j:=0;
    for i:=1 to M do
        with e0[i] do begin
            readln(fi,x,y);
            inc(j); a[j]:=x;
            inc(j); a[j]:=y;
        end;
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var
    i,j,p,tmp:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=a[(i+j) div 2];
    repeat
        while a[i] < p do inc(i);
        while a[j] > p do dec(j);
        if i <= j then begin
            tmp:=a[i];
            a[i]:=a[j];
            a[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
function    find(x:longint):longint;
var
    l,r,mid:longint;
begin
    l:=1;   r:=N;
    while l <= r do begin
        mid:=(l+r) div 2;
        if a[mid] = x then exit(mid)
        else
            if a[mid] > x then r:=mid-1
            else l:=mid+1;
    end;
end;
{---------------------------------------------------------------------------}
procedure   create_graph;
var
    i,j:longint;
begin
    quick_sort(1,2*M);
    a[0]:=-1;
    N:=0;
    for i:=1 to 2*M do begin
        if a[i] <> a[i-1] then begin
            inc(N);
            a[N]:=a[i];
        end;
    end;
    j:=M;   M:=0;
    for i:=1 to N do head[i]:=0;
    for i:=1 to j do
        with e0[i] do
            add_edge(find(x),find(y));

end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var
    i:longint;
begin
    i:=head[u];
    while i <> 0 do
        with e[i] do begin
            if parent[y] = -1 then begin
                parent[y]:=u;
                d[y]:=d[u]+1;
                DFS(y);
            end;
            i:=link;
        end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,u,tmp:longint;
begin
    for i:=1 to N do parent[i]:=-1;
    parent[1]:=0; d[1]:=0;
    DFS(1);
    tmp:=0;
    for i:=1 to N do
        if d[i] > tmp then begin
            tmp:=d[i];
            u:=i;
        end;

    for i:=1 to N do parent[i]:=-1;
    parent[u]:=0; d[u]:=0;
    DFS(u);
    tmp:=0;
    for i:=1 to N do
        if d[i] > tmp then begin
            tmp:=d[i];
            u:=i;
        end;
    while u <> 0 do begin
        write(fo,a[u],' ');
        u:=parent[u];
    end;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    create_graph;
    solve;
    close(fo);
    close(fi);
end.