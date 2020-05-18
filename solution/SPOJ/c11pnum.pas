{$R+, $I+}
{$M 16777216}

uses    math;
const   MAX_N = 2642260;
        MAX_P = 192730;
        oo = 1000000000;

type    ll = qword;

var fi,fo:text;
    nTest,k,nP:longint;
    n:ll;
    ok:array[0..MAX_N] of boolean;
    p:array[0..MAX_P] of longint;


procedure   init();
var i:longint;
    j:ll;
begin
    nP:=0;
    for i:=2 to MAX_N do ok[i]:=true;
    for i:=2 to MAX_N do
        if ok[i] then begin
            inc(nP);
            p[nP]:=i;
            j:=i;
            j:=j*j;
            while j < MAX_N do begin
                ok[j]:=false;
                j:=j+i;
            end;
        end;
end;


function    find(pos:longint):ll;
var i:longint;
    x,t:ll;
begin
    t:=1;
    for i:=pos to pos+k-1 do begin
        x:=p[i];
        if double(t)*double(x) > n then exit(0)
        else t:=t*x;
        //if t <= (n div x) then t:=t*x
        //else exit(-1);
    end;
    if t > n then t:=0;
    exit(t);
end;


procedure   solve();
var l,r,mid:longint;
    t,res:ll;
begin
    res:=0;
    l:=1;   r:=nP-k+1;
    while l <= r do begin
        mid:=(l+r) shr 1;
        t:=find(mid);
        if t > 0 then begin
            res:=t;
            l:=mid+1;
        end
        else r:=mid-1;
    end;
    if (n = 1) or (res = 0) then writeln(fo,-1)
    else writeln(fo,res);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'C11PNUM.in');    reset(fi);
    assign(fo,'C11PNUM.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    init();
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,n,k);
        solve();
        dec(nTest);
    end;
    close(fi);
    close(fo);
end.
