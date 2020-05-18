const
    INPUT = 'PERMUT2.inp';
    OUTPUT = 'PERMUT2.out';
    MAX_N = 100010;

var
    fi,fo:text;
    N:longint;
    a,b:array[0..MAX_N] of longint;

procedure   solve;
var
    i:longint;
begin
    for i:=1 to N do begin
        read(fi,a[i]);
        b[a[i]]:=i;
    end;
    for i:=1 to N do
        if a[i] <> b[i] then begin
            writeln(fo,'not ambiguous');
            exit;
        end;
    writeln(fo,'ambiguous');
end;


begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N);
    while N > 0 do begin
        solve;
        readln(fi,N);
    end;
    close(fo);
    close(fi);
end.