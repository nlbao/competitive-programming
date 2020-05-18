const   MAX_N = 110;
        MAX_M = 110;
        oo = 1000000000;
        dx:array[1..4] of longint = (0,0,+1,-1);
        dy:array[1..4] of longint = (+1,-1,0,0);

var fi,fo:text;
    n,m,l,r,sx,sy:longint;
    a:array[0..MAX_N,0..MAX_M] of char;
    f:array[0..MAX_N,0..MAX_M] of longint;
    qx,qy:array[0..MAX_N*MAX_M] of longint;

procedure   enter;
var i,j:longint;
begin
    readln(fi,n,m);
    for i:=0 to n+1 do
        for j:=0 to m+1 do begin
            a[i][j]:='*';
            f[i][j]:=oo;
        end;
    for i:=1 to n do begin
        for j:=1 to m do begin
            read(fi,a[i][j]);
            if a[i][j] = 'C' then begin
                sx:=i; sy:=j;
            end;
        end;
        readln(fi);
    end;
end;

procedure   push(x,y,f0:longint);
begin
    inc(r);
    qx[r]:=x;   qy[r]:=y;
    f[x][y]:=f0;
end;

procedure   solve;
var i,j,t,x,y:longint;
begin
    l:=1;   r:=0;
    push(sx,sy,0);
    repeat
        i:=qx[l];   j:=qy[l];   inc(l);
        if (i = 1) and (j = 1) then break;
        for t:=1 to 4 do begin
            x:=i+dx[t]; y:=j+dy[t];
            if (a[x][y] <> '*') and (f[i][j]+1 < f[x][y]) then push(x,y,f[i][j]+1);
        end;
    until l > r;
    if f[1][1] >= oo then f[1][1]:=0;
    writeln(fo,f[1][1]);
end;


begin
    assign(fi,'VMunch.in');     reset(fi);
    assign(fo,'VMunch.out');    rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.