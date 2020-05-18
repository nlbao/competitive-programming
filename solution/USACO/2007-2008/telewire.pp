uses    math;

const   MAX_N = 100010;
        MAX_H = 101;
        oo = 2000000000;

var fi,fo:text;
    n,c:longint;
    a:array[0..MAX_N] of longint;
    f,x,y:array[0..1,0..MAX_H+1] of longint;

procedure   enter;
var i:longint;
begin
    readln(fi,n,c);
    for i:=1 to n do read(fi,a[i]);
end;

procedure   update(i,t:longint);
var j:longint;
begin
    for j:=0 to MAX_H+1 do begin
        x[t][j]:=oo;
        y[t][j]:=oo;
    end;
    for j:=a[i] to MAX_H do x[t][j]:=min(x[t][j-1],f[t][j]-c*j);
    for j:=MAX_H downto 0 do y[t][j]:=min(y[t][j+1],f[t][j]+c*j);
end;

procedure   solve;
var i,j,jj,t,tt,res:longint;
begin
    t:=0;
    for j:=0 to MAX_H do f[0][j]:=oo;
    for j:=a[1] to MAX_H do f[0][j]:=sqr(j-a[1]);
    update(1,0);
    for i:=2 to n do begin
        tt:=t;
        t:=(t+1) mod 2;
        for j:=0 to MAX_H do f[t][j]:=oo;
        for j:=a[i] to MAX_H do
            f[t][j]:=min(x[tt][j]+c*j,y[tt][j]-c*j)+sqr(j-a[i]);
        update(i,t);
    end;
    res:=f[t][a[n]];
    for j:=a[n]+1 to MAX_H do
        res:=min(res,f[t][j]);
    writeln(fo,res);
end;

begin
    assign(fi,'telewire.in');  reset(fi);
    assign(fo,'telewire.out'); rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.