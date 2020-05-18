uses    math;

const   MAX_N = 100010;
        MAX_X = 1000010;
        oo = 1000000000;

var fi,fo:text;
    n,d,l,r,aa,bb,res:longint;
    a,b,q:array[0..MAX_X] of longint;

procedure   enter;
var i,x,y:longint;
begin
    for i:=0 to MAX_X do begin
        a[i]:=oo;
        b[i]:=-oo;
    end;
    readln(fi,n,d);
    for i:=1 to n do begin
        readln(fi,x,y);
        a[x]:=min(a[x],y);
        b[x]:=max(b[x],y);
    end;
end;

procedure   push(i:longint);
begin
    while (r >= l) and (a[q[r]] >= a[i]) do dec(r);
    inc(r); q[r]:=i;
end;

procedure   pop(var i:longint);
begin
    i:=q[l];    inc(l);
end;

procedure   check(var i:longint;    j:longint);
var t:longint;
begin
    push(j);
    if a[j] < aa then begin
        aa:=a[j];   bb:=b[j];
        i:=j;
        repeat
            pop(t);
        until t = i;
    end
    else if b[j] > bb then bb:=b[j];

    while bb-aa >= d do begin
        res:=min(res,abs(j-i));
        if l > r then break;
        pop(i);
        aa:=a[i];
    end;
end;

procedure   solve;
var i,j:longint;
begin
    res:=oo;

    i:=0;
    l:=1;   r:=0;
    aa:=a[0];   bb:=b[0];
    for j:=0 to MAX_X do check(i,j);

    i:=MAX_X;
    l:=1;   r:=0;
    aa:=a[MAX_X];   bb:=b[MAX_X];
    for j:=MAX_X-1 downto 0 do check(i,j);

    if res = oo then res:=-1;
    writeln(fo,res);
end;


begin
    assign(fi,'fpot.in');   reset(fi);
    assign(fo,'fpot.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
