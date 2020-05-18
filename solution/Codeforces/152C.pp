var fi,fo:text;
    n,m,i,j:longint;
    c,res:int64;
    a:array[0..110,0..110] of char;
    ok:array['A'..'Z'] of boolean;

begin
    assign(fi,'152C.in');   reset(fi);
    assign(fo,'152C.out');  rewrite(fo);
    readln(fi,n,m);
    for i:=1 to n do begin
        for j:=1 to m do read(fi,a[i][j]);
        readln(fi);
    end;
    res:=1;
    for i:=1 to m do begin
        c:=0;
        fillchar(ok,sizeof(ok),false);
        for j:=1 to n do
            if not ok[a[j][i]] then begin
                ok[a[j][i]]:=true;
                c:=c+1;
            end;
        res:=(res*c) mod 1000000007;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.