const   INPUT = 'PARIGAME.in';
        OUTPUT = 'PARIGAME.out';
        MAX_N = 510;

var fi,fo:text;
    nTest,n:longint;
    a,r,c,f:array[0..MAX_N,0..MAX_N] of longint;

procedure   enter;
var i,j:longint;
begin
    readln(fi,n);
    for i:=1 to n do
        for j:=1 to n do
            read(fi,a[i][j]);
end;

procedure   init;
var i,j:longint;
begin
    for i:=1 to n do begin
        r[i][0]:=0; c[i][0]:=0;
        for j:=1 to n do begin
            r[i][j]:=r[i][j-1]+a[i][j];
            c[i][j]:=c[i][j-1]+a[j][i];
        end;
    end;
end;

procedure   solve;
var i,j,t:longint;
begin
    f[0][0]:=0; f[0][1]:=0; f[1][0]:=0;
    for i:=1 to n do
        for j:=1 to n do
            if (r[i][j] mod 2 = 0) and (f[i-1][j] = 0) then f[i][j]:=1
            else if (c[j][i] mod 2 = 0) and (f[i][j-1] = 0) then f[i][j]:=1
            else f[i][j]:=0;
    if f[n][n] = 1 then writeln(fo,'YES')
    else writeln(fo,'NO');
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        init;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.