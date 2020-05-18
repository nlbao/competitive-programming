var fi,fo:text;
    n,i:longint;
    a:array[0..6] of longint;

begin
    assign(fi,'139A.in');   reset(fi);
    assign(fo,'139A.out');  rewrite(fo);
    readln(fi,n);
    for i:=0 to 6 do read(fi,a[i]);
    i:=-1;
    while n > 0 do begin
        i:=(i+1) mod 7;
        n:=n-a[i];
    end;
    writeln(fo,i+1);
    close(fo);
    close(fi);
end.