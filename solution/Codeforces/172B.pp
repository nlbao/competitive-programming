var fi,fo:text;
    a,b,m,r,i:longint;
    ok:array[0..100010] of longint;

begin
    assign(fi,'172B.in');   reset(fi);
    assign(fo,'172B.out');  rewrite(fo);
    readln(fi,a,b,m,r);
    fillchar(ok, sizeof(ok), 0);
    ok[r]:=1;
    for i:=2 to 200000 do begin
        r:=(a*r+b) mod m;
        if ok[r] > 0 then begin
            writeln(fo,i-ok[r]);
            break;
        end;
        ok[r]:=i;
    end;
    close(fo);
    close(fi);
end.