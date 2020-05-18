uses    math;

const   MAX_N = 444;
        MAX_M = 444;

var fi,fo:text;
    n,m,i,j,res:longint;
    a:array[0..MAX_N,0..MAX_M] of char;
    h:array[0..MAX_N,0..MAX_M] of longint;
    l,r:array[0..MAX_M] of longint;

begin
    assign(fi,'stol.in');   reset(fi);
    assign(fo,'stol.out');  rewrite(fo);
    readln(fi,n,m);
    for i:=1 to n do begin
        for j:=1 to m do read(fi,a[i][j]);
        readln(fi);
    end;
    res:=1;
    fillchar(h,sizeof(h),0);
    for i:=1 to n do begin
        for j:=1 to m do
            if (a[i][j] = '.') then
                h[i][j]:=h[i-1][j]+1;
        h[i][m+1]:=-1;
        for j:=m downto 1 do begin
            r[j]:=j;
            while (h[i][r[j]+1] >= h[i][j]) do r[j]:=r[r[j]+1];
        end;
        h[i][0]:=-1;
        for j:=1 to m do begin
            l[j]:=j;
            while (h[i][l[j]-1] >= h[i][j]) do l[j]:=l[l[j]-1];
            if (h[i][j] > 0) then res:=max(res,2*(h[i][j]+r[j]-l[j]+1));
        end;
    end;
    writeln(fo,res-1);
    close(fo);
    close(fi);
end.