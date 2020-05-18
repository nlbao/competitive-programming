var fi,fo:text;
    n,m,k:int64;

function    mmod(x:int64):int64;    begin   exit(x mod 1000000007); end;

function    pow(a,p:int64):int64;
var t:int64;
begin
    if p = 1 then exit(mmod(a));
    t:=mmod(sqr(pow(a,p div 2)));
    if p mod 2 = 0 then exit(t)
    else exit(mmod(t*a));
end;

function    solve(n,m,k:longint):int64;
begin
    if (n < k) then exit(pow(m,n));
    if k mod 2 = 0 then
        if n <> k then exit(m)
        else exit(pow(m,n div 2));
    if k = 1 then exit(pow(m,n))
    else
        if n <> k then exit(mmod(m*m))
        else exit(mmod(pow(m,n div 2)*m));
end;

begin
    assign(fi,'151D.in');   reset(fi);
    assign(fo,'151D.out');  rewrite(fo);
    readln(fi,n,m,k);
    writeln(fo,solve(n,m,k));
    close(fo);
    close(fi);
end.
