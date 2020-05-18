uses    math;

const   MAX_N = 1010;

var fi,fo:text;
    nTest:longint;
    s,t:ansiString;
    f:array[0..MAX_N] of longint;

procedure   solve;
var n,i,j,k,fmax,res:longint;
begin
    readln(fi,s);
    n:=length(s);
    res:=0; t:='';
    for i:=1 to n do begin
        t:=s[i]+t;
        f[1]:=0;    j:=0;
        fmax:=0;
        for k:=2 to i do begin
            while (j > 0) and (t[j+1] <> t[k]) do j:=f[j];
            if t[j+1] = t[k] then inc(j);
            f[k]:=j;
            fmax:=max(fmax,j);
        end;
        res:=res+i-fmax;
    end;
    writeln(fo,res);
end;

begin
    assign(fi,'DiSubStr.in');   reset(fi);
    assign(fo,'DiSubStr.out');  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
