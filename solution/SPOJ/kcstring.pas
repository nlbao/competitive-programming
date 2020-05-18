const   MAX_N = 1010;
        MODUN = 24101992;

type    ll = longint;

var fi,fo:text;
    a,b:ansiString;
    n,m,i,j:longint;
    ch:char;
    x,y:array['a'..'z',0..MAX_N] of longint;
    f:array[0..MAX_N,0..MAX_N] of ll;
    res:ll;


begin
    assign(fi,'kcstring.in');   reset(fi);
    assign(fo,'kcstring.out');  rewrite(fo);
    readln(fi,a);   n:=length(a);
    readln(fi,b);   m:=length(b);

    for ch:='a' to 'z' do begin
        x[ch][1]:=0;
        y[ch][1]:=0;
    end;
    for ch:='a' to 'z' do begin
        for i:=2 to n+1 do
            if a[i-1] = ch then x[ch][i]:=i-1
            else x[ch][i]:=x[ch][i-1];
        for i:=2 to m+1 do
            if b[i-1] = ch then y[ch][i]:=i-1
            else y[ch][i]:=y[ch][i-1];
    end;


    fillchar(f,sizeof(f),0);
    for i:=1 to n do
        for j:=1 to m do
            if a[i] = b[j] then begin
                f[i][j]:=1;
                for ch:='a' to 'z' do
                    if (x[ch][i] > 0) and (y[ch][j] > 0) then
                        f[i][j]:=(f[i][j] + f[x[ch][i]][y[ch][j]]) mod MODUN;
            end;

    res:=1;
    for ch:='a' to 'z' do
        res:=(res + f[x[ch][n+1]][y[ch][m+1]]) mod MODUN;
    writeln(fo,res);
    close(fo);
    close(fi);
end.