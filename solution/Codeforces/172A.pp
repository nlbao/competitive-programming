var fi,fo:text;
    n,i,j,c:longint;
    s:array[0..30000] of string;
    ok:boolean;

begin
    assign(fi,'172A.in');   reset(fi);
    assign(fo,'172A.out');  rewrite(fo);
    readln(fi,n);
    for i:=1 to n do readln(fi,s[i]);
    c:=0;
    for i:=1 to length(s[1]) do begin
        ok:=true;
        for j:=1 to n do
            if s[j][i] <> s[1][i] then begin
                ok:=false;
                break;
            end;
        if not ok then break;
        inc(c);
    end;
    writeln(fo,c);
    close(fo);
    close(fi);
end.