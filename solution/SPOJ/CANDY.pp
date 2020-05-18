const
    INPUT = 'CANDY.inp';
    OUTPUT = 'CANDY.out';
    MAX_N = 10010;

var
    fi,fo:text;
    N:longint;
    a:array[0..MAX_N] of longint;

procedure   solve;
var
    i,s,res:longint;
begin
    s:=0;
    for i:=1 to N do begin
        read(fi,a[i]);
        s:=s+a[i];
    end;
    if (s mod N) <> 0 then begin
        writeln(fo,-1);
        exit;
    end;
    s:=s div N;
    res:=0;
    for i:=1 to N do
        if a[i] > s then res:=res+a[i]-s;
    writeln(fo,res);
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