const   MAX_N = 2010;

var fi,fo:text;
    nTest,n,w,limit:longint;
    a,s:array[0..MAX_N,0..MAX_N] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

function    max(x,y:longint):longint;   begin   if x > y then exit(x);  exit(y);    end;

procedure   enter;
var i,j,k:longint;
begin
    readln(fi,n,w,limit);
    for i:=1 to n do
        for j:=1 to n do a[i][j]:=0;
    for k:=1 to w do begin
        readln(fi,i,j);
        a[i][j]:=1;
    end;
end;

procedure   solve;
var i,j,l,r,mid,ii,jj,t,res:longint;
begin
    res:=0;
    s[1][1]:=a[1][1];
    for i:=0 to n do begin
        s[0][i]:=0;
        s[i][0]:=0;
    end;
    for i:=1 to n do
        for j:=1 to n do
            s[i][j]:=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];

    for i:=1 to n do
        for j:=1 to n do begin
            l:=1;   r:=min(n-i+1,n-j+1);
            while (l <= r) and (r > res) do begin
                mid:=(l+r) shr 1;
                ii:=i+mid-1;    jj:=j+mid-1;
                t:=s[ii][jj]-s[i-1][jj]-s[ii][j-1]+s[i-1][j-1];
                if t <= limit then begin
                    res:=max(res,mid);
                    l:=mid+1;
                end
                else r:=mid-1;
            end;
        end;
    writeln(fo,sqr(res));
end;

begin
    assign(fi,'100008D.in');    reset(fi);
    assign(fo,'100008D.out');   rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
    end.