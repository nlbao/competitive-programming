{$R+, $I+}
{$M 16777216}

uses    math;

const   MAX_N = 100010;
        MAX_M = 55;
        oo = 1000000000;
        MODUN = 790972;

type    ll = qword;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,i,j:longint;
    a,b:array[0..MAX_N] of longint;
    f:array[0..1,0..MAX_M] of ll;
    res:ll;


procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   sort(l,r:longint);
var i,j,p:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=b[i];
    i:=l;   j:=r;
    repeat
        while b[i] < p do inc(i);
        while b[j] > p do dec(j);
        if i <= j then begin
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;



function    solve(l,r:longint):ll;
var i,j,t,tt:longint;
    d:ll;
begin
    t:=0;
    f[0][0]:=1;
    f[1][0]:=1;
    for i:=1 to m do begin
        f[0][i]:=0;
        f[1][i]:=0;
    end;
    for i:=l to r do begin
        tt:=t;
        t:=(t+1) and 1;
        d:=a[i];
        for j:=1 to min(i-l+1,m) do
            f[t][j]:=(((f[tt][j-1]*d) mod MODUN) + f[tt][j]) mod MODUN ;
    end;
    exit(f[t][m]);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'c11bc1.in');    reset(fi);
    assign(fo,'c11bc1.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n,m);
    for i:=1 to n do read(fi,a[i],b[i]);
    randomize;
    sort(1,n);

    res:=0;
    i:=1;
    while i <= n do begin
        j:=i;
        while (j <= n) and (b[j] = b[i]) do inc(j);
        res:=(res + solve(i,j-1)) mod MODUN;
        i:=j;
    end;
    res:=(solve(1,n) - res) mod MODUN;
    res:=(res+MODUN) mod MODUN;
    writeln(fo,res);
    close(fi);
    close(fo);
end.

