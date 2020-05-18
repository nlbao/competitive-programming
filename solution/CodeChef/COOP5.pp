const   MAX_A = 1000010;

var fi,fo:text;
    nTest,n,k,i,j,a:longint;
    s,t:int64;
    c:array[0..MAX_A] of longint;

begin
    assign(fi,'COOP5.in');  reset(fi);
    assign(fo,'COOP5.out'); rewrite(fo);
    readln(fi,nTest);
    for i:=1 to nTest do begin
        fillchar(c,sizeof(c),0);
        readln(fi,n,k);
        for j:=1 to n do begin
            read(fi,a);
            inc(c[a]);
        end;
        s:=0;
        for j:=MAX_A downto 0 do
            if k = 0 then break
            else begin
                t:=k;
                if c[j] < t then t:=c[j];
                s:=s+int64(j)*t;
                k:=k-t;
            end;
        writeln(fo,s);
    end;
    close(fo);
    close(fi);
end.