const
    INPUT = 'SAMER08F.inp';
    OUTPUT = 'SAMER08F.out';
    MAX_N = 100;

var
    fi,fo:text;
    N:longint;
    sum:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   init;
var
    i:longint;
begin
    sum[1]:=1;
    for i:=2 to MAX_N do
        sum[i]:=sum[i-1]+sqr(i);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    readln(fi,N);
    while N > 0 do begin
        writeln(fo,sum[N]);
        readln(fi,N);
    end;
    close(fo);
    close(fi);
end.