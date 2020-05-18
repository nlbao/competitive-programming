{$M+ 16777216}

uses    math;

const   MAX_N = 110;
        MAX_M = sqr(MAX_N);
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    nX,nY,nE:longint;
    e:array[0..MAX_M] of recEdge;
    head,q,d,trace:array[0..MAX_N] of longint;
    matchX,matchY,degX,degY,listX,listY:array[0..MAX_N] of longint;
    ok:array[0..MAX_M] of boolean;
    res:array[0..MAX_N,0..MAX_N] of longint;
    a:array[0..MAX_N,0..MAX_N] of boolean;



procedure   add_edge(u,v:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        link:=head[x];
        head[x]:=nE;
    end;
end;


procedure   enter();
var i,j:longint;
    s:ansiString;
begin
    nE:=0;
    fillchar(a,sizeof(a),false);
    readln(fi,nX,nY);
    for i:=1 to nY do degY[i]:=0;
    for i:=1 to nX do begin
        degX[i]:=0;
        readln(fi,s);
        for j:=1 to nY do
            if s[j] = '1' then begin
                a[i][j]:=true;
                inc(degX[i]);
                inc(degY[j]);
            end;
    end;
end;


function    find_path():boolean;
var i,l,r,u,v:longint;
begin
    l:=1;   r:=0;
    for i:=1 to nX do begin
        u:=listX[i];
        if matchX[u] = 0 then begin
            d[u]:=0;
            inc(r); q[r]:=u;
        end
        else d[u]:=-1;
    end;
    d[0]:=-1;

    while l <= r do begin
        u:=q[l]; inc(l);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            v:=matchY[y];
            if d[v] = -1 then begin
                d[v]:=d[u]+1;
                inc(r); q[r]:=v;
            end;
            i:=link;
        end;
    end;
    exit(d[0] <> -1);
end;


function    dfs(u:longint):boolean;
var i,v:longint;
begin
    if u = 0 then exit(true);
    i:=head[u];
    while i <> 0 do with e[i] do begin
        v:=matchY[y];
        if (d[v] = d[u]+1) and (dfs(v)) then begin
            matchX[u]:=y;
            matchY[y]:=u;
            exit(true);
        end;
        i:=link;
    end;
    d[u]:=-1;
    exit(false);
end;


procedure   sort();
var i,j,t:longint;
begin
    for i:=1 to nX do
        for j:=i+1 to nX do
            if degX[listX[i]] < degX[listX[j]] then begin
                t:=listX[i];
                listX[i]:=listX[j];
                listX[j]:=t;
            end;

    for i:=1 to nY do
        for j:=i+1 to nY do
            if degY[listY[i]] < degY[listY[j]] then begin
                t:=listY[i];
                listY[i]:=listY[j];
                listY[j]:=t;
            end;
end;

procedure   solve();
var i,j,m,c:longint;
begin
    m:=0;
    fillchar(res,sizeof(res),0);
    for i:=1 to nE do ok[i]:=true;
    for i:=1 to nX do listX[i]:=i;
    for i:=1 to nY do listY[i]:=i;

    repeat
        c:=0;
        for i:=1 to nX do matchX[i]:=0;
        for i:=1 to nY do matchY[i]:=0;
        sort();

        nE:=0;
        for i:=1 to nX do head[i]:=0;
        for i:=1 to nX do
            for j:=nY downto 1 do
                if a[listX[i]][listY[j]] then
                    add_edge(listX[i],listY[j]);


        while find_path() do
            for i:=1 to nX do
                if matchX[listX[i]] = 0 then
                    c:=c+longint(dfs(listX[i]));

        if c = 0 then break;

        m:=m+1;
        for i:=1 to nX do
            if matchX[i] > 0 then begin
                j:=matchX[i];
                res[i][j]:=m;
                a[i][j]:=false;
                dec(degX[i]);
                dec(degY[j]);
            end;
    until false;

    writeln(fo,m);
    for i:=1 to nX do begin
        for j:=1 to nY do write(fo,res[i][j],' ');
        writeln(fo);
    end;
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'NKDEC.in');    reset(fi);
    assign(fo,'NKDEC.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.