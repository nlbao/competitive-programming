const
    INPUT = 'NKCity.inp';
    OUTPUT = 'NKCity.out';
    MAX_N = 1000;
    MAX_M = 10000;

type
    recE = record
        u,v,w:longint;
        mark:boolean;
    end;

var
    N,M,Res:longint;
    E:array[1..MAX_M] of recE;
    parent:array[1..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,M);
    for i:=1 to M do
        begin
            readln(fi,E[i].u,E[i].v,E[i].w);
            E[i].mark:=false;
        end;
    close(fi);
end;
{---------------------------------------------------------------------------}
procedure   Quick_sort(l,r:longint);
var
    i,j,p:longint;
    tmp:recE;
begin
    i:=l;   j:=r;
    p:=E[(i+j) div 2].w;
    repeat
        while E[i].w < p do inc(i);
        while E[j].w > p do dec(j);
        if i <= j then
            begin
                tmp:=E[i];  E[i]:=E[j]; E[j]:=tmp;
                inc(i); dec(j);
            end;
    until i >= j;
    if l < j then Quick_sort(l,j);
    if i < r then Quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
function    GetRoot(u:longint):longint;
begin
    if parent[u] < 0 then exit(u)
    else
        begin
            parent[u]:=GetRoot(parent[u]);
            exit(parent[u]);
        end;
end;
{---------------------------------------------------------------------------}
procedure   Union(r1,r2:longint);
var
    tmp:longint;
begin
    tmp:=parent[r1]+parent[r2];
    if r1 > r2 then
        begin
            parent[r1]:=r2;
            parent[r2]:=tmp;
        end
    else
        begin
            parent[r2]:=r1;
            parent[r1]:=tmp;
        end;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,count,r1,r2:longint;
    connected:boolean;
begin
    connected:=false;
    count:=0;
    for i:=1 to N do parent[i]:=-1;
    for i:=1 to M do
        begin
            r1:=GetRoot(E[i].u);    r2:=GetRoot(E[i].v);
            if r1 <> r2 then
                begin
                    inc(count);
                    E[i].mark:=true;
                    Union(r1,r2);
                    if count = N-1 then
                        begin
                            connected:=true;
                            break;
                        end;
                end;
        end;
    if not connected then Res:=-1
    else
        for i:=M downto 1 do
            if E[i].mark = true then
                begin
                    Res:=E[i].w;
                    break;
                end;
end;
{---------------------------------------------------------------------------}
procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,Res);
    close(fo);
end;
{---------------------------------------------------------------------------}

begin
    Enter;
    Quick_sort(1,M);
    Solve;
    Print_result;
end.