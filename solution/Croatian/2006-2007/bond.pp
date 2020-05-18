uses    math;

const   MAX_N = 30;

var fi,fo:text;
    n,i,j,k,ii:longint;
    a:array[0..MAX_N,0..MAX_N] of double;
    f:array[0..1050000] of double;

begin
    assign(fi,'bond.in');   reset(fi);
    assign(fo,'bond.out');  rewrite(fo);
    readln(fi,n);
    for i:=1 to n do
        for j:=1 to n do begin
            read(fi,a[i][j]);
            a[i][j]:=a[i][j]/100;
        end;
    fillchar(f, sizeof(f), 0);
    f[0]:=1;
    for i:=0 to (1 shl n)-2 do begin
        k:=1;
        for j:=1 to n do k:=k+((i shr (j-1)) and 1);
                for j:=1 to n do
            if i and (1 shl (j-1)) = 0 then begin
                ii:=i or (1 shl (j-1));
                f[ii]:=max(f[ii],f[i]*a[k][j]);
            end;
    end;
    writeln(fo,f[(1 shl n)-1]*100:0:12);
    close(fo);
    close(fi);
end.
