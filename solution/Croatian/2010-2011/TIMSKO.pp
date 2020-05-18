const   INPUT = 'TIMSKO.in';
        OUTPUT = 'TIMSKO.out';
        MAX_K = 210;

var fi,fo:text;
    m,n,k,i,t,res:longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,m,n,k);
    res:=0;
    for i:=0 to k do
        if (m-i >= 0) and (n-(k-i) >= 0) then begin
            t:=(m-i) div 2;
            if t > n-k+i then t:=n-k+i;
            if t > res then res:=t;
        end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.