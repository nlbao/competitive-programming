const
    INPUT = 'LuckyNum.inp';
    OUTPUT = 'LuckyNum.out';
    MAX_N = 200;

var
    fi,fo:text;
    T,X,l8,l6,i,j:longint;

procedure   Find(X:longint; var l8,l6:longint);
var
    i,j:longint;
    F:array[-1..MAX_N,0..MAX_N] of longint;
begin
    l8:=0;  l6:=0;
    F[0,0]:=0;
    for j:=1 to MAX_N do
        F[0,j]:=(10*F[0,j-1]+6) mod X;
    for i:=1 to MAX_N do
        begin
            F[i,0]:=(10*F[i-1,0]+8) mod X;
            for j:=1 to MAX_N do
                F[i,j]:=(10*F[i,j-1]+6) mod X;
        end;
    for i:=0 to MAX_N do
        for j:=0 to MAX_N do
            if (i > 0) or (j > 0) then
                if F[i,j] = 0 then
                    if (l8+l6 = 0) or (l8+l6 > i+j) or ((l8+l6 = i+j) and (l8 > i)) then
                        begin
                            l8:=i;
                            l6:=j;
                        end;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,T);
    for i:=1 to T do
        begin
            readln(fi,X);
            Find(X,l8,l6);
            if (l8 <> 0) or (l6 <> 0) then
                begin
                    for j:=1 to l8 do
                        write(fo,8);
                    for j:=1 to l6 do
                        write(fo,6);
                    writeln(fo);
                end
            else
                writeln(fo,-1);
        end;
    close(fo);
    close(fi);
end.
