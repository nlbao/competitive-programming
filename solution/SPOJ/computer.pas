uses    math;

const   MAX_X = 1003;
        MAX_N = 1003;
        oo = 1000000000;


var fi,fo:text;
    id,x,a,y,b,n:longint;
    g:array[0..MAX_X] of longint;
    f:array[0..1,0..MAX_X] of longint;


procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;


function    check(value:longint):boolean;
var i,j,k,t,tt:longint;
    s1,s2,c1,c2,tmp,left,right,r:longint;
begin
    t:=0;
    for i:=0 to x do begin
        f[0][i]:=oo;
        f[1][i]:=oo;
    end;
    f[0][0]:=0;

    left:=max((value-b*y) div a, 1);
    right:=min(((x*a+y*b) div n) div a + 1,x);

    {s:=-a;
    for i:=0 to right do begin
        s:=s+a;
        tmp:=s;
        if tmp >= value then tmp:=0
        else begin
            tmp:=(value-tmp) div b;
            if tmp*b + s < value then tmp:=tmp+1;
        end;
        g[i]:=tmp;
    end;   }

    s1:=-a;     c1:=-1;
    s2:=y*b;    c2:=y;
    for i:=0 to right do begin
        s1:=s1+a;
        c1:=c1+1;
        while (c2 > 0) and (s1+s2-b >= value) do begin
            s2:=s2-b;
            c2:=c2-1;
        end;
        if s1+s2 >= value then g[i]:=c2
        else g[i]:=oo;
    end;



    for i:=1 to n do begin
        tt:=t;
        t:=(t+1) and 1;
        f[t][0]:=oo;
        for j:=left to x do begin
            f[t][j]:=oo;
            r:=min(j,right);
            for k:=0 to r do
                f[t][j]:=min(f[t][j], f[tt][j-k] + g[k]);
        end;
    end;

    for i:=0 to x do
        if f[t][i] <= y then exit(true);
    exit(false);
end;



function    solve():longint;
var l,r,mid,res:longint;
begin
    if x > y then begin
        swap(x,y);
        swap(a,b);
    end;

    res:=0;
    l:=0;
    r:=(x*a+y*b) div n + 1;
    while l <= r do begin
        mid:=(l+r) shr 1;
        if check(mid) = true then begin
            res:=mid;
            l:=mid+1;
        end
        else r:=mid-1;
    end;
    exit(res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'COMPUTER.in');   reset(fi);
    assign(fo,'COMPUTER.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    for id:=1 to 2 do begin
        readln(fi,x,a,y,b,n);
        writeln(fo,solve());
    end;
    close(fi);
    close(fo);
end.



