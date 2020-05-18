const   INPUT = '131A.in';
        OUTPUT = '131A.out';

var fi,fo:text;
    s:string;

function    solve(var s:string):string;
var i:longint;
begin
    for i:=2 to length(s) do
        if upcase(s[i]) <> s[i] then exit(s);
    if upcase(s[1]) <> s[1] then s[1]:=upcase(s[1])
    else s[1]:=chr(ord(s[1])+32);
    for i:=2 to length(s) do s[i]:=chr(ord(s[i])+32);
    exit(s);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,s);
    writeln(fo,solve(s));
    close(fo);
    close(fi);
end.