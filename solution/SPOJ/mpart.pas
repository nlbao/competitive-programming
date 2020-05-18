uses    math;

const   MAX_A = 1003;
        MAX_B = 502;
        MAX_N = 2 + MAX_A + MAX_B;
        MAX_M = 501502;
        oo = 1000000000;

type    recEdge = record
            x,y:longint;
            c,f:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,nA,nB,nE,s,t:longint;
    e:array[-MAX_M..MAX_M] of recEdge;
    id:array[1..2,0..MAX_A] of longint;
    head,q,d,pos:array[0..MAX_N] of longint;

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
        c:=0;   f:=0;
        link:=head[x];
        head[x]:=-nE;
    end;
end;

procedure   push(var x:longint);    begin   inc(n); x:=n;   end;

function    enter():boolean;
var i,j,u,v,len,err:longint;
    ch:char;
begin
    readln(fi,nA,nB);
    if (nA = 0) or (nB = 0) then exit(false);
    n:=2;   nE:=0;
    s:=1;   t:=2;
    fillchar(head,sizeof(head),0);
    for i:=1 to nA do push(id[1][i]);
    for i:=1 to nB do push(id[2][i]);
    for i:=1 to nA do add_edge(s,id[1][i],1);
    for i:=1 to nB do add_edge(id[2][i],t,0);

    for u:=1 to nA do begin
        ch:='.';
        while ch <> ' ' do read(fi,ch);
        while not eoln(fi) do begin
            read(fi,v);
            add_edge(id[1][u],id[2][v+1],1);
        end;
        readln(fi);
    end;
    exit(true);
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
    exit(d[t] <> -1);
end;


function    check(limit:longint):boolean;
var i,j,u,delta,flow,top:longint;
begin
    for i:=1 to nB do begin
        u:=id[2][i];
        j:=head[u];
        while j <> 0 do with e[j] do begin
            if y = 2 then c:=limit;
            j:=link;
        end;
    end;
    for i:=-nE to nE do e[i].f:=0;

    flow:=0;
    while find_path() do begin
        for i:=0 to n do pos[i]:=head[i];
        top:=0; q[0]:=0;
        u:=s;
        repeat
           if u = t then begin
                delta:=oo;
                for i:=0 to top-1 do with e[q[i]] do
                    if c-f < delta then begin
                        delta:=c-f;
                        j:=i;
                    end;
                for i:=0 to top-1 do begin
                    with e[q[i]] do f:=f+delta;
                    //with e[q[i] xor 1] do f:=f-delta;
                    with e[-q[i]] do f:=f-delta;
                end;
                flow:=flow+delta;
                top:=j;
                u:=e[q[j]].x;
            end;

            while pos[u] <> 0 do with e[pos[u]] do begin
                if (f < c) and (d[y] = d[u]+1) then break;
                pos[u]:=link;
            end;
            if pos[u] <> 0 then begin
                q[top]:=pos[u];
                inc(top);
                u:=e[pos[u]].y;
            end
            else begin
                if top = 0 then break;
                d[u]:=-1;
                dec(top);
                u:=e[q[top]].x;
            end;
        until false;
    end;
    exit(flow = nA);
end;


procedure   solve();
var l,r,mid,res:longint;
begin
    res:=0;
    l:=1;   r:=nA;
    while l <= r do begin
        mid:=(l+r) shr 1;
        if check(mid) then begin
            res:=mid;
            r:=mid-1;
        end
        else l:=mid+1;
    end;
    writeln(fo,res);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'MPART.in');   reset(fi);
    assign(fo,'MPART.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    repeat
        if not enter() then break;
        solve();
    until false;
    close(fi);
    close(fo);
end.