{
    ID: storm59061
    PROB: transform
    LANG: PASCAL
}

const
    INPUT = 'transform.in';
    OUTPUT = 'transform.out';
    MAX_N = 10;

type
    arrMatrix = array[1..MAX_N,1..MAX_N] of char;

var
    fi,fo:text;
    N:longint;
    s,t:arrMatrix;

{---------------------------------------------------------------------------}
procedure   enter(var x:arrMatrix);
var
    i,j:longint;
begin
    for i:=1 to n do begin
        for j:=1 to n do read(fi,x[i,j]);
        readln(fi);
    end;
end;
{---------------------------------------------------------------------------}
function    r90(x:arrMatrix):arrMatrix;
var
    i,j,k:longint;
    y:arrMatrix;
begin
    for i:=1 to n do begin
        j:=n-i+1;
        for k:=1 to n do y[k,j]:=x[i,k];
    end;
    exit(y);
end;
{---------------------------------------------------------------------------}
function    r180(x:arrMatrix):arrMatrix;
begin
    exit(r90(r90(x)));
end;
{---------------------------------------------------------------------------}
function    r270(x:arrMatrix):arrMatrix;
begin
    exit(r180(r90(x)));
end;
{---------------------------------------------------------------------------}
function    reflect(x:arrMatrix):arrMatrix;
var
    i,j:longint;
    y:arrMatrix;
begin
    for i:=1 to n do
        for j:=1 to n do
            y[i,j]:=x[i,n-j+1];
    exit(y);
end;
{---------------------------------------------------------------------------}
function    compare(x,y:arrMatrix):boolean;
var
    i,j:longint;
begin
    for i:=1 to n do
        for j:=1 to n do
            if x[i,j] <> y[i,j] then exit(false);
    exit(true);
end;
{---------------------------------------------------------------------------}
function    solve(s,t:arrMatrix):longint;
var
    x:arrMatrix;
begin
    if compare(r90(s),t) then exit(1);
    if compare(r180(s),t) then exit(2);
    if compare(r270(s),t) then exit(3);
    x:=reflect(s);
    if compare(x,t) then exit(4);
    if compare(r90(x),t) or compare(r180(x),t) or compare(r270(x),t) then exit(5);
    if compare(s,t) then exit(6);
    exit(7);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,n);
    enter(s);
    enter(t);
    writeln(fo,solve(s,t));
    close(fo);
    close(fi);
end.
