const   MAX_N = 100010;
        MAX_M = MAX_N;

var fi,fo:text;
    n,m:longint;
    p,s,f,g:array[0..MAX_N] of longint;
    b,d:array[0..MAX_M] of longint;

function    max(x,y:longint):longint;   begin   if x > y then exit(x)   else exit(y);   end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,p[i]);
    readln(fi,m);
    for i:=1 to m do readln(fi,b[i],d[i]);
end;

procedure   quick_sort(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    p:=b[l+random(r-l+1)];
    i:=l;   j:=r;
    repeat
        while b[i] < p do inc(i);
        while b[j] > p do dec(j);
        if i <= j then begin
            swap(b[i],b[j]);
            swap(d[i],d[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;

function    solve:longint;
var i,j,l,r,minb,maxf:longint;
begin
    randomize;
    quick_sort(1,m);
    s[0]:=0;
    for i:=1 to n do begin
        s[i]:=s[i-1]+p[i];
        f[i]:=0;    g[i]:=0;
    end;
    maxf:=0;    minb:=0;
    for i:=1 to m do begin
        l:=max(minb,b[i]-d[i]);
        if l >= b[i] then exit(0);
        for j:=l to b[i]-1 do begin
            r:=j+d[i];
            if r > n then break;
            f[r]:=0;    g[r]:=i;
            if j > l then f[r]:=max(f[r],f[r-1]);
            if g[j] = i-1 then f[r]:=max(f[r],f[j]+s[r]-s[j])
            else f[r]:=max(f[r],maxf+s[r]-s[j]);
        end;
        minb:=l+d[i];
        maxf:=0;
        for j:=l to b[i]-1 do begin
            r:=j+d[i];
            if r > n then break;
            maxf:=max(maxf,f[r]);
        end;
        {for j:=1 to n do write(f[j],' ');
        writeln;}
    end;
    maxf:=0;
    for i:=1 to n do
        if g[i] = m then maxf:=max(maxf,f[i]);
    exit(maxf);
end;

begin
    assign(fi,'MFish.in');  reset(fi);
    assign(fo,'MFish.out'); rewrite(fo);
    enter;
    writeln(fo,solve);
    close(fo);
    close(fi);
end.