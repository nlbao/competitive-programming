const
    INPUT = ''{'sort.inp'};
    OUTPUT = ''{'sort.out'};
    MAX_N = 100010;

var
    fi,fo:text;
    N,res:longint;
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
procedure   swap(l,r:longint);
var
    i,tmp:longint;
begin
    tmp:=a[l];
    for i:=l to r-1 do a[i]:=a[i+1];
    a[r]:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j:longint;
    check:boolean;
begin
    res:=1;
    a[N+1]:=-1;
    repeat
        check:=true;
        i:=1;
        while i < N do begin
            if a[i+1] <= a[i] then inc(i)
            else begin
                j:=i+1;
                while a[j+1] >= a[j] do inc(j);
                swap(i,j);
                check:=false;
            end;
        end;
        if check = false then inc(res);
    until check = true;
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