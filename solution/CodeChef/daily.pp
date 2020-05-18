var fi,fo:text;
    s:ansiString;
    n,x,i,j,res:longint;
    a:array[0..9] of longint;

function    cal_c(k,n:longint):longint;
var i,c:longint;
begin
    if (k = 0) or (k = n) then exit(1);
    if (k < 0) or (k > n) then exit(0);
    c:=1;
    for i:=1 to n do c:=c*i;
    for i:=1 to k do c:=c div i;
    for i:=1 to n-k do c:=c div i;
    exit(c);
end;

begin
    assign(fi,'daily.in');  reset(fi);
    assign(fo,'daily.out'); rewrite(fo);
    readln(fi,x,n);
    res:=0;
    for i:=1 to n do begin
        for j:=1 to 9 do a[j]:=0;
        readln(fi,s);
        for j:=1 to 54 do
            if s[j] = '0' then
                if j < 37 then inc(a[((j-1) div 4)+1])
                else inc(a[((54-j) div 2)+1]);
        for j:=1 to 9 do
            res:=res+cal_c(x,a[j]);
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.