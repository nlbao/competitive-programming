const   INPUT = 'ADS.in';
        OUTPUT = 'ADS.out';
        MAX_N = 2010;
        MAX_M = 5010;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m:longint;
    e:array[0..2*MAX_M] of recEdge;
    head:array[0..MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;

procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u;   y:=v;
        link:=head[x];
        head[x]:=m;
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
        add_edge(v,u);
    end;
end;

procedure   DFS(u:longint);
var i:longint;
begin
    avail[u]:=false;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if avail[y] then DFS(y);
        i:=link;
    end;
end;

procedure   solve;
var i,c:longint;
begin
    c:=0;
    for i:=1 to n do avail[i]:=true;
    for i:=1 to n do
        if avail[i] then begin
            inc(c);
            DFS(i);
        end;
    writeln(fo,(m div 2)-n+c);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.