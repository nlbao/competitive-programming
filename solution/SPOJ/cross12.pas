uses    math;

const   MAX_N = 10004;
        MAX_M = 100005;
        MAX_R = 102;
        oo = 1000000000;

var fi,fo:text;
    n,m:longint;
    r,v,f:array[0..MAX_N] of longint;
    s:ansiString;
    next:array[0..MAX_M] of longint;
    a:array[0..MAX_R] of longint;


procedure   enter();
var i:longint;
begin
    read(fi,n,m);
    for i:=1 to n do read(fi,r[i]);
    readln(fi);
    readln(fi,s);
end;


procedure   init();
var i,j,pos,len:longint;
begin
    next[m]:=m+1;
    for i:=m-1 downto 0 do
        if s[i+1] = '0' then next[i]:=i+1
        else next[i]:=next[i+1];

    for i:=1 to MAX_R do begin
        a[i]:=0;
        pos:=0; len:=0;
        while pos <= m do begin
            j:=next[pos];
            if len+j-pos > i then begin
                inc(a[i]);
                len:=0;
            end;
            len:=len+j-pos;
            pos:=j;
        end;
        inc(a[i]);
    end;
end;


procedure   sort(l,r:longint);
var i,j,p,t:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=v[i];
    i:=l;   j:=r;
    repeat
        while v[i] < p do inc(i);
        while v[j] > p do dec(j);
        if i <= j then begin
            t:=v[i];
            v[i]:=v[j];
            v[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


procedure   solve();
var i:longint;
begin
    for i:=1 to n do v[i]:=a[r[i]];
    randomize;
    sort(1,n);

    f[0]:=0;
    f[1]:=v[1];
    f[2]:=v[2];
    for i:=3 to n do
        f[i]:=min(f[i-1]+v[1]+v[i], f[i-2]+v[1]+v[i]+2*v[2]);
    writeln(fo,f[n]);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'CROSS12.in');    reset(fi);
    assign(fo,'CROSS12.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    init();
    solve();
    close(fi);
    close(fo);
end.