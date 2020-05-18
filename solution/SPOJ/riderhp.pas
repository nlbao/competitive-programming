{$M+ 2000000}
uses    math;

const   MAX_N = 100005;
        oo = 1000000000;

type    ll = double;
        recPoint = record
            x,y:longint;
        end;

var fi,fo:text;
    n,m:longint;
    a:array[0..MAX_N] of recPoint;
    b:array[0..MAX_N] of recPoint;
    up,down:array[0..MAX_N] of longint;
    res:array[0..MAX_N] of ll;


procedure   enter();
var i:longint;
begin
    read(fi,n);
    for i:=2 to n+1 do begin
        a[i].x:=i-1;
        read(fi,a[i].y);
    end;
    a[1]:=a[2];     a[1].y:=0;
    a[n+2]:=a[n+1]; a[n+2].y:=0;
    inc(n,2);
end;


function    det(a,b,c,d:ll):ll; inline; begin   exit(a*d-b*c);  end;

function    cw(a,b,c:recPoint):boolean; inline;
begin   exit(det(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y) < 0);  end;

function    ccw(a,b,c:recPoint):boolean; inline;
begin   exit(det(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y) > 0);  end;


procedure   convex_hull(var n:longint);
var i,nU,nD:longint;
    p1,p2:recPoint;
begin
    if n < 4 then exit;
    p1:=a[1];   p2:=a[n];
    nU:=1;  up[1]:=1;
    nD:=1;  down[1]:=1;

    for i:=2 to n do begin
        if (i = n) or (cw(p1,a[i],p2)) then begin
            while (nU > 1) and (not cw(a[up[nU-1]], a[up[nU]], a[i])) do dec(nU);
            inc(nU);    up[nU]:=i;
        end;
        if (i = n) or (ccw(p1,a[i],p2)) then begin
            while (nD > 1) and (not ccw(a[down[nD-1]], a[down[nD]], a[i])) do dec(nD);
            inc(nD);    down[nD]:=i;
        end;
    end;

    n:=0;
    for i:=1 to nU do begin
        inc(n);
        b[n]:=a[up[i]];
    end;
    for i:=nD-1 downto 2 do begin
        inc(n);
        b[n]:=a[down[i]];
    end;
    b[0]:=b[n];
    b[n+1]:=b[1];
end;


procedure   sort(l,r:longint);
var i,j,tt:longint;
    p,t:recPoint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=a[i];
    i:=l;   j:=r;
    repeat
        while a[i].y < p.y do inc(i);
        while a[j].y > p.y do dec(j);
        if i <= j then begin
            t:=a[i];    a[i]:=a[j];     a[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;

procedure   init();
var i:longint;
begin
    convex_hull(n);
    read(fi,m);
    for i:=1 to m do begin
        a[i].x:=i;
        read(fi,a[i].y);
    end;
    randomize;
    sort(1,m);
end;


function    check(y0:double;    k:longint):longint;
var a1,b1,c1,f1,f2:ll;
begin
    if b[k].y <= y0 then exit(-1);
    a1:=y0-b[k].y;
    b1:=b[k].x;
    c1:=-b1*y0;

    f1:=a1*b[k-1].x + b1*b[k-1].y + c1;
    f2:=a1*b[k+1].x + b1*b[k+1].y + c1;

    if f1*f2 < 0 then exit(0);
    if (f1 > 0) or (f2 > 0) then exit(-1);
    exit(1);
end;


function    f(a,b:double):double;   inline; begin   exit(a/b);  end;

procedure   solve();
var i,k:longint;
    minf:ll;
begin
    k:=2;
    for i:=1 to m do begin
        while (k < n) and (check(a[i].y,k) <> 1) do inc(k);
        while (k < n-1) and (check(a[i].y,k+1) = 1) do inc(k);
        minf:=f(b[k].x,b[k].y-a[i].y);
        res[a[i].x]:=minf;
    end;
    for i:=1 to m do writeln(fo,res[i]:0:6);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'RIDERHP.in');   reset(fi);
    assign(fo,'RIDERHP.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    enter();
    init();
    solve();
    close(fi);
    close(fo);
end.