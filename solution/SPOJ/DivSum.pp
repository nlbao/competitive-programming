const
    INPUT = 'DivSum.inp';
    OUTPUT = 'DivSum.out';
    MAX_N = 500010;

var
    fi,fo:text;
    nTest,N:longint;
    sum:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   init;
var
    i,j:longint;
begin
    for i:=1 to MAX_N do sum[i]:=0;
    for i:=1 to MAX_N do begin
        j:=i+i;
        while j <= MAX_N do begin
            sum[j]:=sum[j]+i;
            j:=j+i;
        end;
    end;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,N);
        writeln(fo,sum[N]);
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.