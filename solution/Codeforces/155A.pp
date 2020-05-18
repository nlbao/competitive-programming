
var fi,fo:text;
    n,i,j,c:longint;
    a:array[0..1010] of longint;
    ck1,ck2:boolean;


begin
    assign(fi,'155A.in');   reset(fi);
    assign(fo,'155A.out');  rewrite(fo);
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
    c:=0;
    for i:=2 to n do begin
        ck1:=true;  ck2:=true;
        for j:=1 to i-1 do
            if a[i] > a[j] then ck1:=false
            else if a[i] < a[j] then ck2:=false
            else begin
                ck1:=false;
                ck2:=false;
            end;
        if (ck1) or (ck2) then inc(c);
    end;
    writeln(fo,c);
    close(fo);
    close(fi);
end.
