const
    INPUT = 'NKLineUp.inp';
    OUTPUT = 'NKLineUp.out';
    MAX_N = 50000;
    MAX_Q = 200000;

type
    recF = record
        min,max:longint;
    end;

var
    fi,fo:text;
    N,Q,maxF,minF,i,u,v:longint;
    A:array[1..MAX_N] of longint;
    F:array[1..4*MAX_N] of recF;

function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;

function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;

procedure   Update_F(i,k,l,r:longint);
var
    mid:longint;
begin
    if (l > i) or (r < i) then exit;
    if l = r then
        begin
            F[k].max:=A[i];
            F[k].min:=A[i];
            exit;
        end;
    mid:=(l+r) div 2;
    Update_F(i,k*2,l,mid);
    Update_F(i,k*2+1,mid+1,r);
    F[k].max:=max(F[k*2].max,F[k*2+1].max);
    F[k].min:=min(F[k*2].min,F[k*2+1].min);
end;

procedure   Find(i,j,k,l,r:longint);
var
    mid:longint;
begin
    if (l > j) or (r < i) then exit;
    if (i <= l) and (r <= j) then
        begin
            maxF:=max(maxF,F[k].max);
            minF:=min(minF,F[k].min);
            exit;
        end;
    mid:=(l+r) div 2;
    Find(i,j,k*2,l,mid);
    Find(i,j,k*2+1,mid+1,r);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N,Q);
    for i:=1 to N do readln(fi,A[i]);
    for i:=1 to 4*N do
        begin
            F[i].min:=0;
            F[i].max:=0;
        end;
    for i:=1 to N do
        Update_F(i,1,1,N);
    for i:=1 to Q do
        begin
            read(fi,u,v);
            minF:=MAXLONGINT;
            maxF:=0;
            Find(u,v,1,1,N);
            writeln(fo,maxF-minF);
        end;
    close(fo);
    close(fi);
end.