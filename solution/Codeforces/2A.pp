const   INPUT = '2A.in';
        OUTPUT = '2A.out';
        MAX_N = 1010;
        MAX_M = 1010;

type    str = ansiString;

var fi,fo:text;
    n,m:longint;
    s:str;
    names:array[0..MAX_N] of str;
    score,pos:array[0..MAX_N] of longint;
    f:array[0..MAX_M,0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var i,j,err:longint;
begin
    m:=0;
    readln(fi,n);
    for i:=1 to n do begin
        readln(fi,s);
        j:=1;
        while (s[j] >= 'a') and (s[j] <= 'z') do inc(j);
        val(copy(s,j+1,length(s)-j),score[i],err);
        s:=copy(s,1,j-1);
        pos[i]:=1;
        while (pos[i] <= m) and (names[pos[i]] <> s) do inc(pos[i]);
        if pos[i] > m then begin
            inc(m);
            names[m]:=s;    f[m][0]:=0;
        end;
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,j,maxF:longint;
begin
    for i:=1 to n do begin
        for j:=1 to m do f[j][i]:=f[j][i-1];
        f[pos[i]][i]:=f[pos[i]][i]+score[i];
    end;
    maxF:=-1;
    for i:=1 to m do
        if f[i][n] > maxF then maxF:=f[i][n];
    for i:=1 to n do
        for j:=1 to m do
            if (f[j][n] = maxF) and (f[j][i] >= maxF) then begin
                writeln(fo,names[j]);
                exit;
            end;
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