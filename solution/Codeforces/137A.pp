const   INPUT = '137A.in';
        OUTPUT = '137A.out';
        MAX_N = 110;

var fi,fo:text;
    s:string;
    n,i,j,res:longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,s);
    n:=length(s);
    res:=0;
    i:=1;
    while i <= n do begin
        inc(res);
        j:=i;
        while (j < n) and (j-i < 4) and (s[j+1] = s[i]) do inc(j);
        i:=j+1;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.