uses    math;
const   MAX_N = 30010;


var fi,fo:text;
    n,top,i,l,r,mid,t:longint;
    a,f:array[0..MAX_N] of longint;

begin
    assign(fi,'lis.in');    reset(fi);
    assign(fo,'lis.out');   rewrite(fo);
    read(fi,n);
    for i:=1 to n do read(fi,a[i]);
    top:=0;
    for i:=1 to n do begin
        t:=0;
        l:=1;   r:=top;
        while l <= r do begin
            mid:=(l+r) shr 1;
            if a[f[mid]] < a[i] then begin
                t:=mid;
                l:=mid+1;
            end
            else r:=mid-1;
        end;
        inc(t);
        f[t]:=i;
        top:=max(top,t);
    end;
    writeln(fo,top);
    close(fo);
    close(fi);
end.