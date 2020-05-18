const   INPUT = '137B.in';
        OUTPUT = '137B.out';
        MAX_N = 5010;

var fi,fo:text;
    n,i,a,res:longint;
    ok:array[0..MAX_N] of boolean;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,n);
    for i:=1 to n do ok[i]:=false;
    res:=0;
    for i:=1 to n do begin
        read(fi,a);
        if (a < 1) or (a > n) or (ok[a]) then inc(res)
        else ok[a]:=true;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.