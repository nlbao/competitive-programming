uses    math;

const   MAX_N = 50010;
        m = 50010;

var fi,fo:text;
    nTest,n,u,v:longint;
    a,b,c:array[0..MAX_N] of longint;
    f:array[0..7*m] of longint;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do begin
        read(fi,a[i],b[i],c[i]);
        inc(a[i]);  inc(b[i]);
    end;
end;

procedure   qsort(l,r:longint);
var i,j,p1,p2:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l+1);
    p1:=b[i];   p2:=c[i];
    i:=l;   j:=r;
    repeat
        while (b[i] < p1) or ((b[i] = p1) and (c[i] > p2)) do inc(i);
        while (b[j] > p1) or ((b[j] = p1) and (c[j] < p2)) do dec(j);
        if i <= j then begin
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            swap(c[i],c[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    qsort(l,j); qsort(i,r);
end;

procedure   init;
var i:longint;
begin
    randomize;
    qsort(1,n);
    for i:=1 to 7*m do f[i]:=0;
end;

procedure   fix(x,y:longint);   begin   u:=x;   v:=y;   end;

procedure   update(k,l,r:longint);
var mid:longint;
begin
    if (l > r) or (l > v) or (r < u) or (f[k] = r-l+1) then exit;
    if (u <= l) and (r <= v) then begin
        f[k]:=r-l+1;
        exit;
    end;
    mid:=(l+r) shr 1;
    update(k shl 1,l,mid);
    update((k shl 1)+1,mid+1,r);
    if f[k] < r-l+1 then
        f[k]:=f[k shl 1]+f[(k shl 1)+1];
end;

function    get(k,l,r:longint):longint;
var mid:longint;
begin
    if (l > r) or (l > v) or (r < u) then exit(0);
    if f[k] = r-l+1 then exit(min(r,v)-max(l,u)+1);
    if (u <= l) and (r <= v) then exit(f[k]);
    mid:=(l+r) shr 1;
    exit(get(k shl 1,l,mid)+get((k shl 1)+1,mid+1,r));
end;

function    find(i,j,value:longint):longint;
var l,r,mid,t:longint;
begin
    l:=i;   r:=j;   t:=j;
    repeat
        mid:=(l+r) shr 1;
        fix(mid,j);
        if (j-mid+1)-get(1,1,m) >= value then begin
            t:=mid;
            l:=mid+1;
        end
        else r:=mid-1;
    until l > r;
    exit(t);
end;

procedure   solve;
var i,t,p,res:longint;
begin
    res:=0;
    for i:=1 to n do begin
        fix(a[i],b[i]);
        t:=c[i]-get(1,1,m);
        if t > 0 then begin
            res:=res+t;
            p:=find(b[i]-c[i]+1,b[i],t);
            fix(p,b[i]);
            update(1,1,m);
        end;
    end;
    writeln(fo,res);
end;

begin
    assign(fi,'interval.in');   reset(fi);
    assign(fo,'interval.out');  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        init;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
