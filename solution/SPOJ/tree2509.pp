uses    math;

const   MAX_N = 510;
        MAX_M = sqr(MAX_N) div 2;
        oo = 1000000000;

type    recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,maxH:longint;
    head,p:array[0..MAX_N] of longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    ok:array[-MAX_M..MAX_M] of boolean;
    check:boolean;
    a:array[0..MAX_N,0..MAX_N] of longint;

procedure   add_edge(u,v:longint);
begin
    inc(a[u][v]);
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
    fillchar(head, sizeof(head), 0);
    fillchar(a, sizeof(a), 0);
    for i:=1 to j do begin
        readln(fi,u,v);
        add_edge(u,v);
        add_edge(v,u);
    end;
end;

procedure   dfs(u,h:longint);
var v:longint;
begin
    if not check then exit;
    maxH:=max(maxH,h);
    for v:=1 to n do
        if a[u][v] > 0 then begin
            if p[v] = 0 then begin
                p[v]:=u;
                dec(a[u][v]);   dec(a[v][u]);
                dfs(v,h+1);
            end
            else begin
                check:=false;
                exit;
            end;
        end;
end;

procedure   solve;
var i:longint;
begin
    fillchar(p, sizeof(p), 0);
    check:=true;
    maxH:=0;
    p[1]:=n+10;
    dfs(1,0);
    for i:=1 to n do
        if p[i] = 0 then check:=false;
    if not check then writeln(fo,0)
    else begin
        writeln(fo,1);
        writeln(fo,maxH);
    end;
end;


begin
    assign(fi,'tree2509.in');      reset(fi);
    assign(fo,'tree2509.out');     rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
