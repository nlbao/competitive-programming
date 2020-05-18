const   MAX_N = 260;
        MAX_M = sqr(MAX_N);

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,s,t:longint;
    e:array[0..MAX_M] of recEdge;
    head:array[0..MAX_N] of longint;
    nq:array[0..1] of longint;
    qx,qy:array[0..1,0..MAX_M] of longint;
    ok:array[0..1,0..MAX_N,0..MAX_N] of boolean;

procedure   enter;
var i,j,u,v:longint;
begin
    readln(fi,n,j);
    readln(fi,s,t);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        inc(m);
        with e[m] do begin
            readln(fi,x,y);
            link:=head[x];
            head[x]:=m;
        end;
    end;
end;

procedure   push(k,u,v:longint);
begin
    inc(nq[k]);
    qx[k][nq[k]]:=u;
    qy[k][nq[k]]:=v;
end;


function    solve(s,t:longint):longint;
var i,j,k,kk,u,v,c:longint;
begin
    fillchar(ok,sizeof(ok),false);
    nq[0]:=0;   nq[1]:=0;   k:=0;   c:=0;
    push(0,s,t);
    repeat
        if k = 1 then inc(c);
        kk:=(k+1) mod 2;
        for i:=1 to nq[k] do begin
            if (k = 0) and (qx[k][i] = qy[k][i]) then exit(c);

            if k = 0 then j:=head[qx[k][i]]
            else j:=head[qy[k][i]];

            while j <> 0 do with e[j] do begin
                if k = 0 then begin
                    u:=y;
                    v:=qy[k][i];
                end
                else begin
                    u:=qx[k][i];
                    v:=y;
                end;
                if not ok[kk][u][v] then begin
                    ok[kk][u][v]:=true;
                    push(kk,u,v);
                end;
                j:=link;
            end;
        end;
        nq[k]:=0;   k:=kk;
    until nq[k] < 1;
    exit(-1);
end;


begin
    assign(fi,'QBAgents.in');   reset(fi);
    assign(fo,'QBAgents.out');  rewrite(fo);
    enter;
    writeln(fo,solve(s,t));
    close(fo);
    close(fi);
end.