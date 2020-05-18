var fi,fo:text;
    s:ansiString;
    nTest,i,j,c:longint;

begin
    assign(fi,'LUCKY5.in');     reset(fi);
    assign(fo,'LUCKY5.out');    rewrite(fo);
    readln(fi,nTest);
    for i:=1 to nTest do begin
        readln(fi,s);
        c:=0;
        for j:=1 to length(s) do
            if (s[j] <> '4') and (s[j] <> '7') then
                c:=c+1;
        writeln(fo,c);
    end;
    close(fo);
    close(fi);
end.