const
    INPUT = 'Well.inp';
    OUTPUT = 'Well.out';
    MAX_N1 = 20;
    MAX_M1 = 100;
    MAX_N2 = 8;
    MAX_M2 = 64;
    MAX_P2 = MAX_N1*MAX_M1;

type
    bigNum = ansiString;

var
    fi,fo:text;
    nTest,i,types,M,N:longint;
    p2:array[0..MAX_P2] of bigNum;
    F:array[0..MAX_M2,0..MAX_P2] of int64;

{---------------------------------------------------------------------------}
function    cong(a,b:bigNum):bigNum;
var
    sum,carry,i,x,y:longint;
    c:bigNum;
begin
    carry:=0;   c:='';
    while length(a) < length(b) do a:='0'+a;
    while length(b) < length(a) do b:='0'+b;
    for i:=length(a) downto 1 do begin
        x:=ord(a[i])-48;
        y:=ord(b[i])-48;
        sum:=x+y+carry;
        carry:=sum div 10;
        c:=chr((sum mod 10)+48)+c;
    end;
    if carry > 0 then c:='1'+c;
    exit(c);
end;
{---------------------------------------------------------------------------}
function    tru(a,b:bigNum):bigNum;
var
    c:bigNum;
    s,borrow,i:longint;
begin
    borrow:=0;  c:='';
    while length(a) < length(b) do a:='0'+a;
    while length(b) < length(a) do b:='0'+b;
    for i:=length(a) downto 1 do begin
        s:=ord(a[i])-ord(b[i])-borrow;
        if s < 0 then begin
            s:=s+10;
            borrow:=1;
        end
        else borrow:=0;
        c:=chr(s+48)+c;
    end;
    while (length(c) > 1) and (c[1] = '0') do delete(c,1,1);
    exit(c);
end;
{---------------------------------------------------------------------------}
function    nhan(a:bigNum;  b:longint):bigNum;
var
    i,carry,s:longint;
    c,tmp:bigNum;
begin
    c:='';
    carry:=0;
    for i:=length(a) downto 1 do begin
        s:=(ord(a[i])-48)*b+carry;
        carry:=s div 10;
        c:=chr((s mod 10)+48)+c;
    end;
    if carry > 0 then str(carry,tmp)
    else tmp:='';
    exit(tmp+c);
end;
{---------------------------------------------------------------------------}
function    chia(a:bigNum;  b:longint):bigNum;
var
    s,i,hold:longint;
    c:bigNum;
begin
    hold:=0;    s:=0;   c:='';
    for i:=1 to length(a) do begin
        hold:=hold*10+ord(a[i])-48;
        s:=hold div b;
        hold:=hold mod b;
        c:=c+chr(s+48);
    end;
    while (length(c) > 1) and (c[1] = '0') do delete(c,1,1);
    exit(c);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i:longint;
begin
    p2[0]:='1';
    for i:=1 to MAX_P2 do
        p2[i]:=nhan(p2[i-1],2);
end;
{---------------------------------------------------------------------------}
procedure   solve1;
begin
    writeln(M,' ',N,' ',p2[M*N]);
    writeln(fo,cong(chia(tru(p2[M*N],p2[M]),N),p2[M]));
end;
{---------------------------------------------------------------------------}
function    get_bit(x,i:longint):longint;   inline;
begin
    exit((x shr (i-1)) and 1);
end;
{---------------------------------------------------------------------------}
function    check(x,y:longint):boolean;
var
    i:longint;
begin
    for i:=1 to N-1 do
        if (get_bit(x,i) = get_bit(y,i)) and (get_bit(x,i+1) = get_bit(y,i+1)) and (get_bit(x,i) = get_bit(x,i+1)) then
            exit(false);
    if (get_bit(x,N) = get_bit(y,N)) and (get_bit(x,1) = get_bit(y,1)) and (get_bit(x,N) = get_bit(x,1)) then
        exit(false);
    exit(true);
end;
{---------------------------------------------------------------------------}
procedure   solve2;
var
    i,j,k,R:longint;
    s1,s2:int64;
begin
    if N = 1 then begin
        writeln(fo,p2[M]);
        exit;
    end;
    R:=1;
    for i:=1 to N do R:=R*2;
    dec(R);
    for j:=0 to R do F[1,j]:=1;
    for i:=2 to M do
        for j:=0 to R do begin
            F[i,j]:=0;
            for k:=0 to R do
                if check(j,k) = true then
                    F[i,j]:=F[i,j]+F[i-1,k];
        end;
    s1:=0;
    for j:=0 to R do
        s1:=s1+F[M,j];
    s2:=0;
    for j:=0 to R do
        if check(j,j) = true then
            s2:=s2+1;
    writeln(fo,(s1-s2) div N + s2);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    readln(fi,nTest);
    for i:=1 to nTest do begin
        readln(fi,types,M,N);
        if types = 1 then solve1
        else solve2;
    end;
    close(fo);
    close(fi);
end.