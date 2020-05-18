const   INPUT = 'EDIST.in';
        OUTPUT = 'EDIST.out';
        MAX_N = 2010;
        MAX_M = 2010;

var fi,fo:text;
    nTest,n,m:longint;
    a,b:ansiString;
    f:array[0..MAX_N,0..MAX_M] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x) else exit(y); end;

procedure   enter;
begin
    readln(fi,a);
    readln(fi,b);
    n:=length(a);
    m:=length(b);
end;

procedure   solve;
var i,j:longint;
begin
    for i:=0 to n do f[i][0]:=i;
    for j:=0 to m do f[0][j]:=j;
    for i:=1 to n do
        for j:=1 to m do begin
            f[i][j]:=f[i-1][j-1];
            if a[i] <> b[j] then inc(f[i][j]);
            f[i][j]:=min(f[i][j],min(f[i-1][j]+1,f[i][j-1]+1));
        end;
    writeln(fo,f[n][m]);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
