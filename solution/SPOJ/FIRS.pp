const
    INPUT = 'FIRS.inp';
    OUTPUT = 'FIRS.out';
    MAX_N = 100001;

type
    arr = array[1..MAX_N] of longint;

var
    N,Res:longint;
    A,idx:arr;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,N);
    for i:=1 to N do
        begin
            read(fi,A[i]);
            idx[i]:=i;
        end;
    A[N+1]:=MAXLONGINT;
    close(fi);
end;

procedure   Swap(var x,y:longint);
var
    tmp:longint;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;

procedure   Quick_sort(var X:arr; l,r:longint);
var
    i,j,p:longint;
begin
    i:=l;   j:=r;
    p:=X[(i+j) div 2];
    repeat
        while X[i] < p do inc(i);
        while X[j] > p do dec(j);
        if i <= j then
            begin
                Swap(A[i],A[j]);
                Swap(idx[i],idx[j]);
                inc(i); dec(j);
            end;
    until i >= j;
    if l < j then Quick_sort(X,l,j);
    if i < r then Quick_sort(X,i,r);
end;

procedure   Init;
var
    i,j:longint;
begin
    Quick_sort(A,1,N);
    i:=1;
    repeat
        j:=i;
        while A[j+1] = A[i] do inc(j);
        if j > i then
            Quick_sort(idx,i,j);
        i:=j+1;
    until i >= N;
end;

procedure   Find;
var
    i,j,S:longint;
    avail:array[0..MAX_N] of boolean;
begin
    for i:=1 to N do
        avail[i]:=true;
    avail[0]:=false;    avail[N+1]:=false;
    S:=N;
    Res:=0;
    for i:=1 to N do
        if avail[idx[i]] then
            begin
                inc(Res);
                j:=idx[i];
                if avail[j-1] then
                    begin
                        avail[j-1]:=false;
                        dec(S);
                    end;
                if avail[j+1] then
                    begin
                        avail[j+1]:=false;
                        dec(S);
                    end;
                if S = 0 then break;
            end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,Res);
    close(fo);
end;

begin
    Enter;
    Init;
    Find;
    Print_result;
end.