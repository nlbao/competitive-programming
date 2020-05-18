const
    INPUT = '112A.inp';
    OUTPUT = '112A.out';

var
    fi,fo:text;
    s1,s2:ansiString;

function    check:longint;
var
    i,x,y:longint;
begin
    for i:=1 to length(s1) do begin
        x:=ord(upcase(s1[i]));
        y:=ord(upcase(s2[i]));
        if x < y then exit(-1)
        else if x > y then exit(1);
    end;
    exit(0);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,s1);
    readln(fi,s2);
    writeln(fo,check);
    close(fo);
    close(fi);
end.