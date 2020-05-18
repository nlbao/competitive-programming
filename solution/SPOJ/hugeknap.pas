uses    math;

const   MAX_N = 10001;
        MAX_M = 1001;


var fi,fo:text;
    id,nTest,n,m:longint;
    v,w:array[0..MAX_N] of longint;
    f:array[0..MAX_N,0..MAX_M] of longint;
    ok:array[0..MAX_N] of boolean;



procedure   enter();
var i:longint;
begin
    read(fi,n,m);
    for i:=1 to n do read(fi,w[i]);
    for i:=1 to n do read(fi,v[i]);
end;


procedure   solve();
var i,j,x,y,res,s:longint;
begin
    res:=0;
    x:=0;   y:=0;
    s:=0;
    for i:=0 to m do f[0][i]:=0;
    for i:=1 to n do begin
        ok[i]:=false;
        for j:=0 to w[i]-1 do f[i][j]:=f[i-1][j];
        s:=min(s+w[i],m);
        for j:=w[i] to m do begin
            f[i][j]:=max(f[i][j], f[i-1][j-w[i]]+v[i]);
            if f[i][j] > res then begin
                res:=f[i][j];
                x:=i;   y:=j;
            end;
        end;
    end;

    j:=0;
    while (x > 0) and (y > 0) do begin
        if f[x][y] <> f[x-1][y] then begin
            j:=j+1;
            ok[x]:=true;
            y:=y-w[x];
        end;
        x:=x-1;
    end;
    writeln(fo,res,' ',j);
    for i:=1 to n do
        if ok[i] then write(fo,i,' ');
    writeln(fo);
end;


procedure   gen_test();
var i:longint;
begin
    randomize;
    n:=10000;
    m:=1000;
    for i:=1 to n do w[i]:=random(1000)+1;
    for i:=1 to n do v[i]:=random(1000)+1;
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'HUGEKNAP.in');   reset(fi);
    assign(fo,'HUGEKNAP.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    //readln(fi,nTest);
    nTest:=40;
    for id:=1 to nTest do begin
        //enter();
        gen_test();
        solve();
    end;
    close(fi);
    close(fo);
end.