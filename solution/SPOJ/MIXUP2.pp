const   MAX_N = 18;
        MAX_K = 3410;
        MAX_P = 65540;

var fi,fo:text;
    n,k,i,j,ii,t:longint;
    a:array[0..MAX_N] of longint;
    ok:array[0..MAX_N,0..MAX_N] of boolean;
    f:array[0..MAX_P,0..MAX_N] of int64;
    res:int64;

function    get_bit(i,x:longint):longint;
begin
    exit((x shr (i-1)) and 1);
end;

begin
    assign(fi,'mixup2.in');     reset(fi);
    assign(fo,'mixup2.out');    rewrite(fo);
    read(fi,n,k);
    for i:=1 to n do read(fi,a[i]);

    for i:=1 to n do
        for j:=1 to n do
            if abs(a[i]-a[j]) > k then ok[i][j]:=true
            else ok[i][j]:=false;

    fillchar(f,sizeof(f),0);
    for i:=1 to n do f[1 shl (i-1),i]:=1;
    for i:=0 to (1 shl n)-1 do
        for j:=1 to n do
            for t:=1 to n do
                if (get_bit(t,i) = 0) and (ok[j][t]) then begin
                    ii:=i or (1 shl (t-1));
                    f[ii,t]:=f[ii,t]+f[i][j];
                end;

    res:=0;
    for i:=1 to n do res:=res+f[(1 shl n)-1,i];
    writeln(fo,res);
    close(fo);
    close(fi);
end.