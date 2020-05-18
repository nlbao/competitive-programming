const
    INPUT = 'SPBinary.inp';
    OUTPUT = 'SPBinary.out';
    MAX_N = 601;
    MAX_K = MAX_N;
    MAX_DIGIT = 8;
    BASE = 100000000;
    MAX_LENGTH = 23;

type
    bigNum = array[0..MAX_LENGTH] of longint;
    pF = ^recF;
    recF = record
        value:array[0..1] of bigNum;
        left,right:pF;
    end;

var
    fi,fo:text;
    N,K:longint;
    first,last:pF;

{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;   inline;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   to_BigNum(S:ansiString;   var X:bigNum);
var
    i,j:longint;
begin
    fillchar(X,sizeof(X),0);
    i:=length(S);
    repeat
        j:=i;
        while (j > 1) and (i-j+1 < MAX_DIGIT) do dec(j);
        inc(X[0]);
        val(copy(S,j,i-j+1),X[X[0]]);
        i:=j-1;
    until i < 1;
    while (X[0] > 0) and (X[X[0]] = 0) do dec(X[0]);
end;
{---------------------------------------------------------------------------}

procedure   cong(a,b:bigNum;    var c:bigNum);
var
    i,nho:longint;
begin
    fillchar(c,sizeof(c),0);
    c[0]:=a[0];
    if b[0] > c[0] then c[0]:=b[0];
    nho:=0;
    for i:=1 to c[0] do
        begin
            c[i]:=a[i]+b[i]+nho;
            nho:=c[i] div BASE;
            c[i]:=c[i] mod BASE;
        end;
    if nho > 0 then
        begin
            inc(c[0]);
            c[c[0]]:=nho;
        end;
end;
{---------------------------------------------------------------------------}
procedure   tru(a,b:bigNum; var c:bigNum);
var
    i,nho:longint;
begin
    fillchar(c,sizeof(c),0);
    c[0]:=a[0];
    nho:=0;
    for i:=1 to c[0] do
        begin
            c[i]:=a[i]-b[i]-nho;
            if c[i] < 0 then
                begin
                    c[i]:=c[i]+BASE;
                    nho:=1;
                end
            else nho:=0;
            c[i]:=c[i] mod BASE;
        end;
    while (c[0] > 0) and (c[c[0]] = 0) do dec(c[0]);
end;
{---------------------------------------------------------------------------}
function    to_string(a:bigNum):ansiString;
var
    i:longint;
    s,s1:ansiString;
begin
    s:='';
    for i:=1 to a[0] do
        begin
            str(a[i],s1);
            while length(s1) < MAX_DIGIT do s1:='0'+s1;
            s:=s1+s;
        end;
    while (length(s) > 0) and (s[1] = '0') do delete(s,1,1);
    if length(s) = 0 then s:='0';
    exit(s);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    p,q:pF;
    i,j:longint;
begin
    new(p);
    for i:=0 to 1 do to_bigNum('1',p^.value[i]);
    p^.left:=nil; p^.right:=nil;
    first:=p;
    for i:=2 to K do begin
        q:=p;
        new(p);
        for j:=0 to 1 do to_bigNum('0',p^.value[j]);
        p^.left:=q; p^.right:=nil;
        q^.right:=p;
    end;
    last:=p;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    p,q:pF;
    i,j:longint;
    sum1,sum0,tmp0,tmp1,res:bigNum;
begin
    to_bigNum('0',sum0);    to_bigNum('0',sum1);
    to_bigNum('0',tmp0);    to_bigNum('0',tmp1);

    for i:=2 to N do begin
        tru(sum1,tmp1,sum1);
        cong(sum1,first^.value[1],sum1);
        tru(sum0,tmp0,sum0);
        cong(sum0,first^.value[0],sum0);
        tmp0:=last^.value[0];    tmp1:=last^.value[1];
{tinh tien doan 1..K-1 -> 2..K}
        q:=last;
        last^.left^.right:=nil;
        last:=last^.left;
        dispose(q);
{tinh f[1] moi}
        new(p);
        p^.value[0]:=sum1;  p^.value[1]:=sum0;
        p^.left:=nil;   p^.right:=first;
        first^.left:=p;
        first:=p;
    end;

    to_bigNum('0',res);
    p:=first;
    for j:=1 to min(K,N) do begin
        cong(p^.value[0],p^.value[1],tmp0);
        cong(res,tmp0,res);
        p:=p^.right;
    end;

    writeln(fo,to_string(res));
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N,K);
    init;
    solve;
    close(fo);
    close(fi);
end.
