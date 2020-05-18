const   INPUT = 'C11SEQ2.in';
        OUTPUT = 'C11SEQ2.out';
        MAX_N = 70;
        MAX_K = 70;

var fi,fo:text;
    n,k:longint;
    m:int64;
    a,p,id:array[0..MAX_N] of longint;
    s:array[0..MAX_N] of int64;
    c:array[0..MAX_K,0..MAX_N] of int64;
    f:array[0..MAX_N,0..MAX_K] of int64;


{---------------------------------------------------------------------------}
procedure   enter;
var i:longint;
begin
    readln(fi,n,k);
    for i:=1 to n do read(fi,a[i]);
    readln(fi,m);
    for i:=1 to k do read(fi,p[i]);
end;
{---------------------------------------------------------------------------}
procedure   init;
var i,j:longint;
begin
    fillchar(c,sizeof(c),0);
    for i:=0 to n do begin
        c[0][i]:=1;
        c[1][i]:=i;
        c[i][i]:=1;
    end;
    for i:=1 to n do
        for j:=2 to i do
            c[j][i]:=c[j-1][i-1]+c[j][i-1];
    fillchar(f,sizeof(f),0);
    for j:=1 to k do
        for i:=1 to n-(k-j) do
            f[i][j]:=c[k-j][n-i];
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var i,j,p,tmp:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=a[id[(i+j) shr 1]];
    repeat
        while a[id[i]] < p do inc(i);
        while a[id[j]] > p do dec(j);
        if i <= j then begin
            tmp:=id[i]; id[i]:=id[j];   id[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   solve1(m:int64);
var i,j,limit,pre:longint;
    x:array[0..MAX_N] of longint;
begin
    fillchar(x,sizeof(x),0);
    pre:=0;
    for j:=1 to k do begin
        limit:=n-(k-j);
        for i:=pre+1 to limit do id[i-pre]:=i;
        quick_sort(1,limit-pre);
        s[0]:=0;
        for i:=1 to limit-pre do s[i]:=s[i-1]+f[id[i]][j];
        for i:=1 to limit-pre do
            if s[i] >= m then begin
                x[j]:=a[id[i]];
                pre:=id[i];
                m:=m-s[i-1];
                break;
            end;
    end;
    for j:=1 to k do write(fo,x[j],' ');
    writeln(fo);
end;
{---------------------------------------------------------------------------}
procedure   solve2;
var i,j,limit,pre:longint;
    res:int64;
begin
    res:=1; pre:=0;
    for j:=1 to k do begin
        limit:=n-(k-j);
        for i:=pre+1 to limit do id[i-pre]:=i;
        quick_sort(1,limit-pre);
        s[0]:=0;
        for i:=1 to limit-pre do s[i]:=s[i-1]+f[id[i]][j];
        for i:=1 to limit-pre do
            if a[id[i]] = p[j] then begin
                res:=res+s[i-1];
                pre:=id[i];
                break;
            end;
    end;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init;
    solve1(m);
    solve2;
    close(fo);
    close(fi);
end.