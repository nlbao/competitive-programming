const   MAX_N = 20010;
        MAX_nP = 500;

var fi,fo:text;
    n,nP,i,j,ii,res:longint;
    a:array[0..MAX_N] of longint;
    p:array[0..MAX_nP] of longint;
    f,g:array[0..MAX_N,0..MAX_nP] of longint;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

procedure   add(x:longint); begin   inc(nP);    p[nP]:=x;   end;

begin
    assign(fi,'158D.in');   reset(fi);
    assign(fo,'158D.out');  rewrite(fo);
    res:=0;
    readln(fi,n);
    for i:=1 to n do begin
        read(fi,a[i]);
        res:=res+a[i];
    end;

    nP:=0;
    for i:=1 to n do
        if i*i > n then break
        else if n mod i = 0 then begin
            add(i);
            j:=n div i;
            if j <> i then add(j);
        end;

    for i:=n downto 1 do
        for j:=1 to nP do begin
            f[i][j]:=a[i];
            ii:=i+p[j];
            if ii <= n then begin
                f[i][j]:=f[i][j]+f[ii][j];
                g[i][j]:=g[ii][j];
            end
            else g[i][j]:=ii mod n;
        end;

    for i:=1 to n do
        for j:=1 to nP do
            if (n div p[j] > 2) and (g[i][j] = i) then
                res:=max(res,f[i][j]);
    writeln(fo,res);
    close(fo);
    close(fi);
end.