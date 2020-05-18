const   MAX_N = 110;
        MODUN = 1000000007;

type    int = int64;

var fi,fo:text;
    s:ansiString;
    nTest,n:longint;
    a:array[0..MAX_N] of longint;

procedure   enter;
var i:longint;
begin
    readln(fi,s);
    n:=length(s);
    for i:=1 to n do a[i]:=ord(s[i])-ord('a')+1;
end;

function    mmod(x:int):int;
begin
    while x < 0 do x:=x+MODUN;
    exit(x mod MODUN);
end;

function    solve:int;
var i,j,d:longint;
    c,f:array[0..26] of int;
begin
    if n = 1 then exit(0);
    fillchar(f,sizeof(f),0);
    fillchar(c,sizeof(c),0);
    for j:=1 to 26 do
        if (j >= a[2]) and (a[1] >= j-a[2]+1) then f[j]:=1
        else if (j < a[2]) and (a[1] <= 26-(j-a[2])) then f[j]:=1;
    for j:=1 to 26 do c[j]:=c[j-1]+f[j];

    for i:=3 to n do begin
        fillchar(f,sizeof(f),0);
        for j:=1 to 26 do begin
            d:=j-a[i];
            if d >= 0 then f[j]:=mmod(c[26]-c[d])
            else f[j]:=mmod(c[26+d]);
        end;
        for j:=1 to 26 do c[j]:=mmod(c[j-1]+f[j]);
    end;
    exit(mmod(c[26]-1));
end;

begin
    assign(fi,'157E.in');   reset(fi);
    assign(fo,'157E.out');  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        writeln(fo,solve);
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.