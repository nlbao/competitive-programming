const
    INPUT = '114A.inp';
    OUTPUT = '114A.out';

var
    fi,fo:text;
    L,i:longint;
    K,x:int64;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,K);
    readln(fi,L);
    x:=K;
    i:=0;
    while x < L do begin
        x:=x*K;
        inc(i);
    end;
    if x = L then begin
        writeln(fo,'YES');
        writeln(fo,i);
    end
    else writeln(fo,'NO');

    close(fo);
    close(fi);
end.