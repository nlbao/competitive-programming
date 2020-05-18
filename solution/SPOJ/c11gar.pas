{$M+ 2000000,0,2000000}
uses    math;

const   MAX_N = 255;
        oo = 1000000000;

var fi,fo:text;
    m,n,k,res:longint;
    a,b:array[0..MAX_N,0..MAX_N] of longint;
    h,s,f,g:array[0..MAX_N] of longint;


procedure   enter();
var i,j,t,p:longint;
begin
    read(fi,n,m);
    fillchar(a,sizeof(a),0);
    read(fi,p,k);
    for t:=1 to p do begin
        read(fi,i,j);
        inc(a[m-j+1][i]);
    end;
end;


procedure   cal();
var i,j,x1,x2,tmp:longint;
begin
    for i:=0 to m+1 do begin
        f[i]:=oo;
        g[i]:=oo;
    end;

    s[0]:=0;
    for x1:=1 to m do begin
        for i:=0 to n do h[i]:=0;
        for x2:=x1 to m do begin
            for i:=1 to n do begin
                h[i]:=h[i] + a[x2][i];
                s[i]:=s[i-1] + h[i];
            end;

            tmp:=oo;
            i:=0;
            for j:=1 to n do begin
                while (i < j) and (s[j]-s[i] > k) do inc(i);
                while (i < j-1) and (s[j]-s[i+1] = k) do inc(i);
                if s[j]-s[i] = k then
                    tmp:=min(tmp,2*(j-i + x2-x1+1));
            end;
            f[x2]:=min(f[x2],tmp);
            g[x1]:=min(g[x1],tmp);
        end;
    end;

    for i:=1 to m do f[i]:=min(f[i],f[i-1]);
    for i:=m downto 1 do g[i]:=min(g[i],g[i+1]);
    for i:=1 to m-1 do res:=min(res,f[i] + g[i+1]);
end;



procedure   solve();
var i,j:longint;
begin
    res:=oo;
    cal();
    for i:=1 to m do
        for j:=1 to n do b[i][j]:=a[i][j];
    for i:=1 to n do
        for j:=1 to m do
            a[i][j]:=b[j][i];
    i:=m;   m:=n;   n:=j;
    cal();

    if res = oo then writeln(fo,'NO')
    else writeln(fo,res);
end;



begin
{$IFDEF WINDOWS}
    assign(fi,'c11gar.in');    reset(fi);
    assign(fo,'c11gar.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.