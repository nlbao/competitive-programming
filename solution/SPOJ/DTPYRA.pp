{$R+}
const   INPUT = 'DTPYRA.in';
        OUTPUT = 'DTPYRA.out';
        MAX_N = 1000000000;
        MAX_U = 3000000;
        eps = 1e-9;

var fi,fo:text;
    nTest,nU:longint;
    n:int64;
    uoc:array[0..1000000]of double;

function    min(x,y:double):double;
begin
    if x < y then exit(x)
    else exit(y);
end;

function    can3(x:double):double;
begin
    exit(exp(ln(x)/3)+eps);
end;

procedure   quick_sort(l,r:longint);
var i,j:longint;
    p,tmp:double;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=uoc[(i+j) div 2];
    repeat
        while uoc[i] < p do inc(i);
        while uoc[j] > p do dec(j);
        if i <= j then begin
            tmp:=uoc[i];    uoc[i]:=uoc[j]; uoc[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(l,j);    quick_sort(i,r);
end;

procedure   init;
var i,limit,m:int64;
begin
    nU:=0;
    m:=6*n;
    limit:=trunc(min(MAX_U,sqrt(m+10+eps)))+1;
    i:=0;
    while i < limit do begin
        inc(i);
        if m mod i = 0 then begin
            inc(nU); uoc[nU]:=i;
            inc(nU); uoc[nU]:=m div i;
        end;
    end;
    quick_sort(1,nU);
    uoc[0]:=-1;
    {writeln(n,' ',nU);
    i:=0;
    while i < nU do begin
        inc(i);
        write('  ',uoc[i]:0:0);
    end;
    writeln;}
end;

procedure   find(n:double);
var k:longint;
    i,j,a,b,c,delta,x,y:double;
    res:string;
begin
    res:='NO';
    for k:=1 to nU do begin
        i:=uoc[k];
        j:=i*i;
        a:=6*i;
        b:=6-6*j;
        c:=2*i*j-3*j+i-6*n;
        delta:=b*b-4*a*c;
        if delta >= 0 then begin
            x:=(-b-sqrt(delta))/(2*a);
            if (x >= i) and (x = trunc(x)) then begin
                y:=x-i;
                res:='YES';
                break;
            end;
            x:=(-b+sqrt(delta))/(2*a);
            if (x >= i) and (x = trunc(x)) then begin
                y:=x-i;
                res:='YES';
                break;
            end;
        end;
    end;
    writeln(fo,res);
    if res = 'YES' then writeln(fo,x:0:0,' ',y:0:0);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,n);
        init;
        find(n);
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
