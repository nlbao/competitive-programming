const
    INPUT = 'MCoins.inp';
    OUTPUT = 'MCoins.out';
    MAX_N = 1000001;

var
    fi,fo:text;
    nTest,K,L,N:longint;
    f:array[0..MAX_N] of boolean;

procedure   solve;
var
    i:longint;
begin
    f[0]:=false;
    for i:=1 to K-1 do f[i]:=not f[i-1];
    for i:=K to L-1 do
        if (f[i-1]) and (f[i-K]) then f[i]:=false
        else f[i]:=true;
    for i:=L to MAX_N do
        if (f[i-1]) and (f[i-K]) and (f[i-L]) then
            f[i]:=false
        else
            f[i]:=true;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,K,L,nTest);
    solve;
    repeat
        read(fi,N);
        if f[N] then write(fo,'A')
        else write(fo,'B');
        dec(nTest);
    until nTest = 0;
    close(fo);
    close(fi);
end.
