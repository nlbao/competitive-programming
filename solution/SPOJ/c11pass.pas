{$M 2000000,0,2000000}
uses    math;

const   MAX_N = 1003;
        oo = 1000000000;
        MODULE = 1000000007;

type    ll = int64;

var fi,fo:text;
    nTest,n,m,k:ll;
    f:array[0..1,0..MAX_N] of ll;


procedure   up(var x:ll;    y:ll);
begin   x:=(x + (y mod MODULE)) mod MODULE; end;


function    solve():ll;
var i,j,t,tt:longint;
begin
    if n mod m <> 0 then exit(0);
    if k = 1 then exit(1);

    fillchar(f,sizeof(f),0);
    t:=0;
    f[t][0]:=1;
    for i:=0 to n-1 do begin
        tt:=t;
        t:=1-t;
        for j:=0 to n do f[t][j]:=0;

        up(f[t][m-1], k*f[tt][0]);
        for j:=1 to n do begin
            if f[tt][j] = 0 then continue;
            up(f[t][j-1], f[tt][j]);
            if j+m-1 <= n then
                up(f[t][j+m-1], (k-1)*f[tt][j]);
        end;
    end;
    exit(f[t][0]);
end;


begin
{$IFDEF WINDOWS}
    assign(fi,'C11PASS.in');    reset(fi);
    assign(fo,'C11PASS.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,n,k,m);
        writeln(fo,solve());
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.