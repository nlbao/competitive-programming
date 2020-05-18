{$M 16777216}
uses    math;

const   MAX_N = 100005;
        oo = 1000000000;

type    ll = double;
        recPoint = record
            x,y:ll;
        end;

var fi,fo:text;
    n,k:longint;
    a,b:array[0..MAX_N] of recPoint;
    up,down:array[0..MAX_N] of longint;
    d:array[0..MAX_N] of double;


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

procedure   convex_hull();
var i,u,d:longint;
    p1,p2:recPoint;
begin
    randomize;
    sort(1,n);
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

    n:=0;
    for i:=1 to u do begin
        inc(n);
        b[n]:=a[up[i]];
    end;
    for i:=d-1 downto 2 do begin
        inc(n);
        b[n]:=a[down[i]];
    end;
    for i:=1 to n do a[i]:=b[i];
    a[0]:=a[n]; a[n+1]:=a[1];
end;


function    goc(a,b:recPoint):double;
var t:double;
begin
    t:=sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
    if t = 0 then exit(0);
    exit(double(b.y-a.y)/t);
end;

procedure   init();
var i:longint;
begin
    convex_hull();
    k:=1;
    for i:=1 to n do begin
        a[i+n]:=a[i];
        if a[i].x < a[k].x then k:=i;
    end;
    a[n+n+1]:=a[1];
    for i:=k+1 to k+n do d[i]:=goc(a[k],a[i]);
end;


procedure   get_line(p1,p2:recPoint;    var a,b,c:ll);
begin
    a:=p1.y-p2.y;
    b:=p2.x-p1.x;
    c:=-(a*p1.x+b*p1.y);
end;

function    f(a,b,c:ll; p:recPoint):ll;    inline;
begin   exit(a*p.x+b*p.y+c);    end;

function    on_segment(a,b,p:recPoint):boolean;
var a1,b1,c1:ll;
begin
    get_line(a,b,a1,b1,c1);
    if f(a1,b1,c1,p) <> 0 then exit(false);
    if (p.x < min(a.x,b.x)) or (p.x > max(a.x,b.x)) then exit(false);
    if (p.y < min(a.y,b.y)) or (p.y > max(a.y,b.y)) then exit(false);
    exit(true);
end;

function    check(p:recPoint):boolean;
var l,r,mid,i:longint;
    a1,b1,c1:ll;
    g,tmp:double;
begin
    l:=k+1; r:=k+n-1;
    g:=goc(a[k],p);
    if p.x < a[k].x then exit(false);

    if (p.x = a[k].x) or (g = 0) then
        exit((on_segment(a[k],a[l],p)) or (on_segment(a[k],a[r],p)));

    if (g > d[l]) or (g < d[r]) then exit(false);
    if g = d[l] then exit(on_segment(a[k],a[l],p));
    if g = d[r] then exit(on_segment(a[k],a[r],p));

    while l <= r do begin
        mid:=(l+r) shr 1;
        if d[mid] <= g then begin
            i:=mid;
            r:=mid-1;
        end
        else l:=mid+1;
    end;

    get_line(a[i],a[i-1],a1,b1,c1);
    tmp:=f(a1,b1,c1,p);
    if tmp = 0 then exit(true);
    exit(f(a1,b1,c1,a[k])*tmp > 0);
end;


procedure   solve();
var i,nQ:longint;
    p:recPoint;
begin
    read(fi,nQ);
    for i:=1 to nQ do begin
        read(fi,p.x,p.y);
        if check(p) then writeln(fo,'YES')
        else writeln(fo,'NO');
    end;
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'kmix.in');    reset(fi);
    assign(fo,'kmix.out');   rewrite(fo);
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
