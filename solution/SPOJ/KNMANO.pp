const
    INPUT = 'KNMANO.inp';
    OUTPUT = 'KNMANO.out';
    MAX_N = 11;

type
    recPoint = record
        x,y:longint;
    end;

var
    fi,fo:text;
    nTest,N,front,rear:longint;
    P,L,T:recPoint;
    avail:array[-MAX_N..MAX_N,-MAX_N..MAX_N] of boolean;
    f:array[0..MAX_N,0..MAX_N] of longint;
    queue:array[0..sqr(MAX_N)] of recPoint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    s:string;
begin
    N:=8;
    readln(fi,s);
    P.x:=ord(s[2])-ord('0');
    P.y:=ord(s[1])-ord('a')+1;
    L.x:=ord(s[5])-ord('0');
    L.y:=ord(s[4])-ord('a')+1;
    T.x:=ord(s[8])-ord('0');
    T.y:=ord(s[7])-ord('a')+1;
end;
{---------------------------------------------------------------------------}
function    check(x,y:longint):boolean; inline;
begin
    if (not avail[x,y]) or (x < 1) or (x > N) or (y < 1) or (y > N) then exit(false);
    exit(true);
end;
{---------------------------------------------------------------------------}
procedure   set_avail(x,y:longint;  value:boolean); inline;
begin
    avail[x-2,y-1]:=value;  avail[x-2,y+1]:=value;
    avail[x-1,y-2]:=value;  avail[x-1,y+2]:=value;
    avail[x+1,y-2]:=value;  avail[x+1,y+2]:=value;
    avail[x+2,y-1]:=value;  avail[x+2,y+1]:=value;
end;
{---------------------------------------------------------------------------}
procedure   push_to_queue(i,j,value:longint); inline;
begin
    inc(rear);
    queue[rear].x:=i;   queue[rear].y:=j;
    f[i,j]:=value+1;
    avail[i,j]:=false;
end;
{---------------------------------------------------------------------------}
procedure   pop_from_queue(var i,j:longint);    inline;
begin
    i:=queue[front].x;  j:=queue[front].y;
    inc(front);
end;
{---------------------------------------------------------------------------}
procedure   add(i,j:longint);
begin
    if check(i-2,j-1) = true then push_to_queue(i-2,j-1,f[i,j]);
    if check(i-2,j+1) = true then push_to_queue(i-2,j+1,f[i,j]);
    if check(i-1,j-2) = true then push_to_queue(i-1,j-2,f[i,j]);
    if check(i-1,j+2) = true then push_to_queue(i-1,j+2,f[i,j]);
    if check(i+1,j-2) = true then push_to_queue(i+1,j-2,f[i,j]);
    if check(i+1,j+2) = true then push_to_queue(i+1,j+2,f[i,j]);
    if check(i+2,j-1) = true then push_to_queue(i+2,j-1,f[i,j]);
    if check(i+2,j+1) = true then push_to_queue(i+2,j+1,f[i,j]);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j:longint;
begin
    for i:=1 to N do
        for j:=1 to N do
            avail[i,j]:=true;
    set_avail(L.x,L.y,false);
    front:=1;   rear:=0;
    i:=P.x; j:=P.y;
    f[i,j]:=0;
    add(i,j);
    if rear = 0 then begin
        writeln(fo,-1);
        exit;
    end;

    set_avail(L.x,L.y,true);
    f[T.x,T.y]:=-1;
    repeat
        pop_from_queue(i,j);
        add(i,j);
        if not avail[T.x,T.y] then break;
    until front = rear+1;
    writeln(fo,f[T.x,T.y]);
end;
{---------------------------------------------------------------------------}
begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    repeat
        enter;
        solve;
        dec(nTest);
    until nTest = 0;
    close(fo);
    close(fi);
end.