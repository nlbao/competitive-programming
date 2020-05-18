{$R+, $I+, $Q+}
{$M+ 16777216}

uses    math;

const   MAX_N = 505;
        BASE = 262143;
        R = 10007;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m:longint;
    a:array[0..5,0..MAX_N] of ll;
    b:array[0..MAX_N] of ll;
    ok:array[0..2,0..BASE] of boolean;
    h,f:array[0..2,0..BASE] of longint;
    res:ll;


procedure   enter();
var i,j:longint;
begin
    read(fi,n,m);
    for i:=1 to 5 do
        for j:=1 to n do read(fi,a[i][j]);
end;



procedure   solve_0();
var i1,i2,i3,i4,i5:longint;
begin
    res:=0;
    for i1:=1 to n do
        for i2:=1 to n do
            for i3:=1 to n do
                for i4:=1 to n do
                    for i5:=1 to n do
                        if (a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]+a[5][i5] = m) then
                            res:=res+1;
    writeln(fo,res);
end;


function    find(id:longint;    x:ll):longint;
var i:longint;
begin
    i:=x and BASE;
    if i < 0 then i:=(i+BASE+1) and BASE;
    while (ok[id][i]) and (h[id][i] <> x) do
        i:=(i+R) and BASE;
    exit(i);
end;


procedure   push(id:longint;    x:ll);
var i:longint;
begin
    i:=find(id,x);
    if not ok[id][i] then begin
        h[id][i]:=x;
        ok[id][i]:=true;
        f[id][i]:=1
    end
    else f[id][i]:=f[id][i]+1;
end;


procedure   solve_1();
var i,j,k,p:longint;
    x,y,t,c:ll;
begin
    for i:=1 to 2 do
        for j:=0 to BASE do
            ok[i][j]:=false;

    for i:=1 to n do
        for j:=1 to n do
            push(1,a[1][i]+a[2][j]);

    for i:=1 to n do
        for j:=1 to n do
            push(2,a[4][i]+a[5][j]);

    for i:=1 to n do
        for j:=i+1 to n do
            if a[3][i] > a[3][j] then begin
                x:=a[3][i];
                a[3][i]:=a[3][j];
                a[3][j]:=x;
            end;

    res:=0;
    for i:=0 to BASE do
        if ok[1][i] then begin
            x:=h[1][i];
            t:=f[1][i];
            for j:=1 to n do begin
                k:=find(2,m-x-a[3][j]);
                if ok[2][k] then
                    res:=res + t*int64(f[2][k]);
            end;
        end;
    writeln(fo,res);
end;


procedure   gen_test();
var i,j:longint;
begin
    randomize;
    n:=random(101)+400;
    m:=random(1000000000);
    for i:=1 to 5 do
        for j:=1 to n do begin
            a[i][j]:=random(1000000000);
            if random(oo) mod 2 = 0 then a[i][j]:=-a[i][j];
        end;

    writeln(fo,n,' ',m);
    for i:=1 to 5 do begin
        for j:=1 to n do writeln(fo,a[i][j],' ');
        //writeln(fo);
    end;
    writeln(fo);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'C11LOCK.in');    reset(fi);
    assign(fo,'C11LOCK.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    n:=-2*oo;
    enter();
    //gen_test();
    if n <= 20 then solve_0()
    else solve_1();
    close(fi);
    close(fo);
end.
