const   INPUT = '46E.in';
        OUTPUT = '46E.out';
        MAX_N = 1510;
        MAX_M = 1510;
        MAX_INT = 1000000000000000010;

var fi,fo:text;
    n,m:longint;
    a,s,f,l,r:array[0..MAX_N,0..MAX_M] of int64;

function    max(x,y:int64):int64;begin  if x > y then exit(x)   else exit(y);   end;

procedure   enter;
var i,j:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do
        for j:=1 to m do read(fi,a[i][j]);
end;

procedure   solve;
var i,j:longint;
    res:int64;
begin
    for i:=1 to n do begin
        s[i][1]:=a[i][1];
        for j:=2 to m do s[i][j]:=s[i][j-1]+a[i][j];
    end;
    r[1][m+1]:=-MAX_INT;
    for j:=m downto 2 do begin
        f[1][j]:=s[1][j];
        r[1][j]:=max(r[1][j+1],f[1][j]);
    end;
    for i:=2 to n do
        if i mod 2 = 1 then begin
            r[i][m+1]:=-MAX_INT;
            for j:=m downto 2 do begin
                f[i][j]:=l[i-1][j-1]+s[i][j];
                r[i][j]:=max(r[i][j+1],f[i][j]);
            end;
        end
        else begin
            l[i][0]:=-MAX_INT;
            for j:=1 to m-1 do begin
                f[i][j]:=r[i-1][j+1]+s[i][j];
                l[i][j]:=max(l[i][j-1],f[i][j]);
            end;
        end;
    if n mod 2 = 1 then res:=r[n][2]
    else res:=l[n][m-1];
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
