uses    math;

const   MAX_N = 1003;
        MODULE = 2012;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n:longint;
    s:ansiString;
    a,d:array[0..MAX_N] of longint;
    top:array[0..1] of longint;
    qx,qy:array[0..1,0..MAX_N] of longint;
    f,turn:array[0..1,0..MAX_N,0..MAX_N] of longint;


procedure   gen_test();
var i,j,m:longint;
begin
    randomize;
    s:='()';
    n:=random(50)+1;
    for i:=1 to n do begin
        if random(1000) mod 2 = 0 then s:=s+'()'
        else begin
            m:=random(20)+1;
            for j:=1 to m do s:=s+'(';
            for j:=1 to m do s:=s+')';
        end;
    end;
    n:=length(s);
    writeln(fo,s);
end;

procedure   enter();
var i:longint;
begin
    readln(fi,s);
    n:=length(s);
    gen_test();
    for i:=1 to n do
        if s[i] = '(' then a[i]:=1
        else a[i]:=-1;
end;


function    check_input():boolean;
var i,c:longint;
begin
    if n mod 2 = 1 then exit(false);
    c:=0;
    for i:=1 to n do begin
        c:=c+a[i];
        if c < 0 then exit(false);
    end;
    c:=0;
    for i:=n downto 1 do begin
        c:=c+a[i];
        if c > 0 then exit(false);
    end;
    exit(true);
end;


procedure   init();
var i:longint;
begin
    d[n+1]:=0;
    for i:=n downto 1 do
        d[i]:=d[i+1]-a[i];
end;

procedure   solve_0(n:ll);
var i,j,c1,c2,res:longint;
begin
    res:=0;
    for i:=0 to (1 shl n)-1 do begin
        c1:=0;
        c2:=0;
        for j:=0 to n-1 do begin
            if ((i shr j) and 1) = 1 then c1:=c1+a[j+1]
            else c2:=c2+a[j+1];
            if (c1 < 0) or (c2 < 0) then break;
        end;
        if (c1 = 0) and (c2 = 0) then res:=(res+1) mod MODULE;
    end;
    writeln(fo,res);
end;


procedure   push(t,x,y,i:longint);
begin
    inc(top[t]);
    qx[t][top[t]]:=x;
    qy[t][top[t]]:=y;
    f[t][x][y]:=0;
    turn[t][x][y]:=i;
end;


procedure   solve_1();
var i,j,t,tt,x,y:longint;
begin
    fillchar(turn,sizeof(turn),0);
    fillchar(top,sizeof(top),0);
    t:=0;
    push(t,0,1,1);  f[t][0][1]:=1;
    push(t,1,0,1);  f[t][1][0]:=1;

    for i:=2 to n do begin
        tt:=t;
        t:=(t+1) and 1;
        top[t]:=0;
        for j:=1 to top[tt] do begin
            x:=qx[tt][j];
            y:=qy[tt][j];

            if f[tt][x][y] = 0 then continue;

            if a[i] = 1 then begin
                if x+1+y = d[i+1] then begin
                    if turn[t][x+1][y] <> i then push(t,x+1,y,i);
                    f[t][x+1][y]:=(f[t][x+1][y] + f[tt][x][y]) mod MODULE;
                    if turn[t][x][y+1] <> i then push(t,x,y+1,i);
                    f[t][x][y+1]:=(f[t][x][y+1] + f[tt][x][y]) mod MODULE;
                end;
            end
            else begin
                if x+y-1 = d[i+1] then begin
                    if x > 0 then begin
                        if turn[t][x-1][y] <> i then push(t,x-1,y,i);
                        f[t][x-1][y]:=(f[t][x-1][y] + f[tt][x][y]) mod MODULE;
                    end;
                    if y > 0 then begin
                        if turn[t][x][y-1] <> i then push(t,x,y-1,i);
                        f[t][x][y-1]:=(f[t][x][y-1] + f[tt][x][y]) mod MODULE;
                    end;
                end;
            end;
        end;
    end;
    writeln(fo,f[t][0][0]);
end;

begin
    assign(fi,'bbreeds.in');    reset(fi);
    assign(fo,'bbreeds.out');   rewrite(fo);
    enter();
    if not check_input() then writeln(fo,0)
    else begin
        init();
        //solve_0(n);
        solve_1();
    end;
    close(fi);
    close(fo);
end.