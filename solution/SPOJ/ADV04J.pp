const
    INPUT = 'ADV04J.inp';
    OUTPUT = 'ADV04J.out';
    MAX_N = 1000010;

var
    fi,fo:text;
    nTest,N:longint;

function    f(n:longint):longint;
begin
    if n = 1 then exit(1);
    if n = 2 then exit(2);
    exit(f(n-(n div 2))+1);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,N);
        writeln(fo,f(N));
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
