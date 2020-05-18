const   MAX_N = 100010;
        oo = 1000000000;

var fi,fo:text;
    nTest,n:longint;
    a,b,c,t:array[0..MAX_N] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
    for i:=1 to n do read(fi,b[i]);
    for i:=1 to n do read(fi,c[i]);
end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   qsort(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    p:=a[l+random(r-l+1)];
    i:=l;   j:=r;
    repeat
        while a[i] < p do inc(i);
        while a[j] > p do dec(j);
        if i <= j then begin
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            swap(c[i],c[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    qsort(l,j); qsort(i,r);
end;

procedure   update(i,value:longint);
begin
    if i > n then exit;
    t[i]:=min(t[i],value);
    update(i+(i and (-i)),value);
end;

function    get(i:longint):longint;
begin
    if i < 1 then exit(oo);
    exit(min(get(i-(i and (-i))),t[i]));
end;

procedure   solve;
var i,res:longint;
begin
    randomize;
    qsort(1,n);
    res:=0;
    for i:=0 to n+1 do t[i]:=oo;
    for i:=1 to n do begin
        if get(b[i]-1) > c[i] then inc(res);
        update(b[i],c[i]);
    end;
    writeln(fo,res);
end;

begin
    assign(fi,'niceday.in');     reset(fi);
    assign(fo,'niceday.out');    rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.