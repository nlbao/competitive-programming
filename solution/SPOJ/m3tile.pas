const   MAX_N = 30;

type    ll = int64;

var fi,fo:text;
    n,i,j:longint;
    f:array[0..MAX_N] of ll;


begin
    assign(fi,'m3tile.in');     reset(fi);
    assign(fo,'m3tile.out');    rewrite(fo);
    f[0]:=1;
    f[1]:=0;
    f[2]:=3;
    f[3]:=0;
    for i:=4 to MAX_N do begin
        f[i]:=0;
        if i mod 2 = 1 then continue;
        f[i]:=3*f[i-2];
        j:=4;
        while i >= j do begin
            f[i]:=f[i] + 2*f[i-j];
            j:=j+2;
        end;
    end;

    repeat
        read(fi,n);
        if n = -1 then break;
        writeln(fo,f[n]);
    until false;
    close(fo);
    close(fi);
end.