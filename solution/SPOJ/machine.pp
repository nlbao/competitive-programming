const   MAX_N = 10010;

var fi,fo:text;
    n:longint;
    x,y,z,a,b,id:array[0..MAX_N] of longint;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,x[i]);
    for i:=1 to n do read(fi,y[i]);
    for i:=1 to n do begin
        read(fi,z[i]);
        id[i]:=i;
        a[i]:=x[i]+y[i];
        b[i]:=y[i]+z[i];
    end;
end;

function    cmp(a1,b1,a2,b2:longint):longint;
begin
    if a1 <= b1 then
        if a2 > b2 then exit(-1)
        else
            if a1 < a2 then exit(-1)
            else if a1 > a2 then exit(1);

    if a1 > b1 then
        if a2 <= b2 then exit(1)
        else
            if b1 > b2 then exit(-1)
            else if b1 < b2 then exit(1);
    exit(0);
end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   qsort(l,r:longint);
var i,j,p1,p2:longint;
begin
    if l >= r then exit;
    i:=id[l+random(r-l+1)];
    p1:=a[i];   p2:=b[i];
    i:=l;   j:=r;
    repeat
        while cmp(a[id[i]],b[id[i]],p1,p2) < 0 do inc(i);
        while cmp(a[id[j]],b[id[j]],p1,p2) > 0 do dec(j);
        if i <= j then begin
            swap(id[i],id[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    qsort(l,j); qsort(i,r);
end;

procedure   solve;
var i,j,tx,ty,tz:longint;
begin
    randomize;
    qsort(1,n);
    tx:=0;  ty:=0;  tz:=0;
    for i:=1 to n do begin
        j:=id[i];
        tx:=tx+x[j];
        ty:=max(tx,ty)+y[j];
        tz:=max(ty,tz)+z[j];
    end;
    writeln(fo,tz);
    for i:=1 to n do write(fo,id[i],' ');
end;

begin
    assign(fi,'machine.in');    reset(fi);
    assign(fo,'machine.out');   rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
