const
    INPUT = '59E.inp';
    OUTPUT = '59E.out';
    MAX_N = 3010;
    MAX_M = 20010;
    MAX_K = 100010;
    MAX_INT = 10000000;

type
    recEdge = record
        x,y:longint;
        link:longint;
    end;
    recEdge2 = record
        x,y:longint;
    end;
    arrQ = array[0..MAX_K] of longint;
    recQ = record
        x,y,z:arrQ;
    end;

var
    fi,fo:text;
    N,M,K,front,rear:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head:array[0..MAX_N] of longint;
    Q:recQ;
    queue:array[0..2*MAX_M] of recEdge2;
    d,trace:array[0..MAX_N,0..MAX_N] of longint;


{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint);
begin
    inc(M);
    with e[M] do begin
        x:=u;   y:=v;
        link:=head[u];
        head[u]:=M;
    end;
    with e[-M] do begin
        x:=v;   y:=u;
        link:=head[v];
        head[v]:=-M;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j,u,v:longint;
begin
    readln(fi,N,j,K);
    M:=0;
    for i:=1 to N do head[i]:=0;
    for i:=1 to j do begin
        readln(fi,u,v);
        add_edge(u,v);
    end;
    for i:=1 to K do
        with Q do readln(fi,x[i],y[i],z[i]);
end;
{---------------------------------------------------------------------------}
procedure   swap(var x,y:longint);
var
    tmp:longint;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var
    i,j,p1,p2,p3:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    with Q do begin
        p1:=x[(i+j) div 2];
        p2:=y[(i+j) div 2];
        p3:=z[(i+j) div 2];
        repeat
            while (x[i] < p1) or ((x[i] = p1) and (y[i] < p2)) or ((x[i] = p1) and (y[i] = p2) and (z[i] < p3)) do inc(i);
            while (x[j] > p1) or ((x[j] = p1) and (y[j] > p2)) or ((x[j] = p1) and (y[j] = p2) and (z[j] > p3)) do dec(j);
            if i <= j then begin
                swap(x[i],x[j]);
                swap(y[i],y[j]);
                swap(z[i],z[j]);
                inc(i); dec(j);
            end;
        until i >= j;
    end;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
function    check(u,v,t:longint):boolean;
var
    l,r,mid:longint;
begin
    if (u = v) and (u = t) then exit(true);
    with Q do begin
        l:=1;   r:=K;
        while l <= r do begin
            mid:=(l+r) div 2;
            if (x[mid] = u) and (y[mid] = v) and (z[mid] = t) then exit(false);
            if (x[mid] > u) or ((x[mid] = u) and (y[mid] > v)) or ((x[mid] = u) and (y[mid] = v) and (z[mid] > t)) then r:=mid-1
            else l:=mid+1;
        end;
    end;
    if l > r then exit(true)
    else exit(false);
end;
{---------------------------------------------------------------------------}
procedure   push(u,v:longint);
begin
    inc(rear);
    with queue[rear] do begin
        x:=u;
        y:=v;
    end;
end;
{---------------------------------------------------------------------------}
procedure   pop(var u,v:longint);
begin
    with queue[front] do begin
        u:=x;
        v:=y;
    end;
    inc(front);
end;
{---------------------------------------------------------------------------}
function    BFS(s,t:longint):longint;
var
    i,j,z,u:longint;
begin
    for i:=1 to N do
        for j:=1 to N do begin
            d[i,j]:=MAX_INT;
            trace[i,j]:=-1;
        end;
    d[s,s]:=0;
    front:=1;   rear:=0;
    push(s,s);
    repeat
        pop(z,u);
        i:=head[u];
        while i <> 0 do
            with e[i] do begin
                if (d[z,u]+1 < d[u,y]) and (check(z,u,y) = true) then begin
                    d[u,y]:=d[z,u]+1;
                    trace[u,y]:=z;
                    push(u,y);
                end;
                i:=link;
            end;
    until (u = T) or (front > rear);
    if u = T then exit(z)
    else exit(-1);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,tmp:longint;
    res:array[0..MAX_N] of longint;
begin
    i:=BFS(1,N);
    if i = -1 then begin
        writeln(fo,-1);
        exit;
    end;
    writeln(fo,d[i,N]);
    res[0]:=1;  res[1]:=N;
    j:=N;
    repeat
        tmp:=i;
        i:=trace[i,j];
        j:=tmp;
        inc(res[0]);
        res[res[0]]:=j;
    until i = -1;
    for i:=res[0]-1 downto 1 do write(fo,res[i],' ');
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    quick_sort(1,K);
    solve;
    close(fo);
    close(fi);
end.