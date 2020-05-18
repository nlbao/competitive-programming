{
    PROB: climb
    LANG: PASCAL
    ID: storm59061
}

const   MAX_N = 25010;

var fi,fo:text;
    n,n1,n2:longint;
    a,b,c,d:array[0..MAX_N] of longint;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

procedure   enter;
var i,x,y:longint;
begin
    readln(fi,n);
    n1:=0;  n2:=0;
    for i:=1 to n do begin
        readln(fi,x,y);
        if x < y then begin
            inc(n1);
            a[n1]:=x;   b[n1]:=y;
        end
        else begin
            inc(n2);
            c[n2]:=x;   d[n2]:=y;
        end;
    end;
end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   qsort1(l,r:longint);
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
            inc(i); dec(j);
        end;
    until i >= j;
    qsort1(l,j);    qsort1(i,r);
end;

procedure   qsort2(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    p:=d[l+random(r-l+1)];
    i:=l;   j:=r;
    repeat
        while d[i] > p do inc(i);
        while d[j] < p do dec(j);
        if i <= j then begin
            swap(c[i],c[j]);
            swap(d[i],d[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    qsort2(l,j);    qsort2(i,r);
end;

procedure   solve;
var i,ta,tb,res:longint;
begin
    randomize;  qsort1(1,n1);
    randomize;  qsort2(1,n2);
    res:=0;
    ta:=0;  tb:=0;
    for i:=1 to n1 do begin
        ta:=ta+a[i];
        tb:=max(ta,tb)+b[i];
    end;
    res:=tb;
    for i:=1 to n2 do begin
        ta:=ta+c[i];
        tb:=max(ta,tb)+d[i];
    end;
    res:=max(res,tb);
    writeln(fo,res);
end;

begin
    assign(fi,'climb.in');  reset(fi);
    assign(fo,'climb.out'); rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.