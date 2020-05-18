const
    INPUT = 'NKPoly.inp';
    OUTPUT = 'NKPoly.out';
    MAX_N = 210;
    MAX_INT = sqr(10000000);

type
    recPoint = record
        x,y:double;
    end;
    arrPoly = array[0..MAX_N] of recPoint;

var
    fi,fo:text;
    N:longint;
    p:arrPoly;
    f:array[0..MAX_N,0..MAX_N] of double;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,N);
    for i:=0 to N-1 do
        readln(fi,p[i].x,p[i].y);
end;
{---------------------------------------------------------------------------}
function    max(x,y:double):double; inline;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
function    min(x,y:double):double; inline;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
function    s(i,j,k:longint):double;    inline;
begin
    exit(abs(p[i].x*p[j].y-p[j].x*p[i].y+p[j].x*p[k].y-p[k].x*p[j].y+p[k].x*p[i].y-p[i].x*p[k].y)/2);
    {exit(abs((p[i].x-p[j].x)*(p[i].y+p[j].y)+(p[j].x-p[k].x)*(p[j].y+p[k].y)+(p[k].x-p[i].x)*(p[k].y+p[i].y))/2);}
end;
{---------------------------------------------------------------------------}
procedure   solve_max;
var
    i,j,k:longint;
    res_max:double;
begin
    res_max:=0;
    for i:=0 to N-3 do
        for j:=i+1 to N-2 do
            for k:=j+1 to N-1 do
                res_max:=max(res_max,s(i,j,k));
    writeln(fo,res_max:0:1);
end;
{---------------------------------------------------------------------------}
procedure   solve_min;
var
    i,j,t,k:longint;
begin
    for t:=0 to 1 do
        for i:=0 to N-1 do f[i,i+t]:=0;
    for t:=2 to N-1 do begin
        for i:=0 to N-1-t do begin
            j:=i+t;
            f[i,j]:=MAX_INT;
            for k:=i+1 to j-1 do
                f[i,j]:=min(f[i,j],max(f[i,k],max(f[k,j],s(i,j,k))));
        end;
    end;
    writeln(fo,f[0,N-1]:0:1);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve_max;
    solve_min;
    close(fo);
    close(fi);
end.