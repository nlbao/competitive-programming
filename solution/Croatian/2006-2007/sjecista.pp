var fi,fo:text;
    n,i,j:longint;
    a,b,res:int64;


begin
    assign(fi,'SJECISTA.in');   reset(fi);
    assign(fo,'SJECISTA.out');  rewrite(fo);
    readln(fi,n);
    res:=0;
    for i:=1 to n-2 do begin
        a:=i-1;
        b:=n-i-1;
        res:=res+a*b;
    end;
    writeln(fo,(res*int64(n)) div 4);
    close(fo);
    close(fi);
end.
