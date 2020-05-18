const
    INPUT = 'MDigits.inp';
    OUTPUT = 'MDigits.out';
    MAX_N = 9;

type
    arrX = array[0..MAX_N] of int64;

var
    fi,fo:text;
    A,B:int64;
    i,nA,nB:longint;
    p10,xA,xB:arrX;

{---------------------------------------------------------------------------}
procedure   init(i:longint; var x:arrX; var n:longint);
begin
    n:=0;
    repeat
        inc(n);
        x[n]:=i mod 10;
        i:=i div 10;
    until i = 0;
end;
{---------------------------------------------------------------------------}
function    g(var x:arrX;   i,j:longint):int64;
begin
    if i < j then exit(0);
    g:=x[i];
    while i > j do begin
        dec(i);
        g:=g*10+x[i];
    end;
end;
{---------------------------------------------------------------------------}
function    f(i,d:longint;  var x:arrX; n:longint):int64;
var
    k:int64;
begin
    if d > 0 then begin
        if d < x[i] then exit((g(x,n,i+1)+1)*p10[i-1]);
        if d > x[i] then exit(g(x,n,i+1)*p10[i-1]);
        exit(g(x,n,i+1)*p10[i-1]+g(x,i-1,1)+1);
    end
    else begin
        if d < x[i] then exit(g(x,n,i+1)*p10[i-1]);
        if d > x[i] then exit((g(x,n,i+1)-1)*p10[i-1]);
        exit((g(x,n,i+1)-1)*p10[i-1]+g(x,i-1,1)+1);
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    nA,nB:longint;
    xA,xB:arrX;
    sA,sB:int64;
    i,d:longint;
begin
    init(A,xA,nA);
    init(B,xB,nB);
    sA:=0;  sB:=0;
    for i:=1 to nA-1 do sA:=sA+f(i,0,xA,nA);
    for i:=1 to nB-1 do sB:=sB+f(i,0,xB,nB);
    write(fo,sB-sA,' ');
    for d:=1 to 9 do begin
        sA:=0;
        for i:=1 to nA do
            sA:=sA+f(i,d,xA,nA);
        sB:=0;
        for i:=1 to nB do
            sB:=sB+f(i,d,xB,nB);
        write(fo,sB-sA,' ');
    end;
    writeln(fo);
end;
{---------------------------------------------------------------------------}
begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    p10[0]:=1;
    for i:=1 to MAX_N do p10[i]:=p10[i-1]*10;
    readln(fi,A,B);
    while B <> 0 do begin
        if A > B then begin
            i:=A;   A:=B;   B:=i;
        end;
        dec(A);
        solve;
        readln(fi,A,B);
    end;
    close(fo);
    close(fi);
end.
