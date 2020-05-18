const
    INPUT = 'ACode.in';
    OUTPUT = 'ACode.out';
    MAX_N = 5010;

var
    fi,fo:text;
    s:ansistring;
    n:longint;
    f:array[0..MAX_N] of int64;

procedure   solve;
var
    i,j,err:longint;
begin
    n:=length(s);
    f[0]:=1;    f[1]:=1;
    for i:=2 to n do begin
        if s[i] = '0' then f[i]:=0
        else f[i]:=f[i-1];
        val(copy(s,i-1,2),j,err);
        if (s[i-1] <> '0') and (j < 27) then
            f[i]:=f[i]+f[i-2];
    end;
    writeln(fo,f[n]);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,s);
    while s <> '0' do begin
        solve;
        readln(fi,s);
    end;
    close(fo);
    close(fi);
end.