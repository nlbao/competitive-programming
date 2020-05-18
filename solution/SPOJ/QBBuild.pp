const
    INPUT = 'QBBuild.inp';
    OUTPUT = 'QBBuild.out';
    MAX_N = 100;
    MAX = sqr(MAX_N)*10000+1;

var
    fi,fo:text;
    N,count:longint;
    a:array[0..24,1..4] of longint;
    tmp:array[1..4] of longint;
    avail:array[1..4] of boolean;
    F:array[1..MAX_N,1..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i,u,v:longint;
begin
    readln(fi,N);
    for u:=1 to N do begin
        for v:=1 to N do F[u,v]:=MAX;
        F[u,u]:=0;
    end;
    readln(fi,a[0][1],a[0][2],a[0][3],a[0][4]);
    while not eof(fi) do begin
        readln(fi,u,v,i);
        if i < F[u,v] then begin
            F[u,v]:=i;
            F[v,u]:=i;
        end;
    end;
end;
{---------------------------------------------------------------------------}
procedure   TryA(i:longint);
var
    j:longint;
begin
    if i > 4 then begin
        inc(count);
        for j:=1 to 4 do a[count][j]:=tmp[j];
        exit;
    end;
    for j:=1 to 4 do
        if avail[j] then begin
            tmp[i]:=a[0][j];
            avail[j]:=false;
            TryA(i+1);
            avail[j]:=true;
            tmp[i]:=0;
        end;
end;
{---------------------------------------------------------------------------}
procedure   Floyd;
var
    i,j,t:longint;
begin
    for t:=1 to N do
        for i:=1 to N do
            for j:=1 to N do
                if F[i,t]+F[t,j] < F[i,j] then
                    F[i,j]:=F[i,t]+F[t,j];
end;
{---------------------------------------------------------------------------}
procedure   Init;
var
    i:longint;
begin
    count:=0;
    for i:=1 to 4 do begin
        avail[i]:=true;
        tmp[i]:=0;
    end;
    TryA(1);
    Floyd;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,u,v,tmp,S:longint;
begin
    S:=MAX;
    for i:=1 to 24 do begin
        for u:=1 to N do
            for v:=1 to N do begin
                tmp:=F[a[i][1],u]+F[a[i][2],u]+F[a[i][3],v]+F[a[i][4],v]+F[u,v];
                if tmp < S then S:=tmp;
            end;
    end;
    writeln(fo,S);
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