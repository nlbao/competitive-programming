uses    math;

const   MAX_N = 202;
        MAX_M = sqr(MAX_N);
        oo = 1000000000;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    nX,nY,n,m,nE:longint;
    e:array[0..MAX_M] of recEdge;
    a,head,q,d,matchX,matchY:array[0..MAX_N] of longint;
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
var i,j,t:longint;
begin
    nE:=0;
    fillchar(head,sizeof(head),0);
    read(fi,n);
    for i:=1 to n do read(fi,a[i]);

    for i:=1 to n do
        for j:=i+1 to n do
            if a[i] > a[j] then begin
                t:=a[i];
                a[i]:=a[j];
                a[j]:=t;
            end;
    i:=1;   t:=0;
    while i <= n do begin
        j:=i;
        while (j <= n) and (a[j] = a[i]) do inc(j);
        a[i-t]:=a[i];
        t:=t+j-i-1;
        i:=j;
    end;
    n:=n-t;

    nX:=n;  nY:=n;
    for i:=n downto 2 do
        for j:=i-1 downto 1 do
            if a[i] mod a[j] = 0 then
                add_edge(i,j);
end;


function    find_path():boolean;
var l,r,i,u:longint;
begin
    l:=1;   r:=0;
    for i:=1 to nX do
        if matchX[i] = 0 then begin
            d[i]:=0;
            inc(r); q[r]:=i;
        end
        else d[i]:=-1;
    d[0]:=-1;

    repeat
        u:=q[l];    inc(l);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if d[matchY[y]] = -1 then begin
                d[matchY[y]]:=d[u]+1;
                if matchY[y] = 0 then exit(true);
                inc(r); q[r]:=matchY[y];
            end;
            i:=link;
        end;
    until l > r;
    exit(false);
end;


function    dfs(u:longint):boolean;
var i:longint;
begin
    if u = 0 then exit(true);
    i:=head[u];
    while i <> 0 do with e[i] do begin
        if d[matchY[y]] = d[u]+1 then
            if dfs(matchY[y]) then begin
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
    res:=0;
    for i:=1 to nX do matchX[i]:=0;
    for i:=1 to nY do matchY[i]:=0;

    while find_path() do
        for i:=1 to nX do
            if (matchX[i] = 0) and (dfs(i)) then
                inc(res);

    for i:=1 to nX do okX[i]:=true;
    for i:=1 to nY do okY[i]:=true;
    for u:=1 to nX do
        if matchX[u] = 0 then get(u);
    okY[0]:=false;
    for u:=1 to nX do
        if okY[matchX[u]] then okX[u]:=false;

    writeln(fo,n-res);
    for i:=1 to n do
        if (okX[i]) and (okY[i]) then write(fo,a[i],' ');
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'DIVREL.in');    reset(fi);
    assign(fo,'DIVREL.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.