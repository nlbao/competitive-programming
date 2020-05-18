const   MAX_N = 110;
        dx:array[1..4] of longint = (0,0,+1,-1);
        dy:array[1..4] of longint = (+1,-1,0,0);

var fi,fo:text;
    n,l,r:longint;
    a:array[0..MAX_N,0..MAX_N] of longint;
    c:array[0..MAX_N] of longint;
    ok:array[0..MAX_N,0..MAX_N] of boolean;
    qx,qy:array[0..sqr(MAX_N)] of longint;

procedure   enter;
var i,x,y:longint;
begin
    fillchar(a, sizeof(a), 0);
    fillchar(c, sizeof(c), 0);
    for i:=1 to n-1 do begin
        while not eoln(fi) do begin
            read(fi,x,y);
            a[x][y]:=i;
            inc(c[i]);
            inc(c[0]);
        end;
        readln(fi);
    end;
    c[0]:=n*n-c[0];
end;

procedure   push(x,y:longint);  begin   inc(r); qx[r]:=x;   qy[r]:=y;   ok[x][y]:=false;    end;

procedure   pop(var x,y:longint);   begin   x:=qx[l];   y:=qy[l];   inc(l); end;

function    solve:string;
var i,j,k,ii,jj,x,y,count:longint;
begin
    fillchar(ok, sizeof(ok), true);
    for i:=0 to n-1 do
        if c[i] < n then exit('wrong');
    for i:=1 to n do
        for j:=1 to n do
            if ok[i][j] then begin
                count:=1;
                l:=1;   r:=0;
                push(i,j);
                repeat
                    pop(ii,jj);
                    for k:=1 to 4 do begin
                        x:=ii+dx[k];
                        y:=jj+dy[k];
                        if (x < 1) or (x > n) or (y < 1) or (y > n) then continue;
                        if (ok[x][y]) and (a[x][y] = a[i][j]) then begin
                            inc(count);
                            push(x,y);
                        end;
                    end;
                until l > r;
                if count < c[a[i][j]] then exit('wrong');
            end;
            writeln(n);
    exit('good');
end;

begin
    assign(fi,'11110.in');  reset(fi);
    assign(fo,'11110.out'); rewrite(fo);
    readln(fi,n);
    while n > 0 do begin
        enter;
        writeln(fo,solve);
        readln(fi,n);
    end;
    close(fo);
    close(fi);
end.