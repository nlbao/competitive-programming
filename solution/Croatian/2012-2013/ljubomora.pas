const   MAX_M = 300010;
        oo = 1000000000000;

type    ll = int64;

var fi,fo:text;
    n,m,i:longint;
    res,l,r,mid:ll;
    a:array[0..MAX_M] of longint;


function    check(x:ll):boolean;
var i:longint;
    sum,t:ll;
begin
    sum:=0;
    for i:=1 to m do begin
        t:=a[i] div x;
        sum:=sum+t;
        if a[i] mod x > 0 then sum:=sum+1;
        if sum > n then exit(false);
    end;
    exit(true);
end;


begin
    assign(fi,''{'ljubomora.in'});  reset(fi);
    assign(fo,''{'ljubomora.out'}); rewrite(fo);
    read(fi,n,m);
    for i:=1 to m do read(fi,a[i]);
    res:=oo;
    l:=1;   r:=oo;
    while l <= r do begin
        mid:=(l+r) shr 1;
        if check(mid) = true then begin
            res:=mid;
            r:=mid-1;
        end
        else l:=mid+1;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.
