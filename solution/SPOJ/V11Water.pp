const
    INPUT = 'V11Water.inp';
    OUTPUT = 'V11Water.out';
    MAX_N = 100000;

var
    N:longint;
    Res:int64;
    H:array[1..MAX_N] of int64;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,N);
    for i:=1 to N do read(fi,H[i]);
    close(fi);
end;
{---------------------------------------------------------------------------}
function    min(x,y:int64):int64;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
function    max(x,y:int64):int64;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}

procedure   Find;
var
    i,j:longint;
    L,R:array[1..MAX_N] of int64;
begin
    Res:=0;
    L[1]:=H[1];
    for i:=2 to N do L[i]:=max(L[i-1],H[i]);
    R[N]:=H[N];
    for i:=N-1 downto 1 do R[i]:=max(R[i+1],H[i]);
    for i:=2 to N-1 do
        if (H[i] < L[i-1]) and (H[i] < R[i+1]) then
            Res:=Res+min(L[i-1],R[i+1])-H[i];
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,Res);
    close(fo);
end;
{---------------------------------------------------------------------------}

begin
    Enter;
    Find;
    Print_result;
end.