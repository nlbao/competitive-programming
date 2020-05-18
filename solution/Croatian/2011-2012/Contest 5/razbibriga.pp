var fi,fo:text;
    n,i:longint;
    s:ansiString;
    f:array['A'..'Z','A'..'Z'] of int64;

procedure   solve;
var i,j,h,k:char;
    res:int64;
begin
    res:=0;
    for i:='A' to 'Z' do
        for j:='A' to 'Z' do
            for h:='A' to 'Z' do
                for k:='A' to 'Z' do
                    if (i = j) and (h = k) and (i = h) then
                        res:=res+f[i][j]*(f[i][j]-1)*(f[i][j]-2)*(f[i][j]-3)
                    else if (i = j) and (h = k) then
                        res:=res+f[i][j]*f[h][k]*f[i][h]*(f[i][h]-1)
                    else if (i = h) and (h = k) then
                        res:=res+f[i][j]*f[j][k]*f[i][h]*(f[i][h]-1)
                    else if (i = h) and (j = k) then
                        res:=res+f[i][h]*f[j][k]*f[i][j]*(f[i][j]-1)
                    else if j = h then
                        res:=res+f[i][j]*f[i][h]*f[h][k]*(f[h][k]-1)
                    else
                        res:=res+f[i][j]*f[h][k]*f[i][h]*f[j][k];
    writeln(fo,res);
end;

begin
    assign(fi,'razbibriga.in');     reset(fi);
    assign(fo,'razbibriga.out');    rewrite(fo);
    fillchar(f, sizeof(f), 0);
    readln(fi,n);
    for i:=1 to n do begin
        readln(fi,s);
        inc(f[s[1]][s[length(s)]]);
    end;
    solve;
    close(fo);
    close(fi);
end.
