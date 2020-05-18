const
    INPUT = 'NKRacing.inp';
    OUTPUT = 'NKRacing.out';
    MAX_N = 10010;
    MAX_M = 100010;

type
    recEdge = record
        x,y:longint;
        w:longint;
    end;

var
    fi,fo:text;
    N,M:longint;
    e:array[0..MAX_M] of recEdge;
    parent:array[0..MAX_N] of longint;
    avail:array[0..MAX_M] of boolean;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,N,M);
    for i:=1 to M do
        readln(fi,e[i].x,e[i].y,e[i].w);
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var
    i,j,p:longint;
    tmp:recEdge;
begin
    i:=l;   j:=r;
    p:=e[(i+j) div 2].w;
    while i < j do begin
        while e[i].w > p do inc(i);
        while e[j].w < p do dec(j);
        if i <= j then begin
            tmp:=e[i]; e[i]:=e[j];  e[j]:=tmp;
            inc(i); dec(j);
        end;
    end;
    if l < j then quick_sort(l,j);
    if i < r then quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
function    get_root(u:longint):longint;    inline;
begin
    if parent[u] < 0 then exit(u)
    else begin
        parent[u]:=get_root(parent[u]);
        exit(parent[u]);
    end;
end;
{---------------------------------------------------------------------------}
procedure   union(r1,r2:longint);   inline;
begin
    if parent[r1] < parent[r2] then begin
        parent[r1]:=parent[r1]+parent[r2];
        parent[r2]:=r1;
    end
    else begin
        parent[r2]:=parent[r1]+parent[r2];
        parent[r1]:=r2;
    end;
end;
{---------------------------------------------------------------------------}
procedure   Kruskal;
var
    i,r1,r2:longint;
begin
    for i:=1 to M do avail[i]:=true;
    for i:=1 to N do parent[i]:=-1;
    for i:=1 to M do begin
        r1:=get_root(e[i].x);
        r2:=get_root(e[i].y);
        if r1 <> r2 then begin
            union(r1,r2);
            avail[i]:=false;
        end;
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,res:longint;
begin
    res:=0;
    for i:=1 to M do
        if avail[i] then
            inc(res,e[i].w);
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    quick_sort(1,M);
    Kruskal;
    solve;
    close(fo);
    close(fi);
end.