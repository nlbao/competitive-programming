const
    INPUT = '';
    OUTPUT = '';

var
    fi,fo:text;
    s:string;
    a:longint;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,s);
    readln(fi,a);
    if s[1] = 'f' then
        if a = 1 then writeln(fo,'L')
        else writeln(fo,'R');
    if s[1] = 'b' then
        if a = 1 then writeln(fo,'R')
        else writeln(fo,'L');
    close(fo);
    close(fi);
end.