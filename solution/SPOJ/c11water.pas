{$M+ 2000000,0,2000000}
uses    math;

const   MAX_N = 1003;
        MAX_Q = sqr(MAX_N);
        oo = 1000000000;
        dx:array[1..4] of longint = (0,0,+1,-1);
        dy:array[1..4] of longint = (-1,+1,0,0);

type    ll = int64;
        recH = record
            x,y:longint;
            value:longint;
        end;

var fi,fo:text;
    n,m,top:longint;
    a:array[0..MAX_N,0..MAX_N] of longint;
    avail:array[0..MAX_N,0..MAX_N] of boolean;
    h:array[0..MAX_Q] of recH;
    qx,qy:array[0..MAX_Q] of longint;
    res:ll;



procedure   enter();
var i,j:longint;
begin
    read(fi,m,n);
    fillchar(avail,sizeof(avail),false);
    for i:=1 to m do
        for j:=1 to n do begin
            read(fi,a[i][j]);
            avail[i][j]:=true;
        end;
end;


procedure   swapH(i,j:longint);
var t:recH;
begin   t:=h[i];    h[i]:=h[j];     h[j]:=t;    end;

function    cmp(i,j:longint):longint;   begin   exit(h[i].value-h[j].value);    end;

procedure   up_heap(i:longint);
var j:longint;
begin
    j:=i shr 1;
    if (j < 1) or (cmp(j,i) <= 0) then exit;
    swapH(i,j);
    up_heap(j);
end;

procedure   down_heap(i:longint);
var j:longint;
begin
    j:=i shl 1;
    if (j < top) and (cmp(j+1,j) < 0) then inc(j);
    if (j > top) or (cmp(j,i) >= 0) then exit;
    swapH(i,j);
    down_heap(j);
end;

procedure   push(u,v:longint);
begin
    inc(top);
    with h[top] do begin
        x:=u;   y:=v;
        value:=a[x][y];
    end;
    up_heap(top);
    avail[u][v]:=false;
end;

procedure   pop(var u,v:longint);
begin
    with h[1] do begin
        u:=x; v:=y;
    end;
    swapH(1,top);
    dec(top);
    down_heap(1);
end;


procedure   bfs(x,y:longint);
var i,j,k,l,r:longint;
    tmp:ll;
begin
    tmp:=a[x][y];
    l:=1;       r:=1;
    qx[1]:=x;   qy[1]:=y;

    repeat
        x:=qx[l];   y:=qy[l];
        inc(l);
        for k:=1 to 4 do begin
            i:=x+dx[k];
            j:=y+dy[k];
            if not avail[i][j] then continue;
            if a[i][j] >= tmp then begin
                if avail[i][j] then push(i,j);
                continue;
            end;

            inc(r);
            qx[r]:=i;   qy[r]:=j;
            push(i,j);
            res:=res + tmp-a[i][j];
        end;
    until l > r;
end;


procedure   solve();
var x,y,i:longint;
begin
    res:=0;
    top:=0;
    for i:=1 to m do begin
        push(i,1);
        push(i,n);
    end;
    for i:=2 to n-1 do begin
        push(1,i);
        push(m,i);
    end;

    while top > 0 do begin
        pop(x,y);
        bfs(x,y);
    end;
    writeln(fo,res);
end;


begin
{$IFDEF WINDOWS}
    assign(fi,'c11water.in');    reset(fi);
    assign(fo,'c11water.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.