const
    INPUT = 'M00Pair';
    OUTPUT = 'M00Pair';
    MAX_N = 1001;

type
    bigNum = ansiString;

var
    fi,fo:text;
    N:longint;
    f:array[0..MAX_N] of bigNum;

{---------------------------------------------------------------------------}
function    cong(a,b:bigNum):bigNum;
var
    c:bigNum;
    i,carry,x:longint;
begin
    c:='';
    while length(a) < length(b) do a:='0'+a;
    while length(b) < length(a) do b:='0'+b;
    carry:=0;
    for i:=length(a) downto 1 do begin
        x:=ord(a[i])+ord(b[i])-96+carry;
        carry:=x div 10;
        x:=x mod 10;
        c:=chr(x+48)+c;
    end;
    if carry > 0 then
        c:=chr(carry+48)+c;
    exit(c);
end;
{---------------------------------------------------------------------------}
function    tru(a,b:bigNum):bigNum; {a > b}
var
    c:bigNum;
    i,carry,x:longint;
begin
    c:='';
    while length(b) < length(a) do b:='0'+b;
    carry:=0;
    for i:=length(a) downto 1 do begin
        x:=ord(a[i])-ord(b[i])-carry;
        if x < 0 then x:=x+10;
        carry:=x div 10;
        x:=x mod 10;
        c:=chr(x+48)+c;
    end;
    while (length(c) > 1) and (c[1] = '0') do delete(c,1,1);
    exit(c);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i:longint;
begin
    f[1]:='0';
    for i:=2 to MAX_N do begin
        f[i]:=cong(f[i-1],f[i-1]);
        if i mod 2 = 0 then f[i]:=cong(f[i],'1')
        else f[i]:=tru(f[i],'1');
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
begin
    repeat
        N:=0;
        readln(fi,N);
        if N = 0 then exit;
        writeln(fo,f[N]);
    until N = 0;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    solve;
    close(fo);
    close(fi);
end.
