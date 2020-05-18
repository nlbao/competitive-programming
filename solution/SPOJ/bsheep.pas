{$M 16777216}
uses    math;

const   MAX_N = 100005;
        oo = 1000000000;

type    ll = longint;
        recPoint = record
            x,y:ll;
            id:longint;
        end;

var fi,fo:text;
    nTest,n,m:longint;
    a,b:array[0..MAX_N] of recPoint;
    up,down:array[0..MAX_N] of longint;


procedure   enter();
var i:longint;
begin
    read(fi,n);
    for i:=1 to n do with a[i] do begin
        read(fi,x,y);
        id:=i;
    end;
    a[n+1]:=a[1];
end;

function    cmp(i,j:longint):longint;
begin
    if a[i].y < a[j].y then exit(-1);
    if a[i].y > a[j].y then exit(1);
    if a[i].x < a[j].x then exit(-1);
    if a[i].x > a[j].x then exit(1);
    if a[i].id < a[j].id then exit(-1);
    if a[i].id > a[j].id then exit(1);
    exit(0);
end;

procedure   sort(l,r:longint);
var i,j,p:longint;
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
    if n < 3 then exit;
    p1:=a[1];   p2:=a[n];
    u:=1;   up[1]:=1;
    d:=1;   down[1]:=1;

    for i:=2 to n do begin
        if (i = n) or (cw(p1,a[i],p2)) then begin
            while (u > 1) and (not cw(a[up[u-1]], a[up[u]], a[i])) do dec(u);
            inc(u); up[u]:=i;
        end;
        if (i = n) or (ccw(p1,a[i],p2)) then begin
            while (d > 1) and (not ccw(a[down[d-1]], a[down[d]], a[i])) do dec(d);
            inc(d); down[d]:=i;
        end;
    end;

    m:=0;
    for i:=1 to u do begin
        inc(m);
        b[m]:=a[up[i]];
    end;
    for i:=d-1 downto 2 do begin
        inc(m);
        b[m]:=a[down[i]];
    end;
    b[m+1]:=b[1];
end;


function    dist(a,b:recPoint):double;
begin   exit(sqrt(sqr(a.x-b.x) + sqr(a.y-b.y))); end;


procedure   solve();
var i,j,c:longint;
    res:double;
begin
    randomize;
    sort(1,n);
    i:=1;   c:=0;
    while i <= n do begin
        j:=i;
        while (j <= n) and (a[j].x = a[i].x) and (a[j].y = a[i].y) do inc(j);
        a[i-c]:=a[i];
        c:=c+j-i-1;
        i:=j;
    end;
    n:=n-c;
    a[n+1]:=a[1];

    if n = 1 then begin
        writeln(fo,0.0:0:2);
        write(fo,a[1].id);
        exit;
    end;

    if n = 2 then begin
        writeln(fo,2*dist(a[1],a[2]):0:2);
        for i:=1 to n do write(fo,a[i].id,' ');
        exit;
    end;

    convex_hull(n);

    res:=0;
    for i:=1 to m do res:=res + dist(b[i],b[i+1]);
    writeln(fo,res:0:2);

    j:=1;
    for i:=2 to m do
        if (b[i].y < b[j].y) or ((b[i].y = b[j].y) and (b[i].x < b[j].x)) then
            j:=i;
    for i:=j downto 1 do write(fo,b[i].id,' ');
    for i:=m downto j+1 do write(fo,b[i].id,' ');
end;

begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'BSHEEP.inp');    reset(fi);
    assign(fo,'BSHEEP.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    readln(fi,nTest);
    while nTest > 0 do begin
       enter();
       solve();
       writeln(fo);
       if nTest > 1 then writeln(fo);
       dec(nTest);
    end;
    close(fo);
    close(fi);
end.