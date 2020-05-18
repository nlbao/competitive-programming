const
    INPUT = 'NTHuge.inp';
    OUTPUT = 'NTHuge.out';
    MAX_N = 32;
    MAX_M = 65540;

type
    recF = record
        w,v:int64;
    end;
    arrF = array[0..MAX_M] of recF;

var
    N,M1,M2,P1,P2:longint;
    L,R,Sw,Sv,maxT,Res:int64;
    W,V:array[1..MAX_N] of int64;
    F1,F2:arrF;
    T:array[1..4*MAX_M] of int64;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,L,R);
    for i:=1 to N do
        read(fi,W[i],V[i]);
    close(fi);
end;

function    max(x,y:int64):int64;
begin
    if x > y then exit(x)
    else exit(y);
end;

procedure   Swap(var x,y:recF);
var
    tmp:recF;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;

procedure   Quick_sort(var F:arrF;  l,r:longint);
var
    i,j:longint;
    p:int64;
begin
    i:=l;   j:=r;
    p:=F[(i+j) div 2].w;
    repeat
        while F[i].w < p do inc(i);
        while F[j].w > p do dec(j);
        if i <= j then
            begin
                Swap(F[i],F[j]);
                inc(i); dec(j);
            end;
    until i >= j;
    if l < j then Quick_sort(F,l,j);
    if i < r then Quick_sort(F,i,r);
end;

procedure   TryF1(i:longint);
var
    j:longint;
begin
    if i > P1 then
        begin
            inc(M1);
            F1[M1].w:=Sw;
            F1[M1].v:=Sv;
        end
    else
        for j:=0 to 1 do
            begin
                Sw:=Sw+j*W[i];
                Sv:=Sv+j*V[i];
                TryF1(i+1);
                Sv:=Sv-j*V[i];
                Sw:=Sw-j*W[i];
            end;
end;

procedure   TryF2(i:longint);
var
    j,t:longint;
begin
    if i > P2 then
        begin
            inc(M2);
            F2[M2].w:=Sw;
            F2[M2].v:=Sv;
        end
    else
        for j:=0 to 1 do
            begin
                t:=i+P1;
                Sw:=Sw+j*W[t];
                Sv:=Sv+j*V[t];
                TryF2(i+1);
                Sv:=Sv-j*V[t];
                Sw:=Sw-j*W[t];
            end;
end;

procedure   F_Init;
begin
    P1:=N div 2;
    M1:=0;
    Sw:=0;  Sv:=0;
    TryF1(1);
    P2:=N-P1;
    M2:=0;
    Sw:=0;  Sv:=0;
    TryF2(1);
    Quick_sort(F2,1,M2);
end;

procedure   Update_T(i,k,l,r:longint);
var
    mid:longint;
begin
    if (i < l) or (i > r) then exit;
    if l = r then
        begin
            T[k]:=F2[i].v;
            exit;
        end;
    mid:=(l+r) div 2;
    Update_T(i,k*2,l,mid);
    Update_T(i,k*2+1,mid+1,r);
    T[k]:=max(T[k*2],T[k*2+1]);
end;

procedure   T_Init;
var
    i:longint;
begin
    for i:=1 to 4*M2 do T[i]:=0;
    for i:=1 to M2 do
        Update_T(i,1,1,M2);
end;

procedure   FindMaxT(i,j,k,l,r:longint);
var
    mid:longint;
begin
    if (j < l) or (i > r) then exit;
    if (i <= l) and (r <= j) then
        begin
            maxT:=max(maxT,T[k]);
            exit;
        end;
    mid:=(l+r) div 2;
    FindMaxT(i,j,k*2,l,mid);
    FindMaxT(i,j,k*2+1,mid+1,r);
end;

procedure   Find;
var
    i,j,k,l0,r0,mid:longint;
    tmp:int64;
begin
    Res:=0;
    F2[0].w:=-1;    F2[M2+1].w:=-1;
    for i:=1 to M1 do
        begin
            j:=0;   k:=0;
            tmp:=L-F1[i].w;
            if tmp >= 0 then
                begin
                    l0:=1;  r0:=M2;
                    while l0 < r0-1 do
                        begin
                            mid:=(l0+r0) div 2;
                            if F2[mid].w >= tmp then r0:=mid
                            else l0:=mid;
                        end;
                    if F2[l0].w >= tmp then j:=l0
                    else
                        if F2[r0].w >= tmp then j:=r0;
                end;
            tmp:=R-F1[i].w;
            if (j > 0) and (tmp >= 0) then
                begin
                    l0:=1;  r0:=M2;
                    while l0 < r0-1 do
                        begin
                            mid:=(l0+r0) div 2;
                            if F2[mid].w <= tmp then l0:=mid
                            else r0:=mid;
                        end;
                    if F2[r0].w <= tmp then k:=r0
                    else
                        if F2[l0].w <= tmp then k:=l0;
                end;
            if (k >= j) and (j > 0) then
                begin
                    maxT:=0;
                    FindMaxT(j,k,1,1,M2);
                    Res:=max(Res,F1[i].v+maxT);
                end;
        end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,Res);
    close(fo);
end;

begin
    Enter;
    F_Init;
    T_Init;
    Find;
    Print_result;
end.