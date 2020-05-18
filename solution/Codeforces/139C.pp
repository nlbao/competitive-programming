const   MAX_N = 2510;

type    myStr = ansiString;

var fi,fo:text;
    n,k:longint;
    s:array[0..4*MAX_N] of myStr;

function    is_vowel(ch:char):boolean;
begin
    case ch of
        'a','e','i','o','u': exit(true);
    end;
    exit(false);
end;

procedure   enter;
var i,j,p:longint;
begin
    readln(fi,n,k);
    for i:=1 to 4*n do begin
        readln(fi,s[i]);
        p:=0;
        for j:=length(s[i]) downto 1 do
            if is_vowel(s[i][j]) then begin
                inc(p);
                if p = k then break;
            end;
        if p = k then delete(s[i],1,j-1)
        else s[i]:='';
    end;
end;

function    cmp(a,b:myStr):boolean;
begin
    if (a = '') or (b = '') then exit(false);
    if (a = 'aaaa') or (b = 'aaaa') then exit(true);
    if a = b then exit(true);
    exit(false);
end;

function    cal(var x,y,z,t:myStr):myStr;
begin
    if (cmp(x,t)) and (cmp(y,z)) then begin
        if cmp(x,y) then exit('aaaa')
        else exit('abba');
    end;
    if (cmp(x,z)) and (cmp(y,t)) then exit('abab');
    if (cmp(x,y)) and (cmp(z,t)) then exit('aabb');
    exit('');
end;

function    solve:ansiString;
var i:longint;
    x:myStr;
    p:array[0..MAX_N] of myStr;
begin
    for i:=1 to n do p[i]:=cal(s[4*i-3],s[4*i-2],s[4*i-1],s[4*i]);
    x:=p[1];
    if x = '' then exit('NO');
    for i:=2 to n do begin
        if not cmp(x,p[i]) then exit('NO');
        if p[i] <> 'aaaa' then x:=p[i];
    end;
    exit(x);
end;


begin
    assign(fi,'139C.in');   reset(fi);
    assign(fo,'139C.out');  rewrite(fo);
    enter;
    writeln(fo,solve);
    close(fo);
    close(fi);
end.