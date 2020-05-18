const   INPUT = 'A.in';
        OUTPUT = 'A.out';
        MAX_N = 21;
        MAX_M = 51;
        MAX_INT = 1000000000000;

var fi,fo:text;
    n:longint;
    f,c:array[0..MAX_N] of int64;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do
        readln(fi,f[i],c[i]);
end;

function    find(v,t:int64):int64;
var i,j:longint;
    sumF,sumC:int64;
begin
    find:=MAX_INT;
    for i:=0 to (1 shl n)-1 do begin
        sumF:=0;    sumC:=0;
        for j:=1 to n do
            if ((i shr (j-1)) and 1) = 1 then begin
                inc(sumF,f[j]*t);
                inc(sumC,c[j]);
                if sumC >= find then break
                else if sumF >= v then find:=sumC;
            end;
    end;
end;

procedure   solve;
var i,j,m:longint;
    v,t,res:int64;
begin
    readln(fi,m);
    for j:=1 to m do begin
        readln(fi,v,t);
        write(fo,'Case ',j,': ');
        res:=find(v,t);
        if res = MAX_INT then writeln(fo,'IMPOSSIBLE')
        else writeln(fo,res);
        dec(m);
    end;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.