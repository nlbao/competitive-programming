var n,a,b,i:longint;
begin
    readln(n,a,b);
    i:=n-b-1;
    if a > i then i:=a;
    writeln(n-i);
end.