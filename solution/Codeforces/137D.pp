const   INPUT = '137D.in';
        OUTPUT = '137D.out';
        MAX_N = 510;
        MAX_INT = 1000000;

var fi,fo:text;
    s:ansiString;
    n,p:longint;
    f,g,trace:array[0..MAX_N,0..MAX_N] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x)   else exit(y);   end;

procedure   enter;
begin
    readln(fi,s);
    readln(fi,p);
    n:=length(s);
end;

procedure   cal_g;
var i,j:longint;
begin
    for i:=1 to n-1 do begin
        g[i][i]:=0;
        if s[i] = s[i+1] then g[i][i+1]:=0
        else g[i][i+1]:=1;
    end;
    g[n][n]:=0;
    for j:=3 to n do
        for i:=1 to n-j+1 do begin
            g[i][i+j-1]:=g[i+1][i+j-2];
            if s[i] <> s[i+j-1] then inc(g[i][i+j-1]);
        end;
end;

procedure   cal_f;
var i,ii,j,t:longint;
begin
    f[1][0]:=1; f[1][1]:=0;
    for j:=2 to p do f[1][j]:=MAX_INT;
    for i:=2 to n do begin
        f[i][0]:=i;
        for j:=1 to p do f[i][j]:=MAX_INT;
        for j:=1 to min(i,p) do
            for ii:=i downto 1 do begin
                t:=f[ii-1][j-1]+g[ii][i];
                if t < f[i][j] then begin
                    f[i][j]:=t;
                    trace[i][j]:=ii-1;
                end;
            end;
    end;
end;

function    print(l,r:longint):ansiString;
begin
    if r = l then exit(s[l]);
    if r = l+1 then exit(s[l]+s[l]);
    exit(s[l]+print(l+1,r-1)+s[l]);
end;

procedure   solve;
var i,j,k,minf:longint;
    res:ansiString;
begin
    cal_g;
    if p = 1 then begin
        writeln(fo,g[1][n]);
        writeln(fo,print(1,n));
        exit;
    end;
    cal_f;
    minf:=MAX_INT;
    for i:=1 to p do
        if f[n][i] < minf then begin
            minf:=f[n][i];
            j:=i;
        end;
    i:=trace[n][j];
    res:=print(i+1,n);
    while i > 0 do begin
        k:=i;
        dec(j);
        i:=trace[i][j];
        res:=print(i+1,k)+'+'+res;
    end;
    writeln(fo,minf);
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
