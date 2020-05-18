const
    INPUT = 'QMax.inp';
    OUTPUT = 'QMax.out';
    MAX_N = 50000;
    MAX_M = 100000;
    MAX_F = 8*MAX_N+1;

type
    recF = record
        value,max:longint;
    end;

var
    fi,fo:text;
    N,M,P,first,last,value:longint;
    F:array[1..MAX_F] of recF;

{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;   inline;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   Init;
var
    i:longint;
begin
    readln(fi,N,M);
    for i:=1 to 8*N do begin
        F[i].value:=0;
        F[i].max:=0;
    end;
end;
{---------------------------------------------------------------------------}
procedure   UpdateF(k,l,r:longint);
var
    mid:longint;
begin
    if (l > last) or (r < first) then exit;
    if (l >= first) and (r <= last) then begin
        F[k].value:=F[k].value+value;
        F[k].max:=F[k].max+value;
        exit;
    end;
    mid:=(l+r) shr 1;
    UpdateF(k shl 1,l,mid);
    UpdateF((k shl 1)+1,mid+1,r);
    F[k].max:=max(F[k shl 1].max,F[(k shl 1)+1].max)+F[k].value;
end;
{---------------------------------------------------------------------------}
function    GetF(k,l,r:longint):longint;
var
    mid:longint;
begin
    if (l > last) or (r < first) then exit(-1);
    if (l >= first) and (r <= last) then exit(F[k].max);
    mid:=(l+r) shr 1;
    exit(max(GetF(k shl 1,l,mid),GetF((k shl 1)+1,mid+1,r))+F[k].value);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i:longint;
begin
    for i:=1 to M do begin
        read(fi,first,last,value);
        UpdateF(1,1,N);
    end;
    read(fi,P);
    for i:=1 to P do begin
        read(fi,first,last);
        writeln(fo,GetF(1,1,N));
    end;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Init;
    Solve;
    close(fo);
    close(fi);
end.
