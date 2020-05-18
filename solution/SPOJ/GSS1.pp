const
    INPUT = '';
    OUTPUT = '';
    MAX_N = 50000;
    MAX_M = 50000;
    MAX_F = 8*MAX_N;
    MAX_INT = 15007*MAX_N+1;

type
    recF = record
        sum:longint;
        left,right,all:longint;
    end;

var
    fi,fo:text;
    N,M,pos,value,first,last,Res,pre:longint;
    F:array[1..MAX_F] of recF;

{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   UpdateF(k,l,r:longint);
var
    mid:longint;
begin
    if l > r then exit;
    if (l > pos) or (r < pos) then exit;
    if l = r then begin
        F[k].sum:=value;
        F[k].all:=value;
        F[k].left:=value;
        F[k].right:=value;
        exit;
    end;
    mid:=(l+r) shr 1;
    UpdateF(k shl 1,l,mid);
    UpdateF((k shl 1)+1,mid+1,r);

    F[k].sum:=F[k shl 1].sum+F[(k shl 1)+1].sum;
    F[k].all:=max(max(F[k shl 1].all,F[(k shl 1)+1].all),F[k shl 1].right+F[(k shl 1)+1].left);
    F[k].left:=max(F[k shl 1].left,F[k shl 1].sum+F[(k shl 1)+1].left);
    F[k].right:=max(F[(k shl 1)+1].right,F[(k shl 1)+1].sum+F[k shl 1].right);
end;
{---------------------------------------------------------------------------}
procedure   GetF(k,l,r:longint);
var
    mid:longint;
begin
    if l > r then exit;
    if (l > last) or (r < first) then exit;
    if (l >= first) and (r <= last) then begin
        Res:=max(Res,max(pre+F[k].left,F[k].all));
        pre:=max(pre+F[k].sum,F[k].right);
        exit;
    end;
    mid:=(l+r) shr 1;
    GetF(k shl 1,l,mid);
    GetF((k shl 1)+1,mid+1,r);
end;
{---------------------------------------------------------------------------}
procedure   Init;
var
    i,j:longint;
begin
    read(fi,N);
    for i:=1 to 8*N do begin
        F[i].sum:=0;
        F[i].all:=0;
        F[i].left:=0;
        F[i].right:=0;
    end;
    for i:=1 to N do begin
        pos:=i;
        read(fi,value);
        UpdateF(1,1,N);
    end;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i:longint;
begin
    read(fi,M);
    for i:=1 to M do begin
        read(fi,first,last);
        Res:=-MAX_INT;  pre:=-MAX_INT;
        GetF(1,1,N);
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