const   INPUT = '124B.in';
        OUTPUT = '124B.out';
        MAX_N = 10;
        MAX_K = 10;
        MAX_INT = 1000000000;

var fi,fo:text;
    n,k,res:longint;
    a:array[0..MAX_N] of string;
    avail:array[0..MAX_K] of boolean;
    p:array[0..MAX_K] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var i:longint;
begin
    readln(fi,n,k);
    for i:=1 to n do readln(fi,a[i]);
end;
{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   update;
var i,j,x,err,minX,maxX:longint;
    s:string;
begin
    maxX:=0;    minX:=MAX_INT;
    for i:=1 to n do begin
        s:='';
        for j:=1 to k do s:=s+a[i][p[j]];
        val(s,x,err);
        maxX:=max(maxX,x);
        minX:=min(minX,x);
    end;
    if maxX >= minX then res:=min(res,maxX-minX);
end;
{---------------------------------------------------------------------------}
procedure   sinh(i:longint);
var j:longint;
begin
    if res = 0 then exit;
    if i > k then begin
        update;
        exit;
    end;
    for j:=1 to k do
        if avail[j] then begin
            avail[j]:=false;
            p[i]:=j;
            sinh(i+1);
            p[i]:=0;
            avail[j]:=true;
        end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i:longint;
begin
    for i:=1 to k do avail[i]:=true;
    res:=MAX_INT;
    sinh(1);
    writeln(fo,res);
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