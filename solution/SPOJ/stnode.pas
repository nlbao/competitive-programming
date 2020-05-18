{$R+, $I+}
{$M 16777216}

uses    math;

const   MAX_N = 10010;
        MAX_M = 100010;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,s,t,nA,last:longint;
    e:array[0..2*MAX_M] of recEdge;
    head,p,a,c:array[0..MAX_N] of longint;


procedure   enter();
var i:longint;
begin
    read(fi,n,m,s,t);
    for i:=1 to n do head[i]:=0;
    for i:=1 to m do with e[i] do begin
        read(fi,x,y);
        link:=head[x];
        head[x]:=i;
    end;
end;


function    dfs_1(u:longint):boolean;
var i:longint;
    ok:boolean;
begin
    ok:=(u = t);
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if p[y] = 0 then begin
            p[y]:=u;
            if dfs_1(y) then ok:=true;
        end;
        i:=link;
    end;
    if ok then begin
        inc(nA);
        a[nA]:=u;
        c[u]:=nA;
    end;
    exit(ok);
end;


procedure   dfs_2(u:longint);
var i:longint;
begin
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if c[y] <= nA then last:=min(last,c[y])
        else if p[y] = 0 then begin
            p[y]:=u;
            dfs_2(y);
        end;
        i:=link;
    end;
end;


procedure   solve();
var i,u,res:longint;
begin
    nA:=0;
    for i:=1 to n do begin
        p[i]:=0;
        c[i]:=MAX_N+MAX_M;
    end;
    p[s]:=-1;
    dfs_1(s);

    res:=0;
    last:=nA;
    for i:=1 to n do p[i]:=0;
    for i:=nA downto 1 do begin
        u:=a[i];
        if (u <> s) and (u <> t) and (last >= i) then res:=res+1;
        p[u]:=-1;
        dfs_2(u);
    end;

    writeln(fo,res);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'STNODE.in');    reset(fi);
    assign(fo,'STNODE.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.

