const   MAX_N = 20010;

var fi,fo:text;
    nTest,n:longint;
    a,b:array[0..MAX_N] of longint;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,a[i],b[i]);
end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   quick_sort(l,r:longint);
var i,j,p1,p2:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l+1);
    p1:=a[i];   p2:=b[i];
    i:=l;   j:=r;
    repeat
        while (a[i] > p1) or ((a[i] = p1) and (b[i] < p2)) do inc(i);
        while (a[j] < p1) or ((a[j] = p1) and (b[j] > p2)) do dec(j);
        if i <= j then begin
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;

procedure   solve;
var i,k,l,r,mid,t:longint;
    f:array[0..MAX_N] of longint;
begin
    k:=1;   f[1]:=b[1];
    for i:=2 to n do begin
        l:=1;   r:=k;   t:=0;
        while l <= r do begin
            mid:=(l+r) shr 1;
            if f[mid] > b[i] then r:=mid-1
            else begin
                t:=mid;
                l:=mid+1;
            end;
        end;
        inc(t); f[t]:=b[i];
        if t > k then inc(k);
    end;
    writeln(fo,k);
end;

begin
    assign(fi,'MDolls.in');   reset(fi);
    assign(fo,'MDolls.out');  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        randomize;
        quick_sort(1,n);
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.