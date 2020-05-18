{$M+ 2000000}
uses    math;

const   MAX_N = 202;
        MAX_Q = sqr(MAX_N)*4;
        oo = 1000000000;
        dx:array[1..4] of longint = (-1,0,+1,0);
        dy:array[1..4] of longint = (0,+1,0,-1);
        left:array[1..4] of longint = (4,1,2,3);
        right:array[1..4] of longint = (2,3,4,1);
        link:array[1..4] of longint = (3,4,1,2);
        BASE = 100000000;
        DIGIT = 8;
        MAX_LEN = 11;

type    ll = int64;
        bigNum = array[0..MAX_LEN] of ll;

var fi,fo:text;
    sd:char;
    n,m,sx,sy,tx,ty,l,r:longint;
    ok:array[-1..MAX_N,-1..MAX_N] of boolean;
    d:array[0..MAX_N,0..MAX_N,1..4] of longint;
    c:array[0..MAX_N,0..MAX_N,1..4] of bigNum;
    qx,qy,qk:array[0..MAX_Q] of longint;



procedure   toBigNum(var a:bigNum;  x:ll);
begin
    fillchar(a,sizeof(a),0);
    while x > 0 do begin
        inc(a[0]);
        a[a[0]]:=x mod BASE;
        x:=x div BASE;
    end;
    if a[0] = 0 then a[0]:=1;
end;


procedure   cong(a,b:bigNum;    var c:bigNum);
var i:longint;
    r:ll;
begin
    fillchar(c,sizeof(c),0);
    c[0]:=max(a[0],b[0]);
    r:=0;
    for i:=1 to c[0] do begin
        c[i]:=a[i]+b[i]+r;
        r:=c[i] div BASE;
        c[i]:=c[i] mod BASE;
    end;
    while r > 0 do begin
        inc(c[0]);
        c[c[0]]:=r mod BASE;
        r:=r div BASE;
    end;
end;


function    toString(var a:bigNum):ansiString;
var i:longint;
    s,t:ansiString;
begin
    s:='';
    for i:=1 to a[0] do begin
        str(a[i],t);
        while length(t) < DIGIT do t:='0'+t;
        s:=t+s;
    end;
    if length(s) = 0 then s:='0';
    while (length(s) > 1) and (s[1] = '0') do delete(s,1,1);
    exit(s);
end;



procedure   enter();
var i,j:longint;
    map:ansiString;
begin
    readln(fi,m,n);
    fillchar(ok,sizeof(ok),false);
    for i:=1 to m do begin
        readln(fi,map);
        for j:=1 to n do
            if map[j] <> '*' then begin
                ok[i][j]:=true;
                if map[j] = 'X' then begin tx:=i;  ty:=j;  end
                else if map[j] <> '.' then begin
                    sx:=i;  sy:=j;
                    sd:=map[j];
                end;
            end
            else ok[i][j]:=false;
    end;
end;


procedure   push(x,y,k:longint);
begin
    inc(r);
    qx[r]:=x;   qy[r]:=y;
    qk[r]:=k;
end;

procedure   pop(var x,y,k:longint);
begin
    x:=qx[l];   y:=qy[l];
    k:=qk[l];
    inc(l);
end;


procedure   init();
var i,j,k:longint;
begin
    for i:=1 to m do
        for j:=1 to n do
            for k:=1 to 4 do d[i][j][k]:=oo;
    case sd of
        'N': k:=1;
        'E': k:=2;
        'S': k:=3;
        'W': k:=4;
    end;
    d[sx][sy][k]:=0;
    toBigNum(c[sx][sy][k],1);

    l:=1;   r:=0;
    push(sx,sy,k);
end;


procedure   up(x,y,k,dd:longint;    cc:bigNum);
begin
    if dd > d[x][y][k] then exit;
    if dd < d[x][y][k] then begin
        d[x][y][k]:=dd;
        c[x][y][k]:=cc;
        push(x,y,k);
    end
    else cong(c[x][y][k],cc, c[x][y][k]);
end;


procedure   solve();
var i,k,x,y,u,v,td:longint;
    tc:bigNum;
begin
    while l <= r do begin
        pop(x,y,k);
        td:=d[x][y][k]+1;
        tc:=c[x][y][k];

        up(x,y,left[k], td, tc);
        up(x,y,right[k], td, tc);

        for i:=1 to 4 do begin
            if (i <> k) and (i <> link[k]) then continue;
            u:=x + dx[i];
            v:=y + dy[i];
            while ok[u][v] do begin
                up(u,v,k, td, tc);
                u:=u + dx[i];
                v:=v + dy[i];
            end;
        end;
    end;
end;


procedure   print_res();
var k,res:longint;
    sum:bigNum;
begin
    res:=oo;
    for k:=1 to 4 do res:=min(res,d[tx][ty][k]);
    if res = oo then begin
        writeln(fo,0,' ',0);
        exit;
    end;

    toBigNum(sum,0);
    for k:=1 to 4 do
        if d[tx][ty][k] = res then
            cong(sum,c[tx][ty][k], sum);
    writeln(fo,res,' ',toString(sum));
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'jupi.in10');  reset(fi);
    assign(fo,'jupi.out10');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    enter();
    init();
    solve();
    print_res();
    close(fo);
    close(fi);
end.