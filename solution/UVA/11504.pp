const   MAX_N = 100010;
        MAX_M = 100010;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    nTest,n,m,count,nC,top:longint;
    head,num,low,stack,c,deg:array[0..MAX_N] of longint;
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
var i,j,u,v:longint;
begin
    readln(fi,n,j);
    m:=0;
    fillchar(head, sizeof(head), 0);
    for i:=1 to j do begin
        readln(fi,u,v);
        add_edge(u,v);
    end;
end;

procedure   push(u:longint);    begin   inc(top);   stack[top]:=u;  end;

procedure   pop(var u:longint); begin   u:=stack[top];  dec(top);   end;

procedure   dfs(u:longint);
var i:longint;
begin
    push(u);
    inc(count);
    num[u]:=count;  low[u]:=count;
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
            c[i]:=nC;
            ok[i]:=false;
        until i = u;
    end;
end;

procedure   solve;
var i,res:longint;
begin
    for i:=1 to n+1 do begin
        ok[i]:=true;
        num[i]:=-1;
        deg[i]:=0;
    end;
    nC:=0;  count:=0;
    for i:=1 to n do
        if ok[i] then begin
            top:=0;
            dfs(i);
        end;
    for i:=1 to m do
        with e[i] do
            if c[x] <> c[y] then inc(deg[c[y]]);
    res:=0;
    for i:=1 to nC do
        if deg[i] = 0 then inc(res);
    writeln(fo,res);
end;

begin
    assign(fi,'11504.in');  reset(fi);
    assign(fo,'11504.out'); rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
