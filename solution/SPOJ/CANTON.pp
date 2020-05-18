const
    INPUT = 'CANTON.inp';
    OUTPUT = 'CANTON.out';
    MAX_N = 10000010;

var
    fi,fo:text;
    nTest:longint;
    N:int64;

procedure   solve;
var
    r,c:int64;
begin
    r:=round(sqrt(2*N)-1);
    while r*(r+1) < 2*N do inc(r);
    c:=N-(r*(r-1) div 2);
    if r mod 2 = 0 then
        writeln(fo,'TERM ',N,' IS ',c,'/',r-c+1)
    else
        writeln(fo,'TERM ',N,' IS ',r-c+1,'/',c);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,N);
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.