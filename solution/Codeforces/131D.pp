const   INPUT = '131D.in';
        OUTPUT = '131D.out';
        MAX_N = 3010;
        MAX_M = 3010;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,count,top,front,rear:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,parent,number,low,stack,q,res:array[0..MAX_N] of longint;
    avail,cycle:array[0..MAX_N] of boolean;

function    min(x,y:longint):longint;   begin   if x < y then exit(x)   else exit(y);   end;

procedure   push(x:longint);    begin   inc(rear);  q[rear]:=x; end;

function    pop:longint;    begin   pop:=q[front];  inc(front); end;

procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        link:=head[u];
        head[u]:=m;
    end;
end;

procedure   enter;
var i,u,v:longint;
begin
    readln(fi,n);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to n do begin
        readln(fi,u,v);
        add_edge(u,v);
        add_edge(v,u);
    end;
end;

procedure   DFS(u:longint);
var i:longint;
begin
    inc(top);   stack[top]:=u;
    inc(count);
    number[u]:=count;   low[u]:=count;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if (avail[y]) and (y <> parent[u]) then
            if (number[y] = -1) then begin
                parent[y]:=u;
                DFS(y);
                low[u]:=min(low[u],low[y]);
            end
            else low[u]:=min(low[u],number[y]);
        i:=link;
    end;
    avail[u]:=false;
    if low[u] = number[u] then
        if (stack[top] = u) then dec(top)
        else
            repeat
                i:=stack[top];  dec(top);
                cycle[i]:=true;
            until i = u;
end;

procedure   solve;
var i,u:longint;
begin
    for i:=1 to n do begin
        avail[i]:=true;
        parent[i]:=-1;  number[i]:=-1;
        cycle[i]:=false;
        res[i]:=-1;
    end;
    top:=0; count:=0;   parent[1]:=0;
    DFS(1);

    front:=1;   rear:=0;
    for i:=1 to n do
        if cycle[i] then begin
            push(i);
            res[i]:=0;
        end;
    repeat
        u:=pop;
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if res[y] = -1 then begin
                push(y);
                res[y]:=res[u]+1;
            end;
            i:=link;
        end;
    until front > rear;
    for i:=1 to n do write(fo,res[i],' ');
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.