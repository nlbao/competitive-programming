const   MAX_N = 810;
        MAX_nH = sqr(MAX_N);
        oo = 1000000000;
        dx:array[1..4] of longint = (0,0,+1,-1);
        dy:array[1..4] of longint = (+1,-1,0,0);

var fi,fo:text;
    nTest,n,s,xs,ys,xt,yt,front,rear:longint;
    a:array[0..MAX_N,0..MAX_N] of char;
    qx,qy:array[0..sqr(MAX_N)] of longint;
    c,d:array[0..MAX_N,0..MAX_N] of longint;

procedure   enter;
var i,j:longint;
begin
    readln(fi,n,s);
    for i:=0 to n+1 do
        for j:=0 to n+1 do a[i][j]:='T';
    for i:=1 to n do begin
        for j:=1 to n do begin
            read(fi,a[i][j]);
            if a[i][j] = 'M' then begin
                xs:=i;  ys:=j;
                a[i][j]:='G';
            end
            else if a[i][j] = 'D' then begin
                xt:=i;  yt:=j;
            end
        end;
        readln(fi);
    end;
end;

procedure   push(x,y:longint);
begin
    inc(rear);
    qx[rear]:=x;
    qy[rear]:=y;
end;

procedure   pop(var x,y:longint);
begin
    x:=qx[front];
    y:=qy[front];
    inc(front);
end;

procedure   init;
var i,j,k,x,y:longint;
begin
    front:=1;   rear:=0;
    for i:=1 to n do
        for j:=1 to n do
            if a[i][j] = 'H' then begin
                push(i,j);
                d[i][j]:=0;
                a[i][j]:='T';
            end
            else d[i][j]:=oo;
    while front <= rear do begin
        pop(i,j);
        for k:=1 to 4 do begin
            x:=i+dx[k];
            y:=j+dy[k];
            if (a[x][y] = 'G') and (d[x][y] = oo) then begin
                push(x,y);
                d[x][y]:=d[i][j]+1;
            end;
        end;
    end;
end;

function    check(value:longint):boolean;
var i,j,k,t,x,y:longint;
begin
    if value >= d[xs][ys] then exit(false);
    front:=1;   rear:=0;
    for i:=1 to n do
        for j:=1 to n do
            c[i][j]:=oo;
    c[xs][ys]:=0;
    push(xs,ys);
    t:=0;
    repeat
        inc(t);
        repeat
            pop(i,j);
            if t+value > d[i][j] then continue;
            if c[i][j] >= t*s then begin
                push(i,j);
                break;
            end;
            for k:=1 to 4 do begin
                x:=i+dx[k];
                y:=j+dy[k];
                if (a[x][y] <> 'T') and (c[x][y] = oo) then begin
                    push(x,y);
                    c[x][y]:=c[i][j]+1;
                end;
            end;
        until (front > rear) or (c[xt][yt] < oo);
    until (front > rear) or (c[xt][yt] < oo);
    if c[xt][yt] < oo then exit(true);
    exit(false);
end;


procedure   solve;
var l,r,mid,res:longint;
begin
    res:=-1;
    l:=0;   r:=n*n;
    repeat
        mid:=(l+r) shr 1;
        if check(mid) = true then begin
            res:=mid;
            l:=mid+1;
        end
        else r:=mid-1;
    until l > r;
    writeln(fo,res);
end;

begin
    assign(fi,'CTOI09_1.in');   reset(fi);
    assign(fo,'CTOI09_1.out');   rewrite(fo);
    readln(fi,nTest);
    {nTest:=1;}
    while nTest > 0 do begin
        enter;
        init;
        solve;
        dec(ntest);
    end;
    close(fo);
    close(fi);
end.
