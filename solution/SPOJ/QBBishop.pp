const   INPUT = 'QBBishop.inp';
        OUTPUT = 'QBBishop.out';
        MAX_N = 210;
        MAX_M = MAX_N;
        MAX_INT = 1000000000;
        dx:array[1..4] of longint = (-1,-1,+1,+1);
        dy:array[1..4] of longint = (-1,+1,-1,+1);

var fi,fo:text;
    n,sx,sy,tx,ty,front,rear:longint;
    qx,qy:array[0..sqr(MAX_N)] of longint;
    f:array[0..MAX_N,0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var i,j,m:longint;
begin
    readln(fi,n,m,sx,sy,tx,ty);
    for i:=1 to n do
        for j:=1 to n do f[i][j]:=-1;
    for i:=0 to n+1 do begin
        f[0][i]:=-MAX_INT;  f[n+1][i]:=-MAX_INT;
        f[i][0]:=-MAX_INT;  f[i][n+1]:=-MAX_INT;
    end;
    while m > 0 do begin
        readln(fi,i,j);
        f[i][j]:=-MAX_INT;
        dec(m);
    end;
end;
{---------------------------------------------------------------------------}
procedure   push(i,j:longint);
begin
    inc(rear);
    qx[rear]:=i;    qy[rear]:=j;
end;
{---------------------------------------------------------------------------}
procedure   pop(var i,j:longint);
begin
    i:=qx[front];   j:=qy[front];
    inc(front);
end;
{---------------------------------------------------------------------------}
function    solve:longint;
var i,j,k,x,y:longint;
begin
    front:=1;   rear:=0;
    push(sx,sy);
    f[sx][sy]:=0;
    repeat
        pop(i,j);
        for k:=1 to 4 do begin
            x:=i+dx[k]; y:=j+dy[k];
            while f[x][y] <> -MAX_INT do begin
                if f[x][y] = -1 then begin
                    push(x,y);
                    f[x][y]:=f[i][j]+1;
                    if (x = tx) and (y = ty) then exit(f[x][y]);
                end;
                inc(x,dx[k]);    inc(y,dy[k]);
            end;
        end;
    until front > rear;
    exit(-1);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    writeln(fo,solve);
    close(fo);
    close(fi);
end.