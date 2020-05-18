const   MAX_N = 200010;
        MAX_K = 200010;
        oo = 2100000000;

var fi,fo:text;
    n,m:longint;
    t,head:array[0..MAX_N] of longint;
    a:array[0..MAX_K] of longint;


procedure   qsort(l,r:longint);
var i,j,p,t:longint;
begin
    if l >= r then exit;
    p:=a[l+random(r-l+1)];
    i:=l;   j:=r;
    repeat
        while a[i] < p do inc(i);
        while a[j] > p do dec(j);
        if i <= j then begin
            t:=a[i];    a[i]:=a[j];     a[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    qsort(l,j); qsort(i,r);
end;

procedure   enter;
var i,j,k:longint;
begin
    readln(fi,n,m);
    k:=0;
    for i:=1 to n+1 do head[i]:=0;
    for i:=1 to n do begin
        read(fi,t[i],head[i+1]);
        for j:=1 to head[i+1] do begin
            inc(k);
            read(fi,a[k]);
        end;
    end;
    for i:=2 to n+1 do begin
        head[i]:=head[i-1]+head[i];
        randomize;
        qsort(head[i-1]+1,head[i]);
    end;
end;

function    count(x:longint):longint;
var i,l,r,p,c,mid:longint;
begin
    c:=0;
    for i:=1 to n do begin
        l:=head[i]+1;   r:=head[i+1];
        p:=l-1;
        while l <= r do begin
            mid:=(l+r) shr 1;
            if a[mid] <= x then begin
                p:=mid;
                l:=mid+1;
            end
            else r:=mid-1;
        end;
        c:=c+(p-head[i]);
        x:=x+t[i];
    end;
    exit(c);
end;

procedure   solve;
var i,st,l,r,mid,res:longint;
begin
    st:=0;
    for i:=1 to n do st:=st+t[i];
    res:=oo;
    l:=0;   r:=oo;
    repeat
        mid:=(l+r) shr 1;
        if count(mid) >= m then begin
            res:=mid+st;
            r:=mid-1;
        end
        else l:=mid+1;
    until l > r;
    writeln(fo,res);
end;


begin
    assign(fi,'NKBus.in');  reset(fi);
    assign(fo,'NKBus.out'); rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.