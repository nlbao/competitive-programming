const   INPUT = 'GNYR09F.in';
        OUTPUT = 'GNYR09F.out';
        MAX_N = 110;
        MAX_K = 110;
        MAX_INT = MAXLONGINT;

var fi,fo:text;
    nTest,id,n,k:longint;
    f:array[0..1,0..MAX_K,0..1] of int64;

function    limit(x:int64):boolean;
begin
    if x > MAX_INT div 2 then exit(false);
    exit(true);
end;

function    solve(n,k:longint):int64;
var i,j,t,tt:longint;
begin
    if n = 1 then
        if k = 0 then exit(2)
        else exit(0);
    if k > n-1 then exit(0);
    writeln(n,' ',k);
    {fillchar(f,sizeof(f),0);}
    for t:=0 to 1 do
        for j:=0 to k do
            for i:=0 to 1 do f[t][j][i]:=0;
    t:=0;
    f[t][0][0]:=2;  f[t][0][1]:=1;  f[t][1][0]:=0;  f[t][1][1]:=1;
    for i:=3 to n do begin
        tt:=t;
        t:=(t+1) mod 2;
        f[t][0][0]:=f[tt][0][0]+f[tt][0][1];
        f[t][0][1]:=f[tt][0][0];
        for j:=1 to k do
            if j > i-1 then begin
                f[t][j][0]:=0;  f[t][j][1]:=0;
            end
            else begin
                f[t][j][0]:=f[tt][j][0]+f[tt][j][1];
                if j = i-1 then f[t][j][1]:=1
                else f[t][j][1]:=f[tt][j][0]+f[tt][j-1][1];
            end;
        writeln(i);
    end;
    write('   ',f[t][k][0],' ',f[t][k][1]);
    writeln('   ',f[t][k][0]+f[t][k][1]);
    exit(f[t][k][0]+f[t][k][1]);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,id,n,k);
        writeln(fo,id,' ',solve(n,k));
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.