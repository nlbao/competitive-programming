const   MAX_N = 11;

var fi,fo:text;
    s:string;
    n,i,j,k:longint;
    f:array[0..MAX_N] of longint;


procedure   swap(var x,y:char);
var t:char;
begin   t:=x;   x:=y;   y:=t;   end;


procedure   sort(l,r:longint);
var i,j:longint;
    p:char;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=s[i];
    i:=l;   j:=r;
    repeat
        while s[i] < p do inc(i);
        while s[j] > p do dec(j);
        if i <= j then begin
            swap(s[i],s[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


begin
    assign(fi,'qbhv.in');   reset(fi);
    assign(fo,'qbhv.out');  rewrite(fo);
    readln(fi,s);
    n:=length(s);
    sort(1,n);

    f[0]:=1;
    for i:=1 to n do f[i]:=f[i-1]*i;
    k:=f[n];
    i:=1;
    repeat
        j:=i;
        while (j < n) and (s[j+1] = s[i]) do inc(j);
        k:=k div f[j-i+1];
        i:=j+1;
    until i > n;
    writeln(fo,k);

    writeln(fo,s);
    repeat
        k:=0;
        for i:=n-1 downto 1 do
            if s[i] < s[i+1] then begin
                k:=i;
                break;
            end;
        if k = 0 then break;

        for i:=n downto 1 do
            if s[i] > s[k] then begin
                swap(s[i],s[k]);
                sort(k+1,n);
                break;
            end;
        writeln(fo,s);
    until false;
    close(fo);
    close(fi);
end.