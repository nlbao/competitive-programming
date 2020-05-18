{$M 16777216}
uses    math;

const   MAX_N = 4003;
        oo = 1000000000;

type    ll = longint;
        recPoint = record
            x,y:ll;
        end;

var fi,fo:text;
    n:longint;
    a:array[0..MAX_N] of recPoint;
    up,down:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;


procedure   enter();
var i:longint;
begin
    read(fi,n);
    for i:=1 to n do read(fi,a[i].x,a[i].y);
end;

function    cmp(i,j:longint):longint;
begin
    if a[i].x < a[j].x then exit(-1);
    if a[i].x > a[j].x then exit(1);
    if a[i].y < a[j].y then exit(-1);
    if a[i].y > a[j].y then exit(1);
    exit(0);
end;

procedure   sort(l,r:longint);
var i,j:longint;
    t:recPoint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    a[0]:=a[i];
    i:=l;   j:=r;
    repeat
        while cmp(i,0) < 0 do inc(i);
        while cmp(j,0) > 0 do dec(j);
        if i <= j then begin
            t:=a[i];    a[i]:=a[j];     a[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;

function    det(a,b,c,d:ll):ll; inline; begin   exit(a*d-b*c);  end;

function    cw(a,b,c:recPoint):boolean; inline;
begin   exit(det(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y) < 0);  end;

function    ccw(a,b,c:recPoint):boolean; inline;
begin   exit(det(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y) > 0);  end;

procedure   convex_hull(n:longint);
var i,u,d:longint;
    p1,p2:recPoint;
begin
    for i:=1 to n do ok[i]:=true;
    if n < 3 then exit;
    p1:=a[1];   p2:=a[n];
    u:=1;   up[1]:=1;
    d:=1;   down[1]:=1;

    for i:=2 to n do begin
        if (i = n) or (cw(p1,a[i],p2)) then begin
            while (u > 1) and (ccw(a[up[u-1]], a[up[u]], a[i])) do dec(u);
            inc(u); up[u]:=i;
        end;
        if (i = n) or (ccw(p1,a[i],p2)) then begin
            while (d > 1) and (cw(a[down[d-1]], a[down[d]], a[i])) do dec(d);
            inc(d); down[d]:=i;
        end;
    end;

    for i:=1 to u do ok[up[i]]:=false;
    for i:=d-1 downto 2 do ok[down[i]]:=false;
end;


procedure   solve();
var i,m,res:longint;
begin
    randomize;
    sort(1,n);
    res:=0;
    while n > 2 do begin
        res:=res+1;
        convex_hull(n);
        m:=n;   n:=0;
        for i:=1 to m do
            if ok[i] then begin
                inc(n);
                a[n]:=a[i];
            end;
    end;
    writeln(fo,res);
end;

begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'MILITARY.inp');    reset(fi);
    assign(fo,'MILITARY.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.
