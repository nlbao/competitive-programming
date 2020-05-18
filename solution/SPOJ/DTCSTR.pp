const   INPUT = 'DTCSTR.in';
        OUTPUT = 'DTCSTR.out';
        MAX_N = 500010;
        MAX_INT = 1000000000;

type    str = ansiString;
        pQueue = ^recQueue;
        recQueue = record
            id:longint;
            next:pQueue;
        end;

var fi,fo:text;
    s:str;
    n:longint;
    t,f,last:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
begin
    readln(fi,s);
    n:=length(s);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,j,k:longint;
begin
    for i:=2 to n do last[i]:=0;
    last[1]:=1;
    t[1]:=0;    f[1]:=1;
    j:=0;
    for i:=2 to n do begin
        while (j > 0) and (s[j+1] <> s[i]) do j:=t[j];
        if s[j+1] = s[i] then inc(j);
        t[i]:=j;
        f[i]:=i;
        if (last[f[t[i]]] >= i-t[i]) then f[i]:=f[t[i]];
        last[f[i]]:=i;
    end;
    writeln(fo,f[n]);
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