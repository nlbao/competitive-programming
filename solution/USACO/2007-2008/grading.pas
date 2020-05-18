uses    math;

const   MAX_N = 2010;
        oo = MAXLONGINT;

type    ll = longint;

var fi,fo:text;
    n:longint;
    a,id,pos:array[0..MAX_N] of longint;
    d:array[0..MAX_N,0..MAX_N] of ll;
    f,g:array[0..1,0..MAX_N] of ll;


procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;


procedure   sort(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=a[i];
    i:=l;   j:=r;
    repeat
        while a[i] < p do inc(i);
        while a[j] > p do dec(j);
        if i <= j then begin
            swap(a[i],a[j]);
            swap(id[i],id[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


procedure   enter();
var i,j:longint;
begin
    read(fi,n);
    for i:=1 to n do begin
        read(fi,a[i]);
        id[i]:=i;
    end;
    randomize;
    sort(1,n);
    for i:=1 to n do pos[id[i]]:=i;
    for i:=1 to n do
        for j:=1 to n do
            d[i][j]:=abs(a[i]-a[j]);
end;


function    solve_1():longint;
var i,j,t,tt:longint;
begin
    t:=0;
    g[0][0]:=oo;
    for i:=1 to n do begin
        f[0][i]:=d[pos[1]][i];
        g[0][i]:=min(g[0][i-1],f[0][i]);
    end;
    for i:=2 to n do begin
        tt:=t;
        t:=(t+1) and 1;
        g[t][0]:=oo;
        for j:=1 to n do begin
            f[t][j]:=g[tt][j] + d[pos[i]][j];
            g[t][j]:=min(g[t][j-1], f[t][j]);
        end;
    end;
    exit(g[t][n]);
end;


function    solve_2():longint;
var i,j,t,tt:longint;
begin
    t:=0;
    g[0][n+1]:=oo;
    for i:=n downto 1 do begin
        f[0][i]:=d[pos[1]][i];
        g[0][i]:=min(g[0][i+1],f[0][i]);
    end;
    for i:=2 to n do begin
        tt:=t;
        t:=(t+1) and 1;
        g[t][n+1]:=oo;
        for j:=n downto 1 do begin
            f[t][j]:=g[tt][j] + d[pos[i]][j];
            g[t][j]:=min(g[t][j+1], f[t][j]);
        end;
    end;
    exit(g[t][1]);
end;


begin
    assign(fi,'grading.in');    reset(fi);
    assign(fo,'grading.out');   rewrite(fo);
    enter();
    writeln(fo,min(solve_1(),solve_2()));
    close(fo);
    close(fi);
end.