{$M+ 2000000,0,2000000}
uses    math;

const   MAX_N = 10004;
        MAX_M = 100005;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nC,count,top:longint;
    e:array[0..MAX_M] of recEdge;
    head,stt,stack,num,low:array[0..MAX_N] of longint;


procedure   enter();
var i:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do head[i]:=0;
    for i:=1 to m do with e[i] do begin
        read(fi,x,y);
        link:=head[x];
        head[x]:=i;
    end;
end;


procedure   dfs(u:longint);
var i:longint;
begin
    stt[u]:=0;
    inc(top);   stack[top]:=u;
    inc(count);
    num[u]:=count;  low[u]:=oo;

    i:=head[u];
    while i <> 0 do with e[i] do begin
        if stt[y] < 1 then
            if stt[y] = -1 then begin
                dfs(y);
                low[u]:=min(low[u],low[y]);
            end
            else low[u]:=min(low[u],num[y]);
        i:=link;
    end;

    if low[u] >= num[u] then begin
        inc(nC);
        repeat
            i:=stack[top];
            dec(top);
            stt[i]:=1;
        until i = u;
    end;
end;


procedure   solve();
var i:longint;
begin
    nC:=0;
    count:=0;   top:=0;
    for i:=1 to n do stt[i]:=-1;
    for i:=1 to n do
        if stt[i] = -1 then dfs(i);
    writeln(fo,nC);
end;



begin
{$IFDEF WINDOWS}
    assign(fi,'tjalg.in');    reset(fi);
    assign(fo,'tjalg.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.