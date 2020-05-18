const   INPUT = 'NKNL.in';
        OUTPUT = 'NKNL.out';
        MAX_N = 260;

type    arrChar = array[0..MAX_N] of char;
        str = ansiString;

var fi,fo:text;
    s:str;
    n,res:longint;
    t:array[0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var i:longint;
begin
    readln(fi,s);
    n:=length(s);
end;
{---------------------------------------------------------------------------}
function    KMP_table(var w:str;    nW,pos:longint):longint;
var i,j,k:longint;
    check:boolean;
begin
    t[pos]:=0;
    j:=0;
    for i:=pos+1 to nW do begin
        while (j > 0) and (w[pos+j] <> w[i]) do begin
            if w[pos+j] > w[i] then exit(i-j);
            j:=t[pos+j-1];
        end;
        if w[pos+j] > w[i] then exit(i-j);
        if w[pos+j] = w[i] then inc(j);
        t[i]:=j;
        {writeln(pos,' ',i,' ',j);}
        check:=true;
        if j > 0 then begin
            k:=1;
            while pos+t[i]-1+k <= i do begin
                if w[pos+t[i]-1+k] > w[pos+k-1] then begin
                    check:=false;
                    break;
                end;
                inc(k);
            end;
        end;
        if (check = true) and (i-pos+1 >= 5) then begin
            inc(res);
            writeln(pos,' ',i);
        end;
    end;
    exit(pos+1);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i:longint;
begin
    res:=0;
    i:=1;
    while i <= n do i:=KMP_table(s,n,i);
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