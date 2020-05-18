const   MAX_N = 110;
        oo = 2000000000;

var fi,fo:text;
    nTest,n,m,q,i,j,k,u,v,w:longint;
    f:array[0..MAX_N,0..MAX_N] of longint;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

begin
    assign(fi,'10048.in');  reset(fi);
    assign(fo,'10048.out'); rewrite(fo);
    nTest:=0;
    readln(fi,n,m,q);
    while n > 0 do begin
        for i:=1 to n do
            for j:=1 to n do f[i][j]:=oo;
        for i:=1 to m do begin
            readln(fi,u,v,w);
            f[u][v]:=min(f[u][v],w);
            f[v][u]:=f[u][v];
        end;
        for k:=1 to n do
            for i:=1 to n do
                for j:=1 to n do begin
                    f[i][j]:=min(f[i][j],max(f[i][k],f[j][k]));
                    f[j][i]:=f[i][j];
                end;
        inc(nTest);
        writeln(fo,'Case #',nTest);
        for i:=1 to q do begin
            readln(fi,u,v);
            if f[u][v] = oo then writeln(fo,'no path')
            else writeln(fo,f[u][v]);
        end;
        readln(fi,n,m,q);
        if n <> 0 then writeln(fo);
    end;
    close(fo);
    close(fi);
end.
