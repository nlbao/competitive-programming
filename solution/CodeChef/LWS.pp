uses    math;

const   MAX_N = 2010;

var fi,fo:text;
    nTest,n:longint;
    a:array[0..MAX_N] of longint;
    f:array[0..1,0..26,0..26] of longint;

procedure   enter;
var i:longint;
    s:ansiString;
begin
    readln(fi,s);
    n:=length(s);
    for i:=1 to n do a[i]:=ord(s[i])-ord('a')+1;
end;

procedure   up(var x:longint;   y:longint); begin   if y > 1 then x:=max(x,y);    end;

procedure   solve;
var i,j,ii,t,tt,res:longint;
begin
    res:=1;
    fillchar(f,sizeof(f),0);
    t:=0;
    f[0][a[1]][0]:=1;
    f[0][0][a[1]]:=1;
    for i:=2 to n do begin
        tt:=t;
        t:=(t+1) mod 2;
        for j:=0 to 26 do
            for ii:=0 to 26 do
                f[t][j][ii]:=f[tt][j][ii];
        for j:=0 to 26 do begin
            for ii:=0 to a[i] do
                up(f[t][a[i]][j], f[tt][ii][j]+1);
            for ii:=a[i] to 26 do
                up(f[t][j][a[i]], f[tt][j][ii]+1);
            up(f[t][j][a[i]], f[tt][j][0]+1);
        end;
        f[t][a[i]][0]:=max(f[t][a[i]][0],1);
        f[t][0][a[i]]:=max(f[t][0][a[i]],1);
    end;
    for i:=0 to 26 do
        for j:=0 to 26 do res:=max(res,f[t][i][j]);
    writeln(fo,res);
end;

begin
    assign(fi,'LWS.in');    reset(fi);
    assign(fo,'LWS.out');   rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.