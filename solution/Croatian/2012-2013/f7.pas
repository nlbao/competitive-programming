uses    math;

const   MAX_N = 300010;

var fi,fo:text;
    n,i,res:longint;
    a,f1,f2,g1,g2:array[0..MAX_N] of longint;


begin
    assign(fi,'f7.in');    reset(fi);
    assign(fo,'f7.out');   rewrite(fo);
    read(fi,n);
    for i:=1 to n do read(fi,a[i]);

    f1[0]:=-2*n;
    f2[0]:=2*n;
    for i:=1 to n do begin
        f1[i]:=max(a[i],f1[i-1]);
        f2[i]:=min(a[i],f2[i-1]);
    end;

    g1[n+1]:=-2*n;
    g2[n+1]:=2*n;
    for i:=n downto 1 do begin
        g1[i]:=max(a[i],g1[i+1]);
        g2[i]:=min(a[i],g2[i+1]);
    end;

    res:=0;
    for i:=1 to n do
        if (a[i]+n >= max(f1[i-1],g1[i+1])+1) and (a[i]+n >= max(f2[i-1],g2[i+1])+n-1) then begin
            inc(res);
            writeln(i);
        end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.