const
    INPUT = 'NKMOU.inp';
    OUTPUT = 'NKMOU.out';
    MAX_N = 20000;
    IT_SIZE = 8*MAX_N;

type
    recIT = record
        value:longint;
        leaf:boolean;
    end;

var
    fi,fo:text;
    N,H,first,last,newValue,Res,sum:longint;
    IT:array[1..IT_SIZE] of recIT;
    check:boolean;

{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   GetLeaf(k,value:longint);
begin
    IT[k].leaf:=true;
    IT[k].value:=value;
end;
{---------------------------------------------------------------------------}
procedure   UpdateIT(k,l,r:longint);
var
    mid:longint;
begin
    if (l > r) or (first > last) then exit;
    if (l > last) or (r < first) then exit;
    if (l >= first) and (r <= last) then begin
        GetLeaf(k,newValue);
        exit;
    end;
    mid:=(l+r) shr 1;
    if IT[k].leaf = true then begin
        IT[k].leaf:=false;
        GetLeaf(k shl 1,IT[k].value);
        GetLeaf((k shl 1)+1,IT[k].value);
    end;
    UpdateIT(k shl 1,l,mid);
    UpdateIT((k shl 1)+1,mid+1,r);
end;
{---------------------------------------------------------------------------}
procedure   GetIT(k,l,r:longint);
var
    mid,t:longint;
begin
    if (l > r) or (check = false) then exit;
    if IT[k].leaf = true then begin
        if IT[k].value <= 0 then begin
            Res:=Res+r-l+1;
            sum:=sum+(r-l+1)*IT[k].value;
        end
        else begin
            t:=(H-sum) div IT[k].value;
            if t > r-l+1 then t:=r-l+1;
            if t > 0 then begin
                Res:=Res+t;
                sum:=sum+t*IT[k].value;
            end
            else check:=false;
        end;
        exit;
    end;
    mid:=(l+r) shr 1;
    GetIT(k shl 1,l,mid);
    GetIT((k shl 1)+1,mid+1,r);
end;
{---------------------------------------------------------------------------}
procedure   Init;
begin
    readln(fi,N);
    first:=1;   last:=N;
    newValue:=0;
    UpdateIT(1,1,N);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    ch:char;
    i,j:longint;
begin
    repeat
        read(fi,ch);
        if ch = 'I' then begin
            readln(fi,first,last,newValue);
            UpdateIT(1,1,N);
        end
        else
            if ch = 'Q' then begin
                readln(fi,H);
                Res:=0; sum:=0;
                check:=true;
                GetIT(1,1,N);
                writeln(fo,Res);
            end;
    until ch = 'E';
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
