const
    INPUT = '83C.inp';
    OUTPUT = '83C.out';
    MAX_N = 60;
    MAX_M = 60;
    MAX_ID = 15000;
    MAX_QUEUE = 10000000;

type
    pTrie = ^recTrie;
    recTrie = record
        link:array['a'..'z'] of pTrie;
    end;

    pQueue = ^recQueue;
    recQueue = record
        i,j:longint;
        d:longint;
        count:longint;
        used:array['a'..'z'] of boolean;
        trace:ansiString;
        next:pQueue;
    end;

var
    fi,fo:text;
    N,M,K,Si,Sj:longint;
    a:array[0..MAX_N,0..MAX_M] of char;
    first,last:pQueue;
    root:array[0..MAX_N,0..MAX_M] of pTrie;
    res:ansiString;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,N,M,K);
    for i:=1 to N do begin
        for j:=1 to M do begin
            read(fi,a[i,j]);
            if a[i,j] = 'S' then begin
                Si:=i;
                Sj:=j;
            end;
        end;
        readln(fi);
    end;
end;
{---------------------------------------------------------------------------}
procedure   new_node(var p:pTrie);
var
    ch:char;
begin
    new(p);
    for ch:='a' to 'z' do
        p^.link[ch]:=nil;
end;
{---------------------------------------------------------------------------}
function    check(q:pQueue):boolean;
var
    t:longint;
    ch:char;
    s:string;
    p:pTrie;
    c:boolean;
begin
    s:='';
    with q^ do begin
        for ch:='a' to 'z' do
            if used[ch] then s:=s+ch;
        if s = '' then exit(true);
        p:=root[i,j];
        writeln('-----------------> ',s,' ',p^.link[s[1]] = nil,' ',p = root[1,2],' ',i,' ',j);
    end;
    c:=false;
    for t:=1 to length(s) do begin
        if p^.link[s[t]] = nil then begin
            new_node(p^.link[s[t]]);
            c:=true;
        end;
        p:=p^.link[s[t]];
    end;
    writeln('                         ',c);
    exit(c);
end;
{---------------------------------------------------------------------------}
procedure   push(x,y:longint;   q:pQueue);
var
    p:pQueue;
begin
    if (x < 1) or (y < 1) or (x > N) or (y > M) or (a[x,y] = 'S') then exit;
    p^:=q^;
    with p^ do begin
        i:=x;   j:=y;
        writeln('     ',i,' ',j);
        inc(d);
        if a[x,y] <> 'T' then begin
            if not used[a[x,y]] then
                if count = K then exit
                else begin
                    used[a[x,y]]:=true;
                    inc(count);
                end;
            if check(p) = false then exit;
            trace:=trace+a[x,y];
        end;
    end;
    p^.next:=nil;
    last^.next:=p;
    last:=p;
    writeln('                push ',x,' ',y);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j:longint;
    ch:char;
    s:ansiString;
    p:pQueue;
begin
    res:='-1';
    for i:=1 to MAX_N do
        for j:=1 to MAX_M do
            new_node(root[i,j]);
    new(first);
    with first^ do begin
        i:=Si;  j:=Sj;
        d:=0;
        count:=0;
        for ch:='a' to 'z' do used[ch]:=false;
        trace:='';
        next:=nil;
    end;
    last:=first;

    repeat
        i:=first^.i;  j:=first^.j;
        writeln(i,' ',j);
            push(i+1,j,first);
            push(i-1,j,first);
            push(i,j+1,first);
            push(i,j-1,first);
        s:=first^.trace;
        if a[i,j] = 'T' then
            if (res = '-1') or (length(s) < length(res)) or ((length(s) = length(res)) and (s < res)) then res:=s;
        p:=first;
        writeln(first^.next = first);
        first:=first^.next;
        writeln(first^.next = first,' ',first = nil);
        {if first <> nil then first^.pre:=nil;}
        readln;
    until first = nil;
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
