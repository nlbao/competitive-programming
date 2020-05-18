const   INPUT = 'MinMove.in';
        OUTPUT = 'MinMove.out';
        MAX_N = 100010;

type    str = ansiString;

var fi,fo:text;
    s:array[0..MAX_N] of char;
    n:longint;

{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i:longint;
    s0:str;
begin
    readln(fi,s0);
    n:=length(s0);
    for i:=1 to n do s[i-1]:=s0[i];
    end;
{---------------------------------------------------------------------------}
procedure   solve;  {Dijkstra's EWDs}
var min,p,len,i,j:longint;
begin
    min:=0; {vi tri bat dau res}
    p:=1;   {vi tri tu 0 -> p-1 da xet xong}
    len:=0; { s[p -> (p+len-1)]  =  s[min -> (min+len-1)] }
                                                {p luon > min}
    while (p < n) and (min+len+1 < n) do begin  {gioi han de min khong > n trong TH 3}
        i:=min+len;
        j:=(p+len) mod n;
        if s[i] = s[j] then inc(len)
        else if s[i] < s[j] then begin
            p:=p+len+1;     {s[min] < s[min+1], s[min+2],..., s[i]}
            len:=0;         {s[p] = s[min], s[p+1] = s[min+1], ..., s[i-1] = s[j-1]}
        end
        else begin
            min:=max(min+len+1,p);  {p < min+len+1 => s[min] < s[p] => khong chon p}
            p:=min+1;
            len:=0;
        end;
    end;
    writeln(fo,min);
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