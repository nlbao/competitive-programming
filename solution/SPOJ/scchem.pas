uses    math;

const   MAX_N = 55;
        MAX_M = sqr(MAX_N);
        oo = 1000000000;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    nTest,test_id,nX,nY,nE:longint;
    e:array[0..MAX_M] of recEdge;
    head,q,d,matchX,matchY,list:array[0..MAX_N] of longint;
    chooseX,chooseY:array[0..MAX_N] of boolean;
    a:array[0..MAX_N,0..MAX_N] of boolean;


procedure   enter();
var i,j:longint;
    s:ansiString;
begin
    nE:=0;
    readln(fi,nX,nY);
    for i:=0 to nX do head[i]:=0;
    for i:=1 to nX do begin
        readln(fi,s);
        for j:=1 to nY do
            if s[j] = '0' then begin
                inc(nE);
                with e[nE] do begin
                    x:=i;   y:=j;
                    link:=head[x];
                    head[x]:=nE;
                end;
                a[i][j]:=false;
            end
            else a[i][j]:=true;
    end;
end;


function    find_path():boolean;
var i,u,v,l,r:longint;
begin
    l:=1;   r:=0;
    for i:=1 to nX do
        if matchX[i] = 0 then begin
            d[i]:=0;
            inc(r); q[r]:=i;
        end
        else if matchX[i] = -1 then d[i]:=-2
        else d[i]:=-1;
    d[0]:=-1;

    while l <= r do begin
        u:=q[l]; inc(l);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            v:=matchY[y];
            if (matchY[y] >= 0) and (d[v] = -1) then begin
                d[v]:=d[u]+1;
                if v = 0 then exit(true);
                inc(r); q[r]:=v;
            end;
            i:=link;
        end;
    end;
    exit(false);
end;


function    dfs(u:longint):boolean;
var i,v:longint;
begin
    if u = 0 then exit(true);
    i:=head[u];
    while i <> 0 do with e[i] do begin
        v:=matchY[y];
        if (matchY[y] >= 0) and (d[v] = d[u]+1) and (dfs(v)) then begin
            matchX[u]:=y;
            matchY[y]:=u;
            exit(true);
        end;
        i:=link;
    end;
    d[u]:=-1;
    exit(false);
end;


function    check(u,v:longint):longint;
var i,old,res,m:longint;
begin
    res:=0;
    for i:=1 to nX do
        if a[i][v] then matchX[i]:=0
        else matchX[i]:=-1;
    for i:=1 to nY do
        if a[u][i] then matchY[i]:=0
        else matchY[i]:=-1;
    matchX[u]:=-1;
    matchY[v]:=-1;
    matchX[0]:=0;

    m:=0;
    for u:=1 to nX do begin
        if matchX[u] <> 0 then continue;
        inc(m);
        list[m]:=u;
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if matchY[y] = 0 then begin
                matchX[u]:=y;
                matchY[y]:=u;
                inc(res);
                dec(m);
                break;
            end;
            i:=link;
        end;
    end;

    while find_path() do begin
        old:=m;
        for i:=old downto 1 do begin
            u:=list[i];
            if (matchX[u] = 0) and (dfs(u)) then begin
                inc(res);
                list[i]:=list[m];
                dec(m);
            end;
        end;
        if old = m then break;
    end;

    res:=-res;
    for u:=1 to nX do res:=res+longint(matchX[u] >= 0);
    for u:=1 to nY do res:=res+longint(matchY[u] >= 0);
    exit(res+2);
end;


function    solve():longint;
var u,v,res:longint;
begin
    res:=0;
    for u:=1 to nX do
        for v:=1 to nY do
            if a[u][v] then
                res:=max(res,check(u,v));
    exit(res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'SCCHEM.in');    reset(fi);
    assign(fo,'SCCHEM.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    readln(fi,nTest);
    for test_id:=1 to nTest do begin
        enter();
        writeln(fo,'Case ',test_id,': ',solve());
    end;
    close(fi);
    close(fo);
end.