const   INPUT = 'KINV.inp';
        OUTPUT = 'KINV.out';
        MAX_N = 10010;
        MAX_K = 20;
        MODUN = 1000000000;

var fi,fo:text;
    n,k:longint;
    a,t:array[0..MAX_N] of longint;
    f:array[0..MAX_N] of longint;

procedure   enter;
var i:longint;
begin
    readln(fi,n,k);
    for i:=1 to n do read(fi,a[i]);
end;

procedure   update(i,value:longint);
begin
    if (i < 1) or (i > n) then exit;
    t[i]:=(t[i]+value) mod MODUN;
    update(i+(i and (-i)),value);
end;

function    get(i:longint):longint;
begin
    if (i < 1) or (i > n) then exit(0);
    if i = 1 then exit(t[1]);
    exit((get(i-(i and (-i)))+t[i]) mod MODUN);
end;

procedure   solve;
var i,j,tmp,res:longint;
begin
    for i:=1 to n do f[i]:=1;
    for j:=2 to k do begin
        for i:=1 to n do t[i]:=0;
        for i:=n downto 1 do begin
            tmp:=get(a[i]-1);
            update(a[i],f[i]);
            f[i]:=tmp;
        end;
    end;
    res:=0;
    for i:=1 to n do res:=(res+f[i]) mod MODUN;
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