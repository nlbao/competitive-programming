const
    INPUT = '112B.inp';
    OUTPUT = '112B.out';

var
    fi,fo:text;
    N,x,y:longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N,x,y);
    N:=N div 2;
    if ((x = N) or (x = N+1)) and ((y = N) or (y = N+1)) then
        writeln(fo,'NO')
    else
        writeln(fo,'YES');
    close(fo);
    close(fi);
end.