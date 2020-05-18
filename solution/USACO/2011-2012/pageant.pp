{
    PROB: pageant
    LANG: PASCAL
    ID: storm59061
}

const   INPUT = 'pageant.in';
        OUTPUT = 'pageant.out';
        MAX_N = 60;
        MAX_M = 60;
        MAX_INT = 1000000000;
        dx:array[1..4] of longint = (0,0,-1,+1);
        dy:array[1..4] of longint = (-1,+1,0,0);

var fi,fo:text;
    n,m,front,rear,res:longint;
    a:array[0..MAX_N,0..MAX_M] of char;
    avail:array[0..MAX_N,0..MAX_M] of boolean;
    c,f:array[0..MAX_N,0..MAX_M] of longint;
    qx,qy:array[0..MAX_N*MAX_M] of longint;

{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i,j:longint;
begin
    readln(fi,n,m);
    for i:=0 to n+1 do
        for j:=0 to m+1 do begin
            avail[i][j]:=false;
            c[i][j]:=-1;
        end;
    for i:=1 to n do begin
        for j:=1 to m do begin
            read(fi,a[i][j]);
            avail[i][j]:=true;
            if a[i][j] = 'X' then c[i][j]:=0;
        end;
        readln(fi);
    end;
end;
{---------------------------------------------------------------------------}
procedure   push(x,y:longint);
begin
    inc(rear);
    qx[rear]:=x;    qy[rear]:=y;
end;
{---------------------------------------------------------------------------}
procedure   pop(var x,y:longint);
begin
    x:=qx[front];   y:=qy[front];
    inc(front);
end;
{---------------------------------------------------------------------------}
procedure   BFS(x,y,id:longint);
var i,j,k:longint;
begin
    front:=1;   rear:=0;
    push(x,y);
    c[x][y]:=id;
    repeat
        pop(x,y);
        for k:=1 to 4 do begin
            i:=x+dx[k]; j:=y+dy[k];
            if c[i][j] = 0 then begin
                push(i,j);
                c[i][j]:=id;
            end;
        end;
    until front > rear;
end;
{---------------------------------------------------------------------------}
function    find(x,y:longint):longint;
var i,j,k:longint;
begin
    for i:=1 to n do
        for j:=1 to m do avail[i][j]:=true;
    front:=1;   rear:=0;
    push(x,y);
    f[x][y]:=0;
    avail[x][y]:=false;
    repeat
        pop(x,y);
        for k:=1 to 4 do begin
            i:=x+dx[k]; j:=y+dy[k];
            if (avail[i][j]) and (c[i][j] <> 1) then
                if c[i][j] = 2 then exit(f[x][y])
                else begin
                    push(i,j);
                    f[i][j]:=f[x][y]+1;
                    avail[i][j]:=false;
                end;
        end;
    until front > rear;
    exit(MAX_INT);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,j,k:longint;
begin
    k:=0;
    for i:=1 to n do
        for j:=1 to m do
            if c[i][j] = 0 then begin
                inc(k);
                BFS(i,j,k);
            end;
    res:=MAX_INT;
    for i:=1 to n do
        for j:=1 to m do
            if c[i][j] = 1 then res:=min(res,find(i,j));
    if res = MAX_INT then res:=0;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
