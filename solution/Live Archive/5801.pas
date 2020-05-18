uses    math;

type    ll = int64;

var fi,fo:text;
    nTest,test_id,n,m:longint;


function    solve(n,m:longint):longint;
var i:longint;
    x,d:ll;
begin
    if (n < 0) or (m < 0) or (m > n) then exit(0);
    if (m = 0) or (m = n) then exit(1);
    if n = 2 then exit(2);
    x:=n;   d:=n-3;
    for i:=1 to m-1 do begin
        x:=x+d;
        d:=d-2;
    end;
    exit(x);
end;

begin
    assign(fi,'5801.in');    reset(fi);
    assign(fo,'5801.out');   rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,test_id,n,m);
        writeln(fo,test_id,' ',solve(n,m));
        dec(nTest);
    end;
    close(fi);
    close(fo);
end.

