const   INPUT = 'CountPL.in';
        OUTPUT = 'CountPL.out';
        MAX_N = 300;

var fi,fo:text;
    s:ansiString;
    n,i,j:longint;
    g:array[0..MAX_N,0..MAX_N] of boolean;
    f:array[0..MAX_N] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x)   else exit(y);   end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,s);
    n:=length(s);
    fillchar(g,sizeof(g),false);
    for i:=1 to n-1 do begin
        g[i][i]:=true;
        if s[i] = s[i+1] then g[i][i+1]:=true;
    end;
    g[n][n]:=true;
    for j:=3 to n do
        for i:=1 to n-j+1 do
            g[i][i+j-1]:=(g[i+1][i+j-2]) and (s[i] = s[i+j-1]);
    f[0]:=0;
    for i:=1 to n do begin
        f[i]:=i;
        for j:=i downto 1 do
            if g[j][i] = true then
                f[i]:=min(f[i],f[j-1]+1);
    end;
    writeln(fo,f[n]);
    close(fo);
    close(fi);
end.