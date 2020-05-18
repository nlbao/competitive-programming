const
    INPUT = '';
    OUTPUT = '';
    MAX_N = 1000;

type
    pX = ^recX;
    recX = record
        id:longint;
        next:pX;
    end;

var
    N:longint;
    A:array[1..MAX_N,1..MAX_N] of longint;
    first,last:pX;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    fi:text;
    i,j:longint;
    ch:char;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    for i:=1 to N do
        begin
            for j:=1 to N do
                begin
                    read(fi,ch);
                    A[i,j]:=ord(ch)-48;
                end;
            readln(fi);
        end;
    close(fi);
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    p,q,x:pX;
    i:longint;
    avail:boolean;
begin
    New(p);
    p^.id:=1;
    p^.next:=nil;
    first:=p;   last:=p;
    for i:=2 to N do
        begin
            avail:=true;
            New(x);
            x^.id:=i;
            p:=first;
            while p^.next <> nil do
                begin
                    q:=p^.next;
                    if (A[p^.id,i] = 1) and (A[i,q^.id] = 1) then
                        begin
                            x^.next:=q;
                            p^.next:=x;
                            avail:=false;
                            break;
                        end;
                    p:=q;
                end;
            if avail then
                if A[i,first^.id] = 1 then
                    begin
                        x^.next:=first;
                        first:=x;
                    end
                else
                    begin
                        x^.next:=nil;
                        last^.next:=x;
                        last:=x;
                    end;
        end;
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    fo:text;
    p:pX;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    p:=first;
    while p <> nil do
        begin
            write(fo,p^.id,' ');
            p:=p^.next;
        end;
    close(fo);
end;
{---------------------------------------------------------------------------}

begin
    Enter;
    Solve;
    Print_result;
end.
