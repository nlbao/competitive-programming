const   INPUT = '50D.in';
        OUTPUT = '50D.out';
        MAX_N = 110;
        MAX_K = MAX_N;
        MAX_W = 1010;
        MAX_INT = 1000000000;
        e = 2.7182818284590452353602874713527;
        eps = 0.000001;

var fi,fo:text;
    n,k:longint;
    w:double;
    x,y,d,a:array[0..MAX_N] of double;


procedure   enter;
var i:longint;
begin
    readln(fi,n);
    readln(fi,k,w);
    readln(fi,x[0],y[0]);
    for i:=1 to n do begin
        readln(fi,x[i],y[i]);
        d[i]:=sqrt(sqr(x[0]-x[i])+sqr(y[0]-y[i]));
    end;
end;

function    p(d,r:double):double;
begin
    if d <= r then exit(1)
    else exit(exp(1-sqr(d)/sqr(r)));
end;

procedure   quick_sort(l,r:longint);
var i,j:longint;
    p,tmp:double;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=a[(i+j) shr 1];
    repeat
        while a[i] > p do inc(i);
        while a[j] < p do dec(j);
        if i <= j then begin
            tmp:=a[i]; a[i]:=a[j];  a[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;

function    solve:double;
var i:longint;
    l,r,mid,t,res:double;
begin
    {w:=w/1000;}
    l:=0;   r:=MAX_INT;
    res:=r;
    while r-l >= eps do begin
        mid:=(l+r)/2;
        for i:=1 to n do a[i]:=p(d[i],mid);
        quick_sort(1,n);
        t:=1000;
        for i:=1 to k do t:=t*a[i];
        writeln(mid:0:6);
        if (mid >= 0.6699) and (mid-0.6699 <= 0.0001) then begin
            writeln('!!! ',mid:0:6);
            for i:=1 to n do write('    ',a[i]:0:6);
            writeln;
        end;
        if t >= 1000-w then begin
            res:=mid;
            r:=mid;
            for i:=1 to n do write(a[i]:0:6,' ');
            writeln;
            writeln('                  ',res:0:6);
        end
        else l:=mid;
    end;
    writeln(p(d[1],0.66995796551):0:6);
    exit(res);
end;


begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    writeln(fo,solve:0:7);
    close(fo);
    close(fi);
end.