{$N+}

const
    INPUT = 'Fire.inp';
    OUTPUT = 'Fire.out';
    MAX_N = 10000;
    MAX = 1000000000000;

type
    recC = record
        x,y,r:double;
    end;

var
    fi,fo:text;
    N:longint;
    C:array[1..MAX_N] of recC;

{---------------------------------------------------------------------------}
function    d(x1,y1,x2,y2:double):double;   inline;
begin
    exit(sqrt(sqr(x1-x2)+sqr(y1-y2)));
end;
{---------------------------------------------------------------------------}
function    min(x,y:double):double; inline;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   Enter;
var
    i:longint;
begin
    readln(fi,N);
    for i:=1 to N do
        readln(fi,C[i].x,C[i].y,C[i].r);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,j:longint;
    minD,tmp:double;
begin
    minD:=MAX;
    for i:=1 to N-1 do
        for j:=i+1 to N do begin
            tmp:=d(C[i].x,C[i].y,C[j].x,C[j].y)-C[i].r-C[j].r;
            if tmp < minD then minD:=tmp;
        end;

    writeln(fo,minD:0:4);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    Solve;
    close(fo);
    close(fi);
end.
