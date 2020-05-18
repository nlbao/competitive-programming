{
    ID: storm59061
    PROB: palsquare
    LANG: PASCAL
}

const
    INPUT = 'palsquare.in';
    OUTPUT = 'palsquare.out';
    N = 300;

var
    fi,fo:text;
    base,i:longint;
    s:string;

function    check(var s:string):boolean;
var
    i,m:longint;
begin
    m:=length(s);
    if m = 0 then exit(false);
    for i:=1 to m div 2 do
        if s[i] <> s[m-i+1] then exit(false);
    exit(true);
end;

function    convert(x,base:longint):string;
var
    r:longint;
    s:string;
begin
    s:='';
    while x > 0 do begin
        r:=x mod base;
        if r < 10 then s:=chr(ord('0')+r)+s
        else s:=chr(ord('A')+r-10)+s;
        x:=x div base;
    end;
    exit(s);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,base);
    for i:=1 to N do begin
        s:=convert(sqr(i),base);
        if check(s) = true then
            writeln(fo,convert(i,base),' ',s);
    end;
    close(fo);
    close(fi);
end.