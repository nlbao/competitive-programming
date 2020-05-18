const   INPUT = '21C.in';
        OUTPUT = '21C.out';
        MAX_N = 100010;

var fi,fo:text;
    n:longint;
    a,s,c:array[0..MAX_N] of int64;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
end;

function    solve:int64;
var i:longint;
    res:int64;
begin
    if n < 3 then exit(0);
    s[1]:=a[1];
    for i:=2 to n do s[i]:=s[i-1]+a[i];
    c[n]:=0; c[n-1]:=0;
    for i:=n-2 downto 1 do begin
        c[i]:=c[i+1];
        if 3*(s[i+1]) = 2*s[n] then c[i]:=c[i]+1;
    end;
    res:=0;
    for i:=1 to n-1 do
        if 3*s[i] = s[n] then res:=res+c[i];
    exit(res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    writeln(fo,solve);
    close(fo);
    close(fi);
end.