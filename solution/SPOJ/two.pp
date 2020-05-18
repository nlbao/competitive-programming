const   MAX_N = 10010;

var fi,fo:text;
    n:longint;
    a,b,id:array[0..MAX_N] of longint;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
    for i:=1 to n do begin
        read(fi,b[i]);
        id[i]:=i;
    end;
end;

function    cmp(a1,b1,a2,b2:longint):longint;
begin
    if (a1 <= b1) and (a2 > b2) then exit(-1);
    if (a1 > b1) and (a2 <= b2) then exit(1);
    if (a1 <= b1) and (a2 <= b2) then begin
        if a1 < a2 then exit(-1);
        if a1 > a2 then exit(1);
    end;
    if (a1 > b1) and (a2 > b2) then begin
        if b1 > b2 then exit(-1);
        if b1 < b2 then exit(1);
    end;
    exit(0);
end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   qsort(l,r:longint);
var i,j,p1,p2:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l+1);
    p1:=a[i];   p2:=b[i];
    i:=l;   j:=r;
    repeat
        while cmp(a[i],b[i],p1,p2) < 0 do inc(i);
        while cmp(a[j],b[j],p1,p2) > 0 do dec(j);
        if i <= j then begin
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            swap(id[i],id[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    qsort(l,j); qsort(i,r);
end;

procedure   solve;
var i,ta,tb:longint;
begin
    randomize;
    qsort(1,n);
    ta:=0;  tb:=0;
    for i:=1 to n do begin
        ta:=ta+a[i];
        tb:=max(ta,tb)+b[i];
    end;
    writeln(fo,tb);
    for i:=1 to n do write(fo,id[i],' ');
end;

begin
    assign(fi,'two.in');    reset(fi);
    assign(fo,'two.out');   rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.

