const   INPUT = '29E.in';
        OUTPUT = '29E.out';
        MAX_N = 510;


type    pEdge = ^recEdge;
        recEdge = record
            x,y:longint;
            link:pEdge;
        end;
        recQueue = record
            x,y:longint;
            turn:longint;
        end;

var fi,fo:text;
    n,m,front,rear:longint;
    head:array[0..MAX_N] of pEdge;
    f,trace:array[0..MAX_N,0..MAX_N,0..1] of longint;
    q:array[0..sqr(2*MAX_N)] of recQueue;

{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint; var head_u:pEdge);
var p:pEdge;
begin
    new(p);
    with p^ do begin
        x:=u;   y:=v;
        link:=head_u;
        head_u:=p;
    end;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i,u,v:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do head[i]:=nil;
    for i:=1 to m do begin
        readln(fi,u,v);
        add_edge(u,v,head[u]);
        add_edge(v,u,head[v]);
    end;
end;
{---------------------------------------------------------------------------}
procedure   push(u,v,t:longint);
begin
    inc(rear);
    with q[rear] do begin
        x:=u;   y:=v;
        turn:=t;
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,k,u,v,t:longint;
    p:pEdge;
begin
    for i:=1 to n do
        for j:=1 to n do
            for k:=0 to 1 do begin
                f[i][j][k]:=0;
                trace[i][j][k]:=-1;
            end;
    trace[1][n][0]:=0;
    front:=1;   rear:=0;
    push(1,n,0);
    while (front <= rear) and (trace[n][1][0] = -1) do begin
        with q[front] do begin
            u:=x;   v:=y;   t:=turn;
        end;
        if t = 0 then begin
            p:=head[u];
            while p <> nil do
                with p^ do begin
                    if trace[y][v][1] = -1 then begin
                        f[y][v][1]:=f[u][v][0]+1;
                        trace[y][v][1]:=front;
                        push(y,v,1);
                    end;
                    p:=link;
                end;
        end;
        if t = 1 then begin
            p:=head[v];
            while p <> nil do
                with p^ do begin
                    if (y <> u) and (trace[u][y][0] = -1) then begin
                        f[u][y][0]:=f[u][v][1];
                        trace[u][y][0]:=front;
                        push(u,y,0);
                    end;
                    p:=link;
                end;
        end;
        inc(front);
    end;
end;
{---------------------------------------------------------------------------}
procedure   print_result;
var i,j:longint;
    res:array[0..1,0..MAX_N] of longint;
begin
    if f[n][1][0] = 0 then begin
        writeln(fo,-1);
        exit;
    end;
    writeln(fo,f[n][1][0]);
    res[0][1]:=n;   res[1][1]:=1;
    i:=1;   j:=trace[n][1][0];
    while j > 0 do
        with q[j] do begin
            if turn = 0 then begin
                inc(i);
                res[0][i]:=x;
                res[1][i]:=y;
            end;
            j:=trace[x][y][turn];
        end;
    for j:=i downto 1 do write(fo,res[0][j],' ');
    writeln(fo);
    for j:=i downto 1 do write(fo,res[1][j],' ');
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(Fo);
    enter;
    solve;
    print_result;
    close(fo);
    close(fi);
end.
