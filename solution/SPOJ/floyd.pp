uses    math;

const   MAX_N = 111;
        MAX_M = sqr(MAX_N);
        oo = 1000000000;

var fi,fo:text;
    n,m,q,i,j,k,c:longint;
    f,trace:array[0..MAX_N,0..MAX_N] of longint;
    res:array[0..MAX_N] of longint;


begin
    assign(fi,'floyd.in');  reset(fi);
    assign(fo,'floyd.out'); rewrite(fo);
    read(fi,n,m,q);
    for i:=1 to n do begin
        for j:=1 to n do begin
            f[i][j]:=oo;
            trace[i][j]:=-1;
        end;
        f[i][i]:=0;
        trace[i][i]:=i;
    end;
    for i:=1 to m do begin
        read(fi,j,k,c);
        f[j][k]:=min(f[j][k],c);
        f[k][j]:=f[j][k];
        trace[j][k]:=j;
        trace[k][j]:=k;
    end;

    for k:=1 to n do
        for i:=1 to n do
            for j:=1 to n do
                if f[i][k]+f[k][j] < f[i][j] then begin
                    f[i][j]:=f[i][k]+f[k][j];
                    trace[i][j]:=k;
                end;

    for i:=1 to q do begin
        read(fi,c,j,k);
        if c = 0 then write(fo,f[j][k])
        else begin
            c:=0;
            while k <> j do begin
                inc(c); res[c]:=k;
                k:=trace[j][k];
            end;
            inc(c); res[c]:=j;
            write(fo,c,' ');
            for j:=c downto 1 do write(fo,res[j],' ');
        end;
        writeln(fo);
    end;
    close(fo);
    close(fi);
end.