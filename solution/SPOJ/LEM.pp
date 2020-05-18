program LEM;
const
    INPUT = 'LEM.inp';
    OUTPUT = 'LEM.out';
    MAX_N = 1010;
    MAX_M = 1010;

type
    recPoint = record
        x,y:longint;
    end;

var
    fi,fo:text;
    N,M:longint;
    a:array[0..MAX_N] of recPoint;
    b:array[0..MAX_M] of recPoint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,N,M);
    for i:=1 to N do readln(fi,a[i].x,a[i].y);
    for i:=1 to M do readln(fi,b[i].x,b[i].y);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j:longint;
    min,d:double;
begin
    min:=MAXLONGINT;
    for i:=1 to N do
        for j:=1 to M do begin
            d:=sqrt(sqr(a[i].x-b[j].x)+sqr(a[i].y-b[j].y));
            if d < min then min:=d;
        end;
    writeln(fo,min:0:3);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.