const   INPUT = 'C11Rank.in';
        OUTPUT = 'C11Rank.out';
        MAX_N = 510;

var fi,fo:text;
    nTest,n,m,count,cID,top:longint;
    t,degI,number,id,low,stack:array[0..MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;
    a:array[0..MAX_N,0..MAX_N] of longint;
    ok:boolean;

function    min(x,y:longint):longint;   begin   if x < y then exit(x) else exit(y); end;

function    enter:boolean;
var i,j,u,v:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,t[i]);
    for u:=1 to n do
        for v:=1 to n do a[u][v]:=0;
    readln(fi,m);
    for i:=1 to m do begin
        read(fi,u,v);
        if t[u] <= t[v] then exit(false);
        a[u][v]:=1; a[v][u]:=-1;
    end;
    for u:=1 to n-1 do
        for v:=u+1 to n do
            if a[u][v] = 0 then
                if t[u] < t[v] then begin
                    a[u][v]:=1;     a[v][u]:=-1;
                end
                else begin
                    a[u][v]:=-1;    a[v][u]:=1;
                end;
    exit(true);
end;

procedure   DFS(u:longint);
var v:longint;
begin
    if not ok then exit;
    avail[u]:=false;
    id[u]:=cID; low[u]:=cID;    inc(cID);
    inc(top);   stack[top]:=u;
    for v:=1 to n do
        if (a[u][v] = 1) and (number[v] = -1) then
            if avail[v] then begin
                DFS(v);
                low[u]:=min(low[u],low[v]);
            end
            else low[u]:=min(low[u],id[v]);
    if low[u] = id[u] then
        if stack[top] <> u then begin
            ok:=false;  exit;
        end
        else dec(top);
    number[u]:=count; dec(count);
end;

function    solve:boolean;
var i,j:longint;
begin
    if not ok then exit(false);
    for i:=1 to n do begin
        avail[i]:=true;
        number[i]:=-1;
        degI[i]:=0;
    end;
    for i:=1 to n do
        for j:=1 to n do
            if a[i][j] = -1 then inc(degI[i]);
    count:=n;   cID:=1;
    for i:=1 to n do
        if degI[i] = 0 then DFS(i);
    if not ok then exit(false);
    for i:=1 to n do write(fo,number[i],' ');
    writeln(fo);
    exit(true);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        ok:=enter;
        ok:=solve;
        if not ok then writeln(fo,'IMPOSSIBLE');
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
