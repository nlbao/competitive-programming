const
    INPUT = 'NSteps.inp';
    OUTPUT = 'NSteps.out';
    MAX_N = 10010;

var
    fi,fo:text;
    nTest,X,Y:longint;
    f,g:array[0..MAX_N] of longint;

procedure   init;
var
    i:longint;
begin
    f[0]:=0;    g[0]:=2;
    for i:=1 to MAX_N do
        if (i mod 2) = 1 then begin
            f[i]:=f[i-1]+1;
            g[i]:=g[i-1]+1;
        end
        else begin
            f[i]:=f[i-1]+3;
            g[i]:=g[i-1]+3;
        end;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,X,Y);
        if X = Y then writeln(fo,f[Y])
        else
            if X = Y+2 then writeln(fo,g[Y])
            else writeln(fo,'No Number');
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.