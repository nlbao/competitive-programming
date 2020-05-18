const
    INPUT = 'input.txt';
    OUTPUT = 'output.txt';
    MAX_N = 1010;

var
    fi,fo:text;
    N,K,i,x,res,limit:longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N,K);
    limit:=3*K;
    res:=0;
    for i:=1 to N do begin
        read(fi,x);
        if x > limit then res:=res+x-limit
        else res:=res+(x mod K);
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.