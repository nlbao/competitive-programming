var fi,fo:text;
    i,j:longint;
    f:array[0..41] of longint;

begin
    assign(fi,'modulo.in');     reset(fi);
    assign(fo,'modulo.out');    rewrite(fo);
    fillchar(f, sizeof(f), 0);
    for i:=1 to 10 do begin
        readln(fi,j);
        f[j mod 42]:=1;
    end;
    j:=0;
    for i:=0 to 41 do j:=j+f[i];
    writeln(fo,j);
    close(fo);
    close(fi);
end.