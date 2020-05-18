const
    INPUT = 'SmartDog.inp';
    OUTPUT = 'SmartDog.out';
    MAX_N = 100000;

type
    pF = ^recF;
    recF = record
        id,value:longint;
        next:pF;
    end;

var
    fi,fo:text;
    N,K:longint;
    x,y,c:array[0..MAX_N] of longint;
    root:pF;


{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,N,K);
    for i:=1 to N do
        readln(fi,x[i],y[i],c[i]);
end;
{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;   inline;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
function    distance(i,j:longint):longint;   inline;
begin
    exit(abs(x[i]-x[j])+abs(y[i]-y[j]));
end;
{---------------------------------------------------------------------------}
function    find(var p:pF):longint;
var
    q:pF;
begin
    q:=root;
    while q <> nil do begin
        if distance(q^.id,p^.id) <= K then
            exit(q^.value+c[p^.id]);
        q:=q^.next;
    end;
    exit(-1);
end;
{---------------------------------------------------------------------------}
procedure   insert(var p:pF);
var
    q:pF;
begin
    if p^.value >= root^.value then begin
        p^.next:=root;
        root:=p;
        exit;
    end;
    q:=root;
    while (q^.next <> nil) and (q^.next^.value > p^.value) do
        q:=q^.next;
    p^.next:=q^.next;
    q^.next:=p;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,res:longint;
    p:pF;
begin
    res:=0;
    x[0]:=0;    y[0]:=0;    c[0]:=0;
    new(root);
    root^.id:=0;
    root^.value:=0;
    root^.next:=nil;
    for i:=1 to N do begin
        new(p);
        p^.id:=i;
        p^.value:=find(p);
        if p^.value <> -1 then begin
            insert(p);
            res:=max(res,p^.value);
        end;
    end;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
