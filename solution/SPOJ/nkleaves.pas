uses    math;

const   MAX_N = 100005;
        MAX_M = 13;
        oo = 20000000000000;

type    ll = int64;

var fi,fo:text;
    n,m,pre:longint;
    w,s,p,q:array[0..MAX_N] of ll;
    f:array[0..1,0..MAX_N] of ll;


procedure   enter();
var i:longint;
begin
    read(fi,n,m);
    for i:=1 to n do read(fi,w[n-i+1]);
end;


procedure   init();
var i:longint;
begin
    s[n+1]:=0;  p[n+1]:=0;
    for i:=n downto 1 do begin
        s[i]:=s[i+1]+w[i];
        p[i]:=p[i+1]+int64(i)*w[i];
    end;
end;

function    c(i,j:ll):ll;   begin   exit(j*(s[i]-s[j+1]) + p[j+1]-p[i]); end;

{function    g(i,j:ll):ll;
begin   exit(f[pre][i+1] - f[pre][j+1] + j*s[j+1] - i*s[i+1] - p[j+1] + p[i+1]);    end;}


function    g(i,j:ll):double;
begin   exit(double(f[pre][i+1] - f[pre][j+1] + j*s[j+1] - i*s[i+1] - p[j+1] + p[i+1])/double(j-i)); end;


procedure   solve();
var i,j,k,t,tt:longint;
    l,r:longint;
begin
    t:=0;
    for i:=1 to n do f[t][i]:=c(i,n);
    for i:=1 to m do begin
        f[0][n+1]:=oo;
        f[1][n+1]:=oo;
    end;

    for j:=2 to m do begin
        tt:=t;
        t:=(t+1) and 1;
        pre:=tt;
        l:=1;   r:=0;
        for i:=n downto 1 do begin
            f[t][i]:=oo;
            {if n-i+1 < j then continue;
            if n-i+1 = j then begin
                f[t][i]:=0;
                inc(r); q[r]:=i;
                continue;
            end;}

            {while (l < r) and (g(q[l+1],q[l]) <= s[i]*(q[l]-q[l+1])) do inc(l);
            if l <= r then f[t][i]:=c(i,q[l]) + f[tt][q[l]+1];
            while (r > l) and (g(i,q[r])*(q[r-1]-q[r]) <= g(q[r],q[r-1])*int64(q[r]-i)) do dec(r);
            inc(r); q[r]:=i;}

            while (r > l) and (g(i,q[r]) <= g(q[r],q[r-1])) do dec(r);
            inc(r); q[r]:=i;
            while (l < r) and (g(q[l+1],q[l]) <= s[i]) do inc(l);
            if l <= r then f[t][i]:=c(i,q[l]) + f[tt][q[l]+1];

            {for k:=i to n do
                f[i][j]:=min(f[i][j],c(i,k)+f[k+1][j-1]);}
        end;
    end;
    writeln(fo,f[t][1]);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'NKLEAVES.in');    reset(fi);
    assign(fo,'NKLEAVES.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    init();
    solve();
    close(fi);
    close(fo);
end.