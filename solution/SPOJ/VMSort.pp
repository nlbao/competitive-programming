



begin
    assign(fi,'VMSort.in');     reset(fi);
    assign(fo,'VMSort.out');    rewrite(fo);
    m:=0;
    readln(fi,k);
    while k > 0 do begin
        readln(fi,n);
        for i:=1 to n do begin
            readln(fi,s);
            len:=length(s);
            inc(m);
            h[m]:=0;
            for j:=1 to len do
                h[m]:=longint(h[m]*BASE+int64(s[j]);
        end;
        dec(k);
    end;
    sort(1,m);
    res:=0;
    i:=1;
    while i <= m do begin

    end;
    close(fo);
    close(fi);
end.
