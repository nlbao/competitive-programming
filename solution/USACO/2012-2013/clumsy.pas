uses    math;

const   MAX_N = 100005;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n:longint;
    s:ansiString;
    a:array[0..MAX_N] of longint;
    f:array[0..1003,0..1003] of longint;


procedure   gen_test();
var i:longint;
begin
    randomize;
    n:=random(500)+100;
    if (n and 1) = 1 then n:=n+1;
    s:='';
    for i:=1 to n do
        if random(MAX_N) mod 4 = 0 then s:=s+')'
        else s:=s+'(';
    writeln(fo,s);
end;

procedure   enter();
var i:longint;
begin
    readln(fi,s);
    n:=length(s);
    //gen_test();
    for i:=1 to n do
        if s[i] = '(' then a[i]:=1
        else a[i]:=-1;
end;


function    cost(x,y:longint):longint;
begin   exit(longint(x<0) + longint(y>0));  end;


procedure   solve_0();
var i,j,k,len:longint;
begin
    for i:=1 to n-1 do f[i][i+1]:=cost(a[i],a[i+1]);
    len:=4;
    while len <= n do begin
        for i:=1 to n-len+1 do begin
            j:=i+len-1;
            f[i][j]:=f[i+1][j-1] + cost(a[i],a[j]);

            k:=i+1;
            while k+1 < j do begin
                f[i][j]:=min(f[i][j], f[i][k]+f[k+1][j]);
                k:=k+2;
            end;
        end;
        len:=len+2;
    end;
    writeln(fo,f[1][n]);
end;


procedure   solve_1();
var i,j:longint;
begin
    for i:=1 to n do
        for j:=0 to n+1 do
            f[i][j]:=oo;
    f[1][1]:=longint(a[1] <> 1);
    for i:=2 to n do
        for j:=0 to n do
            if a[i] = 1 then begin
                f[i][j+1]:=min(f[i][j+1], f[i-1][j]);
                if j > 0 then
                    f[i][j-1]:=min(f[i][j-1], f[i-1][j]+1);
            end
            else begin
                f[i][j+1]:=min(f[i][j+1], f[i-1][j]+1);
                if j > 0 then
                    f[i][j-1]:=min(f[i][j-1], f[i-1][j]);
            end;
    writeln(fo,f[n][0]);
end;



procedure   solve_2();
var i,c:longint;
    ch:char;
begin
    c:=0;
    for i:=1 to n do begin
        c:=c+a[i];
        if c < 0 then begin
            a[i]:=1;
            c:=c+2;
        end;
    end;
    c:=0;
    for i:=n downto 1 do begin
        c:=c+a[i];
        if c > 0 then begin
            a[i]:=-1;
            c:=c-2;
        end;
    end;
    c:=0;
    for i:=1 to n do begin
        if a[i] = 1 then ch:='('
        else ch:=')';
        if ch <> s[i] then c:=c+1;
    end;
    writeln(fo,c);
end;

begin
    assign(fi,'clumsy.in');    reset(fi);
    assign(fo,'clumsy.out');   rewrite(fo);
    enter();
    if n <= 100 then solve_0()
    else if n <= 1000 then solve_1()
    else solve_2();
    close(fi);
    close(fo);
end.

