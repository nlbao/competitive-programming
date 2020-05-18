const
    INPUT = 'KDiff.inp';
    OUTPUT = 'KDiff.out';
    MAX_N = 300100;
    MAX_INT = 2000000000;

var
    fi,fo:text;
    N,K:longint;
    a,c,f:array[0..MAX_N] of longint;
    front,rear:array[1..2] of longint;
    queue:array[1..2,0..MAX_N] of longint;  {1: min;    2:max}

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,N,K);
    for i:=1 to N do
        read(fi,a[i]);
end;
{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;   inline;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;   inline;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   push(x,id:longint); inline;
begin
    inc(rear[id]);
    queue[id,rear[id]]:=x;
end;
{---------------------------------------------------------------------------}
procedure   tinh_c;
var
    i,j:longint;
begin
    c[0]:=1;
    front[1]:=1;    rear[1]:=0;     queue[1,0]:=0;  queue[1,1]:=0;
    front[2]:=1;    rear[2]:=0;     queue[2,0]:=0;  queue[2,1]:=0;
    for i:=1 to N do begin
        c[i]:=c[i-1]-1;
        for j:=(i-1+c[i-1]) to N do begin
{min_queue}
            if a[j] <= a[queue[1,front[1]]] then rear[1]:=front[1]-1
            else
                while a[j] <= a[queue[1,rear[1]]] do dec(rear[1]);
            push(j,1);
{max_queue}
            if a[j] >= a[queue[2,front[2]]] then rear[2]:=front[2]-1
            else
                while a[j] >= a[queue[2,rear[2]]] do dec(rear[2]);
            push(j,2);
{check}
            if (a[queue[2,front[2]]]-a[queue[1,front[1]]] > K) then break
            else inc(c[i]);
        end;
{pop}
        if queue[1,front[1]] = i then inc(front[1]);
        if queue[2,front[2]] = i then inc(front[2]);
    end;
end;
{---------------------------------------------------------------------------}
procedure   tinh_f;
var
    i:longint;
begin
    f[N+1]:=0;
    f[N]:=1;
    for i:=N-1 downto 1 do
        f[i]:=max(c[i],f[i+1]);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,sum,res:longint;
begin
    tinh_c;
    tinh_f;
    res:=1;
    for i:=1 to N-1 do begin
        sum:=c[i]+f[i+c[i]];
        res:=max(res,sum);
    end;
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
