{$M+ 2000000,0,2000000}
uses    math;

const   MAX_N = 202;
        MAX_M = sqr(MAX_N);
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nE,nP:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    head:array[0..MAX_N] of longint;
    p:array[0..2*MAX_M] of longint;
    ok:array[-MAX_M..MAX_M] of boolean;


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
var i,u,v:longint;
begin
    nE:=0;
    read(fi,n,m);
    for i:=1 to n do begin
        head[i]:=0;
        read(fi,u);
    end;
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
        if ok[i] then begin
            ok[i]:=false;
            ok[-i]:=false;
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
    fillchar(ok,sizeof(ok),true);
    nP:=0;
    dfs(1);
    writeln(fo,nP-1);
    for i:=1 to nP do write(fo,p[i],' ');
end;


begin
{$IFDEF WINDOWS}
    assign(fi,'nkpos.in');    reset(fi);
    assign(fo,'nkpos.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.