const
    INPUT = 'DTTui1.inp';
    OUTPUT = 'DTTui1.out';
    MAX_N = 40;
    MAX_M = 1000000000;
    MAX_F = 1050000;

type
    recF = record
        w,v:int64;
    end;

var
    fi,fo:text;
    N,cF1,cF2,nF1,nF2:longint;
    M,sW,sV:int64;
    W,V:array[1..MAX_N] of int64;
    F1,F2:array[1..MAX_F] of recF;
    T:array[1..MAX_F] of int64;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i:longint;
begin
    read(fi,N,M);
    for i:=1 to N do read(fi,W[i],V[i]);
end;
{---------------------------------------------------------------------------}
procedure   TryF1(i:longint);
var
    j:longint;
begin
    if i > cF1 then begin
        if sW <=M then begin
            inc(nF1);
            F1[nF1].w:=sW;  F1[nF1].v:=sV;
        end;
    end
    else
        for j:=0 to 1 do begin
            sW:=sW+j*W[i];
            sV:=sV+j*V[i];
            TryF1(i+1);
            sV:=sV-j*V[i];
            sW:=sW-j*W[i];
        end;
end;
{---------------------------------------------------------------------------}
procedure   TryF2(i:longint);
var
    j,t:longint;
begin
    if i > cF2 then begin
        if sW <= M then begin
            inc(nF2);
            F2[nF2].w:=sW;  F2[nF2].v:=sV;
        end;
    end
    else
        for j:=0 to 1 do begin
            t:=cF1+i;
            sW:=sW+j*W[t];
            sV:=sV+j*V[t];
            TryF2(i+1);
            sV:=sV-j*V[t];
            sW:=sW-j*W[t];
        end;
end;
{---------------------------------------------------------------------------}
procedure   Quick_sort(l,r:longint);
var
    i,j:longint;
    p:int64;
    tmp:recF;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=F1[(i+j) div 2].w;
    repeat
        while F1[i].w < p do inc(i);
        while F1[j].w > p do dec(j);
        if i <= j then begin
            tmp:=F1[i]; F1[i]:=F1[j];  F1[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    Quick_sort(l,j);    Quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
procedure   Init;
var
    i,j,k:longint;
begin
    cF2:=N div 2;   cF1:=N-cF2;
    nF1:=0;
    sW:=0;  sV:=0;
    TryF1(1);
    nF2:=0;
    sW:=0;  sV:=0;
    TryF2(1);
    Quick_sort(1,nF1);
end;
{---------------------------------------------------------------------------}
function    max(x,y:int64):int64;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,l,r,mid:longint;
    Res,tmp:int64;
begin
    Res:=-1;
    T[1]:=F1[1].v;
    for i:=2 to nF1 do
        T[i]:=max(T[i-1],F1[i].v);
    for i:=1 to nF2 do begin
        tmp:=M-F2[i].w;
        l:=1;   r:=nF1;
        while l <= r do begin
            mid:=(l+r) div 2;
            if F1[mid].w = tmp then break
            else
                if F1[mid].w < tmp then l:=mid+1
                else r:=mid-1;
        end;
        if F1[mid].w > tmp then dec(mid);
        if F1[mid+1].w <= tmp then inc(mid);
        if mid > 0 then begin
            while (mid < nF1) and (F1[mid+1].w = tmp) do inc(mid);
            Res:=max(Res,F2[i].v+T[mid]);
        end;
    end;
    writeln(fo,Res);
    writeln(nF1,' ',nF2);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    Init;
    Solve;
    close(fo);
    close(fi);
end.

