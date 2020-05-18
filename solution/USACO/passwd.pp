{
    ID: storm59061
    PROB: passwd
    LANG: PASCAL
}

const   INPUT = 'passwd.in';
        OUTPUT = 'passwd.out';
        MAX_L = 15;
        MAX_C = 26;
        MAX_NRES = 25000;

var fi,fo:text;
    setVowel:set of char = ['a','e','i','o','u'];
    l,c,nRes:longint;
    a:array[0..MAX_C] of char;
    s:string;

{---------------------------------------------------------------------------}
procedure   enter;
var i,j:longint;
    tmp:char;
begin
    readln(fi,l,c);
    for i:=1 to c do begin
        read(fi,a[i]);
        read(fi,tmp);
    end;
    for i:=1 to c-1 do
        for j:=i+1 to c do
            if a[i] > a[j] then begin
                tmp:=a[i];
                a[i]:=a[j];
                a[j]:=tmp;
            end;
end;
{---------------------------------------------------------------------------}
function    check(var s:string):boolean;
var i,nVowel:longint;
begin
    nVowel:=0;
    for i:=1 to length(s) do
        if s[i] in setVowel then inc(nVowel);
    if (nVowel >= 1) and (length(s)-nVowel >= 2) then exit(true);
    exit(false);
end;
{---------------------------------------------------------------------------}
procedure   sinh(i,pos:longint);
var j:longint;
begin
    if nRes = MAX_NRES then exit;
    if i > l then begin
        if check(s) = true then begin
            inc(nRes);
            writeln(fo,s);
        end;
        exit;
    end;
    for j:=pos+1 to c do begin
        s:=s+a[j];
        sinh(i+1,j);
        delete(s,i,1);
    end;
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i:longint;
begin
    nRes:=0;
    s:='';
    sinh(1,0);
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