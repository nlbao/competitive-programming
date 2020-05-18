





procedure   enter();
var i,j:longint;
begin
    read(fi,m,n);
    for i:=1 to m do
        for j:=1 to n do read(fi,a[i][j]);
end;



procedure       tryf(j:longint);
begin
    if found then exit;
    if j > n then begin
        found:=check_f();
        exit;
    end;

//try 0
    if ok(1,j,0) then begin
        f[1][j]:=0;
        ck:=true;
        for i:=
    end;
//try 1

end;



procedure   solve();
var i,j:longint;
begin
    fillchar(c,sizeof(c),0);
    tryf(1);
    for i:=1 to m do begin
        for j:=1 to n do write(fo,f[i][j],' ');
        writeln(fo);
    end;
end;


begin
    assign(fi,'nkmines.in');    reset(fi);
    assign(fo,'nkmines.out');   rewrite(fo);
    enter();
    solve();
    close(fo);
    close(fi);
end.