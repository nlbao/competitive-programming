
var fi,fo:text;
    n,m,x,y,nR,i,j,l,r:longint;
    a,b,u,v:array[0..100010] of longint;

begin
    assign(fi,'161A.in');   reset(fi);
    assign(fo,'161A.out');  rewrite(fo);
    readln(fi,n,m,x,y);
    for i:=1 to n do read(fi,a[i]);
    for i:=1 to m do read(fi,b[i]);
    nR:=0;
    j:=1;
    for i:=1 to n do begin
        l:=a[i]-x;  r:=a[i]+y;
        while (j <= m) and (b[j] < l) do inc(j);
        if (j <= m) and (b[j] >= l) and (b[j] <= r) then begin
            inc(nR);
            u[nR]:=i;   v[nR]:=j;
            inc(j);
        end;
    end;
    writeln(fo,nR);
    for i:=1 to nR do writeln(fo,u[i],' ',v[i]);
    close(fo);
    close(fi);
end.
