const   INPUT = 'Number.inp';
        OUTPUT = 'Number.out';
        MAX_N = 10010;
        MAX_M = 10010;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,p,count,top,nC:longint;
    e:array[0..MAX_M] of recEdge;
    head,number,low,stack,c:array[0..MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;

function    min(x,y:longint):longint;   begin   if x < y then exit(x)   else exit(y);   end;

procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u;   y:=v;
        link:=head[u];
        head[u]:=m;
    end;
end;

procedure   enter;
var i,j,u,v:longint;
begin
    readln(fi,n,j,p);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        readln(fi,u,v);
        add_edge(u,v);
    end;
end;

procedure   DFS(u:longint);
var i:longint;
begin
    inc(count);
    number[u]:=count;   low[u]:=count;
    inc(top);   stack[top]:=u;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if avail[y] then
            if number[y] = -1 then begin
                DFS(y);
                low[u]:=min(low[u],low[y]);
            end
            else low[u]:=min(low[u],number[y]);
        i:=link;
    end;
    avail[u]:=false;
    if low[u] = number[u] then begin
        inc(nC);
        repeat
            i:=stack[top];  dec(top);
            c[i]:=nC;
        until i = u;
    end;
end;



procedure   Tarjan;
var i:longint;
begin
    count:=0;   top:=0; nC:=0;
    for i:=1 to n do begin
        avail[i]:=true;
        number[i]:=-1;
    end;
    c[p]:=-1;
    for i:=1 to n do
        if avail[i] then DFS(i);
end;

procedure   solve;
var i,res:longint;
    degO:array[0..MAX_N] of longint;
begin
    for i:=1 to nC do degO[i]:=0;
    for i:=1 to m do with e[i] do
        if c[x] <> c[y] then inc(degO[c[x]]);
    res:=0;
    for i:=1 to nC do
        if (i <> c[p]) and (degO[i] = 0) then inc(res);
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    Tarjan;
    solve;
    close(fo);
    close(fi);
end.
