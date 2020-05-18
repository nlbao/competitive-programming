uses    math;

const   MAX_N = 110;
        MAX_T = 110;
        dx:array[1..8] of longint = (-1,-1,-1,0,0,+1,+1,+1);
        dy:array[1..8] of longint = (-1,0,+1,-1,+1,-1,0,+1);
        dt:array[1..8] of longint = (2,1,2,1,1,2,1,2);


var fi,fo:text;
    n,maxT,m,crrTurn:longint;
    list:array[0..MAX_N] of ansiString;
    a:array[0..10,0..10] of char;
    v,p:array[0..10,0..10] of longint;
    f:array[0..MAX_T] of int64;
    turn:array[0..2000] of longint;
    ok,avail:array[0..10,0..10] of boolean;
    s:ansiString;

procedure   enter();
var i,j:longint;
begin
    readln(fi,n);
    for i:=1 to n do readln(fi,list[i]);
    readln(fi);
    for i:=1 to 4 do begin
        for j:=1 to 4 do read(fi,a[i][j]);
        readln(fi);
    end;
    for i:=1 to 4 do
        for j:=1 to 4 do read(fi,v[i][j]);
    for i:=1 to 4 do
        for j:=1 to 4 do read(fi,p[i][j]);
    readln(fi,i);
    readln(fi,j);
    maxT:=j-i;
end;

procedure   update(v:int64; t:longint);
var i:longint;
begin
    turn[v]:=crrTurn;
    for i:=maxT-t downto 0 do
        f[i+t]:=max(f[i+t],f[i]+v);
end;

procedure   dfs(x,y,len,sum,time:longint);
var i,xx,yy:longint;
begin
    if time > maxT then exit;
    if len = m then begin
        if turn[sum] <> crrTurn then update(sum,time);
        exit;
    end;

    avail[x][y]:=false;
    inc(len);
    for i:=1 to 8 do begin
        xx:=x+dx[i];
        yy:=y+dy[i];
        if (ok[xx][yy]) and (avail[xx][yy]) and (a[xx][yy] = s[len]) then
            dfs(xx,yy,len,sum+v[xx][yy],time+dt[i]);
    end;
    avail[x][y]:=true;
end;

function    solve():int64;
var i,j,k:longint;
    res:int64;
    check:boolean;
begin
    if maxT < 0 then exit(0);
    fillchar(f,sizeof(f),0);
    fillchar(turn,sizeof(turn),0);
    fillchar(avail,sizeof(avail),true);
    fillchar(ok,sizeof(ok),false);
    for i:=1 to 4 do
        for j:=1 to 4 do ok[i][j]:=true;

    for i:=1 to n do begin
        check:=true;
        for j:=1 to i-1 do
            if list[i] = list[j] then begin
                check:=false;
                break;
            end;
        if check = false then continue;
        s:=list[i];
        m:=length(s);
        crrTurn:=i;
        for j:=1 to 4 do
            for k:=1 to 4 do
                if a[j][k] = s[1] then
                    dfs(j,k,1,v[j][k],p[j][k]);
    end;

    res:=0;
    for i:=0 to maxT do res:=max(res,f[i]);
    exit(res);
end;

begin
    assign(fi,'VMSCRMBL.in');   reset(fi);
    assign(fo,'VMSCRMBL.out');  rewrite(fo);
    enter();
    writeln(fo,solve());
    close(fo);
    close(fi);
end.