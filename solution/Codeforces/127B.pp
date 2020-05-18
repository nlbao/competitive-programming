const   INPUT = '127B.in';
        OUTPUT = '127B.out';
        MAX_N = 110;
        MAX_A = 110;

var fi,fo:text;
    n,i,j,res:longint;
    c:array[0..MAX_A] of longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    for i:=1 to MAX_A do c[i]:=0;
    readln(fi,n);
    for i:=1 to n do begin
        read(fi,j);
        inc(c[j]);
    end;
    res:=0;
    for i:=1 to MAX_A do begin
        inc(res,c[i] div 4);
        c[i]:=c[i] mod 4;
    end;
    j:=0;
    for i:=1 to MAX_A do
        if c[i] > 1 then inc(j);
    res:=res+(j div 2);
    writeln(fo,res);
    close(fo);
    close(fi);
end.