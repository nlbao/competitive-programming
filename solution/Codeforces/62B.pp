const
    INPUT = '62B.inp';
    OUTPUT = '62B.out';
    MAX_N = 200002;
    MAX_K = 100001;
    MAX_INT = MAXLONGINT;

var
    fi,fo:text;
    N,K:longint;
    S:ansiString;
    id:array['a'..'z'] of longint;
    l,r:array[0..MAX_N,0..30] of longint;

{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   enter;
begin
    readln(fi,K,N);
    readln(fi,S);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i,j:longint;
    ch:char;
begin
    for i:=1 to 26 do id[chr(i+ord('a')-1)]:=i;
    for i:=1 to 26 do begin
        l[0][i]:=MAX_INT;
        r[N+1][i]:=MAX_INT;
    end;
    for i:=1 to N do
        for j:=1 to 26 do
            if id[S[i]] = j then l[i][j]:=i
            else l[i][j]:=l[i-1][j];
    for i:=N downto 1 do
        for j:=1 to 26 do
            if id[S[i]] = j then r[i][j]:=i
            else r[i][j]:=r[i+1][j];
    for i:=N+1 to MAX_N do
        for j:=1 to 26 do begin
            l[i][j]:=l[N][j];
            r[i][j]:=r[N][j];
        end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,m:longint;
    C:ansiString;
    f:int64;
begin
    repeat
        readln(fi,C);
        f:=0;
        m:=length(C);
        for i:=1 to m do begin
            j:=id[C[i]];
            if (l[i][j] = MAX_INT) and (r[i][j] = MAX_INT) then
                f:=f+m
            else
                f:=f+min(abs(l[i][j]-i),abs(r[i][j]-i));
        end;
        writeln(fo,f);
        dec(K);
    until K = 0;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init;
    solve;
    close(fo);
    close(fi);
end.