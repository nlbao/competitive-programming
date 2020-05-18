const   INPUT = '131C.in';
        OUTPUT = '131C.out';
        MAX_N = 40;
        MAX_M = 40;
        MAX_T = MAX_M+MAX_N;

var fi,fo:text;
    n,m,t:longint;

procedure   solve;
var i,j,k:longint;
    c:array[0..MAX_N,0..MAX_M] of int64;
    res:int64;
begin
    fillchar(c,sizeof(c),0);
    k:=n;
    if m > k then k:=m;
    for i:=1 to k do c[i][i]:=1;
    for i:=2 to k do begin
        c[i][1]:=i;
        for j:=2 to k-1 do c[i][j]:=c[i-1][j]+c[i-1][j-1];
    end;
    res:=0;
    for i:=4 to t-1 do
        if i > n then break
        else if t-i <= m then res:=res+c[n][i]*c[m][t-i];
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,n,m,t);
    solve;
    close(fo);
    close(fi);
end.