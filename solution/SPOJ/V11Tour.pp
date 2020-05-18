uses    math;

const   MAX_N = 100010;
        MAX_M = 100010;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,root,count:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head,number,low,p,l:array[0..MAX_N] of longint;
    ok:array[-MAX_M..MAX_M] of boolean;
    check:boolean;

procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        link:=head[x];
        head[x]:=m;
    end;
    with e[-m] do begin
        x:=v; y:=u;
        link:=head[x];
        head[x]:=-m;
    end;
end;

procedure   enter;
var i,j,u,v:longint;
begin
    readln(fi,n,j);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        readln(fi,u,v);
        if u <> v then add_edge(u,v);
    end;
end;

procedure   dfs1(u:longint);
var i:longint;
begin
    inc(count);
    number[u]:=count;   low[u]:=count;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        ok[i]:=true;
        if y <> p[u] then
            if number[y] = 0 then begin
                p[y]:=u;
                dfs1(y);
                low[u]:=min(low[u],low[y]);
            end
            else low[u]:=min(low[u],number[y]);
        i:=link;
    end;
end;

procedure   dfs2(u:longint);
var i:longint;
begin
    inc(count);
    number[u]:=1;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if (ok[i]) and (y <> p[u]) then
            {if (y <> root) and (number[y] = 0) then begin
                p[y]:=u;
                l[y]:=l[u]+1;
                dfs2(y);
            end
            else
                if (y = root) and (l[u] mod 2 = 0) then check:=true;}
            if number[y] = 0 then begin
                p[y]:=u;
                l[y]:=l[u]+1;
                dfs2(y);
            end
            else
                if (l[u]-l[y]) mod 2 = 0 then check:=true;
        i:=link;
    end;
end;

procedure   solve;
var i,res:longint;
begin
    fillchar(number,sizeof(number),0);
    fillchar(p,sizeof(p),0);
    for i:=1 to n do
        if number[i] = 0 then begin
            count:=0;
            dfs1(i);
        end;
    for i:=-m to m do with e[i] do
        if low[y] > number[x] then begin
            ok[i]:=false;
            ok[-i]:=false;
        end;
    res:=0;
    fillchar(number,sizeof(number),0);
    fillchar(p,sizeof(p),0);
    for i:=1 to n do
        if number[i] = 0 then begin
            count:=0;   check:=false;
            root:=i;    l[i]:=0;
            dfs2(i);
            if check = true then res:=res+count;
        end;
    writeln(fo,res);
end;

begin
    assign(fi,'V11Tour.in');    reset(fi);
    assign(fo,'V11Tour.out');   rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
