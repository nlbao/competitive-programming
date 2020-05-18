

var fi,fo:text;


function    check:string;
var i,j:longint;
    ch:char;
    s:ansiString;
    c:array['A'..'Z'] of longint;
begin
    fillchar(c,sizeof(c),0);
    for i:=1 to 2 do begin
        readln(fi,s);
        for j:=1 to length(s) do inc(c[s[j]]);
    end;
    readln(fi,s);
    for j:=1 to length(s) do c[s[j]]:=c[s[j]]-1;
    for ch:='A' to 'Z' do
        if c[ch] <> 0 then exit('NO');
    exit('YES');
end;


begin
    assign(fi,'141A.in');   reset(fi);
    assign(fo,'141A.out');  rewrite(fo);
    writeln(fo,check);
    close(fo);
    close(fi);
end.