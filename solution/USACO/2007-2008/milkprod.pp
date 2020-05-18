uses    math;

const   MAX_N = 1000010;
        MAX_M = 1010;

var fi,fo:text;
    n,m,r,i,j,res:longint;
    a,b,c,f:array[0..MAX_M] of longint;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   sort(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    p:=a[l+random(r-l)];
    i:=l;   j:=r;
    repeat
        while a[i] < p do inc(i);
        while a[j] > p do dec(j);
        if i <= j then begin
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            swap(c[i],c[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j); sort(i,r);
end;

begin
    assign(fi,'milkprod.in');   reset(fi);
    assign(fo,'milkprod.out');  rewrite(fo);
    randomize;
    readln(fi,n,m,r);
    for i:=1 to m do
        readln(fi,a[i],b[i],c[i]);
    sort(1,m);
    f[1]:=c[1];
    res:=c[1];
    for i:=2 to m do begin
        f[i]:=0;
        for j:=i-1 downto 1 do
            if a[i]-b[j] >= r then f[i]:=max(f[i],f[j]);
        f[i]:=f[i]+c[i];
        res:=max(res,f[i]);
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.
