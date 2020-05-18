const   INPUT = ''{'place.in'};
        OUTPUT = ''{'place.out'};
        MAX_N = 500010;
        MAX_M = MAX_N;
        MAX_Q = 500010;

type    int = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,m,q,count:longint;
    w:array[0..MAX_N] of int;
    e:array[0..MAX_M] of recEdge;
    head,first,last:array[0..MAX_N] of longint;
    IT:array[0..5*MAX_N] of int;
    x,y,value:int;

function    max(x,y:longint):longint;   begin   if x > y then exit(x)   else exit(y);   end;

procedure   add_edge(u,v:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u;   y:=v;
        link:=head[x];
        head[x]:=m;
    end;
end;

procedure   enter;
var i,j:longint;
begin
    readln(fi,n,q);
    m:=0;
    for i:=1 to n do head[i]:=0;
    readln(fi,w[1]);
    for i:=2 to n do begin
        readln(fi,w[i],j);
        add_edge(j,i);
    end;
end;

procedure   DFS(u:longint);
var i:longint;
begin
    inc(count);
    first[u]:=count;    last[u]:=count;
    i:=head[u];
    while i <> 0 do with e[i] do begin
        DFS(y);
        last[u]:=max(last[u],last[y]);
        i:=link;
    end;
end;

procedure   init;
var i:longint;
begin
    count:=0;
    DFS(1);
    for i:=1 to 5*count do IT[i]:=0;
end;

procedure   update(k,l,r:longint);
var mid:longint;
begin
    if (l > r) or (l > y) or (r < x) then exit;
    if (x <= l) and (r <= y) then begin
        IT[k]:=IT[k]+value;
        exit;
    end;
    mid:=(l+r) shr 1;
    update(k shl 1,l,mid);
    update((k shl 1)+1,mid+1,r);
end;

function    get(k,l,r:longint):int;
var mid:longint;
begin
    if (l > r) or (l > x) or (r < x) then exit(0);
    if l = r then exit(IT[k]);
    mid:=(l+r) shr 1;
    exit(get(k shl 1,l,mid)+get((k shl 1)+1,mid+1,r)+IT[k]);
    exit(0);
end;

procedure   solve;
var i,u:longint;
    ch:char;
begin
    for i:=1 to q do begin
        read(fi,ch);
        read(fi,u);
        if ch = 'p' then begin
            readln(fi,value);
            x:=first[u]+1;   y:=last[u];
            update(1,1,count);
        end
        else begin
            readln(fi);
            x:=first[u];
            writeln(fo,w[u]+get(1,1,count));
        end;
    end;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init;
    solve;
    close(fo);
    close(fi);
end.
