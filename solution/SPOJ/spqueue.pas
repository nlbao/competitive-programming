const   MAX_N = 500003;
        MAX_M = MAX_N;
        MAX_P = 41600;

type    ll = int64;

var fi,fo:text;
    nTest,n,nE,id:longint;
    e:array[0..MAX_M] of longint;
    head,link,s,d:array[0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;
    modun:ll;


procedure   enter();
var i,u:longint;
begin
    nE:=0;
    readln(fi,modun,n);
    for i:=0 to n+1 do head[i]:=0;
    for i:=2 to n do begin
        read(fi,u);
        inc(nE);
        e[nE]:=i;
        link[nE]:=head[u];
        head[u]:=nE;
    end;
end;


procedure   dfs(u:longint);
var i:longint;
begin
    s[u]:=1;
    i:=head[u];
    while i <> 0 do begin
        dfs(e[i]);
        s[u]:=s[u] + s[e[i]];
        i:=link[i];
    end;
end;


function    mpow(x,m:longint):ll;
var t:ll;
begin
    if m = 0 then exit(1);
    if m = 1 then exit(x mod modun);
    t:=mpow(x,m shr 1);
    t:=(t*t) mod modun;
    if (m and 1) = 0 then exit(t);
    exit((t*x) mod modun);
end;


function    solve():ll;
var i,j,c:longint;
    res,sum:ll;
begin
    dfs(1);
    for i:=1 to n do begin
        d[i]:=0;
        head[i]:=0;
        ok[i]:=true;
    end;
    for i:=2 to s[1]-1 do d[i]:=1;
    for i:=2 to n do d[s[i]]:=d[s[i]]-1;

    res:=1;
    for i:=2 to n do
        if ok[i] then begin
            sum:=0;
            j:=i;   c:=1;
            while j <= n do begin
                ok[j]:=false;
                head[j]:=i;
                if head[c] = i then s[j]:=s[c]+1
                else s[j]:=1;
                if d[j] <> 0 then
                    sum:=sum + d[j]*s[j];
                j:=j+i;
                inc(c);
            end;
            res:=(mpow(i,sum)*res) mod MODUN;
        end;
    exit(res);
end;


begin
    assign(fi,'spqueue.in');    reset(fi);
    assign(fo,'spqueue.out');   rewrite(fo);
    readln(fi,nTest);
    for id:=1 to nTest do begin
        enter();
        writeln(fo,solve());
    end;
    close(fo);
    close(fi);
end.