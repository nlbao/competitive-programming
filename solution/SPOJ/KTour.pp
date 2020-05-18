{$N+}
const
    INPUT = 'KTour.inp';
    OUTPUT = 'KTour.out';
    MAX_N = 1000000;
    MAX_M = 1000000;

type
    recB = record
        x,y:double;
    end;
var
    N,M:longint;
    A:array[1..MAX_N] of double;
    B:array[1..MAX_M] of recB;
    y0,Res:double;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,N,y0);
    for i:=1 to N do read(fi,A[i]);
    read(fi,M);
    for i:=1 to M do read(fi,B[i].x,B[i].y);
    close(fi);
end;

{function    min(x,y:double):double;
begin
    if x < y then exit(x)
    else exit(y);
end;

function    max(x,y:double):double;
begin
    if x > y then exit(x)
    else exit(y);
end;

function    lengthD(x1,y1,x2,y2:double):double;
begin
    exit(sqrt(sqr(x1-x2)+sqr(y1-y2)));
end;}

procedure   Solve;
var
    i,j:longint;
    minL,tmp:double;
begin
    Res:=0;
    for i:=1 to N do
        begin
            {minL:=lengthD(A[i],y0,B[1].x,B[1].y);}
            minL:=sqrt(sqr(A[i]-B[1].x)+sqr(y0-B[1].y));
            for j:=2 to M do
                begin
                    tmp:=sqrt(sqr(A[i]-B[j].x)+sqr(y0-B[j].y));
                    if tmp < minL then minL:=tmp;
                {minL:=min(minL,lengthD(A[i],y0,B[j].x,B[j].y));}
                end;
            {Res:=max(Res,minL);}
            if minL > Res then Res:=minL;
        end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,Res:0:6);
    close(fo);
end;

begin
    Enter;
    Solve;
    Print_result;
end.
