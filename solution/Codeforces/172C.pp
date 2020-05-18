const   MAX_N = 100010;
        MAX_M = 100010;
        MAX_X = 10010;

type    recE = record
            id:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,top,nE,cturn:longint;
    time:int64;
    t,x,q:array[0..MAX_N] of longint;
    res:array[0..MAX_N] of int64;
    turn,cx,head:array[0..MAX_X] of longint;
    e:array[0..MAX_N] of recE;

function    max(x,y:int64):int64;   begin   if x > y then exit(x);  exit(y);    end;

procedure   enter;
var i:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do readln(fi,t[i],x[i]);
end;

procedure   add(u:longint);
begin
    inc(nE);
    e[nE].id:=u;
    e[nE].link:=head[x[u]];
    head[x[u]]:=nE;
    if turn[x[u]] <> cturn then begin
        turn[x[u]]:=cturn;
        cx[x[u]]:=0;
        inc(top);   q[top]:=x[u];
    end;
    inc(cx[x[u]]);
end;

procedure   sort(l,r:longint);
var i,j,p,t:longint;
begin
    if l >= r then exit;
    p:=q[l+random(r-l)];
    i:=l;   j:=r;
    repeat
        while q[i] < p do inc(i);
        while q[j] > p do dec(j);
        if i <= j then begin
            t:=q[i];    q[i]:=q[j];     q[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j); sort(i,r);
end;

procedure   run;
var i,j,u:longint;
    s:int64;
begin
    randomize;
    sort(1,top);
    s:=0;
    for i:=1 to top do begin
        u:=q[i];
        j:=head[u];
        while j <> 0 do with e[j] do begin
            res[id]:=time+u+s;
            j:=link;
        end;
        head[u]:=0;
        s:=s+(cx[u] div 2)+1;
    end;
    if top > 0 then time:=time+s+2*u;
end;

procedure   solve;
var i,c:longint;
begin
    for i:=0 to MAX_X do begin
        turn[i]:=0;
        cx[i]:=0;
        head[i]:=0;
    end;
    time:=0;
    cturn:=0;   c:=0;
    repeat
        inc(cturn);
        nE:=0;  top:=0;
        for i:=1 to m do begin
            inc(c);
            if c > n then break;
            add(c);
            time:=max(time,t[c]);
        end;
        run;
    until c > n;
    for i:=1 to n do
        write(fo,res[i],' ');
end;

begin
    assign(fi,'172C.in');   reset(fi);
    assign(fo,'172C.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.