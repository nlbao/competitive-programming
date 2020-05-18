{$M 16777216}
uses    math;

const   MAX_N = 53*2;
        oo = 1000000000000000000;
        eps = 0.00001;

type    ll = int64;
        recPoint = record
            x,y:ll;
        end;

var fi,fo:text;
    n,k,m,first,last,nU,nD,nB:longint;
    a,b:array[0..MAX_N] of recPoint;
    dist:array[0..MAX_N,0..MAX_N] of double;
    up,down:array[0..MAX_N] of longint;
    id:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;
    res,sum,s:double;
    p1,p2:recPoint;


procedure   enter();
var i:longint;
begin
    read(fi,n,k);
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

procedure   init();
var i,j:longint;
    t:recPoint;
    u,v:ll;
begin
    for i:=1 to n do
        for j:=i+1 to n do
            if cmp(j,i) < 0 then begin
                t:=a[i];
                a[i]:=a[j];
                a[j]:=t;
            end;
    for i:=1 to n do
        for j:=1 to n do begin
            u:=a[i].x-a[j].x;
            v:=a[i].y-a[j].y;
            dist[i][j]:=sqrt(u*u + v*v);
        end;
end;


function    det(a,b,c,d:ll):ll; inline; begin   exit(a*d-b*c);  end;

function    cw(a,b,c:recPoint):boolean; inline;
begin   exit(det(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y) < 0);  end;

function    ccw(a,b,c:recPoint):boolean; inline;
begin   exit(det(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y) > 0);  end;


procedure   convex_hull(n:longint);
var i,u,d,c:longint;
    p1,p2:recPoint;
begin
    p1:=a[first];
    p2:=a[last];
    u:=1;   up[1]:=first;
    d:=1;   down[1]:=first;

    for i:=2 to last do if ok[i] then begin
        if (i = last) or (cw(p1,a[i],p2)) then begin
            while (u > 1) and (not cw(a[up[u-1]], a[up[u]], a[i])) do dec(u);
            inc(u); up[u]:=i;
        end;
        if (i = last) or (ccw(p1,a[i],p2)) then begin
            while (d > 1) and (not ccw(a[down[d-1]], a[down[d]], a[i])) do dec(d);
            inc(d); down[d]:=i;
        end;
    end;

    c:=0;
    for i:=1 to u do begin
        inc(c);
        id[c]:=up[i];
    end;
    for i:=d-1 downto 2 do begin
        inc(c);
        id[c]:=down[i];
    end;
    id[c+1]:=id[1];
end;


procedure   tryf(pos,c:longint);
var i:longint;
begin
    ok[pos]:=true;
    if c = k then begin
        last:=pos;
        convex_hull(n);
        sum:=0;
        for i:=1 to k do
            sum:=sum + dist[id[i]][id[i+1]];
        res:=min(res,sum);
        exit;
    end;
    for i:=pos+1 to n do tryf(i,c+1);
    ok[pos]:=false;
end;


function    solve():double;
var i,j,t,c:longint;
    a1,b1,c1:ll;
begin
    res:=oo;
    if k = 1 then exit(0);
    if k = 2 then begin
        for i:=1 to n do
            for j:=i+1 to n do
                res:=min(res,dist[i][j]);
        exit(2*res);
    end;

    for i:=1 to n do
        for j:=i+1 to n do begin
            a1:=a[i].y-a[j].y;
            b1:=a[j].x-a[i].x;
            c1:=-(a1*a[i].x + b1*a[i].y);
            c:=0;
            for t:=1 to n do
                if a1*a[t].x + b1*a[t].y + c1 = 0 then inc(c);
            if c >= k then res:=min(res,dist[i][j]);
        end;

    for i:=1 to n-k+1 do begin
        first:=i;
        tryf(i,1);
    end;

    exit(res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'VODEFEND.in');    reset(fi);
    assign(fo,'VODEFEND.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    init();
    writeln(fo,solve():0:4);
    close(fo);
    close(fi);
end.