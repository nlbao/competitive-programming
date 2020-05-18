const   INPUT = 'zbroj.in';
        OUTPUT = 'zbroj.out';

var fi,fo:text;
    a,b:longint;

function    f(n:longint;    c1,c2:char):longint;
var i:longint;
    s:string;
begin
    str(n,s);
    for i:=1 to length(s) do
        if s[i] = c1 then s[i]:=c2;
    val(s,i);
    exit(i);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,a,b);
    write(fo,f(a,'6','5')+f(b,'6','5'),' ',f(a,'5','6')+f(b,'5','6'));
    close(fo);
    close(fi);
end.