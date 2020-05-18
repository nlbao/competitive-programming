const   MAX_N = 500010;

var fi,fo:text;
    n,k,i:longint;
    s:ansiString;
    next,pre:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;

procedure   enter;
var i:longint;
begin
    readln(fi,n,k);
    readln(fi,s);
    for i:=1 to n do begin
        ok[i]:=true;
        pre[i]:=i-1;
        next[i]:=i+1;
    end;
    pre[1]:=-1; next[n]:=-1;
end;

procedure   remove(i:longint);
begin
    if i < 1 then exit;
    ok[i]:=false;
    if pre[i] > 0 then next[pre[i]]:=next[i];
    if next[i] > 0 then pre[next[i]]:=pre[i];
end;

procedure   solve;
var i:longint;
begin
    i:=1;
    while (k > 0) and (next[i] > 0) do begin
        while (next[i] > 0) and (s[i] >= s[next[i]]) do i:=next[i];
        if (next[i] > 0) and (s[i] < s[next[i]]) then begin
            remove(i);
            dec(n); dec(k);
            i:=next[i];
            if pre[i] > 0 then i:=pre[i];
        end;
    end;
    if k > 0 then n:=n-k;
    for i:=1 to length(s) do
        if ok[i] then begin
            write(fo,s[i]);
            dec(n);
            if n < 1 then break;
        end;
    writeln(fo);
end;

begin
    assign(fi,''{'keks.in'});   reset(fi);
    assign(fo,''{'keks.out'});  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.