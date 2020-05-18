{$R+}
const
    INPUT = 'CAR.inp';
    OUTPUT = 'CAR.out';
    MAX_N = 10001;

var
    fi,fo:text;
    N:longint;
    id:array[0..MAX_N] of longint;
    a,b,d:array[0..MAX_N] of double;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,N);
    for i:=1 to N do read(fi,a[i]);
    for i:=1 to N do begin
        read(fi,b[i]);
        d[i]:=a[i]/b[i];
        id[i]:=i;
    end;
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var
    i,j,tmp:longint;
    p:double;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=d[id[(i+j) shr 1]];
    repeat
        while d[id[i]] > p do inc(i);
        while d[id[j]] < p do dec(j);
        if i <= j then begin
            tmp:=id[i]; id[i]:=id[j];  id[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
    t,sum:double;
begin
    sum:=0;
    t:=0;
    for i:=1 to N do begin
        t:=t+b[id[i]];
        sum:=sum+t*a[id[i]];
    end;
    writeln(fo,sum:0:0);
    for i:=1 to N do write(fo,id[i],' ');
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    quick_sort(1,N);
    solve;
    close(fo);
    close(fi);
end.