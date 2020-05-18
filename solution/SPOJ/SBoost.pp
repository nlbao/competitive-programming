const   INPUT = 'SBoost.in';
        OUTPUT = 'SBoost.out';
        MAX_N = 10010;

var fi,fo:text;
    n:longint;
    sf,sm:double;
    f,m:array[0..MAX_N] of double;
    id:array[0..MAX_N] of longint;

procedure   enter;
var i:longint;
begin
    readln(fi,sf,sm,n);
    for i:=1 to n do begin
        read(fi,f[i],m[i]);
        id[i]:=i;
    end;
end;

procedure   quick_sort(l,r:longint);
var i,j,tmp:longint;
    pf,pm:double;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    tmp:=id[(i+j) div 2];
    pf:=f[tmp]; pm:=m[tmp];
    repeat
        while f[id[i]]*pm < pf*m[id[i]] do inc(i);
        while f[id[j]]*pm > pf*m[id[j]] do dec(j);
        if i <= j then begin
            tmp:=id[i]; id[i]:=id[j];   id[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;

procedure   solve;
var i,j:longint;
    check:boolean;
    res:array[0..MAX_N] of boolean;
begin
    quick_sort(1,n);
    for i:=1 to n do res[i]:=false;
    check:=false;
    for i:=n downto 1 do begin
        j:=id[i];
        if sf/sm < (sf+f[j])/(sm+m[j]) then begin
            sf:=sf+f[j];    sm:=sm+m[j];
            res[j]:=true;
            check:=true;
        end;
    end;
    if check = false then writeln(fo,'NONE')
    else
        for i:=1 to n do if res[i] = true then writeln(fo,i);
end;


begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.