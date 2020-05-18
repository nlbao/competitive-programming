const   MAX_N = 510;
        MAX_M = sqr(MAX_N) div 2;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nR:longint;
    head,deg:array[0..MAX_N] of longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    ok:array[-MAX_M..MAX_M] of boolean;
    r:array[0..2*MAX_M] of longint;

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
    fillchar(head, sizeof(head), 0);
    fillchar(deg, sizeof(deg), 0);
    for i:=1 to j do begin
        readln(fi,u,v);
        add_edge(u,v);
        inc(deg[u]);    inc(deg[v]);
    end;
end;


procedure   dfs(u:longint);
var i:longint;
begin
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if ok[i] then begin
            ok[i]:=false;
            ok[-i]:=false;
            dfs(y);
            //break;
        end;
        i:=link;
    end;
    inc(nR);    r[nR]:=u;
end;

procedure   solve;
var i,j,u,v:longint;
begin
    fillchar(ok, sizeof(ok), true);
    nR:=0;
    u:=0;   v:=0;
    for i:=1 to n do
        if deg[i] mod 2 = 1 then begin
            if u = 0 then u:=i
            else v:=i;
        end;
    if (u <> 0) then begin
        add_edge(u,v);
        dfs(u);
        j:=1;
    end
    else begin
        dfs(1);
        j:=0;
    end;
    for i:=nR-j downto 1 do write(fo,r[i],' ');
end;


begin
    assign(fi,'euler.in');      reset(fi);
    assign(fo,'euler.out');     rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
