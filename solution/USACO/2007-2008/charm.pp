const   MAX_N = 3500;
        MAX_M = 13000;

var fi,fo:text;
    n,m,i,j,res:longint;
    w,v:array[0..MAX_N] of longint;
    f:array[0..MAX_M] of longint;

procedure   up(var x:longint;   y:longint); begin   if y > x then x:=y; end;

begin
    assign(fi,'charm.in');  reset(fi);
    assign(fo,'charm.out'); rewrite(fo);
    readln(fi,n,m);
    for i:=1 to n do
        readln(fi,w[i],v[i]);
    fillchar(f,sizeof(f),0);
    for i:=1 to n do
        for j:=m-w[i] downto 0 do
            up(f[j+w[i]],f[j]+v[i]);
    res:=0;
    for i:=0 to m do up(res,f[i]);
    writeln(fo,res);
    close(fo);
    close(fi);
end.