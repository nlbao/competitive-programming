{$M 16777216}
uses    math;

const   MAX_N = 27;
        MAX_M = 222;
        oo = 1000000000;

var fi,fo:text;
    n,m:longint;
    a,b,row,col:array[0..5] of longint;
    f:array[0..MAX_N,0..MAX_M,0..7] of boolean;
    res:array[0..MAX_N,0..MAX_N] of longint;
    found:boolean;


procedure   enter();
var i:longint;
begin
    for i:=1 to 5 do read(fi,a[i]);
    for i:=1 to 5 do read(fi,b[i]);
end;


procedure   init();
var i,j,k:longint;
begin
    n:=25;  m:=25*5;
    fillchar(f,sizeof(f),false);
    for i:=0 to n do f[i][0][0]:=true;
    for i:=1 to n do
        for j:=1 to m do
            for k:=1 to 5 do
                f[i][j][k]:=(f[i-1][j][k]) or ((j >= i) and (f[i-1][j-i][k-1]));
end;


procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;


procedure   tryf(value:longint);
var i,j,u,v,m:longint;
    x,y:array[0..25] of longint;
begin
    if value < 1 then found:=true;
    if found then exit;

    for i:=1 to 5 do begin
        if not f[value][a[i]][row[i]] then exit;
        if not f[value][b[i]][col[i]] then exit;
    end;

    m:=0;
    for i:=1 to 5 do
        for j:=1 to 5 do
            if (res[i][j] = 0) and (a[i] >= value) and (b[j] >= value) then begin
                inc(m);
                x[m]:=i;    y[m]:=j;
            end;

    for i:=1 to m do
        for j:=i+1 to m do
            if a[x[j]]+b[y[j]] > a[x[i]]+b[y[i]] then begin
                swap(x[i],x[j]);
                swap(y[i],y[j]);
            end;

    for i:=1 to m do begin
        u:=x[i];    v:=y[i];
        res[u][v]:=value;
        dec(a[u],value);
        dec(b[v],value);
        dec(row[u]);
        dec(col[v]);

        tryf(value-1);
        if found then exit;

        res[u][v]:=0;
        inc(a[u],value);
        inc(b[v],value);
        inc(row[u]);
        inc(col[v]);
    end;
end;


procedure   solve();
var i,j:longint;
begin
    fillchar(res,sizeof(res),0);
    for i:=1 to 5 do begin
        row[i]:=5;
        col[i]:=5;
    end;
    found:=false;
    tryf(25);

    for i:=1 to 5 do begin
        for j:=1 to 5 do write(fo,res[i][j],' ');
        writeln(fo);
    end;
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'VMMTFIVE.in');    reset(fi);
    assign(fo,'VMMTFIVE.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    init();
    solve();
    close(fo);
    close(fi);
end.