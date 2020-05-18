{$M 16777216}
uses    math;

const   MAX_N = 200005;
        MAX_M = 200005;
        oo = 1000000000;

type    ll = int64;

var fi,fo:text;
    n,m,maxR:longint;
    ax,ay,bx,by:ll;
    x,y:array[0..MAX_N] of ll;
    ra,rb,id,res:array[0..MAX_M] of longint;
    da,db:array[0..MAX_N] of double;
    f:array[0..MAX_N] of longint;

procedure   enter();
var i:longint;
begin
    read(fi,n);
    for i:=1 to n do read(fi,x[i],y[i]);
    read(fi,ax,ay,bx,by,m);
    maxR:=0;
    for i:=1 to m do begin
        read(fi,ra[i],rb[i]);
        id[i]:=i;
        maxR:=max(maxR,max(ra[i],rb[i]));
    end;
end;

procedure   solve_0();
var i,j:longint;
    r1,r2:ll;
    da,db:array[0..2003] of ll;
begin
    for i:=1 to n do begin
        da[i]:=sqr(ax-x[i])+sqr(ay-y[i]);
        db[i]:=sqr(bx-x[i])+sqr(by-y[i]);
    end;
    for i:=1 to m do begin
        res[i]:=0;
        r1:=ra[i];  r2:=rb[i];
        r1:=r1*r1;  r2:=r2*r2;
        for j:=1 to n do
            if (da[j] <= r1) or (db[j] <= r2) then inc(res[i]);
        writeln(fo,res[i]);
    end;
end;


procedure   swap(var x,y:ll);
var t:ll;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   sort_1(l,r:longint);
var i,j:longint;
    p1,p2,t:ll;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p1:=y[i];   p2:=x[i];
    i:=l;   j:=r;
    repeat
        while (y[i] > p1) or ((y[i] = p1) and (x[i] > p2)) do inc(i);
        while (y[j] < p1) or ((y[j] = p1) and (x[j] < p2)) do dec(j);
        if i <= j then begin
            t:=y[i];    y[i]:=y[j];     y[j]:=t;
            t:=x[i];    x[i]:=x[j];     x[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort_1(l,j);
    sort_1(i,r);
end;


procedure   sort_2(l,r:longint);
var i,j,p1,p2,t:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p1:=rb[i];  p2:=ra[i];
    i:=l;   j:=r;
    repeat
        while (rb[i] > p1) or ((rb[i] = p1) and (ra[i] > p2)) do inc(i);
        while (rb[j] < p1) or ((rb[j] = p1) and (ra[j] < p2)) do dec(j);
        if i <= j then begin
            t:=rb[i];   rb[i]:=rb[j];   rb[j]:=t;
            t:=ra[i];   ra[i]:=ra[j];   ra[j]:=t;
            t:=id[i];   id[i]:=id[j];   id[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort_2(l,j);
    sort_2(i,r);
end;


{function    find(x:longint):longint;
var l,r,mid,t:longint;
begin
    t:=oo;
    l:=1;   r:=n;
    while l <= r do begin
        mid:=(l+r) shr 1;
        if db[mid] <= x then begin
            t:=mid;
            r:=mid-1;
        end
        else l:=mid+1;
    end;
    exit(t);
end;  }


procedure   up(i:longint);
begin
    if i > maxR then exit;
    f[i]:=f[i]+1;
    up(i+(i and (-i)));
end;

function    get(i:longint):longint;
begin
    if i < 1 then exit(0);
    if i > maxR then exit(get(maxR));
    exit(get(i-(i and (-i))) + f[i]);
end;


procedure   solve();
var i,l,pos,c:longint;
    a,b,t:ll;
begin
    for i:=1 to n do begin
        a:=sqr(ax-x[i])+sqr(ay-y[i]);
        b:=sqr(bx-x[i])+sqr(by-y[i]);
        x[i]:=a;    y[i]:=b;
    end;
    randomize;
    sort_1(1,n);
    sort_2(1,m);
    for i:=1 to n do begin
        da[i]:=sqrt(x[i]);
        db[i]:=sqrt(y[i]);
    end;

    l:=1;   pos:=1;
    fillchar(f,sizeof(f),0);
    for i:=1 to m do begin
        c:=0;
        while (pos <= n) and (db[pos] > rb[i]) do inc(pos);
        while (l < pos) and (l <= n) do begin
            t:=trunc(da[l]);
            if da[l] > t then t:=t+1;
            if t <= maxR then up(t);
            inc(l);
        end;
        c:=get(ra[i]) + max(n-pos+1,0);
        //if c <> res[id[i]] then begin   writeln(fo,'WA : ',i,' ',id[i]); exit;  end;
        res[id[i]]:=c;
    end;
    for i:=1 to m do writeln(fo,res[i]);
end;


begin
    assign(fi,'NUCLEAR.inp');   reset(fi);
    assign(fo,'NUCLEAR.out');   rewrite(fo);
    enter();
    if (n <= 1000) or (m <= 1000) then solve_0()
    else solve();
    close(fi);
    close(fo);
end.