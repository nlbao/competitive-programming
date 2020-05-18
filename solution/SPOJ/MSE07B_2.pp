const
    INPUT = 'MSE07B.inp';
    OUTPUT = 'MSE07B.out';
    MAX_N = 1000001;
    MAX_HEAP_SIZE = 2*MAX_N;

type
    pCustomer = ^recCustomer;
    recCustomer = record
        x:longint;  {do uu tien}
        id:longint; {chi so khach hang}
        left,right:pCustomer;
    end;

var
    fi,fo:text;
    first,last:pCustomer;

{---------------------------------------------------------------------------}
procedure   insert(var p:pCustomer);
var
    q:pCustomer;
begin
    if (first = nil) or (p^.x < first^.x) then begin
        p^.left:=nil;
        p^.right:=first;
        if last = nil then last:=p
        else
            if last = first then last^.left:=p;
        first:=p;
        exit;
    end;
    q:=first;
    while (q^.right <> nil) and (q^.right^.x < p^.x) do
        q:=q^.right;
    p^.right:=q^.right;
    q^.right:=p;
    p^.left:=q;
    if p^.right = nil then last:=p;
end;
{---------------------------------------------------------------------------}
function    find_max:longint;
var
    p:pCustomer;
begin
    p:=last;
    find_max:=last^.id;
    if last^.left = nil then begin
        first:=nil;
        last:=nil;
    end
    else begin
        last^.left^.right:=nil;
        last:=last^.left;
    end;
    dispose(p);
end;
{---------------------------------------------------------------------------}
function    find_min:longint;
var
    p:pCustomer;
begin
    p:=first;
    find_min:=first^.id;
    if first^.right = nil then begin
        last:=nil;
        first:=nil;
    end
    else begin
        first^.right^.left:=nil;
        first:=first^.right;
    end;
    dispose(p);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    types,i,j:longint;
    p:pCustomer;
begin
    first:=nil;  last:=nil;
    repeat
        read(fi,types);
        if types = 0 then break;
        if types = 1 then begin
            readln(fi,i,j);
            new(p);
            p^.id:=i;   p^.x:=j;
            insert(p);
        end
        else begin
            if first = nil then writeln(fo,0)
            else
                if types = 2 then writeln(fo,find_max)
                else writeln(fo,find_min);
        end;
    until types = 0;
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    solve;
    close(fo);
    close(fi);
end.