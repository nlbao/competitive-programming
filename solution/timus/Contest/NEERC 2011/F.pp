const
    INPUT = 'F.in';
    OUTPUT = 'F.out';
    MAX_N = 50010;
    MAX_Q = 50010;

type
    pEdge = ^recEdge;
    recEdge = record
        x,y:longint;
        link:pEdge;
    end;

var
    fi,fo:text;
    n,q:longint;
    head:array[0..MAX_N] of pEdge;
    parent,nChild,a:array[0..MAX_N] of longint;
    s,sum,increase:array[0..MAX_N] of int64;
{---------------------------------------------------------------------------}
procedure   inc(var x,y:int64);
begin
    x:=x+y;
end;
{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint);
var
    p:pEdge;
begin
    new(p);
    with p^ do begin
        x:=u; y:=v;
        link:=head[u];
        head[u]:=p;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,u:longint;
begin
    readln(fi,n,q,s[0]);
    for i:=0 to n-1 do head[i]:=nil;
    for i:=1 to n-1 do begin
        readln(fi,u,s[i]);
        add_edge(u,i);
    end;
end;
{---------------------------------------------------------------------------}
procedure   DFS(u:longint);
var
    p:pEdge;
begin
    nChild[u]:=1;
    sum[u]:=s[u];
    increase[u]:=0;
    p:=head[u];
    while p <> nil do
        with p^ do begin
            if parent[y] = -1 then begin
                parent[y]:=u;
                DFS(y);
                nChild[u]:=nChild[u]+nChild[y];
                inc(sum[u],sum[y]);
            end;
            p:=link;
        end;
end;
{---------------------------------------------------------------------------}
procedure   down(u:longint);
var
    i:longint;
    p:pEdge;
    tmp:int64;
begin
    i:=0;
    while u > -1 do begin
        i:=i+1;
        a[i]:=u;
        u:=parent[u];
    end;
    while i > 0 do begin
        u:=a[i];
        p:=head[u];
        while p <> nil do
            with p^ do begin
                inc(increase[y],increase[u]);
                p:=link;
            end;
        inc(s[u],increase[u]);
        tmp:=nChild[u];
        tmp:=tmp*increase[u];
        inc(sum[u],tmp);
        increase[u]:=0;
        dec(i);
    end;
end;
{---------------------------------------------------------------------------}
procedure   up(u:longint;   value:int64);
begin
    u:=parent[u];
    while u > -1 do begin
        inc(sum[u],value);
        u:=parent[u];
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,x:longint;
    y,z:int64;
    ch:char;
begin
    parent[0]:=-MAX_N;
    for i:=1 to n-1 do parent[i]:=-1;
    DFS(0);
    while q > 0 do begin
        read(fi,ch);
        if ch = 'e' then begin
            for i:=1 to 7 do read(fi,ch);
            readln(fi,x,y,z);
            down(x);
            if s[x] < y then begin
                inc(s[x],z);
                inc(sum[x],z);
                up(x,z);
            end;
        end
        else begin
            for i:=1 to 9 do read(fi,ch);
            readln(fi,x,y,z);
            down(x);
            if sum[x]/nChild[x] < y then begin
                inc(increase[x],z);
                up(x,z*nChild[x]);
            end;
        end;
        dec(q);
    end;
    for i:=0 to n-1 do
        if head[i] = nil then down(i);
    for i:=0 to n-1 do writeln(fo,s[i]);
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