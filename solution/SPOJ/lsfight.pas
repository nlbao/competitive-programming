const   MAX_N = 505;
        MAX_M = 1005;

var fi,fo:text;
    n,m,i,j,k,len,nRes:longint;
    a:array[0..MAX_N,0..MAX_N] of boolean;
    p:array[0..MAX_M] of longint;
    f:array[0..MAX_M,0..MAX_M] of boolean;


begin
    assign(fi,'lsfight.in');    reset(fi);
    assign(fo,'lsfight.out');   rewrite(fo);
    readln(fi,n);
    for i:=1 to n do
        for j:=1 to n do begin
            read(fi,k);
            a[i][j]:=(k = 1);
        end;

    m:=n+n;
    for i:=1 to n do p[i]:=i;
    for i:=n+1 to m do p[i]:=i-n;

    for i:=1 to m do begin
        f[i][i]:=true;
        f[i][i+1]:=true;
    end;

    for len:=3 to n+1 do
        for i:=1 to m-len+1 do begin
            j:=i+len-1;
            f[i][j]:=false;
            for k:=i to j do
                if (f[i][k]) and (f[k][j]) and ((a[p[i]][p[k]]) or (a[p[j]][p[k]])) then begin
                    f[i][j]:=true;
                    break;
                end;
        end;

    nRes:=0;
    for i:=1 to n do
        if f[i][i+n] then begin
            inc(nRes);
            p[nRes]:=i;
        end;
    writeln(fo,nRes);
    for i:=1 to nRes do writeln(fo,p[i]);
    close(fo);
    close(fi);
end.