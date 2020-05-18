const   INPUT = '58B.in';
        OUTPUT = '58B.out';
        MAX_N = 1000010;

var fi,fo:text;
    N,i:longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N);
    write(fo,N,' ');
    i:=2;
    while N > 1 do begin
        while (N mod i) <> 0 do inc(i);
        N:=N div i;
        write(fo,N,' ');
    end;
    close(fo);
    close(fi);
end.
