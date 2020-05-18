{$N+}

const
    INPUT = 'VMDegree.inp';
    OUTPUT = 'VMDegree.out';
    MAX_N = 100010;

var
    fi,fo:text;
    nTest,i,N:longint;
    d,h:array[0..MAX_N] of longint;
    sumR:array[0..MAX_N] of double;
    res:string;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    read(fi,N);
    for i:=1 to N do read(fi,d[i]);
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var
    i,j,p,tmp:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=d[(i+j) shr 1];
    repeat
        while d[i] > p do inc(i);
        while d[j] < p do dec(j);
        if i <= j then begin
            tmp:=d[i]; d[i]:=d[j];  d[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i,j:longint;
    tmp:double;
    s:int64;
begin
    quick_sort(1,N);

    sumR[N+1]:=0;
    for i:=N downto 1 do
        sumR[i]:=sumR[i+1]+d[i];

    d[0]:=MAXLONGINT;
    h[0]:=N;
    for i:=1 to N do begin
        h[i]:=h[i-1];
        while (h[i] > i) and (d[h[i]-1] < i) do dec(h[i]);
        dec(h[i]);
        if h[i] < i then h[i]:=i;
    end;

    s:=0;
    for i:=1 to N do s:=s+d[i];
    if s mod 2 = 0 then res:='YES'
    else res:='NO';
end;
{---------------------------------------------------------------------------}
function    nhan(x,y:longint):double;   inline;
var
    tmp1,tmp2:double;
begin
    tmp1:=x;    tmp2:=y;
    exit(tmp1*tmp2);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j:longint;
    t:double;
begin
    if res = 'YES' then begin
        for i:=1 to N do begin
            t:=nhan(i,i-1)+nhan(h[i]-i,i)+sumR[h[i]+1];
            if sumR[1]-sumR[i+1] > t then begin
                res:='NO';
                break;
            end;
        end;
    end;

    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    for i:=1 to nTest do begin
        enter;
        init;
        solve;
    end;
    close(fo);
    close(fi);
end.