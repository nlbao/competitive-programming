const   INPUT = '31D.in';
        OUTPUT = '31D.out';
        MAX_W = 110;    MAX_H = 110;
        MAX_N = 100;
        dtop = 1;    dbot = 2;    dleft = 3;   dright = 4;
        dx:array[1..4] of longint = (0,0,-1,+1);
        dy:array[1..4] of longint = (1,-1,0,0);

var fi,fo:text;
    w,h,n,front,rear,nRes:longint;
    e:array[0..MAX_W,0..MAX_H,1..4] of boolean;
    avail:array[0..MAX_W,0..MAX_H] of boolean;
    qx,qy,res:array[0..MAX_W*MAX_H] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var i,j,k,x1,y1,x2,y2:longint;
begin
    readln(fi,w,h,n);
    for i:=1 to w do
        for j:=1 to h do
            for k:=1 to 4 do
                e[i,j,k]:=true;
    while n > 0 do begin
        readln(fi,x1,y1,x2,y2);
        if x1 = x2 then
            for j:=y1+1 to y2 do begin
                e[x1,j,dright]:=false;
                e[x1+1,j,dleft]:=false;
            end
        else
            for i:=x1+1 to x2 do begin
                e[i,y1,dtop]:=false;
                e[i,y1+1,dbot]:=false;
            end;
        dec(n);
    end;
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var i,j,p,tmp:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=res[(i+j) shr 1];
    repeat
        while res[i] < p do inc(i);
        while res[j] > p do dec(j);
        if i <= j then begin
            tmp:=res[i];
            res[i]:=res[j];
            res[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   push(x,y:longint);
begin
    if (not avail[x,y]) or (x < 1) or (x > w) or (y < 1) or (y > h) then exit;
    inc(rear);
    qx[rear]:=x;    qy[rear]:=y;
    avail[x,y]:=false;
end;
{---------------------------------------------------------------------------}
procedure   pop(var x,y:longint);
begin
    x:=qx[front];   y:=qy[front];
    inc(front);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,j,k,x,y,s:longint;
begin
    nRes:=0;
    for i:=1 to w do
        for j:=1 to h do avail[i,j]:=true;
    for i:=1 to w do
        for j:=1 to h do
            if avail[i,j] then begin
                s:=0;
                front:=1;   rear:=0;
                push(i,j);
                repeat
                    inc(s);
                    pop(x,y);
                    for k:=1 to 4 do
                        if e[x,y,k] = true then push(x+dx[k],y+dy[k]);
                until front > rear;
                inc(nRes);
                res[nRes]:=s;
            end;
    quick_sort(1,nRes);
    for i:=1 to nRes do write(fo,res[i],' ');
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