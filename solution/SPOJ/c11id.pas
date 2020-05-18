uses    math;

const   MAX_N = 100010;
        oo = 1000000000;
        MODULE = 1000000007;

type    ll = int64;


var fi,fo:text;
    n,i:longint;
    a:array[0..MAX_N] of longint;
    t,res:ll;


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


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'C11ID.in');    reset(fi);
    assign(fo,'C11ID.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n);
    for i:=1 to n do read(fi,a[i]);

    randomize;
    sort(1,n);

    res:=a[1];
    for i:=2 to n do begin
        t:=a[i]-i+1;
        if t < 1 then begin
            res:=0;
            break;
        end;
        res:=(res*t) mod MODULE;
    end;
    writeln(fo,res);
    close(fi);
    close(fo);
end.
