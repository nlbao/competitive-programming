const   INPUT = '35D.in';
        OUTPUT = '35D.out';
        MAX_N = 110;
        MAX_X = 10010;

var fi,fo:text;
    n,x:longint;
    c:array[0..MAX_N] of longint;
    f:array[0..MAX_N] of longint;

procedure   enter;
var i:longint;
begin
    readln(fi,n,x);
    for i:=1 to n do read(fi,c[i]);
end;

function    solve:longint;
var i,j,tmp,res:longint;
begin
    for i:=1 to n do f[i]:=c[i]*(n-i+1);
    for i:=1 to n-1 do
        for j:=i+1 to n do
            if f[i] > f[j] then begin
                tmp:=f[i]; f[i]:=f[j];  f[j]:=tmp;
            end;
    res:=0;
    for i:=1 to n do
        if f[i] > x then break
        else begin
            x:=x-f[i];
            inc(res);
        end;
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
