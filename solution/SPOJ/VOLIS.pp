const   MAX_N = 1010;
        MAX_INT = 2000000010;

var fi,fo:text;
    n,d:longint;
    a,f:array[0..MAX_N] of longint;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

procedure   enter;
var i:longint;
begin
    readln(fi,n,d);
    for i:=1 to n do begin
        read(fi,a[i]);
        a[i]:=a[i]-d;
    end;
    d:=d+d;
end;

procedure   solve;
var i,j,k:longint;
begin
    for i:=2 to n do f[i]:=MAX_INT;
    f[0]:=-MAX_INT;
    k:=1;   f[1]:=a[1];
    for i:=2 to n do begin
        for j:=k downto 0 do
            if a[i]+d >= f[j] then f[j+1]:=min(f[j+1],max(a[i],f[j]));
        if f[k+1] < MAX_INT then inc(k);
    end;
    writeln(fo,k);
end;

begin
    assign(fi,'VOLIS.in');  reset(fi);
    assign(fo,'VOLIS.out'); rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.