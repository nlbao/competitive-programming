const   MAX_N = 2000000;

var fi,fo:text;
    i,j,n:longint;
    s:ansiString;
    t:char;
    kmp:array[0..MAX_N] of longint;

begin
    assign(fi,'nhay.in');   reset(fi);
    assign(fo,'nhay.out');  rewrite(fo);
    while not eof(fi) do begin
        readln(fi,n);
        readln(fi,s);
        kmp[1]:=0;
        for i:=2 to n do begin
            j:=kmp[i-1];
            while (j > 0) and (s[j+1] <> s[i]) do j:=kmp[j];
            if (s[j+1] = s[i]) then inc(j);
            kmp[i]:=j;
        end;

        i:=0;   j:=0;
        while not eoln(fi) do begin
            inc(i);
            read(fi,t);
            while (j > 0) and (s[j+1] <> t) do j:=kmp[j];
            if (s[j+1] = t) then inc(j);
            if j = n then begin
                writeln(fo,i-n);
                j:=kmp[j];
            end;
        end;
        writeln(fo);
    end;
    close(fo);
    close(fi);
end.