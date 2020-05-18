const   MAX_N = 30010;
        MAX_M = 100010;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,c,q:longint;
    e:array[0..2*MAX_M] of recEdge;
    head:array[0..MAX_N] of longint;
    ok,avail:array[0..MAX_N] of boolean;

procedure   add_edge(u,v:longint);
begin
    if u = v then exit;
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        link:=head[x];
        head[x]:=m;
    end;
end;

procedure   enter;
var i,j,k,u,v:longint;
begin
    readln(fi,n,j,q);
    m:=0;
    fillchar(head,sizeof(head),0);
    for i:=1 to j do begin
        readln(fi,u,v);
        add_edge(u,v);
        add_edge(v,u);
    end;
end;

procedure   dfs(u:longint);
var i:longint;
begin
    if not ok[u] then exit;
    inc(c);
    avail[u]:=false;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if avail[y] then dfs(y);
        i:=link;
    end;
end;

procedure   solve;
var i,u:longint;
begin
    fillchar(ok,sizeof(ok),true);
    while q > 0 do begin
        readln(fi,u);
        ok[u]:=false;
        i:=head[u];
        while i <> 0 do with e[i] do begin
            ok[y]:=false;
            i:=link;
        end;
        dec(q);
    end;
    c:=0;
    fillchar(avail,sizeof(avail),true);
    dfs(1);
    writeln(fo,n-c);
end;

begin
    assign(fi,'damage.in');     reset(fi);
    assign(fo,'damage.out');    rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.