{$M 16777216}
uses    math;

const   MAX_N = 50004;
        MAX_E = MAX_N;
        MAX_M = 102;
        oo = 1000000000;
        MODULE = 321555123;

type    ll = int64;
        recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nE:longint;
    e:array[0..2*MAX_E] of recEdge;
    head:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;
    f:array[0..MAX_N,0..MAX_M] of ll;
    res:ll;


procedure   add_edge(u,v,ww:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        w:=ww;
        link:=head[x];
        head[x]:=nE;
    end;
end;


procedure   enter;
var i,u,v,w:longint;
begin
    read(fi,n,m);
    nE:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to n-1 do begin
        read(fi,u,v,w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    end;
end;


function    mmod(x:ll):ll;  begin   exit(x mod MODULE); end;


procedure   dfs(u:longint);
var i,j:longint;
begin
    ok[u]:=false;
    for i:=0 to m do f[u][i]:=0;
    f[u][0]:=1;

    i:=head[u];
    while i <> 0 do with e[i] do begin
        if ok[y] then begin
            dfs(y);
            for j:=0 to m-w do
                res:=mmod(res + mmod(f[y][j]*f[u][m-(j+w)]));
            for j:=w to m do
                f[u][j]:=mmod(f[u][j] + f[y][j-w]);
        end;
        i:=link;
    end;
end;



procedure   solve;
var i:longint;
begin
    for i:=1 to n do ok[i]:=true;
    res:=0;
    dfs(1);
    writeln(fo,res);
end;



begin
{$IFDEF WINDOWS}
    assign(fi,'310.in');    reset(fi);
    assign(fo,'310.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.