uses    math;

const   MAX_N = 310;

type    ll = int64;

var fi,fo:text;
    n,i,j:longint;
    a:array[0..MAX_N,0..MAX_N] of ll;
    r,c:array[0..MAX_N] of ll;
    res,f,g:ll;


procedure   solve(y1,y2:longint);
var i:longint;
    sum:ll;
begin
    sum:=r[y1] + r[y2];
//x1 < x2
    f:=c[1] - 2*a[y1][1] - a[y2][1];
    for i:=2 to n do begin
        g:=c[i] - 2*a[y2][i] - a[y1][i];
        res:=max(res, sum + f + g);
        f:=max(f,c[i] - 2*a[y1][i] - a[y2][i]);
    end;


//x1 > x2
    f:=c[n] - 2*a[y1][n] - a[y2][n];
    for i:=n-1 downto 1 do begin
        g:=c[i] - 2*a[y2][i] - a[y1][i];
        res:=max(res, sum + f + g);
        f:=max(f,c[i] - 2*a[y1][i] - a[y2][i]);
    end;
end;


begin
    assign(fi,'c11rocks.in');   reset(fi);
    assign(fo,'c11rocks.out');  rewrite(fo);
    read(fi,n);
    fillchar(r,sizeof(r),0);
    fillchar(c,sizeof(c),0);
    for i:=1 to n do
        for j:=1 to n do begin
            read(fi,a[i][j]);
            r[i]:=r[i] + a[i][j];
            c[j]:=c[j] + a[i][j];
        end;

    res:=0;

//x1 = x2
    for i:=1 to n do begin
        f:=r[1]-2*a[1][i];
        for j:=2 to n do begin
            g:=r[j]-2*a[j][i];
            res:=max(res, c[i]+f+g);
            f:=max(f,g);
        end;
    end;

//y1 = y2
    for i:=1 to n do begin
        f:=c[1]-2*a[i][1];
        for j:=2 to n do begin
            g:=c[j]-2*a[i][j];
            res:=max(res, r[i]+f+g);
            f:=max(f,g);
        end;
    end;

//x1 <> x2, y1 <> y2
    for i:=1 to n do
        for j:=i+1 to n do
            solve(i,j);

    writeln(fo,res);
    close(fo);
    close(fi);
end.