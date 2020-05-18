const
    INPUT = 'FWater.inp';
    OUTPUT = 'FWater.out';
    MAX_N = 300;
    MAX_M = sqr(MAX_N+1) div 2;

type
    recE = record
        u,v,w:longint;
    end;

var
    fi,fo:text;
    N,M:longint;
    E:array[1..MAX_M] of recE;
    parent:array[1..MAX_N+1] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i,j:longint;
    P:array[1..MAX_N+1,1..MAX_N+1] of longint;
begin
    read(fi,N);
    for i:=1 to N do begin
        read(fi,j);
        P[i,N+1]:=j;
    end;
    for i:=1 to N do
        for j:=1 to N do read(fi,P[i,j]);
    inc(N);
    M:=0;
    for i:=1 to N-1 do
        for j:=i+1 to N do begin
            inc(M);
            E[M].u:=i;  E[M].v:=j;  E[M].w:=P[i,j];
        end;
end;
{---------------------------------------------------------------------------}
procedure   Quick_sort(l,r:longint);
var
    i,j,p:longint;
    tmp:recE;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=E[(i+j) div 2].w;
    repeat
        while E[i].w < p do inc(i);
        while E[j].w > p do dec(j);
        if i <= j then begin
            tmp:=E[i]; E[i]:=E[j];  E[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    Quick_sort(l,j);    Quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
function    GetRoot(u:longint):longint;
begin
    if parent[u] < 0 then exit(u)
    else begin
        parent[u]:=GetRoot(parent[u]);
        exit(parent[u]);
    end;
end;
{---------------------------------------------------------------------------}
procedure   Union(r1,r2:longint);
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
    i,r1,r2,Res:longint;
begin
    Res:=0;
    for i:=1 to N do parent[i]:=-1;
    for i:=1 to M do begin
        r1:=GetRoot(E[i].u);    r2:=GetRoot(E[i].v);
        if r1 <> r2 then begin
            Union(r1,r2);
            Res:=Res+E[i].w;
        end;
    end;
    writeln(fo,Res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    Quick_sort(1,M);
    Kruskal;
    close(fo);
    close(fi);
end.

