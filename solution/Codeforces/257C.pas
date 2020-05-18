uses    math;

const   MAX_N = 100005;
        oo = 1000000000;

type    ll = double;
        recPoint = record
            x,y:ll;
        end;

var fi,fo:text;
    n:longint;
    a,up,down:array[0..MAX_N] of recPoint;


procedure   enter();
var i:longint;
begin
    read(fi,n);
    for i:=1 to n do
        read(fi,a[i].x,a[i].y);
end;


function    cmp(i,j:longint):ll;
begin
    if a[i].x <> a[j].x then exit(a[i].x-a[j].x);
    if a[i].y <> a[j].y then exit(a[i].y-a[j].y);
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
            t:=a[i];
            a[i]:=a[j];
            a[j]:=t;
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
var i,nU,nD:longint;
    p1,p2:recPoint;
begin
    if n < 3 then exit;

    p1:=a[1];   p2:=a[n];
    nU:=1; up[1]:=a[1];
    nD:=1; down[1]:=a[1];

    for i:=2 to n do begin
        if (i = n) or (cw(p1,a[i],p2)) then begin
            while (nU > 1) and (not cw(up[nU-1],up[nU],a[i])) do dec(nU);
            inc(nU);    up[nU]:=a[i];
        end;
        if (i = n) or (ccw(p1,a[i],p2)) then begin
            while (nD > 1) and (not ccw(down[nD-1],down[nD],a[i])) do dec(nD);
            inc(nD);    down[nD]:=a[i];
        end;
    end;

    n:=0;
    for i:=1 to nU do begin
        inc(n);
        a[n]:=up[i];
    end;
    for i:=nD-1 downto 2 do begin
        inc(n);
        a[n]:=down[i];
    end;
end;



function    ang(var a,b:recPoint):ll;
var d,tmp:ll;
begin
    d:=sqrt( (sqr(a.x)+sqr(a.y)) * (sqr(b.x) + sqr(b.y)) );
    tmp:=(a.x*b.x + a.y*b.y)/d;
    exit((arccos(tmp)*180.0)/pi);
end;


function area(a,b,c:recPoint):ll;
var i:longint;
    p:array[0..4] of recPoint;
    s:ll;
begin
    p[1]:=a; p[2]:=b; p[3]:=c;
    p[4]:=a;
    s:=0;
    for i:=1 to 3 do s:=s + (p[i].x-p[i+1].x)*(p[i].y+p[i+1].y);
    exit(abs(s));
end;


function    solve():double;
var i,j:longint;
    s1,s2,res,tmp:ll;
    p:recPoint;
    ck:boolean;
begin
    randomize;
    sort(1,n);
    a[0]:=a[n];
    convex_hull();
    a[0]:=a[n];
    for i:=1 to n do a[n+i]:=a[i];

    if n = 1 then exit(0);
    if n = 2 then exit(ang(a[1],a[2]));

    p.x:=0;
    p.y:=0;
    s1:=0;
    for i:=1 to n do
        s1:=s1 + (a[i].x-a[i+1].x)*(a[i].y+a[i+1].y);
    s1:=abs(s1);
    s2:=0;
    for i:=1 to n do s2:=s2 + area(p,a[i],a[i+1]);
    ck:=abs(s1-s2) < 0.000001;

    res:=360;
    for i:=1 to n do begin
        j:=i-1;
        tmp:=ang(a[i],a[j]);
        //if ck then tmp:=360-tmp;
        if (ck) or (cw(a[i],p,a[j])) then tmp:=360-tmp;
        res:=min(res,tmp);
    end;
    exit(res);
end;


begin
    assign(fi,'257C.in');    reset(fi);
    assign(fo,'257C.out');   rewrite(fo);
    enter();
    writeln(fo,solve():0:6);
    close(fo);
    close(fi);
end.