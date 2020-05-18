const   MAX_N = 100010;
        MAX_M = 100010;

type    recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n1,n2,d,m,i,x,y:longint;
    a,b,c,head:array[0..MAX_N] of longint;
    l,r:array[0..1] of longint;
    q:array[0..1,0..MAX_N] of longint;
    ok:array[0..MAX_N] of boolean;
    e:array[0..MAX_M] of recEdge;


function    min(x,y:longint):longint;   begin   if x < y then exit(x);  exit(y);    end;

procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        link:=head[x];
        head[x]:=m;
    end;
end;

procedure   empty(id:longint);  begin   l[id]:=1;   r[id]:=0;   end;

procedure   push(id,x:longint); begin   inc(r[id]); q[id][r[id]]:=x;    ok[x]:=true;    end;

function    pop(id:longint):longint;   begin   pop:=q[id][l[id]];  inc(l[id]); end;

function    solve(id:longint):longint;
var i,t,u,res:longint;
begin
    res:=1;
    empty(0);   empty(1);
    fillchar(ok,sizeof(ok),false);
    for i:=1 to n1+n2 do begin
        c[i]:=b[i];
        if c[i] = 0 then push(a[i],i);
    end;
    t:=id;
    if l[t] > r[t] then exit(1000000000);
    repeat
        inc(res);
        while l[t] <= r[t] do begin
            u:=pop(t);
            i:=head[u];
            while i <> 0 do with e[i] do begin
                if not ok[y] then begin
                    dec(c[y]);
                    if c[y] = 0 then push(a[y],y);
                end;
                i:=link;
            end;
        end;
        t:=(t+1) mod 2;
    until l[t] > r[t];
    exit(res);
end;

begin
    assign(fi,'all.in');    reset(fi);
    assign(fo,'all.out');   rewrite(fo);
    readln(fi,n1,n2,d);
    while n1 > 0 do begin
        m:=0;
        for i:=1 to n1+n2 do begin
            a[i]:=0;
            b[i]:=0;
            head[i]:=0;
        end;
        for i:=n1+1 to n1+n2 do a[i]:=1;
        for i:=1 to d do begin
            readln(fi,x,y);
            add_edge(y,x);
            inc(b[x]);
        end;
        writeln(fo,min(solve(0),solve(1)));
        readln(fi,n1,n2,d);
    end;
    close(fo);
    close(fi);
end.
