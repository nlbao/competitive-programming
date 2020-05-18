const   MAX_N = 222;
        MAX_M = sqr(MAX_N);

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,nE,nP:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head,p:array[0..MAX_N] of longint;
    avail:array[-MAX_M..MAX_M] of boolean;


procedure   add_edge(u,v:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        link:=head[x];
        head[x]:=nE;
    end;
    with e[-nE] do begin
        x:=v;   y:=u;
        link:=head[x];
        head[x]:=-nE;
    end;
end;


procedure   enter();
var i,m,u,v:longint;
begin
    nE:=0;
    read(fi,n,m);
    for i:=1 to n do read(fi,u);
    for i:=1 to m do begin
        read(fi,u,v);
        add_edge(u,v);
    end;
end;

procedure   dfs(u:longint);
var i:longint;
begin
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if avail[i] then begin
            avail[i]:=false;
            avail[-i]:=false;
            dfs(y);
        end;
        i:=link;
    end;
    inc(nP);
    p[nP]:=u;
end;


procedure   solve();
var i:longint;
begin
    fillchar(avail,sizeof(avail),true);
    nP:=0;
    dfs(1);
    writeln(fo,nP-1);
    for i:=1 to nP do write(fo,p[i],' ');
end;


begin
    assign(fi,'nkpos.in');  reset(fi);
    assign(fo,'nkpos.out'); rewrite(fo);
    enter();
    solve();
    close(fo);
    close(fi);
end.