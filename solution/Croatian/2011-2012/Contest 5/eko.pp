type    int = int64;

var fi,fo:text;
    n,i:longint;
    m,l,r,mid,res:int;
    a:array[0..1000010] of longint;

function    max(x,y:int):int;   begin   if x > y then exit(x);  exit(y);    end;

function    ok(x:int):boolean;
var i:longint;
    s:int;
begin
    s:=0;
    for i:=1 to n do
        if a[i] > x then begin
            s:=s+int64(a[i])-x;
            if s >= m then exit(true);
        end;
    exit(false);
end;

begin
    assign(fi,''{'eko.in'});    reset(fi);
    assign(fo,''{'eko.out'});   rewrite(fo);
    readln(fi,n,m);
    l:=0;   r:=0;   res:=0;
    for i:=1 to n do begin
        read(fi,a[i]);
        r:=max(r,a[i]);
    end;
    while (l <= r) do begin
        mid:=(l+r) shr 1;
        if ok(mid) then begin
            res:=mid;
            l:=mid+1;
        end
        else r:=mid-1;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.