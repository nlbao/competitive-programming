const
    INPUT = 'Binary2.inp';
    OUTPUT = 'Binary2.out';
    MAX_N = 1000001;
    MAX_K = MAX_N;
    MODULO = 1000000000;

type
    int = longint;
    pF = ^recF;
    recF = record
        value:array[0..1] of int;
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
function    cong(a,b:int):int;  inline;
begin
    exit((a+b) mod MODULO);
end;
{---------------------------------------------------------------------------}
function    tru(a,b:int):int;   inline;
begin
    if a < b then
        exit(((a-b) mod MODULO)+MODULO)
    else
        exit((a-b) mod MODULO);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    p,q:pF;
    i,j:longint;
begin
    new(p);
    for i:=0 to 1 do p^.value[i]:=1;
    p^.left:=nil; p^.right:=nil;
    first:=p;
    for i:=2 to K do begin
        q:=p;
        new(p);
        for j:=0 to 1 do p^.value[j]:=0;
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
    sum1,sum0,tmp0,tmp1,res:int;
begin
    tmp0:=0;    tmp1:=0;
    sum0:=0;    sum1:=0;

    for i:=2 to N do begin
        sum0:=cong(tru(sum0,tmp0),first^.value[0]);
        sum1:=cong(tru(sum1,tmp1),first^.value[1]);
        tmp0:=last^.value[0];   tmp1:=last^.value[1];
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

    res:=0;
    p:=first;
    for j:=1 to min(K,N) do begin
        res:=cong(res,cong(p^.value[0],p^.value[1]));
        p:=p^.right;
    end;

    writeln(fo,res);
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