const
    INPUT = 'LITES.inp';
    OUTPUT = 'LITES.out';
    MAX_N = 100000;
    MAX_F = 4*MAX_N;

var
    fi,fo:text;
    N,M,Res,first,last:longint;
    F:array[1..MAX_F] of longint;
    B:array[1..MAX_F] of boolean;

{---------------------------------------------------------------------------}
procedure   Init;
var
    i:longint;
begin
    for i:=1 to 4*N do begin
        F[i]:=0;
        B[i]:=false;
    end;
end;
{---------------------------------------------------------------------------}
procedure   subUpdateF(k,l,r:longint);
begin
    F[k]:=r-l+1-F[k];
    B[k]:=false;
    B[k shl 1]:=not B[k shl 1];
    B[(k shl 1)+1]:=not B[(k shl 1)+1];
end;
{---------------------------------------------------------------------------}
procedure   UpdateF(k,l,r:longint);
var
    mid:longint;
begin
    if l > r then exit;
    if (l > last) or (r < first) then exit;
    if (l >= first) and (r <= last) then begin
        if B[k] = false then F[k]:=r-l+1-F[k]
        else B[k]:=false;
        B[k shl 1]:=not B[k shl 1];
        B[(k shl 1)+1]:=not B[(k shl 1)+1];
        exit;
    end;
    mid:=(l+r) shr 1;
    if B[k shl 1] = true then
        subUpdateF(k shl 1,l,mid);
    if B[(k shl 1)+1] = true then
        subUpdateF((k shl 1)+1,mid+1,r);
    UpdateF(k shl 1,l,mid);
    UpdateF((k shl 1)+1,mid+1,r);
    F[k]:=F[k shl 1]+F[(k shl 1)+1];
end;
{---------------------------------------------------------------------------}
procedure   GetF(k,l,r:longint);
var
    mid:longint;
begin
    if l > r then exit;
    if (l > last) or (r < first) then exit;
    if (l >= first) and (r <= last) then begin
        if B[k] = true then
            subUpdateF(k,l,r);
        Res:=Res+F[k];
        exit;
    end;
    if B[k] = true then
        subUpdateF(k,l,r);
    mid:=(l+r) shr 1;
    GetF(k shl 1,l,mid);
    GetF((k shl 1)+1,mid+1,r);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,types:longint;
begin
    for i:=1 to M do begin
        readln(fi,types,first,last);
        if types = 0 then UpdateF(1,1,N)
        else begin
            Res:=0;
            GetF(1,1,N);
            writeln(fo,Res);
        end;
    end;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N,M);
    Init;
    Solve;
    close(fo);
    close(fi);
end.