const   MAX_N = 110;
        dx:array[1..4] of longint = (0,0,+1,-1);
        dy:array[1..4] of longint = (+1,-1,0,0);

var fi,fo:text;
    nTest,n,l,r,i:longint;
    a:array[0..MAX_N,0..MAX_N] of char;
    ok:array[0..MAX_N,0..MAX_N] of boolean;
    qx,qy:array[0..sqr(MAX_N)] of longint;

procedure   enter;
var i,j:longint;
begin
    readln(fi,n);
    for i:=1 to n do begin
        for j:=1 to n do begin
            read(fi,a[i][j]);
            ok[i][j]:=(a[i][j] = 'x') or (a[i][j] = '@');
        end;
        readln(fi);
    end;
end;

procedure   push(x,y:longint);  begin   inc(r); qx[r]:=x;   qy[r]:=y;   ok[x][y]:=false;    end;

procedure   pop(var x,y:longint);   begin   x:=qx[l];   y:=qy[l];   inc(l); end;

procedure   solve(id:longint);
var i,j,k,ii,jj,x,y,res:longint;
begin
    res:=0;
    for i:=1 to n do
        for j:=1 to n do
            if ok[i][j] then begin
                inc(res);
                l:=1;   r:=0;
                push(i,j);
                repeat
                    pop(ii,jj);
                    for k:=1 to 4 do begin
                        x:=ii+dx[k];
                        y:=jj+dy[k];
                        if (x < 1) or (x > n) or (y < 1) or (y > n) then continue;
                        if ok[x][y] then push(x,y);
                    end;
                until l > r;
            end;
    writeln(fo,'Case ',id,': ',res);
end;

begin
    assign(fi,'11953.in');  reset(fi);
    assign(fo,'11953.out'); rewrite(fo);
    readln(fi,nTest);
    for i:=1 to nTest do begin
        enter;
        solve(i);
    end;
    close(fo);
    close(fi);
end.
