const
    INPUT = 'PTrang.inp';
    OUTPUT = 'PTrang.out';
    MAX_N = 6000;

var
    N,L,Res:longint;
    W:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,L);
    for i:=1 to N do read(fi,W[i]);
    close(fi);
end;
{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,j,tmp:longint;
    F:array[0..MAX_N] of longint;
begin
    W[0]:=0;
    for i:=2 to N do W[i]:=W[i]+W[i-1];
    F[0]:=0;
    for i:=1 to N do
        begin
            F[i]:=MAXLONGINT;
            for j:=i-1 downto 0 do
                begin
                    tmp:=L-(W[i]-W[j]);
                    if tmp < 0 then break
                    else
                        F[i]:=min(F[i],max(F[j],tmp));
                end;
        end;
    Res:=F[N];
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
    Solve;
    Print_result;
end.