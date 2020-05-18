{$M 16777216}
uses    math;

const   MAX_N = 1003;
        oo = 1000000000;
        eps = 1e-7;

type    ll = int64;
        recPoint = record
            x,y:double;
        end;
        arrPoint = array[0..MAX_N] of recPoint;

var fi,fo:text;
    nTest,n,m,k:longint;
    a,b:arrPoint;


procedure   enter(var n:longint;    var a:arrPoint);
var i:longint;
begin
    read(fi,n);
    for i:=1 to n do read(fi,a[i].x,a[i].y);
    a[0]:=a[n];
    a[n+1]:=a[1];
end;


procedure   get_line(p1,p2:recPoint;    var a,b,c:double);  inline;
begin
    a:=p1.y - p2.y;
    b:=p2.x - p1.x;
    c:=-(a*p1.x + b*p1.y);
end;

function    f(a,b,c:double; p:recPoint):double; inline;
begin   exit(a*p.x + b*p.y + c);    end;

function    cmp(x,y:double):longint;    inline;
begin
    if (x = 0) or (y = 0) then exit(0);
    if (x > 0) and (y < 0) then exit(-1);
    if (x < 0) and (y > 0) then exit(-1);
    exit(1);
end;


function    solve():string;
var i,j:longint;
    a1,b1,c1,t1,t2:double;
    ck:boolean;
begin
    for i:=1 to n do begin
        ck:=true;
        get_line(a[i],a[i+1],a1,b1,c1);
        if i = 1 then t1:=f(a1,b1,c1,a[3])
        else if i = n then t1:=f(a1,b1,c1,a[2])
        else t1:=f(a1,b1,c1,a[1]);

        for j:=1 to m do begin
            t2:=f(a1,b1,c1,b[j]);
            if cmp(t1,t2) >= 0 then begin
                ck:=false;
                break;
            end;
        end;
        if ck then exit('NO');
    end;
    exit('YES');
end;

begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'NKLAND.in');    reset(fi);
    assign(fo,'NKLAND.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    readln(fi,nTest);
    while nTest > 0 do begin
        enter(n,a);
        enter(m,b);
        writeln(fo,solve());
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.