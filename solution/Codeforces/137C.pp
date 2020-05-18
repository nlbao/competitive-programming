const   INPUT = '137C.in';
        OUTPUT = '137C.out';
        MAX_N = 100010;
        MAX_INT = 1000000000;

var fi,fo:text;
    n,i,maxy,res:longint;
    x,y:array[0..MAX_N] of longint;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   quick_sort(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=x[i+random(j-i+1)];
    repeat
        while x[i] < p do inc(i);
        while x[j] > p do dec(j);
        if i <= j then begin
            swap(x[i],x[j]);
            swap(y[i],y[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,n);
    for i:=1 to n do readln(fi,x[i],y[i]);
    quick_sort(1,n);
    res:=0;
    maxy:=y[1];
    for i:=2 to n do
        if y[i] <= maxy then inc(res)
        else maxy:=y[i];
    writeln(fo,res);
    close(fo);
    close(fi);
end.

