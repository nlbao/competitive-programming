var fi,fo:text;
    n,m,x,i:longint;
    a:array[0..100010] of longint;

function    find(x:longint):longint;
var l,r,mid:longint;
begin
    l:=1;   r:=n;
    while l <= r do begin
        mid:=(l+r) shr 1;
        if a[mid] = x then exit(1);
        if a[mid] < x then l:=mid+1
        else r:=mid-1;
    end;
    exit(0);
end;

begin
    assign(fi,'bs2509.in');      reset(fi);
    assign(fo,'bs2509.out');     rewrite(fo);
    readln(fi,n,m);
    for i:=1 to n do read(fi,a[i]);
    for i:=1 to m do begin
        readln(fi,x);
        writeln(fo,find(x));
    end;
    close(fo);
    close(fi);
end.