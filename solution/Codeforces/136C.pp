const   INPUT = '136C.in';
        OUTPUT = '136C.out';
        MAX_N = 100010;
        MAX_INT = 1000000000;

var fi,fo:text;
    n,i:longint;
    a,x:array[0..MAX_N] of longint;

procedure   quick_sort(l,r:longint);
var i,j,p,t:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=a[i+random(j-i+1)];
    repeat
        while a[i] < p do inc(i);
        while a[j] > p do dec(j);
        if i <= j then begin
            t:=a[i];    a[i]:=a[j]; a[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;

procedure   solve;
var i:longint;
begin
    if a[1] = a[n] then begin
        if a[1] = 1 then begin
            x[1]:=1;
            x[n]:=2;
        end
        else begin
            x[n]:=a[1];
            x[1]:=1;
        end;
        for i:=2 to n-1 do x[i]:=a[1];
        exit;
    end;
    x[1]:=1;
    for i:=2 to n do x[i]:=a[i-1];
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
    randomize;
    quick_sort(1,n);
    solve;
    for i:=1 to n do write(fo,x[i],' ');
    close(fo);
    close(fi);
end.
