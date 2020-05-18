const
    INPUT = '110C.inp';
    OUTPUT = '110C.out';
    MAX_N = 1000000;

var
    fi,fo:text;
    N,i,x,y,rx,ry,rsum:longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N);
    rx:=MAXLONGINT; ry:=MAXLONGINT; rsum:=MAXLONGINT;
    for i:=N downto 1 do begin
        x:=2*N-7*i;
        y:=4*i-N;
        if (x >= 0) and (y >= 0) then
            if (x+y < rsum) or ((x+y = rsum) and (x > rx)) then begin
                rx:=x;  ry:=y;
                rsum:=x+y;
            end;
    end;
    if rx <> MAXLONGINT then begin
        for i:=1 to rx do write(fo,4);
        for i:=1 to ry do write(fo,7);
    end
    else write(fo,-1);
    close(fo);
    close(fi);
end.