uses    math;

const   MAX_N = 10010;
        MAX_K = 15;
        oo = 1000000000;

var fi,fo:text;
    n,k,i,j,a,res:longint;
    f:array[0..MAX_N] of longint;


begin
    assign(fi,'amsseq.in');     reset(fi);
    assign(fo,'amsseq.out');    rewrite(fo);
    read(fi,n,k);
    res:=0;
    f[0]:=0;
    for i:=1 to n do begin
        f[i]:=-oo;
        read(fi,a);
        for j:=max(0,i-k) to i-1 do
            f[i]:=max(f[i], f[j]+a);
        res:=max(res,f[i]);
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.