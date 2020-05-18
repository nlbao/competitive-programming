const
    INPUT = '108B.inp';
    OUTPUT = '108B.out';
    MAX_N = 100001;

var
    fi,fo:text;
    N:longint;
    a:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,N);
    for i:=1 to N do read(fi,a[i]);
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var
    i,j,p,tmp:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=a[(i+j) shr 1];
    repeat
        while a[i] < p do inc(i);
        while a[j] > p do dec(j);
        if i <= j then begin
            tmp:=a[i]; a[i]:=a[j];  a[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j:longint;
    res:string;
begin
    res:='NO';
    quick_sort(1,N);
    a[N+1]:=-1;
    i:=1;
    repeat
        j:=i+1;
        while a[j] = a[i] do inc(j);
        if (a[j] < 2*a[i]) and (j <= N) then begin
            res:='YES';
            break;
        end;
        i:=j;
    until i > N;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.