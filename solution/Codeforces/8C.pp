const
    INPUT = '8C.inp';
    OUTPUT = '8C.out';
    MAX_N = 25;
    MAX_INT = 1000000000;

type
    recPoint = record
        x,y:longint;
    end;

var
    fi,fo:text;
    N,count,carry,sum,min_sum,nRes:longint;
    a:array[0..MAX_N] of recPoint;
    w:array[0..MAX_N,0..MAX_N] of longint;
    avail:array[0..MAX_N] of boolean;
    f,res:array[0..10*MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,a[0].x,a[0].y);
    readln(fi,N);
    for i:=1 to N do
        readln(fi,a[i].x,a[i].y);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i,j:longint;
begin
    for i:=0 to N-1 do
        for j:=i+1 to N do begin
            w[i,j]:=sqr(a[i].x-a[j].x)+sqr(a[i].y-a[j].y);
            w[j,i]:=w[i,j];
        end;
    w[0,0]:=MAX_INT;
end;
{---------------------------------------------------------------------------}
procedure   try_f(i:longint);
var
    j,tmp_carry:longint;
begin
    if count = N then begin
        f[i]:=0;
        sum:=sum+w[f[i-1],0];
        if (sum < min_sum) or ((sum = min_sum) and (i < nRes)) then begin
            min_sum:=sum;
            nRes:=i;
            for j:=1 to nRes do res[j]:=f[j];
        end;
        sum:=sum-w[f[i-1],0];
        exit;
    end;

    tmp_carry:=carry;

    if carry = 2 then begin
        f[i]:=0;
        sum:=sum+w[f[i-1],0];
        carry:=0;
        try_f(i+1);
        carry:=tmp_carry;
        sum:=sum-w[f[i-1],0];
        exit;
    end;

    for j:=0 to N do
        if (avail[j]) and (j <> f[i-1]) then begin
            f[i]:=j;
            sum:=sum+w[f[i-1],j];
            if j = 0 then carry:=0
            else begin
                inc(carry);
                inc(count);
                avail[j]:=false;
            end;
            try_f(i+1);
            if j <> 0 then begin
                avail[j]:=true;
                dec(count);
            end;
            carry:=tmp_carry;
            sum:=sum-w[f[i-1],j];
        end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
begin
    for i:=0 to N do avail[i]:=true;
    f[1]:=0;
    min_sum:=MAX_INT;   sum:=0;
    count:=0;   carry:=0;
    try_f(2);
    writeln(fo,min_sum);
    for i:=1 to nRes do
        write(fo,res[i],' ');
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init;
    solve;
    close(fo);
    close(fi);
end.