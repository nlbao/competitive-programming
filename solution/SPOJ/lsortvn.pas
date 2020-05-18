uses    math;

const   MAX_N = 1003;

type    ll = longint;

var fi,fo:text;
    n,i,j,len,t,tt:longint;
    a,p:array[0..MAX_N] of longint;
    g:array[0..MAX_N,0..MAX_N] of longint;
    f:array[0..1,0..MAX_N] of ll;
    t1,t2,res:ll;


begin
    assign(fi,'lsortvn.in');    reset(fi);
    assign(fo,'lsortvn.out');   rewrite(fo);
    read(fi,n);
    for i:=1 to n do begin
        read(fi,a[i]);
        p[a[i]]:=i;
    end;

    for i:=1 to n do begin
        g[i][0]:=0;
        for j:=1 to n do begin
            g[i][j]:=g[i][j-1];
            if p[j] < p[i] then inc(g[i][j]);
        end;
    end;

    t:=0;
    for i:=1 to n do f[0][i]:=p[i];
    for len:=2 to n do begin
        tt:=t;
        t:=(t+1) and 1;
        for i:=1 to n-len+1 do begin
            j:=i+len-1;
            t1:=p[i] - (g[i][j]-g[i][i-1]);
            t2:=p[j] - (g[j][j]-g[j][i-1]);
            f[t][i]:=min(f[tt][i+1] + t1*len, f[tt][i] + t2*len);
        end;
    end;
    writeln(fo,f[t][1]);
    close(fo);
    close(fi);
end.