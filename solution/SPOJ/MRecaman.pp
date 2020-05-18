const
    INPUT = 'MRecaman.inp';
    OUTPUT = 'MRecaman.out';
    MAX_N = 500000;
    MAX_C = 3012500;

var
    fi,fo:text;
    N:longint;
    A:array[0..MAX_N] of int64;
    avail:array[0..MAX_C] of boolean;

{---------------------------------------------------------------------------}
procedure   Init;
var
    i:longint;
begin
    for i:=1 to MAX_C do avail[i]:=true;
    A[0]:=0;
    avail[0]:=false;
    for i:=1 to MAX_N do begin
        A[i]:=A[i-1]-i;
        if (A[i] <= 0) or (not avail[A[i]]) then
            A[i]:=A[i-1]+i;
        avail[A[i]]:=false;
    end;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
begin
    repeat
        read(fi,N);
        if N = -1 then break;
        writeln(fo,A[N]);
    until N = -1;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Init;
    Solve;
    close(fo);
    close(fi);
end.