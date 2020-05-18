{$R+, $I+}
{$M 16777216}

uses    math;

const   MAX_N = 100010;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,i,res:longint;
    a,b,id:array[0..MAX_N] of longint;



procedure   sort(l,r:longint);
var i,j,p1,p2,t:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p1:=a[id[i]];   p2:=b[id[i]];
    i:=l;   j:=r;
    repeat
        while (a[id[i]] < p1) or ((a[id[i]] = p1) and (b[id[i]] > p2)) do inc(i);
        while (a[id[j]] > p1) or ((a[id[j]] = p1) and (b[id[j]] < p2)) do dec(j);
        if i <= j then begin
            t:=id[i];
            id[i]:=id[j];
            id[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'242B.in');    reset(fi);
    assign(fo,'242B.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n);
    for i:=1 to n do begin
        read(fi,a[i],b[i]);
        id[i]:=i;
    end;
    randomize;
    sort(1,n);
    res:=id[1];
    for i:=2 to n do
        if b[id[i]] > b[res] then begin
            res:=-1;
            break;
        end;
    writeln(fo,res);
    close(fi);
    close(fo);
end.

