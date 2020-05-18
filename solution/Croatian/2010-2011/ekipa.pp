const   INPUT = 'ekipa.in';
        OUTPUT = 'ekipa.out';
        MAX_N = 110;
        MAX_M = 110;
        MAX_K = 110;

var fi,fo:text;
    n,m,k:longint;
    a:array[0..MAX_N] of double;

procedure   enter;
var i,j,t:longint;
    s:double;
begin
    readln(fi,n,m,k);
    for i:=1 to n do a[i]:=0;
    for i:=1 to m do
        for j:=1 to n do begin
            read(fi,t,s);
            if s > a[t] then a[t]:=s;
        end;
end;

procedure   solve;
var i,j:longint;
    tmp:double;
begin
    for i:=1 to n-1 do
        for j:=i+1 to n do
            if a[i] < a[j] then begin
                tmp:=a[i]; a[i]:=a[j];  a[j]:=tmp;
            end;
    tmp:=0;
    for i:=1 to k do tmp:=tmp+a[i];
    writeln(fo,tmp:0:1);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.