const
    INPUT = 'CNMarble.inp';
    OUTPUT = 'CNMarble.out';
    MAX_N = 500000;

type
    recA = record
        value:longint;
        next:longint;
    end;

var
    N,M,S,P:longint;
    A:array[1..MAX_N] of recA;
    R:array[1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,M);
    S:=0;
    for i:=1 to N do
        begin
            read(fi,A[i].value);
            S:=S+A[i].value;
            A[i].next:=i+1;
        end;
    A[N].next:=1;
    close(fi);
    P:=S div M;
end;

procedure   Swap(var x,y:longint);
var
    tmp:longint;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;

{procedure   Quick_sort(left,right:longint);
var
    i,j,p:longint;
begin
    i:=left;   j:=right;
    p:=R[(i+j) div 2];
    repeat
        while R[i] < p do inc(i);
        while R[j] > p do dec(j);
        if i <= j then
            begin
                Swap(R[i],R[j]);
                inc(i);
                dec(j);
            end;
    until i >= j;
    if left <= j then Quick_sort(left,j);
    if i <= right then Quick_sort(i,right);
end; }

procedure   Print_result;
var
    fo:text;
    i,j,k:longint;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    k:=1;
    for i:=1 to P do
        begin
            for j:=1 to M do
                begin
                    while A[k].value = 0 do k:=A[k].next;
                    write(fo,k,' ');
                    {R[j]:=k;}
                    dec(A[k].value);
                    k:=A[k].next;
                end;
            {Quick_sort(1,M);
            for j:=1 to M do write(fo,R[j],' ');}
            writeln(fo);
        end;
    close(fo);
end;

begin
    Enter;
    Print_result;
end.