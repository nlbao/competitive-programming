uses    math;

const   MAX_N = 2003;
        oo = 2000000000;

type    ll = longint;

var fi,fo:text;
    n,i,j,t,len:longint;
    a:array[0..MAX_N] of longint;
    k:array[0..MAX_N,0..MAX_N] of longint;
    w,f:array[0..MAX_N,0..MAX_N] of ll;
    v:ll;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'OPTCUT.in');    reset(fi);
    assign(fo,'OPTCUT.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n);
    for i:=1 to n do read(fi,a[i]);
    for i:=1 to n do begin
        w[i][i]:=a[i];
        for j:=i+1 to n do
            w[i][j]:=w[i][j-1]+a[j];
    end;

    for i:=1 to n do begin
        f[i][i]:=0;
        k[i][i]:=i;
    end;

    for len:=2 to n do begin
        for i:=1 to n-len+1 do begin
            j:=i+len-1;
            f[i][j]:=oo;
            for t:=k[i][j-1] to k[i+1][j] do begin
                v:=w[i][j] + f[i][t] + f[t+1][j];
                if v < f[i][j] then begin
                    f[i][j]:=v;
                    k[i][j]:=t;
                end;
            end;
        end;
    end;
    writeln(fo,f[1][n]);
    close(fi);
    close(fo);
end.


