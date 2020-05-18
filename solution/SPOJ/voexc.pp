uses    math;

const   MAX_N = 100010;

type    mreal = double;


var fi,fo:text;
    n,i,j:longint;
    x,y,d,sv,sb,res:mreal;
    a,b,t,f:array[0..MAX_N] of mreal;


procedure   swap(var x,y:mreal);
var t:mreal;
begin   t:=x;   x:=y;   y:=t;   end;


procedure   sort(l,r:longint);
var i,j:longint;
    p:mreal;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    p:=t[i];
    i:=l;   j:=r;
    repeat
        while t[i] > p do inc(i);
        while t[j] < p do dec(j);
        if i <= j then begin
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            swap(t[i],t[j]);
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;



begin
    assign(fi,'voexc.in');  reset(fi);
    assign(fo,'voexc.out'); rewrite(fo);
    sv:=0;  sb:=0;
    read(fi,n);
    j:=0;
    for i:=1 to n do begin
        read(fi,x,y);
        if x = 0 then sb:=sb+y
        else if y = 0 then sv:=sv+x
        else begin
            inc(j);
            a[j]:=x;    b[j]:=y;
            t[j]:=x/y;
        end;
    end;
    n:=j;

    randomize;
    sort(1,n);
    f[n+1]:=0;
    for i:=n downto 1 do f[i]:=f[i+1]+b[i];

    for i:=1 to n do
        if sv+a[i] > sb+f[i+1] then begin
            sb:=sb+f[i+1];
            if sb-sv+b[i] >= 0 then begin
                d:=(sb-sv+b[i])/(a[i]+b[i]);
                sv:=sv+d*a[i];
                sb:=sb+(1-d)*b[i];
            end;
            break;
        end
        else sv:=sv+a[i];
    res:=min(sv,sb);
    writeln(fo,res:0:6);
    close(fo);
    close(fi);
end.