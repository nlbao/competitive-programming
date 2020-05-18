const   INPUT = ''{'robot.in'};
        OUTPUT = ''{'robot.out'};
        MAX_N = 100010;
        MAX_M = 300010;

type    int = int64;
        arr = array[0..MAX_N] of int;

var fi,fo:text;
    n,m:longint;
    a,b,sumA,sumB:arr;

procedure   enter;
var i:longint;
begin
    readln(fi,n,m);
    for i:=1 to n do readln(fi,a[i],b[i]);
end;

procedure   quick_sort(var x:arr;   l,r:longint);
var i,j:longint;
    p,t:int;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=x[i+random(j-i+1)];
    repeat
        while x[i] < p do inc(i);
        while x[j] > p do dec(j);
        if i <= j then begin
            t:=x[i];    x[i]:=x[j];     x[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(x,l,j);    quick_sort(x,i,r);
end;

procedure   init;
var i:longint;
begin
    randomize;
    quick_sort(a,1,n);
    quick_sort(b,1,n);
    sumA[0]:=0; sumB[0]:=0;
    for i:=1 to n do begin
        sumA[i]:=sumA[i-1]+a[i];
        sumB[i]:=sumB[i-1]+b[i];
    end;
end;

function    find(x:int; var a:arr):int;
var l,r,mid,t:longint;
begin
    l:=1;   r:=n;   t:=0;
    repeat
        mid:=(l+r) shr 1;
        if  a[mid] <= x then begin
            t:=mid;
            l:=mid+1;
        end
        else r:=mid-1;
    until l > r;
    exit(t);
end;

procedure   solve;
var i:longint;
    x,y,j,t,res:int;
    ch:char;
begin
    x:=0;   y:=0;
    for i:=1 to m do begin
        read(fi,ch);
        case upcase(ch) of
            'S': inc(y);
            'J': dec(y);
            'I': inc(x);
            'Z': dec(x);
        end;
        j:=find(x,a);   t:=n-j;
        res:=(j*x-sumA[j])+(sumA[n]-sumA[j]-t*x);
        j:=find(y,b);   t:=n-j;
        res:=res+(j*y-sumB[j])+(sumB[n]-sumB[j]-t*y);
        writeln(fo,res);
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