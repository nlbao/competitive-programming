uses    math;

const   MAX_N = 2002;

var fi,fo:text;
    n,m,p,turn,sum:longint;
    a,s,c:array[0..MAX_N,0..MAX_N] of longint;
    ok,avail:array[0..MAX_N,0..MAX_N] of boolean;


procedure   enter();
var i,j:longint;
    ch:char;
begin
    readln(fi,m,n,p);
    for i:=1 to m do begin
        for j:=1 to n do begin
            read(fi,ch);
            a[i][j]:=longint(ch = '#');
        end;
        readln(fi);
    end;
end;


procedure   init();
var i,j,ii,jj:longint;
begin
    fillchar(s,sizeof(s),0);
    s[1][1]:=a[1][1];
    for i:=2 to n do s[1][i]:=s[1][i-1]+a[1][i];
    for i:=2 to m do s[i][1]:=s[i-1][1]+a[i][1];
    for i:=2 to m do
        for j:=2 to n do
            s[i][j]:=s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
    fillchar(ok,sizeof(ok),false);
    for i:=1 to m-p+1 do
        for j:=1 to n-p+1 do begin
            ii:=i+p-1;  jj:=j+p-1;
            ok[i][j]:=((s[ii][jj] - s[i-1][jj] - s[ii][j-1] + s[i-1][j-1]) = 0);
        end;
end;


function    check_row(x,y1,y2:longint):boolean;
var i:longint;
begin
    if (x < 1) or (x > m) then exit(false);
    if (s[x][y2]-s[x][y1-1]-s[x-1][y2]+s[x-1][y1-1]) > 0 then exit(false);
    for i:=y1 to y2 do
        if c[x][i] < turn then exit(true);
end;


function    check_col(y,x1,x2:longint):boolean;
var i:longint;
begin
    if (y < 1) or (y > n) then exit(false);
    if (s[x2][y]-s[x1-1][y]-s[x2][y-1]+s[x1-1][y-1]) > 0 then exit(false);
    for i:=x1 to x2 do
        if c[i][y] < turn then exit(true);
end;


procedure   tryf(x,y:longint);
var i,xx,yy:longint;
begin
    avail[x][y]:=false;
    xx:=x+p-1;  yy:=y+p-1;
//up
    if (check_row(x-1,y,yy) = true) then begin
        for i:=y to yy do if c[x-1][i] < turn then begin
            c[x-1][i]:=turn;
            inc(sum);
        end;
        tryf(x-1,y);
    end;
//down
    if (check_row(xx+1,y,yy) = true) then begin
        for i:=y to yy do if c[xx+1][i] < turn then begin
            c[xx+1][i]:=turn;
            inc(sum);
        end;
        tryf(x+1,y);
    end;
//left
    if (check_col(y-1,x,xx) = true) then begin
        for i:=x to xx do if c[i][y-1] < turn then begin
            c[i][y-1]:=turn;
            inc(sum);
        end;
        tryf(x,y-1);
    end;
//right
    if (check_col(yy+1,x,xx) = true) then begin
        for i:=x to xx do if c[i][yy+1] < turn then begin
            c[i][yy+1]:=turn;
            inc(sum);
        end;
        tryf(x,y+1);
    end;
end;


{procedure   print_map();
var i,j:longint;
begin
    for i:=1 to m do begin
        for j:=1 to n do
            if c[i][j] = turn then write(fo,'.')
            else write(fo,a[i][j]);
        writeln(fo);
    end;
end;}

function    check(x,y:longint):boolean;
var i,j:longint;
begin
    if not ok[x][y] then exit(false);
    for i:=x to x+p-1 do
        for j:=y to y+p-1 do
            if c[i][j] = 0 then exit(true);
    exit(false);
end;


procedure   solve();
var i,j,k,t,res:longint;
begin
    fillchar(c,sizeof(c),0);
    fillchar(avail,sizeof(avail),true);
    res:=0; turn:=1;
    for i:=1 to m do
        for j:=1 to n do begin
            if (check(i,j) = true) then begin
            //if (ok[i][j]) and (c[i][j] = 0) then begin
                inc(turn);
                sum:=p*p;
                for k:=i to i+p-1 do
                    for t:=j to j+p-1 do
                        c[k][t]:=turn;
                tryf(i,j);
                res:=max(res,sum);
                //print_map();
            end;
        end;
    if res = 0 then res:=-1;
    writeln(fo,res);
end;


begin
    assign(fi,'test.in');    reset(fi);
    assign(fo,'c11yard.out');   rewrite(fo);
    enter();
    init();
    solve();
    close(fo);
    close(fi);
end.

