const   MAX_N = 100010;

var fi,fo:text;
    n,c,i,j,a:longint;
    p,s:array[0..MAX_N] of longint;

begin
    assign(fi,'Hallow.in');     reset(fi);
    assign(fo,'Hallow.out');    rewrite(fo);
    readln(fi,c,n);
    while not ((c = 0) and (n = 0)) do begin
        for i:=0 to c-1 do p[i]:=-1;
        s[0]:=0; p[0]:=0;
        for i:=1 to n do begin
            read(fi,a);
            s[i]:=(s[i-1]+a) mod c;
            if p[s[i]] = -1 then p[s[i]]:=i
            else begin
                for j:=p[s[i]]+1 to i do write(fo,j,' ');
                writeln(fo);
                readln(fi);
                break;
            end;
        end;
        readln(fi,c,n);
    end;
    close(fo);
    close(fi);
end.