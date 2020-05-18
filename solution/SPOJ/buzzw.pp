const   MAX_N = 1007;
        BASE = 10007;

var fi,fo:text;
    s,t:ansiString;
    n,m,i,res:longint;
    p,h,a:array[0..MAX_N] of int64;

procedure   init;
var i:longint;
begin
    i:=1;
    while i <= length(s) do begin
        if s[i] = ' ' then delete(s,i,1);
        inc(i);
    end;
    n:=length(s);
    p[0]:=1;    h[0]:=0;
    for i:=1 to n do begin
        p[i]:=longint(p[i-1]*BASE);
        h[i]:=longint(h[i-1]*BASE+ord(s[i]));
    end;
end;

function    get_h(i,j:longint):int64;
begin
    if i = 1 then exit(h[j]);
    exit(longint(h[j]-h[i-1]*p[j-i+1]));
end;

procedure   sort(l,r:longint);
var i,j:longint;
    p,t:int64;
begin
    if l >= r then exit;
    p:=a[l+random(r-l)];
    i:=l;   j:=r;
    repeat
        while a[i] < p do inc(i);
        while a[j] > p do dec(j);
        if i <= j then begin
            t:=a[i];    a[i]:=a[j];     a[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;

function    solve(len:longint):longint;
var i,j,k:longint;
begin
    m:=0;
    for i:=1 to n-len+1 do begin
        inc(m);
        a[m]:=get_h(i,i+len-1);
    end;
    randomize;
    sort(1,m);
    i:=1;   j:=1;   k:=0;
    while (i <= m) do begin
        while (j <= m) and (a[j] = a[i]) do inc(j);
        if j-i > k then k:=j-i;
        i:=j;
    end;
    exit(k);
end;


begin
    assign(fi,'buzzw.in');  reset(fi);
    assign(fo,'buzzw.out'); rewrite(fo);
    readln(fi,s);
    while length(s) > 0 do begin
        init();
        for i:=1 to n do begin
            res:=solve(i);
            if res > 1 then writeln(fo,res)
            else begin
                writeln(fo);
                break;
            end;
        end;
        readln(fi,s);
    end;
    close(fo);
    close(fi);
end.
