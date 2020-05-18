var fi,fo:text;
    a,b:ansiString;
    n,m,i,j,t,tt:longint;
    g:array[0..1,0..5010] of int64;
    f,res:int64;

function    mmod(x:int64):int64;    begin   exit(x mod 1000000007);   end;

begin
    assign(fi,'test.out');   reset(fi);
    assign(fo,'163A.out');  rewrite(fo);
    readln(fi,a);   n:=length(a);
    readln(fi,b);   m:=length(b);
    res:=0;
    t:=0;
    for i:=1 to n do begin
        tt:=t;
        t:=(t+1) mod 2;
        for j:=1 to m do g[t][j]:=0;
        for j:=1 to m do
            if a[i] = b[j] then begin
                f:=1;
                if (i > 1) and (j > 1) then f:=mmod(f+g[tt][j-1]);
                g[t][j]:=f;
                res:=mmod(res+f);
            end;
        for j:=2 to m do g[t][j]:=mmod(g[t][j-1]+g[t][j]);
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.
