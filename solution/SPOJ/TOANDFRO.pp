const
    INPUT = 'TOANDFRO.inp';
    OUTPUT = 'TOANDFRO.out';
    MAX_N = 210;
    MAX_M = 21;

var
    fi,fo:text;
    S:string;
    N,M:longint;
    a:array[0..MAX_N,0..MAX_M] of char;

{---------------------------------------------------------------------------}
procedure   toRectangle;
var
    i,j,k,turn:longint;
begin
    N:=length(S) div M;
    k:=0;
    turn:=1;
    for i:=1 to N do begin
        turn:=turn xor 1;
        if turn = 0 then
            for j:=1 to M do begin
                inc(k);
                a[i,j]:=S[k];
            end;
        if turn = 1 then
            for j:=M downto 1 do begin
                inc(k);
                a[i,j]:=S[k];
            end;
    end;
end;
{---------------------------------------------------------------------------}
procedure   print_result;
var
    i,j:longint;
begin
    for j:=1 to M do
        for i:=1 to N do
            write(fo,a[i,j]);
    writeln(fo);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,M);
    while M <> 0 do begin
        readln(fi,S);
        toRectangle;
        print_result;
        readln(fi,M);
    end;
    close(fo);
    close(fi);
end.