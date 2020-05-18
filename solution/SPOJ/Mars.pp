const   MAX_H = 60;
        MAX_W = 60;
        MAX_N = 2510;
        MAX_INT = 1000000000;
        dx:array[1..4] of longint = (0,0,+1,-1);
        dy:array[1..4] of longint = (+1,-1,0,0);

type    recPoint = record
            x,y:longint;
        end;
        pEdge = ^recEdge;
        recEdge = record
            x,y:longint;
            c:longint;
            link:pEdge;
        end;

var fi,fo:text;
    h,w,k,n,res:longint;
    a,id:array[0..MAX_H,0..MAX_W] of longint;
    b:array[0..MAX_N] of recPoint;
    head:array[0..MAX_N] of pEdge;
    l:array[0..MAX_N,0..MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);   end;

procedure   enter;
var i,j:longint;
    ch:char;
begin
    readln(fi,h,w,k);
    fillchar(id,sizeof(id),0);
    n:=0;
    for i:=1 to h do begin
        for j:=1 to w do begin
            read(fi,ch);
            a[i][j]:=ord(ch)-ord('0');
            inc(n); id[i][j]:=n;
            b[n].x:=i;  b[n].y:=j;
        end;
        readln(fi);
    end;
end;

procedure   add_edge(u,v,c0:longint);
var p:pEdge;
begin
    if (u < 1) or (v < 1) then exit;
    new(p);
    with p^ do begin
        x:=u;   y:=v;
        c:=c0;
        link:=head[x];
        head[x]:=p;
    end;
end;

procedure   init;
var i,j,t,x,y:longint;
begin
    for i:=1 to n do head[i]:=nil;
    for i:=1 to h do
        for j:=1 to w do
            for t:=1 to 4 do begin
                x:=i+dx[t];  y:=j+dy[t];
                add_edge(id[i][j],id[x][y],a[x][y]);
            end;
end;

procedure   BFS(s:longint);
var i,j,u:longint;
    p:pEdge;

procedure   add(u,i:longint);
begin
    inc(l[i][0]);   l[i][l[i][0]]:=u;
    avail[u]:=false;
end;

begin
    if (k = 0) and (a[b[s].x][b[s].y] = 1) then exit;
    for i:=1 to n do avail[i]:=true;
    for i:=0 to k do l[i][0]:=0;
    add(s,0);
    for i:=0 to k do begin
        j:=0;
        while j < l[i][0] do begin
            inc(j);
            u:=l[i][j];
            res:=max(res,sqr(b[u].x-b[s].x)+sqr(b[u].y-b[s].y));
            p:=head[u];
            while p <> nil do with p^ do begin
                if (avail[y]) and (c = 0) then add(y,i);
                p:=link;
            end;
        end;
        if i+a[b[s].x][b[s].y] = k then exit;
        j:=0;
        while j < l[i][0] do begin
            inc(j);
            u:=l[i][j];
            p:=head[u];
            while p <> nil do with p^ do begin
                if (avail[y]) and (c = 1) then add(y,i+1);
                p:=link;
            end;
        end;
    end;
end;

procedure   solve;
var i:longint;
begin
    res:=0;
    for i:=1 to n do BFS(i);
    writeln(fo,res);
end;

begin
    assign(fi,'Mars.in');  reset(fi);
    assign(fo,'Mars.out');  rewrite(fo);
    enter;
    init;
    solve;
    close(fo);
    close(fi);
end.