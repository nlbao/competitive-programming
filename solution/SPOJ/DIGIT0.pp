const
    INPUT = 'DIGIT0.inp';
    OUTPUT = 'DIGIT0.out';
    MAX_N = 10001;

var
    fi,fo:text;
    S:ansiString;
    N:longint;
    c:array['a'..'z'] of longint;
    cd:array[2..5,0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
    ch:char;
begin
    readln(fi,S);
    N:=length(S);
    for ch:='a' to 'z' do c[ch]:=0;
    for i:=1 to N do inc(c[S[i]]);
end;
{---------------------------------------------------------------------------}
procedure   count_divisor(d,k:longint);
var
    i,j,sum:longint;
begin
    cd[d,0]:=0;
    sum:=0;
    for i:=1 to k do begin
        j:=i;
        while j mod d = 0 do begin
            inc(sum);
            j:=j div d;
        end;
        cd[d,i]:=sum;
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    sum2,sum5:longint;
    ch:char;
begin
    count_divisor(2,N);
    count_divisor(5,N);
    sum2:=cd[2,N];  sum5:=cd[5,N];
    for ch:='a' to 'z' do begin
        dec(sum2,cd[2,c[ch]]);
        dec(sum5,cd[5,c[ch]]);
    end;
    if sum2 < sum5 then writeln(fo,sum2)
    else writeln(fo,sum5);
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