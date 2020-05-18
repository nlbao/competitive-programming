const
    INPUT = 'LastDIG.inp';
    OUTPUT = 'LastDIG.out';

var
    fi,fo:text;
    nTest,A,B:longint;

function    power(a,k:longint):longint;
var
    t:longint;
begin
    if a = 0 then exit(0);
    if k = 0 then exit(1);
    if k = 1 then exit(a);
    t:=k div 2;
    if (k mod 2) = 0 then exit(sqr(power(a,t)) mod 10)
    else exit((sqr(power(a,t))*a) mod 10);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,A,B);
        if (A = 0) and (B = 0) then writeln(fo,1)
        else writeln(fo,power(A,B));
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
