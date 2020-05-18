const
    INPUT = 'THREE.inp';
    OUTPUT = 'THREE.out';
    MAX_N = 100;
    MAX_M = 20000;
    MAX = MAX_M*10000+1;

var
    fi,fo:text;
    N,M,S:longint;
    id,F,trace:array[1..MAX_N,1..MAX_N] of longint;
    res:array[0..MAX_M] of boolean;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i,j,u,v:longint;
begin
    readln(fi,N,M);
    for i:=1 to N do begin
        for j:=1 to N do begin
            F[i,j]:=MAX;
            id[i,j]:=0;
        end;
        F[i,i]:=0;
    end;
    for i:=1 to M do begin
        readln(fi,u,v,j);
        if j < F[u,v] then begin
            F[u,v]:=j;  F[v,u]:=j;
            id[u,v]:=i; id[v,u]:=i;
        end;
    end;
end;
{---------------------------------------------------------------------------}
procedure   Floyd;
var
    i,j,t:longint;
begin
    for i:=1 to N do
        for j:=1 to N do
            trace[i,j]:=j;
    for t:=1 to N do
        for i:=1 to N do
            for j:=1 to N do
                if F[i,t]+F[t,j] < F[i,j] then begin
                    F[i,j]:=F[i,t]+F[t,j];
                    trace[i,j]:=trace[i,t];
                end;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,u,v,tmp:longint;
begin
    S:=F[1,1]+F[2,1]+F[3,1];
    v:=1;
    for i:=2 to N do begin
        tmp:=F[1,i]+F[2,i]+F[3,i];
        if tmp < S then begin
            S:=tmp;
            v:=i;
        end;
    end;

    for i:=1 to M do Res[i]:=false;
    for i:=1 to 3 do begin
        u:=i;
        while u <> v do begin
            res[id[u,trace[u,v]]]:=true;
            u:=trace[u,v];
        end;
    end;
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    i,count:longint;
begin
    writeln(fo,S);
    count:=0;
    for i:=1 to M do
        if res[i] = true then inc(count);
    writeln(fo,count);
    for i:=1 to M do
        if res[i] = true then write(fo,i,' ');
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    Floyd;
    Solve;
    Print_result;
    close(fo);
    close(fi);
end.