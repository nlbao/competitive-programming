const   INPUT = 'test.out';
        OUTPUT = 'PALINY.out';
        MAX_N = 50010;

var fi,fo:text;
    n,res:longint;
    s:ansiString;
    d:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   enter;
begin
    readln(fi,n);
    readln(fi,s);
end;
{---------------------------------------------------------------------------}
procedure   cal_odd;
var i,j,l,r:longint;
begin
    for i:=0 to n do d[i]:=0;
    l:=0;   r:=-1;
    for i:=1 to n do begin
        if i > r then j:=1
        else j:=min(d[l+(r-i)],r-i)+1;
        while (i+j <= n) and (i-j >= 1) and (s[i+j] = s[i-j]) do inc(j);
        dec(j);
        d[i]:=j;
        if i+j > r then begin
            l:=i-j;
            r:=i+j;
        end;
        res:=max(res,r-l+1);
    end;
end;
{---------------------------------------------------------------------------}
procedure   cal_even;
var i,j,l,r:longint;
begin
    for i:=0 to n do d[i]:=0;
    l:=0;   r:=-1;
    for i:=1 to n do begin
        if i > r then j:=1
        else j:=min(d[l+(r-i+1)],r-i+1)+1;
        while (i+j-1 <=n) and (i-j >= 1) and (s[i+j-1] = s[i-j]) do inc(j);
        dec(j);
        d[i]:=j;
        if i+j-1 > r then begin
            l:=i-j;
            r:=i+j-1;
        end;
        res:=max(res,r-l+1);
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
begin
    res:=0;
    cal_odd;
    cal_even;
    writeln(fo,res);
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
