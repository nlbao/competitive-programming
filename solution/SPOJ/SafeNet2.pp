const   MAX_N = 30010;
        MAX_M = 100010;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,count,top,res:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head,number,low:array[0..MAX_N] of longint;
    avail:array[-MAX_M..MAX_M] of boolean;
    x,y:array[0..2*MAX_M] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

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
var i,j,u,v:longint;
begin
    readln(fi,n,j);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        readln(fi,u,v);
        add_edge(u,v);
    end;
end;

procedure   push(u,v:longint);
begin
    inc(top);
    x[top]:=u;  y[top]:=v;
end;

procedure   pop(var u,v:longint);
begin
    u:=x[top];  v:=y[top];
    dec(top);
end;

procedure   DFS(u:longint);
var i,c,p,q:longint;
begin
    inc(count);
    number[u]:=count;   low[u]:=n+1;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if avail[i] then begin
            avail[-i]:=false;
            if number[y] > -1 then low[u]:=min(low[u],number[y])
            else begin
                push(u,y);
                DFS(y);
                low[u]:=min(low[u],low[y]);
                if low[y] >= number[u] then begin
                    c:=1;
                    repeat
                        pop(p,q);
                        inc(c);
                    until (p = u) and (q = y);
                    res:=max(res,c);
                end;
            end;
        end;
        i:=link;
    end;
end;

procedure   solve;
var i:longint;
begin
    if n > 0 then res:=1
    else res:=0;
    for i:=1 to n do number[i]:=-1;
    for i:=-m to m do avail[i]:=true;
    for i:=1 to n do
        if number[i] = -1 then begin
            count:=0;   top:=0;
            DFS(i);
        end;
    if (res < 2) and (m > 0) then res:=2;
    writeln(fo,res);
end;


begin
    assign(fi,'SafeNet2.in');   reset(fi);
    assign(fo,'SafeNet2.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.