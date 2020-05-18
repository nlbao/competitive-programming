const   INPUT = '131B.in';
        OUTPUT = '131B.out';
        MAX_N = 100010;
        MAX_T = 10;

var fi,fo:text;
    i,j,n:longint;
    t:array[-MAX_T..MAX_T] of int64;
    res:int64;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    for i:=-MAX_T to MAX_T do t[i]:=0;
    readln(fi,n);
    for i:=1 to n do begin
        read(fi,j);
        t[j]:=t[j]+1;
    end;
    res:=t[0]*(t[0]-1) div 2;
    for i:=1 to MAX_T do res:=res+t[i]*t[-i];
    writeln(fo,res);
    close(fo);
    close(fi);
end.