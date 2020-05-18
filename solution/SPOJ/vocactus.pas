{$M 16777216}
uses    math;

const   MAX_N = 100005;
        MAX_M = 100005;
        oo = 2000000000;

type    recEdge = record
            x,y:longint;
            w:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nE,s,t,root:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head,p,num,a,c:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;
    d:array[-MAX_M..MAX_M] of longint;
    f:array[0..MAX_N,0..1] of longint;


procedure   add_edge(u,v,ww:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        w:=ww;
        link:=head[x];
        head[x]:=nE;
    end;
    with e[-nE] do begin
        x:=v;   y:=u;
        w:=ww;
        link:=head[x];
        head[x]:=-nE;
    end;
end;

procedure   enter();
var i,u,v,w,c:longint;
begin
    read(fi,n,m,s,t);
    nE:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to m do begin
        read(fi,u,v,w);
        add_edge(u,v,w);
    end;
end;


procedure   dfs(u:longint);
var i:longint;
begin
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if d[i] = 0 then begin
            if (p[y] = -1) and (not ok[y]) then begin
                p[y]:=u;
                dfs(y);
            end;
            if (y <> root) and (y <> p[u]) and (ok[y]) then begin
                ok[u]:=true;
                d[i]:=1;
                d[-i]:=-1;
                inc(m); a[m]:=u;
                exit;
            end;
        end;
        i:=link;
    end;
end;

procedure   dfs_2(u:longint);
var i:longint;
begin
    num[u]:=1;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if d[i] = 1 then begin
            if p[y] = -1 then begin
                p[y]:=u;
                dfs_2(y);
            end;
            num[u]:=max(num[u],num[y]+1);
        end;
        i:=link;
    end;
    inc(c[num[u]]);
end;

procedure   init();
var i,j:longint;
begin
    for i:=-nE to nE do d[i]:=0;
    for i:=1 to n do begin
        p[i]:=-1;
        ok[i]:=false;
    end;
    p[s]:=0;
    ok[t]:=true;
    m:=0;   root:=s;
    dfs(s);

    if m = 0 then exit;

    j:=m;   m:=0;
    for i:=1 to n do p[i]:=-1;
    for i:=1 to j do num[i]:=a[i];
    for i:=j downto 1 do begin
        p[num[i]]:=0;
        root:=num[i];
        dfs(num[i]);
    end;


    for i:=1 to n do begin
        num[i]:=0;
        c[i]:=0;
        p[i]:=-1;
    end;
    num[t]:=1;
    dfs_2(s);

    m:=num[s];
    c[0]:=0;    c[m+1]:=0;
    for i:=1 to m+1 do c[i]:=c[i-1]+c[i];
    for i:=1 to n do
        if num[i] > 0 then begin
            a[c[num[i]]]:=i;
            dec(c[num[i]]);
        end;
    m:=c[m+1];
end;


function    solve():longint;
var i,j,k,u:longint;
begin
    if m = 0 then exit(-1);
    for i:=1 to m do
        for j:=0 to 1 do f[a[i]][j]:=oo;
    f[s][0]:=0;

    for k:=m downto 1 do begin
        u:=a[k];
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if d[i] = 1 then
                for j:=0 to 1 do
                    f[y][j]:=min(f[y][j], f[u][1-j]+w);
            i:=link;
        end;
    end;

    if f[t][0] >= oo then exit(-1);
    exit(f[t][0]);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'VOCACTUS.in');    reset(fi);
    assign(fo,'VOCACTUS.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    init();
    writeln(fo,solve());
    close(fo);
    close(fi);
end.