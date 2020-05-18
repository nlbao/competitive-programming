const   INPUT = '4D.in';
        OUTPUT = '4D.out';
        MAX_N = 5010;

type    recItem = record
            w,h:longint;
            id:longint;
        end;

var fi,fo:text;
    n:longint;
    a:array[0..MAX_N] of recItem;

{---------------------------------------------------------------------------}
procedure   enter;
var i:longint;
begin
    read(fi,n);
    for i:=0 to n do
        with a[i] do begin
            readln(fi,w,h);
            id:=i;
        end;
end;
{---------------------------------------------------------------------------}
procedure   quick_sort(l,r:longint);
var i,j,p1,p2:longint;
    tmp:recItem;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p1:=a[(i+j) div 2].w;
    p2:=a[(i+j) div 2].h;
    repeat
        while (a[i].w < p1) or ((a[i].w = p1) and (a[i].h < p2)) do inc(i);
        while (a[j].w > p1) or ((a[j].w = p1) and (a[j].h > p2)) do dec(j);
        if i <= j then begin
            tmp:=a[i]; a[i]:=a[j];  a[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;
{---------------------------------------------------------------------------}
function    check(i,j:longint):boolean;
begin
    if (a[i].w < a[j].w) and (a[i].h < a[j].h) then exit(true)
    else exit(false);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,j,pos,res:longint;
    f,next:array[0..MAX_N] of longint;
begin
    quick_sort(1,n);
    res:=0; pos:=-1;
    for i:=n downto 1 do begin
        f[i]:=0;    next[i]:=-1;
        if check(0,i) = true then begin
            f[i]:=1;
            for j:=i+1 to n do
                if (check(i,j) = true) and (f[j]+1 > f[i]) then begin
                    f[i]:=f[j]+1;
                    next[i]:=j;
                end;
            if f[i] > res then begin
                res:=f[i];
                pos:=i;
            end;
        end;
    end;
    writeln(fo,res);
    while pos <> -1 do begin
        write(fo,a[pos].id,' ');
        pos:=next[pos];
    end;
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