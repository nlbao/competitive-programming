const
    INPUT = '110B.inp';
    OUTPUT = '110B.out';
    MAX_N = 100000;

var
    fi,fo:text;
    N,i,j:longint;
    x:array[0..MAX_N] of char;
    ch:char;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N);
    ch:='a';
    for i:=1 to 4 do begin
        j:=i;
        while j <= N do begin
            x[j]:=ch;
            inc(j,4);
        end;
        inc(ch);
    end;
    for i:=1 to N do write(fo,x[i]);
    close(fo);
    close(fi);
end.