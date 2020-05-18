const   INPUT = 'MTWalk.in';
        OUTPUT = 'MTWalk.out';
        MAX_N = 110;
        MAX_H = 110;
        dx:array[1..4] of longint = (0,0,-1,+1);
        dy:array[1..4] of longint = (-1,+1,0,0);

var fi,fo:text;
    n,front,rear:longint;
    h:array[0..MAX_N,0..MAX_N] of longint;
    avail:array[0..MAX_N,0..MAX_N] of boolean;
    qx,qy:array[0..sqr(MAX_N)] of longint;

procedure   enter;
var i,j:longint;
begin
    readln(fi,n);
    for i:=0 to n+1 do
        for j:=0 to n+1 do h[i][j]:=-1;
    for i:=1 to n do
        for j:=1 to n do read(fi,h[i][j]);
end;

function    find_path(l,r:longint):boolean;
var i,j,k,x,y:longint;
begin
    if (h[1][1] < l) or (h[1][1] > r) then exit(false);
    for i:=1 to n do
        for j:=1 to n do avail[i][j]:=true;
    front:=1;   rear:=1;
    qx[1]:=1;   qy[1]:=1;
    avail[1][1]:=false;
    repeat
        x:=qx[front];   y:=qy[front];   inc(front);
        for k:=1 to 4 do begin
            i:=x+dx[k]; j:=y+dy[k];
            if (avail[i][j]) and (h[i][j] >= l) and (h[i][j] <= r) then begin
                inc(rear);
                qx[rear]:=i;    qy[rear]:=j;
                avail[i][j]:=false;
                if (i = n) and (j = n) then exit(true);
            end;
        end;
    until front > rear;
    exit(false);
end;

procedure   solve;
var i,l,r,mid,res:longint;
begin
    res:=MAX_H;
    for i:=0 to MAX_H do begin
        l:=0;   r:=MAX_H;
        while l <= r do begin
            mid:=(l+r) shr 1;
            if mid-i >= res then dec(r)
            else if (mid >= i) and (find_path(i,mid) = true) then begin
                if mid-i < res then res:=mid-i;
                r:=mid-1;
            end
            else l:=mid+1;
        end;
    end;
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
