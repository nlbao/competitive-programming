


begin
    assign(fi,'123C.in');   reset(fi);
    assign(fo,'123C.out');  rewrite(fo);
    readln(fi,n,m,k);
    for i:=1 to n do
        for j:=1 to m do read(fi,p[i][j]);
        end;
    close(fo);
    close(fi);
end.
