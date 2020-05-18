const
    INPUT = 'D.inp';
    OUTPUT = 'D.out';

var
    fi,fo:text;
    a,b:longint;

function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,a,b);
    writeln(fo,max(40+2*b,39+2*a));
    close(fo);
    close(fi);
end.