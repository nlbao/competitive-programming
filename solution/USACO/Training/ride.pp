{
    PROB: ride
    LANG: PASCAL
    ID: storm59061
}


const
    INPUT = 'ride.in';
    OUTPUT = 'ride.out';

var
    fi,fo:text;
    s1,s2:string;

function    f(var s:string):longint;
var
    i:longint;
begin
    f:=1;
    for i:=1 to length(s) do
        f:=f*(ord(s[i])-ord('A')+1);
    exit(f mod 47);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,s1);
    readln(fi,s2);
    if f(s1) = f(s2) then writeln(fo,'GO')
    else writeln(fo,'STAY');
    close(fo);
    close(fi);
end.