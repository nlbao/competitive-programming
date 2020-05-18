uses    math;

const   MAX_R = 51;
        MAX_N = sqr(MAX_R);
        MAX_M = 2*MAX_N;
        oo = 1000000000;
        dx:array[1..4] of longint = (-1,-1,+1,+1);
        dy:array[1..4] of longint = (-1,+1,+1,-1);

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    m,nX,nY,nE:longint;
    e:array[0..MAX_M] of recEdge;
    id:array[0..MAX_R,0..MAX_R] of longint;
    head,q,d,matchX,matchY:array[0..MAX_N] of longint;
    okX,okY:array[0..MAX_N] of boolean;


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
var i,j,k,x,y:longint;
    s:ansiString;
begin
    nE:=0;
    nX:=0;  nY:=0;
    fillchar(head,sizeof(head),0);
    fillchar(id,sizeof(id),0);
    readln(fi,m);
    for i:=1 to m do begin
        readln(fi,s);
        for j:=1 to m do
            if s[j] = '.' then
                if (i and 1) = 1 then begin inc(nX);    id[i][j]:=nX;   end
                else begin  inc(nY);    id[i][j]:=nY;   end;
    end;

    i:=1;
    repeat
        for j:=1 to m do begin
            if id[i][j] = 0 then continue;
            for k:=1 to 4 do begin
                x:=i+dx[k];
                y:=j+dy[k];
                if id[x][y] > 0 then add_edge(id[i][j],id[x][y]);
            end;
        end;
        i:=i+2;
    until i > m;
end;


function    find_path():boolean;
var i,l,r,u,v:longint;
begin
    l:=1;   r:=0;
    for i:=1 to nX do
        if matchX[i] = 0 then begin
            d[i]:=0;
            inc(r); q[r]:=i;
        end
        else d[i]:=-1;
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

procedure   get(u:longint);
var i:longint;
begin
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if okY[y] then begin
            okY[y]:=false;
            if matchY[y] > 0 then get(matchY[y]);
        end;
        i:=link;
    end;
end;

procedure   solve();
var i,u,res:longint;
begin
    for i:=1 to nX do matchX[i]:=0;
    for i:=1 to nY do matchY[i]:=0;

    while find_path() do
        for i:=1 to nX do
            if matchX[i] = 0 then dfs(i);

    for i:=1 to nX do okX[i]:=true;
    for i:=1 to nY do okY[i]:=true;
    for u:=1 to nX do
        if matchX[u] = 0 then get(u);
    okY[0]:=false;
    for u:=1 to nX do
        if okY[matchX[u]] then okX[u]:=false;

    res:=0;
    for i:=1 to nX do res:=res+longint(okX[i]);
    for i:=1 to nY do res:=res+longint(okY[i]);
    writeln(fo,res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'TPBISHOP.in');    reset(fi);
    assign(fo,'TPBISHOP.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.