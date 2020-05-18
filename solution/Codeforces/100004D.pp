const   c:array['A'..'Z'] of longint = (2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9);

var fi,fo:text;
    nTest,n:longint;
    s:ansiString;
    t:array[0..100] of longint;

function    check:string;
var i,j:longint;
begin
    for i:=1 to n do t[i]:=c[upcase(s[i])];
    i:=1;   j:=n;
    while i < j do begin
        if (t[i] <> t[j]) then exit('NO');
        inc(i); dec(j);
    end;
    exit('YES');
end;

begin
    assign(fi,'100004D.in');    reset(fi);
    assign(fo,'100004D.out');   rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,s);
        n:=length(s);
        writeln(fo,check);
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
