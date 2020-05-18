const
    INPUT = '114D.inp';
    OUTPUT = '114D.out';
    MAX_N = 2001;
    MAX_nNode = 10000;

type
    recTrie = record
        turn,link:longint;
        is_word:boolean;
    end;

var
    fi,fo:text;
    T,Sbegin,Send:ansiString;
    N,Nb,Ne,nNode,crrTurn:longint;
    trie:array[0..MAX_nNode,'a'..'z'] of recTrie;

{---------------------------------------------------------------------------}
procedure   enter;
begin
    readln(fi,T);
    readln(fi,Sbegin);
    readln(fi,Send);
end;
{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   add(var x:ansiString);
var
    i,p:longint;
begin
    p:=0;
    for i:=1 to length(x) do
        with trie[p][x[i]] do begin
            if turn <> crrTurn then begin
                inc(nNode);
                link:=nNode;
                turn:=crrTurn;
            end;
            p:=link;
        end;
    trie[p][x[i]].is_word:=true;
end;
{---------------------------------------------------------------------------}
function    search(var x:ansiString):boolean;
var
    i,p:longint;
begin
    p:=0;
    for i:=1 to length(x) do
        with trie[p][x[i]] do begin
            if turn <> crrTurn then exit(false);
            p:=link;
        end;
    exit(trie[p][x[i]].is_word);
end;
{---------------------------------------------------------------------------}
function    check(var x:ansiString):boolean;
var
    i,j:longint;
begin
    for i:=1 to Nb do
        if x[i] <> Sbegin[i] then exit(false);
    i:=length(x);
    for j:=Ne downto 1 do begin
        if x[i] <> Send[j] then exit(false);
        dec(i);
    end;
    exit(not search(x));
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i:longint;
    ch:char;
begin
    N:=length(T);
    Nb:=length(Sbegin);
    Ne:=length(Send);
    for i:=0 to MAX_nNode do
        for ch:='a' to 'z' do
            with trie[i][ch] do begin
                turn:=0;
                is_word:=false;
            end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,l,count:longint;
    x:ansiString;
begin
    count:=0;
    for l:=max(Nb,Ne) to N do begin
        nNode:=0;
        crrTurn:=l;
        x:=' '+copy(T,1,l-1);
        for i:=l to N do begin
            delete(x,1,1);
            x:=x+T[i];
            if check(x) = true then begin
                inc(count);
                add(x);
            end;
        end;
    end;
    writeln(fo,count);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init;
    solve;
    close(fo);
    close(fi);
end.
