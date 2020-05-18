const   MAX_N = 1010;
        MAX_M = 1010;

var fi,fo:text;
    nTest,n,m:longint;
    f:array[0..MAX_N,0..MAX_M] of longint;

function    max(x,y:longint):longint;   begin   if x > y then exit(x)   else exit(y);   end;

function    cal_f(i,j:longint):longint;
begin
    if (i = 0) or (j = 0) then exit(0);
    if i = 1 then exit(j);
    if j = 1 then exit(1);
    if f[i][j] = 0 then
        f[i][j]:=max(cal_f(i-1,(j div 2))+1,cal_f(i-1,j-(j div 2)-1)+1);
    exit(f[i][j]);
end;

begin
    assign(fi,'EGG.in');    reset(fi);
    assign(fo,'EGG.out');   rewrite(fo);
    fillchar(f,sizeof(f),0);
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,n,m);
        writeln(fo,cal_f(n,m));
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.