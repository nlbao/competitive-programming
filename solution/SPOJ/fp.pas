uses    math;

const   MAX_N = 111;
        MAX_K = 111;
        MODUN = 9;

type    mString = ansiString;
        recNum = record
            value:mString;
            sum,len:longint;
        end;

var fi,fo:text;
    nTest,n,m:longint;
    a:array[0..MAX_N] of recNum;
    f:array[0..1,0..MAX_K,0..MAX_N] of ansiString;


procedure   enter();
var i,j,x:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do with a[i] do begin
        read(fi,x);
        str(x,value);
        len:=length(value);
        sum:=0;
        for j:=1 to len do
            sum:=(sum + ord(value[j])-ord('0')) mod MODUN;
    end;
end;


function    cmp(x,y:recNum):longint;
var i:longint;
    s1,s2:mString;
begin
    s1:=x.value+y.value;
    s2:=y.value+x.value;
    if s1 < s2 then exit(-1);
    if s1 > s2 then exit(1);
    exit(0);
end;


procedure   sort(l,r:longint);
var i,j:longint;
    p,t:recNum;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=a[i];
    i:=l;   j:=r;
    repeat
        while cmp(a[i],p) = 1 do inc(i);
        while cmp(a[j],p) = -1  do dec(j);
        if i <= j then begin
            t:=a[i];
            a[i]:=a[j];
            a[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


function    cmp_num(a,b:ansiString):longint;
var i,n,m:longint;
begin
    n:=length(a);
    m:=length(b);
    if n < m then exit(-1);
    if n > m then exit(1);
    for i:=1 to n do
        if a[i] < b[i] then exit(-1)
        else if a[i] > b[i] then exit(1);
    exit(0);
end;


procedure   solve();
var i,j,k,t,tt,r:longint;
    s:ansiString;
begin
    //for i:=1 to n do writeln(a[i].value,' ',a[i].sum);

    t:=0;
    for i:=0 to m do
        for j:=0 to MODUN-1 do begin
            f[0][i][j]:='-1';
            f[1][i][j]:='-1';
        end;

    for i:=1 to n do begin
        tt:=t;
        t:=(t+1) and 1;

        for k:=0 to MODUN-1 do f[t][1][k]:=f[tt][1][k];
        r:=a[i].sum;
        s:=a[i].value;
        if (f[t][1][r] = '-1') or (cmp_num(f[t][1][r],s) = -1) then
            f[t][1][r]:=s;

        for j:=2 to min(m,i) do begin
            for k:=0 to MODUN-1 do f[t][j][k]:=f[tt][j][k];
            for k:=0 to MODUN-1 do begin
                if f[tt][j-1][k] <> '-1' then begin
                    r:=(k + a[i].sum) mod MODUN;
                    s:=f[tt][j-1][k] + a[i].value;
                    if (f[t][j][r] = '-1') or (cmp_num(f[t][j][r],s) = -1) then
                        f[t][j][r]:=s;
                end;
            end;
        end;
    end;
    writeln(fo,f[t][m][0]);
end;


begin
    assign(fi,'fp.in');     reset(fi);
    assign(fo,'fp.out');    rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter();
        randomize;
        sort(1,n);
        solve();
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.