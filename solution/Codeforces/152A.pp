var fi,fo:text;
    n,m,i,j,res:longint;
    a:array[0..110,0..110] of char;

function    is_best(i,j:longint):boolean;
var k:longint;
begin
    for k:=1 to n do
        if a[k][j] > a[i][j] then exit(false);
    exit(true);
end;

begin
    assign(fi,'152A.in');   reset(fi);
    assign(fo,'152A.out');  rewrite(fo);
    readln(fi,n,m);
    for i:=1 to n do begin
        for j:=1 to m do read(fi,a[i][j]);
        readln(fi);
    end;
    res:=0;
    for i:=1 to n do
        for j:=1 to m do
            if is_best(i,j) then begin
                res:=res+1;
                break;
            end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.