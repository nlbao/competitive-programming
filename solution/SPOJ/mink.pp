const   MAX_N = 50010;

var fi,fo:text;
    nTest:longint;
    a,q:array[0..MAX_N] of longint;


procedure   solve();
var i,n,k,l,r:longint;
begin
    read(fi,n,k);
    for i:=1 to n do read(fi,a[i]);

    l:=1;   r:=0;
    for i:=1 to k-1 do begin
        while (r >= l) and (a[q[r]] > a[i]) do dec(r);
        inc(r);
        q[r]:=i;
    end;

    for i:=k to n do begin
        while (l <= r) and (q[l] <= i-k) do inc(l);
        while (r >= l) and (a[q[r]] > a[i]) do dec(r);
        inc(r);
        q[r]:=i;
        write(fo,a[q[l]],' ');
    end;
end;


begin
    assign(fi,'mink.in');   reset(fi);
    assign(fo,'mink.out');  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        solve();
        writeln(fo);
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.