const   MAX_N = 100010;

var fi,fo:text;
    n,k,i,j:longint;
    h,l,r,mid:double;
    m,id,x,res:array[0..MAX_N] of longint;
    v:array[0..MAX_N] of double;

procedure   swap(var x,y:longint);
var t:longint;
begin   t:=x;   x:=y;   y:=t;   end;

procedure   sort(l,r:longint);
var i,j,p1:longint;
    p2,t:double;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p1:=m[i];   p2:=v[i];
    i:=l;   j:=r;
    repeat
        while (m[i] < p1) or ((m[i] = p1) and (v[i] < p2)) do inc(i);
        while (m[j] > p1) or ((m[j] = p1) and (v[j] > p2)) do dec(j);
        if i <= j then begin
            swap(m[i],m[j]);
            swap(id[i],id[j]);
            t:=v[i];    v[i]:=v[j];     v[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j); sort(i,r);
end;


function    ok(t:double):boolean;
var i,c:longint;
    tmp:double;
begin
    c:=0;
    for i:=1 to n do begin
        tmp:=(c+1)*h;
        if tmp/v[i] <= t then begin
            inc(c);
            x[c]:=i;
            if c = k then exit(true);
        end;
    end;
    exit(false);
end;


begin
    assign(fi,'163B.in');   reset(fi);
    assign(fo,'163B.out');  rewrite(fo);
    randomize;
    readln(fi,n,k,h);
    for i:=1 to n do begin
        read(fi,m[i]);
        id[i]:=i;
    end;
    for i:=1 to n do read(fi,v[i]);
    sort(1,n);

    l:=0;   r:=1000000000;
    for i:=1 to 113 do begin
        mid:=(l+r)/2;
        if ok(mid) then begin
            for j:=1 to k do res[j]:=id[x[j]];
            r:=mid;
        end
        else l:=mid;
    end;
    for i:=1 to k do write(fo,res[i],' ');
    close(fo);
    close(fi);
end.
