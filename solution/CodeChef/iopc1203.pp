const   MAX_N = 100010;
        MAX_M = 5*MAX_N;
        MODUN = 100000007;
        v:array['a'..'z'] of longint = (2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9);
        t:array['a'..'z'] of longint = (1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4);
        c:array[2..9] of longint = (3,3,3,3,3,4,3,4);

type    int = int64;

var fi,fo:text;
    nTest,n,m:longint;
    s:ansiString;
    a,f:array[-5..MAX_M] of int;

procedure   enter;
var i,j:longint;
begin
    readln(fi,s);
    m:=0;
    for i:=1 to length(s) do begin
        for j:=1 to t[s[i]] do begin
            inc(m);
            a[m]:=v[s[i]];
        end;
    end;
end;

function    mmod(x:int):int;    begin   exit(x mod MODUN);  end;

function    cal(x,n:longint):int;
var i,j:longint;
    s:int;
begin
    for i:=1 to n do begin
        f[i]:=0;
        for j:=i-1 downto i-c[x] do
            f[i]:=mmod(f[i]+f[j]);
    end;
    s:=0;   i:=n;
    while i > 0 do begin
        s:=mmod(s+f[i]);
        i:=i-c[x];
    end;
    exit(s);
end;

procedure   solve;
var i,j:longint;
    res:int;
begin
    res:=1;
    for i:=-5 to -1 do f[i]:=0;
    f[0]:=1;
    i:=1;
    while i <= m do begin
        j:=i;
        while (j < m) and (a[j+1] = a[i]) do inc(j);
        res:=mmod(res*cal(a[i],j-i+1));
        i:=j+1;
    end;
    writeln(fo,res);
end;

begin
    assign(fi,'iopc1203.in');   reset(fi);
    assign(fo,'iopc1203.out');  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
