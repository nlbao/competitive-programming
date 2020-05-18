const   MAX_N = 1000000;
        BASE = 10007;
        MODUN = 1000000007;

var fi,fo:text;
    s:ansiString;
    n:longint;

function    num(i:longint):int64;   begin   if i > n then exit(ord(s[i-n])) else exit(ord(s[i]));    end;

function    mmod(x:int64):int64;    begin   while x < 0 do x:=x+MODUN;  exit(x mod MODUN);  end;

function    solve:longint;
var p,g,f:int64;
    i,k:longint;
begin
    p:=1;   g:=0;
    for i:=1 to n do begin
        p:=longint(p*BASE);
        g:=longint(g*BASE+num(i));
    end;
    f:=g;
    for i:=n+1 to 2*n do begin
        f:=longint(f*BASE+num(i)-num(i-n)*p);
        k:=i-n;
        if (f = g) and (k > 0) and (n mod k = 0) then exit(n div k);
    end;
    exit(0);
end;


begin
    assign(fi,'10298.in');  reset(fi);
    assign(fo,'10298.out'); rewrite(fo);
    readln(fi,s);
    while (s <> '.') do begin
        n:=length(s);
        writeln(fo,solve());
        readln(fi,s);
    end;
    close(fo);
    close(fi);
end.
