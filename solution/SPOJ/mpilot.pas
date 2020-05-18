uses    math;

const   MAX_N = 10010;
        oo = 1000000000;

var fi,fo:text;
    n,a,b,i,j,t,tt:longint;
    f:array[0..1,0..MAX_N] of longint;


begin
    assign(fi,'mpilot.in');     reset(fi);
    assign(fo,'mpilot.out');    rewrite(fo);
    read(fi,n);
    for i:=0 to n+1 do begin
        f[0][i]:=oo;
        f[1][i]:=oo;
    end;

    t:=0;
    f[t][0]:=0;
    for i:=1 to n do begin
        read(fi,a,b);
        tt:=t;
        t:=(t+1) and 1;
        for j:=1 to (i shr 1) do
            f[t][j]:=min(f[tt][j-1] + a, f[tt][j] + b);
        f[t][0]:=f[tt][0] + b;
    end;
    writeln(fo,f[t][n shr 1]);
    close(fo);
    close(fi);
end.
