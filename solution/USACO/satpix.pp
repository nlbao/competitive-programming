{
    ID: storm59061
    PROB: satpix
    LANG: PASCAL
}

const
    INPUT = 'satpix.in';
    OUTPUT = 'satpix.out';
    MAX_H = 1010;
    MAX_W = 90;
    dx:array[1..4] of longint = (0,0,-1,+1);
    dy:array[1..4] of longint = (-1,+1,0,0);

type
    recQueue = record
        x,y:longint;
    end;

var
    fi,fo:text;
    h,w,front,rear:longint;
    a:array[0..MAX_H,0..MAX_W] of char;
    avail:array[0..MAX_H,0..MAX_W] of boolean;
    queue:array[0..MAX_H*MAX_W] of recQueue;


procedure   enter;
var
    i,j:longint;
begin
    readln(fi,w,h);
    for i:=0 to h+1 do
        for j:=0 to w+1 do a[i,j]:='.';
    for i:=1 to h do begin
        for j:=1 to w do read(fi,a[i,j]);
        readln(fi);
    end;
end;

procedure   push(i,j:longint);
begin
    inc(rear);
    queue[rear].x:=i;   queue[rear].y:=j;
    avail[i,j]:=false;
end;

procedure   solve;
var
    i,j,k,x,y,count,res:longint;
begin
    for i:=0 to h+1 do
        for j:=0 to w+1 do
            if a[i,j] = '*' then avail[i,j]:=true
            else avail[i,j]:=false;

    res:=0;
    for i:=1 to h do
        for j:=1 to w do
            if avail[i,j] then begin
                count:=1;
                front:=1;   rear:=0;
                push(i,j);
                repeat
                    x:=queue[front].x;  y:=queue[front].y;
                    for k:=1 to 4 do
                        if avail[x+dx[k],y+dy[k]] then begin
                            push(x+dx[k],y+dy[k]);
                            inc(count);
                        end;
                    inc(front);
                until front > rear;
                if count > res then res:=count;
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
