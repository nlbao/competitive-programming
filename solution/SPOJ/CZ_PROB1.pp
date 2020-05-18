const   INPUT = 'CZ_PROB1.in';
        OUTPUT = 'CZ_PROB1.out';
        MAX_nTest = 511;
        MAX_N = 511;
        MAX_Sp2 = 8000;
        MAX_K = 5;

type    arr = array[0..MAX_Sp2] of longint;

var fi,fo:text;
    nTest,n,k,nSp2:longint;
    Sp2:arr;

function    min(x,y:longint):longint;   begin   if x < y then exit(x) else exit(y); end;

procedure   quick_sort(var  x:arr;  l,r:longint);
var i,j,p,tmp:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=x[(i+j) shr 1];
    repeat
        while x[i] < p do inc(i);
        while x[j] > p do dec(j);
        if i <= j then begin
            tmp:=x[i]; x[i]:=x[j];  x[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(x,l,j);    quick_sort(x,i,r);
end;

procedure   init;
var i,j,t:longint;
    is_prime:array[0..MAX_Sp2] of boolean;
begin
    nSp2:=0;
    for i:=2 to MAX_Sp2 do is_prime[i]:=true;
    for i:=2 to MAX_Sp2 do
        if is_prime[i] then begin
            for j:=0 to trunc(sqrt(i)) do begin
                t:=i-sqr(j);
                if t = sqr(trunc(sqrt(t))) then begin
                    inc(nSp2);
                    Sp2[nSp2]:=i;
                    break;
                end;
            end;
            j:=i+i;
            while j <= MAX_Sp2 do begin
                is_prime[j]:=false;
                inc(j,i);
            end;
        end;
    quick_sort(Sp2,1,nSp2);
end;

function    solve(n,k:longint):longint;
var i,j,t:longint;
    res:int64;
    f:array[0..MAX_Sp2,0..MAX_K] of longint;
begin
    n:=Sp2[n];
    for i:=1 to n do begin
        f[i][1]:=1;
        for j:=2 to k do f[i][j]:=0;
    end;
    for i:=2 to n do
        for j:=2 to k do
            if j = i then f[i][j]:=1
            else if j < i then
                for t:=min(i-j,j) downto 1 do
                    f[i][j]:=f[i][j]+f[i-j][t];
    res:=0;
    for j:=1 to min(n,k) do res:=res+f[n][j];
    exit(res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,n,k);
        writeln(fo,solve(n,k));
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
