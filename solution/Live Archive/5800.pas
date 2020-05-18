uses    math;

var fi,fo:text;
    nTest,test_id,r,n,i,j:longint;
    s:ansiString;

begin
    assign(fi,'5800.in');    reset(fi);
    assign(fo,'5800.out');   rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,test_id,r,s);
        if s[1] = ' ' then delete(s,1,1);
        n:=length(s);
        write(fo,test_id,' ');
        for i:=1 to n do
            for j:=1 to r do write(fo,s[i]);
        writeln(fo);
        dec(nTest);
    end;
    close(fi);
    close(fo);
end.