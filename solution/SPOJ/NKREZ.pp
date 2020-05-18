const
    INPUT = 'NKREZ.inp';
    OUTPUT = 'NKREZ.out';
    MAX_N = 30000;

type
    recReq = record
        s,e:longint;
    end;
    arrReq = array[1..MAX_N] of recReq;
var
    N:longint;
    Req:arrReq;
    F:array[1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    for i:=1 to N do
        readln(fi,Req[i].s,Req[i].e);
    close(fi);
end;

procedure   Swap(var x,y:recReq);
var
    t:recReq;
begin
    t:=x;
    x:=y;
    y:=t;
end;

procedure   Quick_sort(l,r:longint);
var
    i,j,p:longint;
begin
    i:=l;   j:=r;
    p:=Req[(i+j) div 2].s;
    while i < j do
        begin
            while Req[i].s < p do inc(i);
            while Req[j].s > p do dec(j);
            if i <=j then
                begin
                    Swap(Req[i],Req[j]);
                    inc(i);
                    dec(j);
                end;
        end;
    if l < j then Quick_sort(l,j);
    if i < r then Quick_sort(i,r);
end;

procedure   QHD;
var
    i,j,max:longint;
begin
    F[1]:=Req[1].e-Req[1].s;
    for i:=2 to N do
        begin
            max:=0;
            for j:=i-1 downto 1 do
                if Req[j].e <= Req[i].s then
                    if F[j] > max then
                        max:=F[j];
            F[i]:=max+Req[i].e-Req[i].s;
        end;
end;

procedure   Print_result;
var
    fo:text;
    i,max:longint;
begin
    max:=F[1];
    for i:=2 to N do
        if F[i] > max then
            max:=F[i];
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,max);
    close(fo);
end;

begin
    Enter;
    Quick_sort(1,N);
    QHD;
    Print_result;
end.