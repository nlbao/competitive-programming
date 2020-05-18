const   INPUT = '136A.in';
        OUTPUT = '136A.out';
        MAX_N = 110;

var fi,fo:text;
    n,i,j:longint;
    t:array[0..MAX_N] of longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,n);
    for i:=1 to n do begin
        read(fi,j);
        t[j]:=i;
    end;
    for i:=1 to n do write(fo,t[i],' ');
    close(fo);
    close(fi);
end.