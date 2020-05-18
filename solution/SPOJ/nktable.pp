const   MAX_M = 510;
        MAX_N = 510;
        dx:array[1..2] of longint = (0,+1);
        dy:array[1..2] of longint = (+1,0);

var fi,fo:text;
    m,n,l,r,front,rear:longint;
    i,j,k,x,y,xx,yy,maxA:longint;
    a:array[0..MAX_M, 0..MAX_N] of longint;
    f,g:array[0..MAX_M, 0..MAX_N] of boolean;
    qx,qy:array[0..MAX_M*MAX_N] of longint;

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

function    ok(x,y:longint):boolean;
begin
    if (x < 1) or (x > m) then exit(false);
    if (y < 1) or (y > n) then exit(false);
    if a[x][y] = 2 then exit(false);
    exit(true);
end;


begin
    assign(fi,'nktable12.in');    reset(fi);
    assign(fo,'nktable12.out');   rewrite(fo);
    read(fi,m,n);
    for i:=1 to m do
        for j:=1 to n do
            read(fi,a[i][j]);

    fillchar(f,sizeof(f),false);
    front:=1;   rear:=0;
    push(m,n);  f[m][n]:=true;
    while front <= rear do begin
        pop(x,y);
        for k:=1 to 2 do begin
            xx:=x-dx[k];
            yy:=y-dy[k];
            if ok(xx,yy) and (f[xx][yy] = false) then begin
                f[xx][yy]:=true;
                push(xx,yy);
            end;
        end;
    end;

    fillchar(g,sizeof(f),false);
    front:=1;   rear:=0;
    push(1,1);
    write(fo,a[1][1]);

    while (front <= rear) and (g[m][n] = false) do begin
        r:=rear; maxA:=-1;
        while front <= r do begin
            pop(x,y);
            for k:=1 to 2 do begin
                xx:=x+dx[k];
                yy:=y+dy[k];
                if ok(xx,yy) and (f[xx][yy]) and (g[xx][yy] = false) then begin
                    if a[xx][yy] > maxA then begin
                        maxA:=a[xx][yy];
                        rear:=r;
                    end;
                    if a[xx][yy] = maxA then begin
                        push(xx,yy);
                        g[xx][yy]:=true;
                    end;
                end;
            end;
        end;
        write(fo,maxA);
    end;
    close(fo);
    close(fi);
end.
