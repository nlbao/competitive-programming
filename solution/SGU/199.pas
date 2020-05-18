{$M 16777216}
uses    math;

const   MAX_N = 100005;
        oo = 1000000000;

var fi,fo:text;
    n,top,i,l,r,t,mid:longint;
    a,b,id,f,trace:array[0..MAX_N] of longint;


function    cmp(i,j:longint):longint;
begin
    if a[i] < a[j] then exit(-1);
    if a[i] > a[j] then exit(1);
    if b[i] < b[j] then exit(-1);
    if b[i] > b[j] then exit(1);
    exit(0);
end;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   sort(l,r:longint);
var i,j:longint;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    a[0]:=a[i]; b[0]:=b[i];
    i:=l;   j:=r;
    repeat
        while cmp(i,0) < 0 do inc(i);
        while cmp(j,0) > 0 do dec(j);
        if i <= j then begin
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            swap(id[i],id[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'199.in');    reset(fi);
    assign(fo,'199.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n);
    for i:=1 to n do begin
        read(fi,a[i],b[i]);
        id[i]:=i;
    end;
    randomize;
    sort(1,n);

    top:=0;
    for i:=1 to n do trace[i]:=0;
    for i:=1 to n do begin
        t:=0;
        l:=1;   r:=top;
        while l <= r do begin
            mid:=(l+r) shr 1;
            if b[f[mid]] < b[i] then begin
                t:=mid;
                l:=mid+1;
            end
            else r:=mid-1;
        end;

        trace[i]:=t;
        inc(t); f[t]:=i;
        top:=max(top,t);
    end;

    writeln(fo,top);
    i:=f[top];
    while i > 0 do begin
        write(fo,id[i],' ');
        i:=trace[i];
    end;
    close(fo);
    close(fi);
end.