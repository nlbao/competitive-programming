const
    INPUT = 'HUGEKNAP.inp';
    OUTPUT = 'HUGEKNAP.out';
    MAX_N = 10000;
    MAX_M = 1000;

type
    pRes = ^recRes;
    recRes = record
        id:longint;
        next:pRes;
    end;
    recTRes = record
        count:longint;
        first,last:pRes;
    end;

var
    fi,fo:text;
    T,N,M,i,last_i:longint;
    W,V:array[1..MAX_N] of longint;
    F:array[-1..0,0..MAX_M] of longint;
    Res:array[-1..0,0..MAX_M] of recTRes;


procedure   Enter;
var
    i:longint;
begin
    readln(fi,N,M);
    for i:=1 to N do read(fi,W[i]);
    for i:=1 to N do read(fi,V[i]);
end;

procedure   Solve;
var
    i,j,k,pre_i:longint;
    p:pRes;
begin
    i:=-1;
    for j:=0 to M do
        begin
            F[i,j]:=0;
            Res[i,j].count:=0;
            Res[i,j].first:=nil;
            Res[i,j].last:=nil;
        end;
    for k:=1 to N do
        begin
            pre_i:=i;   i:=not i;
            for j:=0 to M do
                if (W[k] <= j) and (F[pre_i,j-W[k]]+V[k] > F[pre_i,j]) then
                    begin
                        F[i,j]:=F[pre_i,j-W[k]]+V[k];
                        Res[i,j]:=Res[pre_i,j-W[k]];
                        inc(Res[i,j].count);
                        New(p);
                        p^.id:=k;
                        p^.next:=nil;
                        if Res[i,j].last <> nil then Res[i,j].last^.next:=p
                        else Res[i,j].first:=p;
                        Res[i,j].last:=p;
                    end
                else
                    begin
                        F[i,j]:=F[pre_i,j];
                        Res[i,j]:=Res[pre_i,j];
                    end;
        end;
    last_i:=i;
end;

procedure   Print_result;
var
    j,maxF,max_j:longint;
    p:pRes;
begin
    maxF:=-1;
    for j:=1 to M do
        if F[last_i,j] > maxF then
            begin
                maxF:=F[last_i,j];
                max_j:=j;
            end;
    writeln(fo,F[last_i,max_j],' ',Res[last_i,max_j].count);
    p:=Res[last_i,max_j].first;
    while p <> nil do
        begin
            write(fo,p^.id,' ');
            p:=p^.next;
        end;
    writeln(fo);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,T);
    for i:=1 to T do
        begin
            Enter;
            Solve;
            Print_result;
        end;
    close(fo);
    close(fi);
end.