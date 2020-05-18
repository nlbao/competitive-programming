const   MAX_N = 1000010;
        MAX_M = 1000010;

var fi,fo:text;
    nTest,n,m,nq:longint;
    t,q,next,res:array[0..MAX_M] of longint;
    ok:array[0..MAX_M] of boolean;
    p,pre:array[0..MAX_N] of longint;


procedure   enter;
var i:longint;
begin
    readln(fi,n,m);
    nq:=0;
    next[0]:=1; ok[0]:=false;
    for i:=1 to m do begin
        read(fi,t[i]);
        if t[i] = 0 then begin
            inc(nq);
            q[nq]:=i;
            ok[nq]:=true;
            next[nq]:=nq+1;
            res[nq]:=0;
        end;
    end;
    next[nq]:=-1;
    for i:=1 to n do begin
        p[i]:=0;
        pre[i]:=-1;
    end;
end;

function    up(i:longint):longint;
begin
    if i = -1 then exit(-1);
    if (next[i] > -1) and (not ok[next[i]]) then next[i]:=up(next[i]);
    exit(next[i]);
end;

function    get(i:longint):longint;
var j:longint;
begin
    j:=p[i];
    while (j > -1) and (j <= nq) and ((not ok[j]) or (q[j] <= pre[i])) do begin
        if not ok[j] then j:=up(j);
        if j = -1 then break;
        if q[j] <= pre[i] then j:=next[j];
    end;
    p[i]:=j;
    if (j = -1) or (j > nq) then exit(-1);
    ok[p[i]]:=false;
    p[i]:=up(p[i]);
    exit(j);
end;

function    solve:longint;
var i,j:longint;
begin
    if nq = 0 then exit(-1);
    for i:=1 to m do if t[i] <> 0 then begin
        j:=get(t[i]);
        if j = -1 then exit(-1);
        pre[t[i]]:=i;
        res[j]:=t[i];
    end;
    writeln(fo,'YES');
    for i:=1 to nq do write(fo,res[i],' ');
    writeln(fo);
    exit(0);
end;

begin
    assign(fi,'C11Pipi.in');    reset(fi);
    assign(fo,'C11Pipi.out');   rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        if solve = -1 then writeln(fo,'NO');
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
