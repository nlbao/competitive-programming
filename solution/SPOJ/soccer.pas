{$M+ 2000000}
uses    math;

const   MAX_A = 44;
        MAX_C = 5;
        MAX_N = 3010;
        MAX_M = 8944;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            c,f:longint;
            link:longint;
        end;

var fi,fo:text;
    nTest,n,m,nE,rest,s,t:longint;
    a:array[0..MAX_A,0..MAX_C,0..MAX_A] of longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    score,head,d,q,pos:array[0..MAX_N] of longint;


procedure   enter();
var i,j,k,x,g:longint;
    ch:char;
    crr:array[0..MAX_A,0..MAX_A] of longint;
begin
    readln(fi,n,m,g);
    fillchar(score,sizeof(score),0);
    fillchar(a,sizeof(a),0);
    fillchar(crr,sizeof(crr),0);
    for i:=0 to n-1 do
        for j:=0 to n-1 do
            if j <> i then begin
                crr[i][j]:=1;
                for k:=1 to m do a[i][k][j]:=2;
            end;
    rest:=n*(n-1)*m - 2*g;
    for k:=1 to g do begin
        read(fi,i);
        read(fi,ch);    read(fi,ch);
        readln(fi,j);
        dec(i); dec(j);
        if ch = '>' then begin  x:=i;   i:=j;   j:=x;   end;
        if ch = '=' then begin
            inc(score[i],1);
            inc(score[j],1);
        end
        else inc(score[j],2);
        a[i][crr[i][j]][j]:=0;  inc(crr[i][j]);
        a[j][crr[j][i]][i]:=0;  inc(crr[j][i]);
    end;
end;


procedure   add_edge(u,v,cc:longint);
begin
    inc(nE);
    with e[nE] do begin
        x:=u;   y:=v;
        c:=cc;  f:=0;
        link:=head[x];
        head[x]:=nE;
    end;
    with e[-nE] do begin
        x:=v;   y:=u;
        c:=0;  f:=0;
        link:=head[x];
        head[x]:=-nE;
    end;
end;


procedure   init();
var i,j,k,tmp,sum:longint;
    id:array[0..MAX_A] of longint;
begin
    for i:=1 to n-1 do
        for k:=1 to m do
            if a[0][k][i] > 0 then begin
                inc(score[0],2);
                a[0][k][i]:=0;
                a[i][k][0]:=0;
                rest:=rest-2;
            end;

    tmp:=n-1;
    n:=2;   nE:=0;
    s:=1;   t:=2;
    fillchar(head,sizeof(head),0);

    for i:=1 to tmp do begin
        inc(n);
        id[i]:=n;
        add_edge(s,n,score[0]-score[i]-1);
    end;

    for i:=1 to tmp do
        for j:=i+1 to tmp do
            for k:=1 to m do begin
                if a[i][k][j] > 0 then begin
                    inc(n);
                    add_edge(id[i],n,2);
                    add_edge(id[j],n,2);
                    add_edge(n,t,2);
                end;
            end;
end;


function    find_path():boolean;
var i,l,r,u:longint;
begin
    for i:=1 to n do d[i]:=-1;
    d[s]:=0;
    l:=1;   r:=1;
    q[1]:=s;
    while l <= r do begin
        u:=q[l]; inc(l);
        i:=head[u];
        while i <> 0 do with e[i] do begin
            if (d[y] = -1) and (f < c) then begin
                d[y]:=d[u]+1;
                if y = t then exit(true);
                inc(r); q[r]:=y;
            end;
            i:=link;
        end;
    end;
    exit(false);
end;


function    incflow(u,flow:longint):longint;
var delta:longint;
begin
    if u = t then exit(flow);
    if flow = 0 then exit(0);
    while pos[u] <> 0 do with e[pos[u]] do begin
        if d[y] = d[u]+1 then begin
            delta:=incflow(y,min(flow,c-f));
            if delta > 0 then begin
                f:=f+delta;
                with e[-pos[u]] do f:=f-delta;
                exit(delta);
            end;
        end;
        pos[u]:=link;
    end;
    exit(0);
end;


function    solve():char;
var i,flow,delta:longint;
begin
    for i:=-nE to nE do
        if e[i].c < 0 then exit('N');

    flow:=0;
    while find_path() do begin
        for i:=1 to n do pos[i]:=head[i];
        repeat
            delta:=incflow(s,oo);
            flow:=flow+delta;
        until delta = 0;
    end;
    if flow < rest then exit('N');
    exit('Y');
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'soccer.inp');  reset(fi);
    assign(fo,'soccer.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    readln(fi,nTest);
    while nTest > 0 do begin
        enter();
        init();
        writeln(fo,solve());
        dec(nTest);
    end;
    close(fi);
    close(fo);
end.