const   MAX_N = 1000000000;

var fi,fo:text;
    n:longint;

function    solve(n:longint):longint;
var i,j,c2,res:longint;

    procedure   add(i,value:longint);
    begin
        while i mod 2 = 0 do begin
            c2:=c2+value;
            i:=i shr 1;
        end;
    end;
begin
    res:=1;
    c2:=0;
    i:=n+1; j:=0;
    while i > 1 do begin
        i:=i-1; add(i,1);
        j:=j+1; add(j,-1);
        if c2 < 1 then res:=res+1;
    end;
    exit(res);
end;

begin
    assign(fi,'KCoin.in');  reset(fi);
    assign(fo,'KCoin.out'); rewrite(fo);
    readln(fi,n);
    for n:=1 to 10 do write(fo,solve(n),' ');
    writeln;
    close(fo);
    close(fi);
end.
