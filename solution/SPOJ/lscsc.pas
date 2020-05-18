uses    math;

const   MAX_N = 100005;
        MAX_M = 2*MAX_N;
        oo = 1000000000;

type    ll = int64;

var fi,fo:text;
    n,m,first:longint;
    a:array[0..MAX_M] of ll;



procedure   enter();
var i:longint;
begin
    read(fi,n);
    m:=2*n;
    for i:=1 to m do read(fi,a[i]);
end;

procedure   sort(l,r:longint);
var i,j,p,t:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=a[i];
    i:=l;   j:=r;
    repeat
        while a[i] < p do inc(i);
        while a[j] > p do dec(j);
        if i <= j then begin
            t:=a[i];
            a[i]:=a[j];
            a[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


function    find_left(pos,d:longint):longint;
var i,c:longint;
begin
    c:=0;
    for i:=pos-1 downto 1 do
        if a[i] < a[pos]-d then begin
            first:=pos;
            exit(c);
        end
        else if a[i] = a[pos]-d then begin
            inc(c);
            pos:=i;
        end;
    first:=pos;
    exit(c);
end;

function    find_right(pos,d:longint):longint;
var i,c:longint;
begin
    c:=0;
    for i:=pos+1 to m do
        if a[i] > a[pos]+d then exit(c)
        else if a[i] = a[pos]+d then begin
            inc(c);
            pos:=i;
        end;
    exit(c);
end;

procedure   solve();
var x,y,i,c,d,limit:longint;
begin
    randomize;
    sort(1,m);

    repeat
        x:=random(m-1)+1;
        y:=x+random(m-x)+1;
        d:=a[y]-a[x];
        if d = 0 then begin
            c:=2 + find_left(x,0) + find_right(y,0);
            if c >= n then begin
                writeln(fo,a[first],' ',0);
                exit;
            end;
        end
        else begin
            limit:=trunc(sqrt(d))+1;
            for i:=1 to limit do
                if d mod i = 0 then begin
                    c:=2 + find_left(x,i) + find_right(x,i);
                    if c >= n then begin
                        writeln(fo,a[first],' ',i);
                        exit;
                    end;
                end;
        end;
    until false;
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'LSCSC.in');    reset(fi);
    assign(fo,'LSCSC.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fi);
    close(fo);
end.