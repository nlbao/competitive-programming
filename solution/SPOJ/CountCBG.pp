const
    INPUT = 'CountCBG.inp';
    OUTPUT = 'CountCBG.out';
    MAX_N = 1000000000;

var
    fi,fo:text;
    N,k,s,count:longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    while not eof(fi) do
        begin
            readln(fi,N);
            if (N-1) mod 2 = 0 then count:=1
            else count:=0;
            k:=3;
            s:=3;
            while s < N do
                begin
                    if (N-s) mod k = 0 then inc(count);
                    s:=s+k;
                    inc(k);
                end;
            writeln(fo,count);
        end;
    close(fo);
    close(fi);
end.
