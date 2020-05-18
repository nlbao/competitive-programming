const   INPUT = '35C.in';
        OUTPUT = '35C.out';
        MAX_N = 10;
        MAX_M = 10;
        dx:array[1..4] of longint = (0,0,-1,+1);
        dy:array[1..4] of longint = (-1,+1,0,0);

type    pQueue = ^recQueue;
        recQueue = record
            x,y:longint;
            next:pQueue;
        end;

var fi,fo:text;
    n,m:longint;
    first,last:pQueue;
    avail:array[0..MAX_N,0..MAX_M] of boolean;

{---------------------------------------------------------------------------}
procedure   push(i,j:longint);
var p:pQueue;
begin
    if (not avail[i,j]) or (i < 1) or (i > n) or (j < 1) or (j > m) then exit;
    new(p);
    with p^ do begin
        x:=i;   y:=j;
        next:=nil;
    end;
    if first = nil then first:=p
    else last^.next:=p;
    last:=p;
    avail[i,j]:=false;
end;
{---------------------------------------------------------------------------}
procedure   pop(var i,j:longint);
var p:pQueue;
begin
    p:=first;
    i:=p^.x;    j:=p^.y;
    first:=first^.next;
    dispose(p);
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i,k,x,y:longint;
begin
    readln(fi,n,m);
    for x:=1 to n do
        for y:=1 to m do
            avail[x,y]:=true;
    first:=nil; last:=nil;
    readln(fi,k);
    for i:=1 to k do begin
        read(fi,x,y);
        push(x,y);
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,j,k:longint;
begin
    i:=0;   j:=0;
    while first <> nil do begin
        pop(i,j);
        for k:=1 to 4 do
            push(i+dx[k],j+dy[k]);
    end;
    writeln(fo,i,' ',j);
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