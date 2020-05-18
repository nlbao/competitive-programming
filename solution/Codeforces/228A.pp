var fi,fo:text;
    i,j,t,c:longint;
    a:array[0..5] of longint;

begin
    assign(fi,'228A.in');   reset(fi);
    assign(fo,'228A.out');  rewrite(fo);
    for i:=1 to 4 do read(fi,a[i]);
    for i:=1 to 4 do
        for j:=i+1 to 4 do
            if a[i] > a[j] then begin
                t:=a[i];
                a[i]:=a[j];
                a[j]:=t;
            end;
    c:=0;
    for i:=2 to 4 do
        if a[i] = a[i-1] then inc(c);
    writeln(fo,c);
    close(fo);
    close(fi);
end.