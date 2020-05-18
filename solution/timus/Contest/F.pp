const
    INPUT = 'F.inp';
    OUTPUT = 'F.out';
    MAX_N = 300;

type
    pTrie = ^recTrie;
    recTrie = record
        link:array['1'..'4'] of pTrie;
        f:longint;
    end;

    str = string[16];

var
    fi,fo:text;
    S:str;
    root:pTrie;
    front,rear:longint;
    queue:array[0..MAX_N] of str;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j,k:longint;
begin
    S:='';
    for i:=1 to 4 do
        for j:=1 to 4 do begin
            read(fi,k);
            S:=S+chr(ord(k+48));
        end;
end;
{---------------------------------------------------------------------------}
function    check(var s:str):boolean;
begin
    if (s[1] <> s[2]) or (s[2] <> s[5]) or (s[5] <> s[6]) then exit(false);
    if (s[3] <> s[4]) or (s[4] <> s[7]) or (s[7] <> s[8]) then exit(false);
    if (s[9] <> s[10]) or (s[10] <> s[13]) or (s[13] <> s[14]) then exit(false);
    if (s[11] <> s[12]) or (s[12] <> s[15]) or (s[15] <> s[16]) then exit(false);
    if (s[1] = '1') and (s[3] = '2') and (s[11] = '3') and (s[9] = '4') then exit(true);
    if (s[1] = '2') and (s[3] = '3') and (s[11] = '4') and (s[9] = '1') then exit(true);
    if (s[1] = '3') and (s[3] = '4') and (s[11] = '1') and (s[9] = '2') then exit(true);
    if (s[1] = '4') and (s[3] = '1') and (s[11] = '2') and (s[9] = '3') then exit(true);
    exit(false);
end;
{---------------------------------------------------------------------------}
procedure   init(var p:pTrie);
var
    ch:char;
begin
    new(p);
    for ch:='1' to '4' do
        p^.link[ch]:=nil;
    p^.f:=0;
end;
{---------------------------------------------------------------------------}
procedure   add(var s:str;   d:longint);
var
    p:pTrie;
    i:longint;
begin
    p:=root;
    for i:=1 to length(s) do begin
        if p^.link[s[i]] = nil then
            init(p^.link[s[i]]);
        p:=p^.link[s[i]];
    end;
    p^.f:=d;
end;
{---------------------------------------------------------------------------}
function    search(var s:str):longint;
var
    p:pTrie;
    i:longint;
begin
    p:=root;
    for i:=1 to length(s) do
        if p^.link[s[i]] = nil then exit(-1)
        else p:=p^.link[s[i]];
    exit(p^.f);
end;
{---------------------------------------------------------------------------}
procedure   swap(var x,y,z,t:char);
var
    tmp:char;
begin
    tmp:=x;
    x:=y;
    y:=z;
    z:=t;
    t:=tmp;
end;
{---------------------------------------------------------------------------}
procedure   xoay(var s:str;  types,direct:longint;   var t:str);
begin
    t:=s;
    case types of
        1:  if direct = 1 then swap(t[2],t[8],t[15],t[9])
            else swap(t[9],t[15],t[8],t[2]);
        2:  if direct = 1 then swap(t[3],t[12],t[14],t[5])
            else swap(t[5],t[14],t[12],t[3]);
        3:  if direct = 1 then swap(t[6],t[7],t[11],t[10])
            else swap(t[10],t[11],t[7],t[6]);
        4:  if direct = 1 then swap(t[1],t[4],t[16],t[13])
            else swap(t[13],t[16],t[4],t[1]);
    end;
end;
{---------------------------------------------------------------------------}
procedure   add_to_queue(var s:str;  d:longint);
begin
    if search(s) > -1 then exit;
    inc(rear);
    queue[rear]:=s;
    add(s,d);
end;
{---------------------------------------------------------------------------}
procedure   solve(S:str);
var
    tmp:str;
    d:longint;
begin
    init(root);
    front:=1;   rear:=0;
    add_to_queue(S,0);
    repeat
        S:=queue[front];    inc(front);
        d:=search(S)+1;
        xoay(S,1,1,tmp);    add_to_queue(tmp,d);
        xoay(S,1,2,tmp);    add_to_queue(tmp,d);
        xoay(S,2,1,tmp);    add_to_queue(tmp,d);
        xoay(S,2,2,tmp);    add_to_queue(tmp,d);
        xoay(S,3,1,tmp);    add_to_queue(tmp,d);
        xoay(S,3,2,tmp);    add_to_queue(tmp,d);
        xoay(S,4,1,tmp);    add_to_queue(tmp,d);
        xoay(S,4,2,tmp);    add_to_queue(tmp,d);
    until (check(S) = true) or (front > rear);
    writeln(fo,d-1);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve(S);
    close(fo);
    close(fi);
end.