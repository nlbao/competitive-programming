var fi,fo:text;

function    is_lucky(n:longint):boolean;
var i:longint;
begin
    repeat
        i:=n mod 10;
        if (i <> 4) and (i <> 7) then exit(false);
        n:=n div 10;
    until n = 0;
    exit(true);
end;


function    solve:string;
var n,i:longint;
begin
    readln(fi,n);
    for i:=1 to n do
        if (n mod i = 0) and (is_lucky(i)) then exit('YES');
    exit('NO');
end;

begin
    assign(fi,'122A.in');   reset(fi);
    assign(fo,'122A.out');  rewrite(fo);
    writeln(fo,solve);
    close(fo);
    close(fi);
end.