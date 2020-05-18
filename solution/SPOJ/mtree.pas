{$R+, $I+}
{$M 16777216}

uses    math;

const   MAX_N = 100010;
        MAX_E = MAX_N;
        MODULE = 1000000007;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            w:ll;
            link:longint;
        end;

var fi,fo:text;
    n,nE:longint;
    e:array[0..2*MAX_E] of recEdge;
    head:array[0..MAX_N] of longint;
    f:array[0..MAX_N] of ll;
    ok:array[0..MAX_N] of boolean;
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


procedure   enter();
var i,u,v,w:longint;
begin
    nE:=0;
    read(fi,n);
    for i:=1 to n do head[i]:=0;
    for i:=1 to n-1 do begin
        read(fi,u,v,w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    end;
end;


procedure   dfs(u:longint);
var i:longint;
    t:ll;
begin
    ok[u]:=false;
    f[u]:=0;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if ok[y] then begin
            dfs(y);
            t:=((f[y]+1)*w) mod MODULE;
            res:=(res + (f[u]*t) mod MODULE) mod MODULE;
            f[u]:=(f[u] + t) mod MODULE;
            res:=(res + t) mod MODULE;
        end;
        i:=link;
    end;
end;


procedure   solve();
var i:longint;
begin
    res:=0;
    for i:=1 to n do ok[i]:=true;
    dfs(1);
    writeln(fo,res);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'mtree.in');    reset(fi);
    assign(fo,'mtree.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.

