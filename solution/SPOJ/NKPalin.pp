const
    INPUT = 'NKPalin.inp';
    OUTPUT = 'NKPalin.out';
    MAX_N = 2001;

var
    fi,fo:text;
    S:ansiString;
    N:longint;
    f:array[0..MAX_N,0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
begin
    readln(fi,S);
    N:=length(S);
end;
{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;   inline;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,k:longint;
begin
    for i:=1 to N do f[i,i]:=1;
    for i:=1 to N-1 do
        if S[i] = S[i+1] then f[i,i+1]:=2
        else f[i,i+1]:=1;

    for k:=2 to N-1 do
        for i:=1 to N-k do begin
            j:=i+k;
            f[i,j]:=max(f[i+1,j],f[i,j-1]);
            if S[i] = S[j] then
                f[i,j]:=max(f[i,j],f[i+1,j-1]+2);
        end;
end;
{---------------------------------------------------------------------------}
procedure   print_result;
var
    i,j:longint;
    res1,res2:ansiString;
begin
    res1:='';   res2:='';
    i:=1;   j:=N;
    repeat
        if (S[i] = S[j]) and (f[i,j] = f[i+1,j-1]+2) then begin
            res1:=res1+S[i];
            res2:=S[j]+res2;
            inc(i); dec(j);
        end
        else
            if f[i,j] = f[i+1,j] then inc(i)
            else dec(j);
    until (i = j) or (i+1 = j);
    res1:=res1+S[i];
    if (i+1 = j) and (S[i] = S[j]) then res2:=S[j]+res2;
    writeln(fo,res1+res2);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    print_result;
    close(fo);
    close(fi);
end.