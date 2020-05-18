const   INPUT = 'MLaserP.in';
        OUTPUT = 'MLaserP.out';
        MAX_W = 110;
        MAX_H = 110;
        dx:array[1..4] of longint = (0,0,-1,1);
        dy:array[1..4] of longint = (-1,1,0,0);

var fi,fo:text;
    h,w,x1,y1,x2,y2:longint;
    a:array[0..MAX_H,0..MAX_W] of char;
    f:array[0..MAX_H,0..MAX_W] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x)   else exit(y);   end;

procedure   enter;
var i,j:longint;
begin
    x1:=-1;
    readln(fi,w,h);
    for i:=0 to h+1 do
        for j:=0 to w+1 do a[i][j]:='*';
    for i:=1 to h do begin
        for j:=1 to w do begin
            read(fi,a[i][j]);
            if a[i][j] = 'C' then
                if x1 = -1 then begin   x1:=i;  y1:=j;  end
                else begin x2:=i;   y2:=j;  end;
            f[i][j]:=-1;
        end;
        readln(fi);
    end;
end;

procedure   solve;
var i,j,k,ii,jj,front,rear:longint;
    x,y:array[0..MAX_H*MAX_W] of longint;
begin
    f[x1][y1]:=0;
    front:=1;   rear:=1;
    x[1]:=x1;   y[1]:=y1;
    repeat
        i:=x[front];    j:=y[front];
        inc(front);
        for k:=1 to 4 do begin
            ii:=i;  jj:=j;
            repeat
                ii:=ii+dx[k];    jj:=jj+dy[k];
                if (a[ii][jj] <> '*') and ((f[ii][jj] = -1) or (f[ii][jj] > f[i][j])) then begin
                    if f[ii][jj] = -1 then begin
                        inc(rear);
                        x[rear]:=ii;    y[rear]:=jj;
                    end;
                    f[ii][jj]:=f[i][j]+1;
                end
                else break;
            until false;
        end;
    until (front > rear) or ((i = x2) and (j = y2));
    writeln(fo,f[x2][y2]-1);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.