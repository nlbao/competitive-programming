const   INPUT = '118D.in';
        OUTPUT = '118D.out';
        MAX_N = 110;
        MAX_K = 11;
        MODUN = 100000000;

var fi,fo:text;
    n1,n2,k1,k2:longint;
    f:array[0..MAX_N,0..MAX_N,0..MAX_K] of int64;

function    min(x,y:longint):longint;   begin   if x < y then exit(x)   else exit(y);   end;

procedure   init;
var i,j,k,t:longint;
begin
    fillchar(f,sizeof(f),0);
    for i:=1 to MAX_N do begin
        for j:=1 to i-1 do begin
            for k:=2 to min(i-1,MAX_K) do begin
                f[i][j][k]:=0;
                for t:=1 to k do
                    f[i][j][k]:=(f[i][j][k]+f[i-t][j-1][k]) mod MODUN;
            end;
            while k < MAX_K do begin
                inc(k);
                f[i][j][k]:=f[i][j][k-1];
            end;
        end;
        for k:=1 to MAX_K do f[i][i][k]:=1;
        for k:=i to MAX_K do f[i][1][k]:=1;
    end;
end;

procedure   solve;
var res:int64;
    i:longint;
begin
    res:=0;
    for i:=1 to n1 do
        res:=(res+f[n1][i][k1]*(2*f[n2][i][k2]+f[n2][i+1][k2]+f[n2][i-1][k2])) mod MODUN;
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,n1,n2,k1,k2);
    init;
    solve;
    close(fo);
    close(fi);
end.