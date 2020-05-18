{$M 16777216}
uses    math;

const   MAX_N = 2*5003;
        oo = 1000000000;

type    ll = int64;
        recPoint = record
            x,y:double;
        end;

var fi,fo:text;
    n,k:longint;
    a:array[0..MAX_N] of recPoint;
    d:array[0..MAX_N] of double;


procedure   enter();
var i:longint;
begin
    read(fi,n);
    for i:=1 to n do begin
        read(fi,a[i].x,a[i].y);
        a[n+i]:=a[i];
    end;
    a[0]:=a[n];
end;

function    goc(a,b:recPoint):double;
var t:double;
begin
    t:=sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
    if t = 0 then exit(0)
    else exit((a.y-b.y)/t);
end;

procedure   init();
var i:longint;
begin
    k:=1;
    for i:=2 to n do
        if a[i].x < a[k].x then k:=i;
    for i:=k+1 to k+n do d[i]:=goc(a[i],a[k]);
end;

procedure   get_line(p1,p2:recPoint;    var a,b,c:double);
begin
    a:=p1.y - p2.y;
    b:=p2.x - p1.x;
    c:=-(a*p1.x + b*p1.y);
end;

function    f(a,b,c:double; p:recPoint):double;
begin   exit(a*p.x + b*p.y + c);    end;


function    check(p:recPoint):boolean;
var l,r,mid,i:longint;
    g,a1,b1,c1:double;
begin
    if p.x <= a[k].x then exit(false);
    l:=k+1; r:=k+n-1;
    g:=goc(p,a[k]);
    if (g <= d[l]) or (g >= d[r]) then exit(false);
    while l <= r do begin
        mid:=(l+r) shr 1;
        if d[mid] <= g then begin
            i:=mid;
            l:=mid+1;
        end
        else r:=mid-1;
    end;
    get_line(a[i],a[i+1],a1,b1,c1);
    exit(f(a1,b1,c1,p)*f(a1,b1,c1,a[k]) > 0);
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
    assign(fi,'METERAIN.in');    reset(fi);
    assign(fo,'METERAIN.out');   rewrite(fo);
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