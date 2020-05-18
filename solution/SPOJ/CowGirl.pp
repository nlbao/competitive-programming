const
    INPUT = 'CowGirl.inp';
    OUTPUT = 'CowGirl.out';
    MAX_M = 30;
    MAX_N = 30;
    MAX_R = 500;

type
    recE = record
        u,v:longint;
    end;

var
    fi,fo:text;
    T,i,N,M,L,R:longint;
    head:array[0..MAX_R+1] of longint;
    adj:array[1..sqr(MAX_R)] of longint;
    Res:double;

{---------------------------------------------------------------------------}
procedure   SetBit(x,k,bit:longint);
begin
    if bit = 1 then x:=x or (1 shl (k-1))
    else x:=x and (not (1 shl (k-1)));
end;
{---------------------------------------------------------------------------}
function    GetBit(x,k:longint):longint;
begin
    exit((x shr (k-1)) and 1);
end;
{---------------------------------------------------------------------------}
function    check(x,x1:longint):boolean;
var
    i,tmp:longint;
begin
    for i:=2 to M do
        begin
            tmp:=GetBit(x,i-1)+GetBit(x,i)+GetBit(x1,i-1)+GetBit(x1,i);
            if (tmp < 1) or (tmp > 3) then exit(false);
        end;
    exit(true);
end;
{---------------------------------------------------------------------------}
procedure   Init;
var
    i,j,k,tmp:longint;
    E:array[1..sqr(MAX_R)] of recE;
begin
    if M > N then
        begin
            tmp:=M;
            M:=N;
            N:=tmp;
        end;
    L:=0;
    R:=1;   k:=1;
    for i:=1 to M-1 do
        begin
            k:=k*2;
            R:=R+k;
        end;
    for i:=L to R+1 do head[i]:=0;
    k:=0;
    for i:=L to R do
        for j:=L to R do
            if check(i,j) = true then
                begin
                    inc(k);
                    E[k].u:=i;  E[k].v:=j;
                    inc(head[i]);
                end;
    for i:=L+1 to R+1 do head[i]:=head[i]+head[i-1];
    for i:=1 to k do
        begin
            adj[head[E[i].u]]:=E[i].v;
            dec(head[E[i].u]);
        end;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,j,u,v:longint;
    F:array[1..MAX_N,0..MAX_R] of double;
begin
    for u:=L to R do F[1,u]:=1;
    for i:=2 to N do
        for u:=L to R do
            begin
                F[i,u]:=0;
                for j:=head[u]+1 to head[u+1] do
                    begin
                        v:=adj[j];
                        F[i,u]:=F[i,u]+F[i-1,v];
                    end;
            end;
    Res:=0;
    for u:=L to R do Res:=Res+F[N,u];
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    read(fi,T);
    for i:=1 to T do
        begin
            read(fi,M,N);
            Init;
            Solve;
            writeln(fo,Res:0:0);
        end;
    close(fo);
    close(fi);
end.