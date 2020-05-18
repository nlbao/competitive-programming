const   INPUT = 'C.in';
        OUTPUT = 'C.out';
        MAX_nTest = 15;
        MAX_N = 25;
        MAX_M = 115;

type    pList = ^recList;
        recList = record
            id:longint;
            link:pList;
        end;

var fi,fo:text;
    nTest,n,m:longint;
    list:array[0..MAX_N] of pList;
    s:array[0..MAX_M] of longint;
    count:array[0..MAX_M,0..1] of longint;
    res:char;

{---------------------------------------------------------------------------}
procedure   add_list(i,x:longint);
var p:pList;
begin
    new(p);
    p^.id:=x;
    p^.link:=list[i];
    list[i]:=p;
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i,j:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do list[i]:=nil;
    for i:=1 to m do begin
        s[i]:=0;
        while not eoln(fi) do begin
            read(fi,j);
            add_list(j,i);
            inc(s[i]);
        end;
        readln(fi);
    end;
end;
{---------------------------------------------------------------------------}
procedure   tang(i,color,value:longint);
var p:pList;
begin
    p:=list[i];
    while p <> nil do
        with p^ do begin
            count[id][color]:=count[id][color]+value;
            p:=link;
        end;
end;
{---------------------------------------------------------------------------}
function    check(i:longint):boolean;
var p:pList;
    sum:longint;
begin
    p:=list[i];
    while p <> nil do
        with p^ do begin
            sum:=count[id][0]+count[id][1];
            if sum > s[id] then exit(false);
            if (sum = s[id]) and ((count[id][0] = 0) or (count[id][1] = 0)) then exit(false);
            p:=link;
        end;
    exit(true);
end;
{---------------------------------------------------------------------------}
procedure   tryF(i:longint);
var j:longint;
begin
    if res = 'Y' then exit;
    if i > n then begin
        res:='Y';
        exit;
    end;
    for j:=0 to 1 do begin
        tang(i,j,1);
        if check(i) = true then tryF(i+1);
        tang(i,j,-1);
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i:longint;
begin
    res:='N';
    for i:=1 to m do begin
        count[i][0]:=0;
        count[i][1]:=0;
    end;
    tryF(1);
    write(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.