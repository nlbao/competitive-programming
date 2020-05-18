const   MAX_N = 75007;


var fi,fo:text;
    s,t,res:ansiString;
    n,m,i,j,k:longint;
    kmp,f:array[0..MAX_N] of longint;


begin
    assign(fi,'1684.in');   reset(fi);
    assign(fo,'1684.out');  rewrite(fo);
    readln(fi,s);
    readln(fi,t);
    n:=length(s);
    m:=length(t);
    j:=0;   kmp[1]:=0;
    for i:=2 to n do begin
        while (j > 0) and (s[j+1] <> s[i]) do j:=kmp[j];
        if s[j+1] = s[i] then inc(j);
        kmp[i]:=j;
    end;

    j:=0;
    for i:=1 to m do begin
        while (j > 0) and (s[j+1] <> t[i]) do j:=kmp[j];
        if s[j+1] = t[i] then inc(j);
        if j = 0 then begin
            writeln(fo,'Yes');
            close(fo);
            halt(0);
        end;
        f[i]:=i-j+1;
        if (j = n) then j:=kmp[j];
    end;

    writeln(fo,'No');
    s:='';
    i:=m;
    repeat
        s:=copy(t,f[i],i-f[i]+1)+s;
        i:=f[i]-1;
        if (i > 0) then s:=' '+s;
    until i < 1;
    writeln(fo,s);
    close(fo);
    close(fi);
end.