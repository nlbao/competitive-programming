const   INPUT = '124C.in';
        OUTPUT = '124C.out';
        MAX_N = 1010;

type    str = ansiString;

var fi,fo:text;
    n:longint;
    s:array[0..MAX_N] of char;
    count:array['a'..'z'] of longint;
    res:str;

{---------------------------------------------------------------------------}
procedure   enter;
var s0:str;
    i:longint;
    ch:char;
begin
    readln(fi,s0);
    for ch:='a' to 'z' do count[ch]:=0;
    n:=length(s0);
    for i:=1 to n do begin
        s[i]:=s0[i];
        inc(count[s[i]]);
    end;
    s[0]:=' ';
end;
{---------------------------------------------------------------------------}
function    find_max:char;
var ch:char;
    maxC:longint;
begin
    maxC:=0;    find_max:=' ';
    for ch:='a' to 'z' do
        if count[ch] > maxC then begin
            maxC:=count[ch];
            find_max:=ch;
        end;
end;
{---------------------------------------------------------------------------}
function    solve:boolean;
var i,j:longint;
    ch:char;
    is_prime:array[0..2*MAX_N] of boolean;
begin
    res:=' ';
    for i:=2 to n do begin
        is_prime[i]:=true;
        res:=res+' ';
    end;
    for i:=2 to n do
        if is_prime[i] then begin
            ch:=find_max;
            if ch = ' ' then exit(false);
            j:=i;
            while j <= n do begin
                if count[ch] = 0 then exit(false);
                if res[j] = ' ' then begin
                    res[j]:=ch;
                    dec(count[ch]);
                end
                else if res[j] <> ch then exit(false);
                inc(j,i);
                is_prime[j]:=false;
            end;
        end;
    res[1]:=find_max;
    exit(true);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    if solve = true then begin
        writeln(fo,'YES');
        writeln(fo,res);
    end
    else writeln(fo,'NO');
    close(fo);
    close(fi);
end.