const   INPUT = 'Beads.in';
        OUTPUT = 'Beads.out';
        MAX_N = 10010;

var fi,fo:text;
    s:array[0..MAX_N] of char;
    nTest,n:longint;

{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i:longint;
    s0:ansiString;
begin
    readln(fi,s0);
    n:=length(s0);
    for i:=1 to n do s[i-1]:=s0[i];
end;
{---------------------------------------------------------------------------}
procedure   solve;
var min,p,len,i,j:longint;
begin
    min:=0; p:=1;
    len:=0;
    while (p < n) and (min+len+1 < n) do begin
        i:=min+len;
        j:=(p+len) mod n;
        if s[i] = s[j] then inc(len)
        else if s[i] < s[j] then begin
            p:=p+len+1;
            len:=0;
        end
        else begin
            min:=max(min+len+1,p);
            p:=min+1;
            len:=0;
        end;
    end;
    writeln(fo,min+1);
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