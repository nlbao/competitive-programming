const   INPUT = 'Quad.inp';
        OUTPUT = 'Quad.out';
        MAX_N = 2510;

var fi,fo:text;
    n,p,i,j,k:longint;
    f,g:array[0..4,-1..MAX_N] of longint;

function    max(x,y:longint):longint;   begin   if x > y then exit(x)   else exit(y);   end;

function    min(x,y:longint):longint;   begin   if x < y then exit(x)   else exit(y);   end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,n);
    p:=(n-1) div 2;
    fillchar(f,sizeof(f),0);
    fillchar(g,sizeof(g),0);
    f[0][0]:=1;
    for j:=0 to n do g[0][j]:=1;
    for i:=1 to 4 do
        for j:=1 to n do begin
            {for k:=1 to min(j,p) do begin
                f[i][j]:=f[i][j]+f[i-1][j-k]
            end;}
            f[i][j]:=g[i-1][j-1]-g[i-1][j-min(j,p)-1];
            g[i][j]:=g[i][j-1]+f[i][j];
        end;
    writeln(fo,f[4][n]);
    close(fo);
    close(fi);
end.