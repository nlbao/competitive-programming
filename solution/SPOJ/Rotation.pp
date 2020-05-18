const
    INPUT = 'Rotation.inp';
    OUTPUT = 'Rotation.out';
    MAX_N = 1000;

var
    fi,fo:text;
    N,i,S,D:longint;
    T:boolean;
    C:array[1..MAX_N] of byte;

begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    for i:=2 to N do
        begin
            read(fi,S,D);
            readln(fi,C[D]);
        end;
    close(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    T:=true;
    for i:=2 to N do
        if C[i] = 1 then T:=not T;
    if T = true then write(fo,0)
    else write(fo,1);
    close(fo);
end.