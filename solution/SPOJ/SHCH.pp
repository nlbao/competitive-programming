const   MAX_N = 11;

var fi,fo:text;
    n,k,q:longint;
    b,c,ok:array[0..MAX_N] of longint;
    a:array[0..MAX_N,0..MAX_N] of longint;

procedure   enter;
var i:longint;
begin
    readln(fi,n,k);
    readln(fi,q);
    for i:=1 to k do read(fi,b[i]);
end;


procedure   init;
var i,j:longint;
begin
    for i:=0 to n do
        for j:=0 to n do a[i][j]:=1;
    for i:=2 to n do begin
        a[i][1]:=i;
        for j:=2 to i do
            a[i][j]:=a[i][j-1]*(i-j+1);
    end;
end;


procedure   solve1;
begin

end;

procedure   solve2;
var i,j,p,s:longint;
begin
    s:=1;
    fillchar(ok,sizeof(ok),0);
    for i:=1 to k do begin
        p:=0;
        for j:=1 to b[i]-1 do
            if ok[j] = 0 then inc(p);
        s:=s+p*a[n-i][k-i];
        ok[b[i]]:=1;
    end;
    writeln(fo,s);
end;

begin
    assign(fi,'SHCH.in');   reset(fi);
    assign(fo,'SHCH.out');  rewrite(fo);
    enter;
    init;
    solve1;
    solve2;
    close(fo);
    close(fi);
end.