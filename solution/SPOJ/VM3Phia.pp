const
    INPUT = 'VM3Phia.inp';
    OUTPUT = 'VM3Phia.out';
    MAX_N = 210;
    MAX_M = 2*sqr(MAX_N);

type
    recEdge = record
        x,y:longint;
    end;

var
    fi,fo:text;
    N,M:longint;
    e:array[0..MAX_M] of recEdge;
    head,setID:array[0..MAX_N] of longint;
    link:array[0..MAX_M] of longint;

{---------------------------------------------------------------------------}
procedure   add_edge(u,v:longint);  inline;
begin
    inc(M);
    e[M].x:=u;  e[M].y:=v;
    link[M]:=head[u];
    head[u]:=M;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j,u,v:longint;
begin
    readln(fi,N,j);
    for i:=1 to N do head[i]:=0;
    M:=0;
    for i:=1 to j do begin
        readln(fi,u,v);
        if u <> v then begin
            add_edge(u,v);
            add_edge(v,u);
        end;
    end;
end;
{---------------------------------------------------------------------------}
procedure   push_to_set(id,u:longint);
var
    i:longint;
begin
    setID[u]:=id;
    i:=head[u];
    while i <> 0 do begin
        if setID[e[i].y] = 0 then setID[e[i].y]:=-1;
        i:=link[i];
    end;
    for u:=1 to N do
        if setID[u] = 0 then setID[u]:=id
        else
            if setID[u] = -1 then setID[u]:=0;
end;
{---------------------------------------------------------------------------}
procedure   pop_from_set(id,u:longint);
var
    i:longint;
begin
    i:=head[u];
    while i <> 0 do begin
        if setID[e[i].y] = id then setID[e[i].y]:=0;
        i:=link[i];
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
    check:boolean;
begin
    for i:=1 to N do setID[i]:=0;
    push_to_set(1,1);
    for i:=1 to N do
        if setID[i] = 1 then
            pop_from_set(1,i);
    for i:=1 to N do
        if setID[i] = 0 then begin
            push_to_set(2,i);
            break;
        end;
    for i:=1 to N do
        if setID[i] = 2 then
            pop_from_set(2,i);
    check:=false;
    for i:=1 to N do
        if setID[i] = 0 then begin
            setID[i]:=3;
            check:=true;
        end;
    if check = false then setID[1]:=3;
end;
{---------------------------------------------------------------------------}
procedure   print_result;
var
    i:longint;
begin
    for i:=1 to N do
        write(fo,setID[i]);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    print_result;
    close(fo);
    close(fi);
end.
