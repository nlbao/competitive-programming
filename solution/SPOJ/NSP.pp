var fi,fo:text;
    n,k,i,j,x,y:longint;
    a:array[0..1010,0..1010] of longint;

begin
    assign(fi,'NSP.in');    reset(fi);
    assign(fo,'NSP.out');   rewrite(fo);
    readln(fi,n,k);
    for i:=1 to n do
        for j:=1 to n do read(fi,a[i][j]);
    for i:=1 to k do begin
        readln(fi,j);
        x:=1;   y:=n;
        while a[x][y] <> j do
            if a[x][y] < j then inc(x)
            else dec(y);
        writeln(fo,x,' ',y);
    end;
    close(fo);
    close(fi);
end.
