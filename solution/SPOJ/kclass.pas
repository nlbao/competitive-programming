uses    math;

const   MAX_N = 2010;
        MAX_M = 110;
        MODUN = 1000000007;

type    ll = int64;

var fi,fo:text;
    n,m,i,j,k,l,r:longint;
    x,y,s:array[0..MAX_M] of longint;
    c:array[0..MAX_N,0..MAX_N] of longint;
    g:array[0..MAX_M,0..MAX_N] of longint;
    t,res:ll;


//function    mmod(x:ll):ll;  begin  exit(x mod MODUN); end;


procedure   cal_c();
var i,j:longint;
begin
    fillchar(c,sizeof(c),0);
    c[0][0]:=1;
    for i:=1 to n do begin
        for j:=1 to i do
            c[i][j]:=(c[i-1][j] + c[i-1][j-1]) mod MODUN;
        c[i][0]:=1;
        c[i][i]:=1;
    end;
end;


function    get_c(k,n:longint):ll;
begin
    if n < 1 then writeln('!!!');
    if k > n then exit(0);
    if (k = 0) or (k = n) then exit(1);
    exit(c[n][k]);
end;


begin
    assign(fi,'kclass.in');     reset(fi);
    assign(fo,'kclass.out');    rewrite(fo);

    read(fi,m);
    n:=0;   s[0]:=0;
    for i:=1 to m do begin
        read(fi,x[i]);
        n:=n+x[i];
        s[i]:=s[i-1]+x[i];
    end;
    for i:=1 to m do read(fi,y[i]);

    cal_c();

    res:=get_c(x[1],n);
    for i:=2 to m do res:=(res*int64(c[n-s[i-1]][x[i]])) mod MODUN;


    fillchar(g,sizeof(g),0);
    for i:=0 to s[1] do g[1][i]:=get_c(i,s[1]);
    for i:=2 to m-1 do
        for j:=0 to s[i] do begin
            l:=max(j-y[i],0);
            r:=min(j,s[i-1]);
            for k:=l to r do
                g[i][j]:=(g[i][j] + (int64(g[i-1][k])*int64(c[s[i]-k][j-k])) mod MODUN) mod MODUN;
        end;

    t:=0;
    for k:=0 to y[m]-x[m] do begin
        j:=s[m]-x[m]-k;
        if j < 0 then break;
        t:=(t + g[m-1][j]) mod MODUN;
    end;

    writeln(fo,(t*res) mod MODUN);
    close(fo);
    close(fi);
end.