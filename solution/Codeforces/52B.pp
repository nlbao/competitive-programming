const   INPUT = '52B.in';
        OUTPUT = '52B.out';
        MAX_N = 1010;
        MAX_M = 1010;

var fi,fo:text;
    n,m:longint;
    a:array[0..MAX_N] of ansiString;
    c:array[0..MAX_M] of int64;
    r:array[0..MAX_N] of int64;

procedure   enter;
var i,j:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do readln(fi,a[i]);
end;

procedure   solve;
var i,j:longint;
    res:int64;
begin
    for j:=1 to m do begin
        c[j]:=0;
        for i:=1 to n do
            if a[i][j] = '*' then c[j]:=c[j]+1;
    end;
    for i:=1 to n do begin
        r[i]:=0;
        for j:=1 to m do
            if a[i][j] = '*' then r[i]:=r[i]+1;
    end;

    res:=0;
    for i:=1 to n do
        for j:=1 to m do
            if a[i][j] = '*' then
                res:=res+(r[i]-1)*(c[j]-1);
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