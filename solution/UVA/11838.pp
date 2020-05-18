const   MAX_N = 2010;
        MAX_M = sqr(MAX_N) div 2;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nE,count,nC,top:longint;
    head,num,low,stack:array[0..MAX_N] of longint;
    e:array[0..2*MAX_M] of recEdge;
    ok:array[0..MAX_N] of boolean;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        link:=head[x];
        head[x]:=m;
    end;
end;

procedure   enter;
var i,u,v,t:longint;
begin
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to nE do begin
        readln(fi,u,v,t);
        add_edge(u,v);
        if t = 2 then add_edge(v,u);
    end;
end;

procedure   push(u:longint);    begin   inc(top);   stack[top]:=u;  end;

procedure   pop(var u:longint); begin   u:=stack[top];  dec(top);   end;

procedure   dfs(u:longint);
var i:longint;
begin
    inc(count);
    num[u]:=count;  low[u]:=count;
    push(u);
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if ok[y] then
            if num[y] < 0 then begin
                dfs(y);
                low[u]:=min(low[u],low[y]);
            end
            else low[u]:=min(low[u],num[y]);
        i:=link;
    end;
    if low[u] = num[u] then begin
        inc(nC);
        repeat
            pop(i);
            ok[i]:=false;
        until i = u;
    end;
end;

procedure   solve;
var i,j:longint;
begin
    for i:=1 to n do begin
        ok[i]:=true;
        num[i]:=-1;
    end;
    nC:=0;  count:=0;
    for i:=1 to n do
        if ok[i] then begin
            top:=0;
            dfs(i);
        end;
    if nC > 1 then nC:=0;
    writeln(fo,nC);
end;

begin
    assign(fi,'11838.in');  reset(fi);
    assign(fo,'11838.out'); rewrite(fo);
    readln(fi,n,nE);
    while n > 0 do begin
        enter;
        solve;
        readln(fi,n,nE);
    end;
    close(fo);
    close(fi);
end.