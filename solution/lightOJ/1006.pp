const   INPUT = '1006.in';
        OUTPUT = '1006.out';
        MAX_N = 10000;
        MODUN = 10000007;

var fi,fo:text;
    nTest,n,i,j:longint;
    f:array[0..MAX_N] of int64;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    for i:=1 to nTest do begin
        readln(fi,f[0],f[1],f[2],f[3],f[4],f[5],n);
        f[6]:=(f[0]+f[1]+f[2]+f[3]+f[4]+f[5]) mod MODUN;
        for j:=7 to n do begin
            f[j]:=f[j-1]-f[j-7]+f[j-1];
            while f[j] < 0 do f[j]:=f[j]+MODUN;
            f[j]:=f[j] mod MODUN;
        end;
        writeln(fo,'Case ',i,': ',f[n] mod MODUN);
    end;
    close(fo);
    close(fi);
end.