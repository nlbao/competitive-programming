const   MAX_N = 110;
        MAX_M = 9010;
        oo = 1000000000000;
        eps = 0.0001;


type    recEdge = record
            x,y:longint;
            w:double;
            link:longint;
        end;

var fi,fo:text;
    n,m:longint;
    e,t:array[0..MAX_M] of recEdge;
    head:array[0..MAX_N] of longint;
    d:array[0..MAX_N] of double;

procedure   enter;
var i,j:longint;
begin
    readln(fi,n,j);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        inc(m);
        with e[m] do begin
            readln(fi,x,y,w);
            link:=head[x];
            head[x]:=m;
        end;
    end;
    t:=e;
end;

function    ok(x:double):boolean;
var i,u,count:longint;
    stop:boolean;
    sum,tmp:double;
begin
    sum:=0;
    for i:=1 to m do begin
        t[i].w:=e[i].w-x;
        if t[i].w < eps then sum:=sum+t[i].w;
    end;
    for i:=1 to n do d[i]:=oo;
    d[1]:=0;
    count:=0;
    repeat
        stop:=true;
        inc(count);
        if count > n+1 then exit(true);
        for u:=1 to n do begin
            i:=head[u];
            while i <> 0 do with t[i] do begin
                if d[u]+w < d[y] then begin
                    d[y]:=d[u]+w;
                    stop:=false;
                    if d[y]-sum < eps then exit(true);
                end;
                i:=link;
            end;
        end;
    until stop;
    exit(false);
end;

procedure   solve;
var l,r,mid,res:double;
begin
    res:=0;
    l:=0;   r:=oo;
    while r-l >= eps do begin
        mid:=(l+r)/2;
        if ok(mid) then begin
            res:=mid;
            r:=mid;
        end
        else l:=mid;
    end;
    writeln(fo,res:0:2);
end;

begin
    assign(fi,'QBTrans.in');    reset(fi);
    assign(fo,'QBTrans.out');   rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.