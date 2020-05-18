{$R+,Q+}
const   MAX_N = 4010;

type    int = int64;

var fi,fo:text;
    n,i,j,t,pt:longint;
    f:array[0..1,0..MAX_N] of int;
    res:int;

begin
    assign(fi,'1017.in');     reset(fi);
    assign(fo,'1017.out');    rewrite(fo);
    readln(fi,n);
    res:=0;
    f[0][1]:=1;
    for j:=2 to n do f[0][j]:=0;
    for i:=2 to n-1 do begin
        pt:=t;
        t:=(t+1) mod 2;
        for j:=0 to i-1 do f[t][j]:=0;
        f[t][i]:=1;
        for j:=i+1 to n do
            f[t][j]:=f[pt][j-1]+f[pt][j-i];
        res:=res+f[t][n];
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.