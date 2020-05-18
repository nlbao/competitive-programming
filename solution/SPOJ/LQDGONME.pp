const   INPUT = 'LQDGONME.in';
        OUTPUT = 'LQDGONME.out';
        MAX_N = 1010;
        MAX_M = 20;

var fi,fo:text;
    n,m:longint;
    a,pos:array[0..MAX_M,0..MAX_N] of longint;

function    max(x,y:longint):longint;   begin   if x > y then exit(x)   else exit(y);   end;

procedure   enter;
var i,j:longint;
begin
    readln(fi,n,m);
    for i:=1 to m do
        for j:=1 to n do begin
            read(fi,a[i][j]);
            pos[i][a[i][j]]:=j;
        end;
end;

function    check(x,y:longint):boolean;
var i:longint;
begin
    for i:=1 to m do
        if pos[i][x] > pos[i][y] then exit(false);
    exit(true);
end;

procedure   solve;
var i,j,x,res:longint;
    f:array[0..MAX_N] of longint;
begin
    res:=1;
    for i:=1 to n do f[i]:=1;
    for i:=n downto 1 do begin
        x:=a[1][i];
        for j:=i+1 to n do
            if check(x,a[1][j]) = true then
                f[x]:=max(f[x],f[a[1][j]]+1);
        res:=max(res,f[x]);
    end;
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
