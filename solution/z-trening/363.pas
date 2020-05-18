{$M 16777216}
uses    math;

const   MAX_N = 100005;
        MAX_E = MAX_N;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nE:longint;
    e:array[0..MAX_E] of recEdge;
    head:array[0..MAX_N] of longint;
    v:array[0..MAX_N] of ll;
    f:array[0..MAX_N,0..1] of ll;


procedure   add_edge(u,v:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        link:=head[x];
        head[x]:=nE;
    end;
end;


procedure   enter;
var i,u:longint;
begin
    read(fi,n);
    nE:=0;
    for i:=0 to n do head[i]:=0;

    read(fi,v[1]);
    for i:=2 to n do begin
        read(fi,u,v[i]);
        add_edge(u+1,i);
    end;
end;


procedure   dfs(u:longint);
var i,j:longint;
begin
    f[u][0]:=0;
    f[u][1]:=v[u];

    i:=head[u];
    while i <> 0 do with e[i] do begin
        dfs(y);
        f[u][0]:=f[u][0] + max(f[y][0],f[y][1]);
        f[u][1]:=f[u][1] + f[y][0];
        i:=link;
    end;
end;


procedure   solve;
var i:longint;
begin
    dfs(1);
    writeln(fo,max(f[1][0],f[1][1]));
end;



begin
{$IFDEF WINDOWS}
    assign(fi,'363.in');    reset(fi);
    assign(fo,'363.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.