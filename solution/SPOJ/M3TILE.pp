const
    INPUT = 'M3TILE.inp';
    OUTPUT = 'M3TILE.out';
    MAX_N = 12;

var
    fi,fo:text;
    N:longint;
    F:array[0..MAX_N] of longint;

procedure   Init;
var
    i:longint;
begin
    F[0]:=0;
    F[1]:=0;    F[2]:=3;
    F[3]:=0;    F[4]:=11;
    for i:=5 to MAX_N do
        if (i mod 2) = 0 then
            F[i]:=F[i-2]*3+F[i-4]*2
        else
            F[i]:=0;
    for i:=0 to MAX_N do
        writeln(i,' ',F[i]);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Init;
    repeat
        read(fi,N);
        if N <> -1 then writeln(fo,F[N]);
    until N = -1;
    close(fo);
    close(fi);
end.
