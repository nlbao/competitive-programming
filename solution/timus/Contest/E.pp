const
    INPUT = 'E.inp';
    OUTPUT = 'E.out';

var
    fi,fo:text;
    i:longint;
    s,res:string;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    res:='no';
    readln(fi,s);
    if ord(s[4]) mod 2 = 0 then res:='yes';
    readln(fi,s);
    if ord(s[4]) mod 2 = 1 then res:='yes';
    writeln(fo,res);
    close(fo);
    close(fi);
end.