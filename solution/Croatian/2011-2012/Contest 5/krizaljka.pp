var fi,fo:text;
    s,t:ansiString;
    n,m,i,j,r,c:longint;
    a:array[0..100,0..100] of char;

begin
    assign(fi,''{'krizaljka.in'});  reset(fi);
    assign(fo,''{'krizaljka.out'}); rewrite(fo);
    readln(fi,s);
    i:=1;
    while (s[i] <> ' ') do inc(i);
    t:=copy(s,i+1,length(s)-i);
    delete(s,i,length(s)-i+1);
    n:=length(s);
    m:=length(t);
    for i:=0 to 100 do
        for j:=0 to 100 do a[i][j]:='.';
    r:=0;   c:=0;
    for i:=1 to n do
        if r > 0 then break
        else
            for j:=1 to m do
                if s[i] = t[j] then begin
                    c:=i;
                    r:=j;
                    break;
                end;
    for i:=1 to n do a[r][i]:=s[i];
    for i:=1 to m do a[i][c]:=t[i];
    for i:=1 to m do begin
        for j:=1 to n do write(fo,a[i][j]);
        writeln(fo);
    end;
    close(fo);
    close(fi);
end.
