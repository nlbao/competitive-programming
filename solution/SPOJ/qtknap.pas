{$R+, $I+}
{$M 16777216}

uses    math;

const   MAX_N = 77;
        oo = 1000000000;

type    ll = qword;


var fi,fo:text;
    n,i:longint;
    w,c,sw,sc:array[0..MAX_N] of ll;
    maxW:ll;


procedure   swap(var x,y:ll);
var t:ll;
begin   t:=x;   x:=y;   y:=t;   end;


procedure   sort(l,r:longint);
var i,j:longint;
    p1,p2:ll;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p1:=w[i];   p2:=c[i];
    i:=l;   j:=r;
    repeat
        while (w[i] > p1) or ((w[i] = p1) and (c[i] > p2)) do inc(i);
        while (w[j] < p1) or ((w[j] = p1) and (c[j] < p2)) do dec(j);
        if i <= j then begin
            swap(w[i],w[j]);
            swap(c[i],c[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;

function    max(x,y:ll):ll; begin   if x > y then exit(x);  exit(y);    end;

function    solve(i:longint;    maxW:ll;    used:boolean):ll;
var t:ll;
begin
    if (i > n) or (maxW < 1) then exit(0);
    if sw[i] <= maxW then exit(sc[i]);

    t:=solve(i+1,maxW,false);
    if (w[i] <= maxW) and ((used) or (w[i] <> w[i-1])) then
        t:=max(t,solve(i+1,maxW-w[i],true) + c[i]);
    exit(t);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'qtknap.in');    reset(fi);
    assign(fo,'qtknap.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n,maxW);
    for i:=1 to n do read(fi,w[i],c[i]);
    randomize;
    sort(1,n);

    w[0]:=0;
    sw[n+1]:=0;
    sc[n+1]:=0;
    for i:=n downto 1 do begin
        sw[i]:=sw[i+1]+w[i];
        sc[i]:=sc[i+1]+c[i];
    end;

    writeln(fo,solve(1,maxW,true));
    close(fi);
    close(fo);
end.