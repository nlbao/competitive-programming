{$M 2000000,0,2000000}
uses    math;

const   MAX_N = 2003;
        oo = 1000000000;

type    ll = int64;

var fi,fo:text;
    n,m:longint;
    s:ansiString;
    a:array[0..MAX_N,0..MAX_N] of boolean;
    h,f,stk:array[0..MAX_N] of longint;
    res:ll;
    col:array[0..MAX_N,0..MAX_N] of ll;


procedure   enter();
var i,j:longint;
begin
    readln(fi,m,n);
    for i:=1 to m do begin
        readln(fi,s);
        for j:=1 to n do
            a[i][j]:=(s[j] = '1');
    end;

    fillchar(col,sizeof(col),0);
    for i:=1 to n do
        for j:=1 to m do col[i][j]:=col[i][j-1] + longint(a[j][i]);

end;


procedure   solve_0();
var i,k,x1,x2,b:longint;
    j,h,sum,res:ll;
    p:array[0..MAX_N,0..1] of longint;
begin
    res:=0;
    fillchar(p,sizeof(p),0);
    for x1:=1 to m do
        for x2:=x1 to m do begin
            h:=x2-x1+1;
            sum:=0;
            for i:=1 to n do begin
                b:=col[i][x2] - col[i][x1-1];
                for k:=0 to 1 do p[i][k]:=p[i-1][k];
                if b > 0 then p[i][1]:=i;
                if b < h then p[i][0]:=i;

                if (0 < b) and (b < h) then j:=i
                else if b = 0 then j:=p[i][1]
                else j:=p[i][0];
                sum:=sum + j*(2*i-j+1);
            end;
            res:=res + (h*sum) div 2;
        end;
    writeln(fo,res);
end;


procedure   cal();
var i,x,y,len,top:longint;
begin
    f[0]:=0;
    for y:=0 to n do h[y]:=0;
    for x:=1 to m do begin
        for y:=1 to n do
            if a[x][y] then inc(h[y])
            else h[y]:=0;

        top:=1;
        stk[1]:=0;
        for y:=1 to n do begin
            while (top > 1) and (h[stk[top]] >= h[y]) do dec(top);
            i:=stk[top];
            len:=y-i;
            f[y]:=f[i] + len*h[y];
            if h[y] > 0 then
                res:=res + ll(x*y - f[y]);
            writeln(x,' ',y,'        ',x*y,'      ',f[y],'        ',h[y],'  ',i);
            //readln;
            inc(top);   stk[top]:=y;
        end;
    end;
end;


procedure   solve();
var i,j:longint;
begin
    res:=0;
    cal();
    for i:=1 to m do
        for j:=1 to n do
            a[i][j]:=not a[i][j];
    writeln(res);
    cal();
    writeln(fo,res);
end;


procedure   gen_test(limit:longint);
var i,j:longint;
begin
    assign(fo,'LSEA.in');   rewrite(fo);
    randomize;
    m:=random(limit)+1;
    n:=random(limit)+1;
    writeln(fo,m,' ',n);
    for i:=1 to m do begin
        for j:=1 to n do
            write(fo,chr(ord('0')+random(2)));
        writeln(fo);
    end;
    close(fo);
end;


begin
    //gen_test(5);
{$IFDEF WINDOWS}
    assign(fi,'LSEA.in');    reset(fi);
    assign(fo,'LSEA.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve_0();
    solve();
    close(fo);
    close(fi);
end.