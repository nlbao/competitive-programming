uses    math;

const   MAX_N = 110;
        MAX_M = sqr(MAX_N) div 2;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,count:longint;
    head,num,low,p,nChild:array[0..MAX_N] of longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    ok:array[-MAX_M..MAX_M] of boolean;
    is_cut:array[0..MAX_N] of boolean;

procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u;   y:=v;
        link:=head[x];
        head[x]:=m;
    end;
    with e[-m] do begin
        x:=v;   y:=u;
        link:=head[x];
        head[x]:=-m;
    end;
end;

procedure   enter;
var i,j:longint;
begin
    m:=0;
    for i:=1 to n do head[i]:=0;
    read(fi,i);
    while i > 0 do begin
        while not eoln(fi) do begin
            read(fi,j);
            add_edge(i,j);
        end;
        read(fi,i);
    end;
end;

procedure   dfs(u:longint);
var i:longint;
begin
    inc(count);
    num[u]:=count;  low[u]:=n+100;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if ok[i] then begin
            ok[i]:=false;
            ok[-i]:=false;
            if p[y] = -1 then begin
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

procedure   solve;
var i,j,res:longint;
begin
    fillchar(ok, sizeof(ok), true);
    for i:=1 to n do begin
        p[i]:=-1;
        nChild[i]:=0;
        is_cut[i]:=false;
    end;
    count:=0;
    for i:=1 to n do
        if p[i] = -1 then begin
            p[i]:=0;
            dfs(i);
        end;
    res:=0;
    for i:=1 to n do
        if p[i] > 0 then begin
            j:=p[i];
            if low[i] >= num[j] then
                is_cut[j]:=is_cut[j] or (p[j] > 0) or (nChild[j] > 1);
        end;
    for i:=1 to n do res:=res+longint(is_cut[i]);
    writeln(fo,res);
end;

begin
    assign(fi,'315.in');    reset(fi);
    assign(fo,'315.out');   rewrite(fo);
    readln(fi,n);
    while n > 0 do begin
        enter;
        solve;
        readln(fi,n);
    end;
    close(fo);
    close(fi);
end.