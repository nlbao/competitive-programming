const   INPUT = 'TABOVI.in';
        OUTPUT = 'TABOVI.out';
        MAX_N = 1010;

var fi,fo:text;
    n:longint;
    a,b:array[0..MAX_N] of longint;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
    for i:=1 to n do read(fi,b[i]);
end;

procedure   solve;
var i,j,k,l,r,res:longint;
    c:array[0..MAX_N] of longint;
begin
    res:=0;
    for i:=1 to n do c[i]:=b[i]-a[i];
    for i:=1 to n do begin
        for j:=1 to n do
            if c[j] <> 0 then break;
        if c[j] = 0 then break;
        l:=j;   r:=j;
        while (l > 1) and (c[l-1]*c[l] > 0) do dec(l);
        while (r < n) and (c[r+1]*c[r] > 0) do inc(r);
        k:=MAX_N;
        for j:=l to r do
            if abs(c[j]) < k then k:=abs(c[j]);
        inc(res,k);
        if c[l] > 0 then k:=-k;
        for j:=l to r do inc(c[j],k);
    end;
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.