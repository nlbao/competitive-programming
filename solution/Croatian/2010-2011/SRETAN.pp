const   INPUT = 'SRETAN.in';
        OUTPUT = 'SRETAn.out';
        MAX_N = 1000000010;

var fi,fo:text;
    n,k:int64;
    i:longint;
    p,s,a:array[0..31] of int64;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,n);
    p[0]:=1;    s[0]:=0;
    for i:=1 to 30 do begin
        p[i]:=p[i-1]*2;
        s[i]:=s[i-1]+p[i];
    end;
    k:=1;
    while s[k] < n do inc(k);
    n:=n-s[k-1];
    for i:=k downto 1 do
        if n > p[i-1] then begin
            a[i]:=7;
            n:=n-p[i-1];
        end
        else a[i]:=4;
    for i:=k downto 1 do write(fo,a[i]);
    writeln(fo);
    close(fo);
    close(fi);
end.
