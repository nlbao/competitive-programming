{$M+ 2000000,0,2000000}
uses    math;

const   MAX_N = 105;
        oo = 1000000000;
        MODULE = 1000000007;
        BASE = 10007;

type    ll = int64;

var fi,fo:text;
    n,m,nH:longint;
    a,t:array[0..MAX_N] of longint;
    p,h,b:array[0..MAX_N] of ll;
    c,f:array[0..MAX_N,0..MAX_N] of ll;


function    mmod(x:ll):ll;
begin
    x:=x mod MODULE;
    exit((x+MODULE) mod MODULE);
end;


procedure   enter();
var i:longint;
begin
    read(fi,n);
    for i:=1 to n do begin
        read(fi,a[i]);
        inc(a[i]);
    end;
end;


procedure   solve();
var i,j,k,len,turn:longint;
    g,sum:ll;
begin
    fillchar(c,sizeof(c),0);
    for i:=0 to n do begin
        c[i][0]:=1;
        for j:=1 to i do
            c[i][j]:=mmod(c[i-1][j-1] + c[i-1][j]);
    end;

    p[0]:=1;
    for i:=1 to n do p[i]:=longint(p[i-1]*BASE);

    turn:=0;
    for i:=1 to n do f[i][i]:=1;
    for len:=2 to n do
        for i:=1 to n-len+1 do begin
            inc(turn);
            j:=i+len-1;

            nH:=0;  h[0]:=0;
            for k:=i to j do t[a[k]]:=turn;
            for k:=1 to n do
                if t[k] = turn then begin
                    inc(nH);
                    b[nH]:=p[k];
                    h[nH]:=longint(h[nH-1] + p[k]);
                end;

            f[i][j]:=0;
            sum:=0;
            for k:=i to j-1 do begin
                sum:=longint(sum + p[a[k]]);
                if sum <> longint(h[k-i] + b[k-i+2]) then continue;
                g:=mmod(mmod(f[i][k]*f[k+1][j])*c[j-i-1][k-i]);
                f[i][j]:=mmod(f[i][j] + g);
            end;
        end;
    writeln(fo,f[1][n]);
end;


begin
{$IFDEF WINDOWS}
    assign(fi,'C11SWAP.in');    reset(fi);
    assign(fo,'C11SWAP.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.