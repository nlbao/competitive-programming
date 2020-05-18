var fi,fo:text;
    n:int64;

procedure   solve;
var tn,i,res:int64;
    c:longint;
begin
    readln(fi,n);
    tn:=n;
    c:=0;   i:=2;   res:=1;
    while (i*i <= n) and (c < 2) do begin
        while (n mod i = 0) and (c < 2) do begin
            inc(c);
            n:=n div i;
            res:=res*i;
        end;
        inc(i);
    end;
    if c = 0 then begin
        writeln(fo,1);
        writeln(fo,0);
        exit;
    end;
    if (c = 2) and (res <> tn) then begin
        writeln(fo,1);
        writeln(fo,res);
        exit;
    end;
    writeln(fo,2);
end;

begin
    assign(fi,'151C.in');   reset(fi);
    assign(fo,'151C.out');  rewrite(fo);
    solve;
    close(fo);
    close(fi);
end.
