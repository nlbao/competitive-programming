{$R+, $I+}
{$M 16777216}

uses    math;

const   MAX_N = 1010;
        MAX_M = 300010;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            w:longint;
        end;

var fi,fo:text;
    nTest,price,n,m,i,r1,r2,res:longint;
    e:array[0..MAX_M] of recEdge;
    p:array[0..MAX_N] of longint;


procedure   sort_e(l,r:longint);
var i,j,p:longint;
    t:recEdge;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=e[i].w;
    i:=l;   j:=r;
    repeat
        while e[i].w < p do inc(i);
        while e[j].w > p do dec(j);
        if i <= j then begin
            t:=e[i];
            e[i]:=e[j];
            e[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort_e(l,j);
    sort_e(i,r);
end;


function    get_root(u:longint):longint;
begin
    if p[u] < 0 then exit(u);
    p[u]:=get_root(p[u]);
    exit(p[u]);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'CSTREET.in');    reset(fi);
    assign(fo,'CSTREET.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    readln(fi,nTest);
    while nTest > 0 do begin
        read(fi,price);
        read(fi,n,m);
        for i:=1 to m do with e[i] do
            read(fi,x,y,w);

        randomize;
        sort_e(1,m);

        res:=0;
        for i:=1 to n do p[i]:=-1;
        for i:=1 to m do with e[i] do begin
            r1:=get_root(x);
            r2:=get_root(y);
            if r1 <> r2 then begin
                res:=res+w;
                p[r1]:=p[r1]+p[r2];
                p[r2]:=r1;
            end;
        end;
        writeln(fo,res*price);
        dec(nTest);
    end;
    close(fi);
    close(fo);
end.

