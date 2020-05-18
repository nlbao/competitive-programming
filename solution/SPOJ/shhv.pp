const   MAX_N = 13;

var fi,fo:text;
    n:longint;
    a,f:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;

procedure   enter();
begin
    n:=0;
    while not eoln(fi) do begin
        inc(n);
        read(fi,a[n]);
    end;
end;


procedure   solve1();
var i,j,c,res:longint;
begin
    f[0]:=1;
    for i:=1 to n do begin
        ok[i]:=true;
        f[i]:=f[i-1]*i;
    end;
    res:=1;
    for i:=1 to n do begin
        c:=0;
        for j:=1 to a[i]-1 do
            if ok[j] then inc(c);
        res:=res+c*f[n-i];
        ok[a[i]]:=false;
    end;
    writeln(fo,res);
end;


procedure   solve2();
var i,j,k:longint;
begin
    read(fi,k);
    for i:=1 to n do ok[i]:=true;
    for i:=1 to n do
        for j:=1 to n do
            if ok[j] then
                if f[n-i] >= k then begin
                    a[i]:=j;
                    ok[j]:=false;
                    break;
                end
                else k:=k-f[n-i];
    for i:=1 to n do write(fo,a[i],' ');
end;


begin
    assign(fi,'shhv.in');   reset(fi);
    assign(fo,'shhv.out');  rewrite(fo);
    enter();
    solve1();
    solve2();
    close(fo);
    close(fi);
end.