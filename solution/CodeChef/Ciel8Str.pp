const   INPUT = 'test.out'{'Ciel8Str.in'};
        OUTPUT = 'Ciel8Str.out';
        MAX_N = 1000010;

var fi,fo:text;
    ch:char;
    i,j,k,t,tt,a:longint;
    f:array[0..1,0..7] of int64;
    res:int64;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    res:=0;
    t:=0;
    for i:=0 to 7 do f[0][i]:=0;
    while not eoln(fi) do begin
        read(fi,ch);
        a:=ord(ch)-ord('0');
        tt:=t;  t:=(t+1) mod 2;
        for j:=0 to 7 do f[t][j]:=0;
        for j:=0 to 7 do begin
            k:=(2*j+a) mod 8;
            f[t][k]:=f[t][k]+f[tt][j];
        end;
        if a <> 0 then f[t][a mod 8]:=f[t][a mod 8]+1
        else res:=res+1;
        res:=res+f[t][0];
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.