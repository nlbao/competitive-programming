var fi,fo:text;
    n,i:longint;
    a:array[0..100010] of longint;

procedure   sort(l,r:longint);
var i,j,p,t:longint;
begin
    if l >= r then exit;
    p:=a[l+random(r-l)];
    i:=l;   j:=r;
    repeat
        while a[i] < p do inc(i);
        while a[j] > p do dec(j);
        if i <= j then begin
            t:=a[i];    a[i]:=a[j];     a[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j); sort(i,r)
end;


begin
    assign(fi,'sort25.in');      reset(fi);
    assign(fo,'sort25.out');     rewrite(fo);
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
    randomize;
    sort(1,n);
    for i:=1 to n do writeln(fo,a[i]);
    close(fo);
    close(fi);
end.