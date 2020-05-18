const   MAX_N = 500010;
        MAX_M = MAX_N;

type    int = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,q,count:longint;
    e:array[0..MAX_M] of recEdge;
    head,l,r:array[0..MAX_N] of longint;
    w,t:array[0..MAX_N] of int;

procedure   enter;
var i,j:longint;
begin
    readln(fi,n,q);
    readln(fi,w[1]);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=2 to n do begin
        readln(fi,w[i],j);
        inc(m);
        with e[m] do begin
            x:=j; y:=i;
            link:=head[x];
            head[x]:=m;
        end;
    end;
    count:=0;
end;


procedure   dfs(u:longint);
var i:longint;
begin
    inc(count);
    l[u]:=count;    r[u]:=l[u];
    i:=head[u];
    while i <> 0 do with e[i] do begin
        dfs(y);
        r[u]:=r[y];
        i:=link;
    end;
end;

procedure   update(i:longint;   value:int);
begin
    if (i > count) then exit;
    t[i]:=t[i]+value;
    update(i+(i and (-i)),value);
end;


function    get(i:longint):int;
begin
    if (i < 1) then exit(0);
    exit(get(i-(i and (-i)))+t[i]);
end;


procedure   solve;
var i,u,value:longint;
    ch:char;
begin
    fillchar(t,sizeof(t),0);
    for i:=1 to q do begin
        read(fi,ch);
        if ch = 'p' then begin
            readln(fi,u,value);
            update(l[u]+1,value);
            update(r[u]+1,-value);
        end
        else begin
            readln(fi,u);
            writeln(fo,get(l[u])+w[u]);
        end;
    end;
end;


begin
    assign(fi,'place.in');  reset(fi);
    assign(fo,'place.out'); rewrite(fo);
    enter;
    dfs(1);
    solve;
    close(fo);
    close(fi);
end.

