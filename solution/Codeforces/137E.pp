const   INPUT = '137E.in';
        OUTPUT = '137E.out';
        MAX_N = 200010;
        MAX_INT = 1000000000;

var fi,fo:text;
    s:ansiString;
    n,i,j,t,res,c:longint;
    g,q:array[0..MAX_N] of longint;

function    is_vowel(c:char):boolean;
begin
    case upcase(c) of
        'A','E','I','O','U': exit(true);
        else exit(false);
    end;
end;

function    find(x:longint):longint;
var j,l,r,mid:longint;
begin
    j:=MAX_INT;
    l:=0;   r:=t;
    while l <= r do begin
        mid:=(l+r) shr 1;
        if g[q[mid]] > x then l:=mid+1
        else begin
            j:=q[mid];
            r:=mid-1;
        end;
    end;
    exit(j);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,s);
    n:=length(s);
    g[0]:=0;
    for i:=1 to n do
        if is_vowel(s[i]) then g[i]:=g[i-1]-1
        else g[i]:=g[i-1]+2;
    res:=-1;    c:=0;
    t:=0;   q[0]:=0;
    for i:=1 to n do
        if g[i] < g[q[t]] then begin
            inc(t);
            q[t]:=i;
        end
        else begin
            j:=find(g[i]);
            if i-j > res then begin
                res:=i-j;
                c:=1;
            end
            else if i-j = res then inc(c);
        end;
    if res = -1 then writeln(fo,'No solution')
    else writeln(fo,res,' ',c);
    close(fo);
    close(fi);
end.