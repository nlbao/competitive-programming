const
    INPUT = 'NKTree.inp';
    OUTPUT = 'NKTree.out';
    MAX_N = 50000;

var
    N:longint;
    A:array[1..MAX_N] of int64;
    Res:string;

{***************************************************************************}
procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    N:=0;
    while not seekeoln(fi) do
        begin
            inc(N);
            read(fi,A[N]);
        end;
    close(fi);
end;
{***************************************************************************}
procedure   Check;
var
    i:longint;
begin
    for i:=1 to N-2 do
        if (A[i+1]-A[i])*(A[i+2]-A[i]) < 0 then
            begin
                Res:='NO';
                exit;
            end;
    Res:='YES';
end;
{***************************************************************************}
procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,Res);
    close(fo);
end;
{***************************************************************************}
begin
    Enter;
    Check;
    Print_result;
end.