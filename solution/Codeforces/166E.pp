var fi,fo:text;
    n,i,j,k,t,tt:longint;
    f:array[0..1,1..4] of int64;
    s:int64;

begin
    assign(fi,'166E.in');   reset(fi);
    assign(fo,'166E.out');  rewrite(fo);
    readln(fi,n);
    fillchar(f,sizeof(f),0);
    f[0][1]:=1;
    t:=0;
    for i:=1 to n do begin
        tt:=(t+1) mod 2;
        s:=0;
        for j:=1 to 4 do s:=s+f[t][j];
        for j:=1 to 4 do f[tt][j]:=(s-f[t][j]) mod 1000000007;
        t:=tt;
    end;
    writeln(fo,f[t][1]);
    close(fo);
    close(fi);
end.
