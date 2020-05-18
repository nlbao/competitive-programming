var fi,fo:text;
    n,k,i,c:longint;
    a:array[0..60] of longint;

begin
    assign(fi,'158A.in');   reset(fi);
    assign(fo,'158A.out');  rewrite(fo);
    readln(fi,n,k);
    for i:=1 to n do read(fi,a[i]);
    c:=0;
    for i:=1 to n do
        if (a[i] > 0) and (a[i] >= a[k]) then inc(c);
    writeln(fo,c);
    close(fo);
    close(fi);
end.