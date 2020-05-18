const
    INPUT = '116A.inp';
    OUTPUT = '116A.out';
    MAX_N = 2000;

var
    fi,fo:text;
    N,i,res,sum:longint;
    a,b:array[0..MAX_N] of longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N);
    for i:=1 to N do read(fi,a[i],b[i]);
    res:=0;
    sum:=0;
    for i:=1 to N do begin
        sum:=sum-a[i]+b[i];
        if sum > res then res:=sum;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.