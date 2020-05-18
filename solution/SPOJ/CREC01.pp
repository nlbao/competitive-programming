const   MAX_M = 1010;
        MAX_N = 1010;

type    int = int64;

var fi,fo:text;
    m,n:longint;
    a:array[0..MAX_N,0..MAX_N] of char;

procedure   enter;
var i,j:longint;
begin
    readln(fi,m,n);
    for i:=1 to m do begin
        for j:=1 to n do read(fi,a[i][j]);
        readln(fi);
    end;
end;

procedure   solve;
var i,j,t:longint;
    h,s:array[0..MAX_N] of longint;
    f:array[0..MAX_N] of int;
    res:int;
begin
    res:=0;
    for j:=1 to n do h[j]:=0;
    for i:=1 to m do begin
        for j:=1 to n do
            if a[i][j] = '1' then inc(h[j])
            else h[j]:=0;
        f[0]:=0;
        t:=0;   s[0]:=0;
        for j:=1 to n do begin
            while (t > 0) and (h[s[t]] >= h[j]) do dec(t);
            f[j]:=h[j]*(j-s[t])+f[s[t]];
            res:=res+f[j];
            inc(t); s[t]:=j;
        end;
    end;
    writeln(fo,res);
end;

begin
    assign(fi,'crec01.in');     reset(fi);
    assign(fo,'crec01.out');    rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.