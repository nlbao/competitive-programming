const   INPUT = 'ADDREV.in';
        OUTPUT = 'ADDREV.out';
        MAX_N = 10010;

var fi,fo:text;
    n,a,b:longint;

function    reverse(x:longint):longint;
var s,t:string;
    i:longint;
begin
    str(x,s);
    t:='';
    for i:=length(s) downto 1 do t:=t+s[i];
    val(t,x,i);
    exit(x);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,n);
    while n > 0 do begin
        readln(fi,a,b);
        writeln(fo,reverse(reverse(a)+reverse(b)));
        dec(n);
    end;
    close(fo);
    close(fi);
end.