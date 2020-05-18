const
    INPUT = 'CTNBulls.inp';
    OUTPUT = 'CTNBulls.out';
    MAX_N = 100001;
    MODUN = 2111992;

var
    fi,fo:text;
    N,K,i,j:longint;
    f,s:array[0..MAX_N] of longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N,K);
    f[1]:=1;    s[1]:=1;
    for i:=2 to N do begin
        f[i]:=1;
        j:=i-K-1;
        if j > 0 then f[i]:=(f[i]+s[j]) mod MODUN;
        s[i]:=(s[i-1]+f[i]) mod MODUN;
    end;
    writeln(fo,s[N]+1);
    close(fo);
    close(fi);
end.