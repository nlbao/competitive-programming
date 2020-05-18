uses    math;

const   MAX_N = 10000005;
        MAX_P = 664599;
        MODUN = 1000000007;

type    ll = int64;

var fi,fo:text;
    n,nP,nA:longint;
    ok:array[0..MAX_N] of boolean;
    turn,p:array[0..MAX_N] of longint;

function    mpow(x,m:ll):ll;
var t:ll;
begin
    if m = 0 then exit(1);
    if m = 1 then exit(x);
    t:=mpow(x,m shr 1);
    t:=(t*t) mod MODUN;
    if (m and 1) = 1 then exit((t*x) mod MODUN);
    exit(t);
end;


function    solve():ll;
var i,j:longint;
    c,t,sum,x,res:ll;
begin
    if n < 1 then exit(0);
    if n = 1 then exit(1);
    res:=1;
    for i:=2 to n do begin
        ok[i]:=true;
        turn[i]:=0;
    end;
    for i:=2 to n do
        if ok[i] then begin
            sum:=0;
            j:=i;   c:=1;
            while j <= n do begin
                ok[j]:=false;
                turn[j]:=i;
                if turn[c] = i then p[j]:=p[c]+1
                else p[j]:=1;
                sum:=sum+p[j];
                j:=j+i;
                inc(c);
            end;
            if (sum and 1) = 1 then sum:=sum-1;
            res:=(mpow(i,sum)*res) mod MODUN;
        end;
    exit(res);
end;


begin
    assign(fi,'c11genie.in');   reset(fi);
    assign(fo,'c11genie.out');  rewrite(fo);
    read(fi,n);
    writeln(fo,solve());
    close(fo);
    close(fi);
end.