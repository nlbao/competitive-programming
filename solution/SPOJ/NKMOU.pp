const
    INPUT = 'NKMOU_2.inp';
    OUTPUT = 'NKMOU_2.out';
    MAX_N = 1000000000;

type
    pIT = ^recIT;
    recIT = record
        leaf:boolean;
        value:longint;
        left,right:pIT;
    end;

var
    fi,fo:text;
    N,H,newValue,Res,sum:longint;
    Root:pIT;
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
procedure   RemoveIT(var p:pIT);
begin
    if p = nil then exit;
    RemoveIT(p^.left);
    RemoveIT(p^.right);
    dispose(p);
    p:=nil;
end;
{---------------------------------------------------------------------------}
procedure   GetLeaf(var p:pIT;  value:longint);
begin
    if p = nil then begin
        new(p);
        p^.left:=nil;   p^.right:=nil;
    end
    else begin
        RemoveIT(p^.left);
        RemoveIT(p^.right);
    end;
    p^.leaf:=true;
    p^.value:=value;
end;
{---------------------------------------------------------------------------}
procedure   UpdateIT(var p:pIT;   l,r,i,j:longint);
var
    mid:longint;
begin
    if (l > r) or (i > j) then exit;
    if (l = i) and (r = j) then begin
        GetLeaf(p,newValue);
        exit;
    end;
    mid:=(l+r) shr 1;
    if p^.leaf = true then begin
        p^.leaf:=false;
        GetLeaf(p^.left,p^.value);
        GetLeaf(p^.right,p^.value);
    end;
    if i <= mid then
        UpdateIT(p^.left,l,mid,i,min(j,mid));
    if j > mid then
        UpdateIT(p^.right,mid+1,r,max(i,mid+1),j);
end;
{---------------------------------------------------------------------------}
procedure   GetIT(p:pIT;    l,r:longint);
var
    mid,t:longint;
begin
    if (l > r) or (check = false) then exit;
    if p^.leaf = true then begin
        if p^.value <= 0 then begin
            Res:=Res+r-l+1;
            sum:=sum+(r-l+1)*p^.value;
        end
        else begin
            t:=(H-sum) div p^.value;
            if t > r-l+1 then t:=r-l+1;
            if t > 0 then begin
                Res:=Res+t;
                sum:=sum+t*p^.value;
            end
            else check:=false;
        end;
        exit;
    end;
    mid:=(l+r) shr 1;
    GetIT(p^.left,l,mid);
    GetIT(p^.right,mid+1,r);
end;
{---------------------------------------------------------------------------}
procedure   Init;
begin
    readln(fi,N);
    Root:=nil;
    GetLeaf(Root,0);
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
            readln(fi,i,j,newValue);
            UpdateIT(Root,1,N,i,j);
        end
        else
            if ch = 'Q' then begin
                readln(fi,H);
                Res:=0; sum:=0;
                check:=true;
                GetIT(Root,1,N);
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