const   MAX_N = 100010;
        MAX_M = 100010;
        oo = 1000000000;

var fi,fo:text;
    n,m,u,v,value:longint;
    c:array[0..MAX_N] of longint;
    a,b:array[0..MAX_N] of longint;
    s,f:array[0..8*MAX_N] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

procedure   minc(var x,y:longint);  begin   x:=x+y; end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   qsort(l,r:longint);
var i,j,p1,p2:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l+1);
    p1:=b[i];   p2:=a[i];
    i:=l;   j:=r;
    repeat
        while (b[i] < p1) or ((b[i] = p1) and (a[i] > p2)) do inc(i);
        while (b[j] > p1) or ((b[j] = p1) and (a[j] < p2)) do dec(j);
        if i <= j then begin
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    qsort(l,j); qsort(i,r);
end;

procedure   enter;
var i:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do read(fi,c[i]);
    for i:=1 to m do read(fi,a[i],b[i]);
    randomize;
    qsort(1,m);
end;

procedure   init_IT(k,l,r:longint);
var mid:longint;
begin
    s[k]:=0;
    if l = r then f[k]:=c[l];
    if l >= r then exit;
    mid:=(l+r) shr 1;
    init_IT(k shl 1,l,mid);
    init_IT((k shl 1)+1,mid+1,r);
    f[k]:=min(f[k shl 1], f[(k shl 1)+1]);
end;

procedure   update_IT(k,l,r:longint);
var mid:longint;
begin
    if (l > r) or (l > v) or (r < u) then exit;
    if (u <= l) and (r <= v) then begin
        minc(s[k],value);
        minc(f[k],value);
        exit;
    end;
    mid:=(l+r) shr 1;
    update_IT(k shl 1,l,mid);
    update_IT((k shl 1)+1,mid+1,r);
    f[k]:=min(f[k shl 1], f[(k shl 1)+1])+s[k];
end;

function    get_IT(k,l,r:longint):longint;
var mid:longint;
begin
    if (l > r) or (l > v) or (r < u) then exit(oo);
    if (u <= l) and (r <= v) then exit(f[k]);
    mid:=(l+r) shr 1;
    exit(min(get_IT(k shl 1,l,mid), get_IT((k shl 1)+1,mid+1,r))+s[k]);
end;

procedure   solve;
var i,res:longint;
begin
    res:=0;
    init_IT(1,1,n);
    for i:=1 to m do begin
        u:=a[i];    v:=b[i];
        if get_IT(1,1,n) > 0 then begin
            inc(res);
            value:=-1;
            update_IT(1,1,n);
        end;
    end;
    writeln(fo,res);
end;

begin
    assign(fi,'barn.in');   reset(fi);
    assign(fo,'barn.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.