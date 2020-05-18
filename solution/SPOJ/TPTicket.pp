const
    INPUT = 'TPTicket.inp';
    OUTPUT = 'TPTicket.out';
    MAX_N = 100000;
    MAX_M = 500000;
    MAX_IT = 8*MAX_N;

type
    recIT = record
        add,max:longint;
    end;

var
    fi,fo:text;
    N,K,M:longint;
    first,last,maxIT:longint;
    IT:array[1..MAX_IT] of recIT;

{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;   inline;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   UpdateIT(k,l,r:longint);
var
    mid:longint;
begin
    if (l > last) or (r < first) then exit;
    if (l >= first) and (r <= last) then begin
        IT[k].add:=IT[k].add+1;
        IT[k].max:=IT[k].max+1;
        exit;
    end;
    mid:=(l+r) shr 1;
    UpdateIT(k shl 1,l,mid);
    UpdateIT((k shl 1)+1,mid+1,r);
    IT[k].max:=max(IT[k shl 1].max,IT[(k shl 1)+1].max)+IT[k].add;
end;
{---------------------------------------------------------------------------}
function    GetIT(k,l,r:longint):longint;
var
    mid:longint;
begin
    if (l > last) or (r < first) then exit(0);
    if (l >= first) and (r <= last) then exit(IT[k].max);
    mid:=(l+r) shr 1;
    exit(max(GetIT(k shl 1,l,mid),GetIT((k shl 1)+1,mid+1,r))+IT[k].add);
end;
{---------------------------------------------------------------------------}
procedure   Init;
var
    i:longint;
begin
    readln(fi,N,K,M);
    for i:=1 to 8*N do begin
        IT[i].add:=0;
        IT[i].max:=0;
    end;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,Res:longint;
begin
    for i:=1 to M do begin
        readln(fi,first,last);
        inc(first);
        Res:=1;
        if first <= last then begin
            if GetIT(1,1,N) < K then UpdateIT(1,1,N)
            else Res:=0;
        end;
        writeln(fo,Res);
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