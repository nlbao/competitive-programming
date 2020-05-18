const   INPUT = {''}'zadaca.in';
        OUTPUT = {''}'zadaca.out';
        MAX_N = 1010;
        MAX_M = 1010;
        MAX_P = 35000;
        MODUN = 1000000000;

type    arr = array[0..10000] of longint;
        arrA = array[0..MAX_N] of longint;

var fi,fo:text;
    n,m,nP,cA,cB:longint;
    a,b:arrA;
    p:array[0..MAX_P] of longint;
    pA,pB:arr;

function    min(x,y:longint):longint;   begin   if x < y then exit(x) else exit(y); end;

procedure   enter;
var i:longint;
begin
    read(fi,n);
    for i:=1 to n do read(fi,a[i]);
    read(fi,m);
    for i:=1 to m do read(fi,b[i]);
end;

procedure   Eratothenes;
var i,j:longint;
    is_prime:array[0..MAX_P] of boolean;
begin
    nP:=0;
    for i:=2 to MAX_P do is_prime[i]:=true;
    for i:=2 to MAX_P do
        if is_prime[i] then begin
            inc(nP);
            p[nP]:=i;
            j:=i+i;
            while j <= MAX_P do begin
                is_prime[j]:=false;
                j:=j+i;
            end;
        end;
end;

procedure   quick_sort(var x:arr;   l,r:longint);
var i,j,p,tmp:longint;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=x[(i+j) shr 1];
    repeat
        while x[i] < p do inc(i);
        while x[j] > p do dec(j);
        if i <= j then begin
            tmp:=x[i]; x[i]:=x[j];  x[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(x,l,j);  quick_sort(x,i,r);
end;

procedure   init(var x:arrA;    nX:longint; var pX:arr; var cX:longint);
var i,j:longint;
    procedure   add(value:longint); begin   inc(cX); pX[cX]:=value;    end;
begin
    cX:=0;
    for i:=1 to nX do begin
        for j:=1 to nP do
            if p[j] > x[i] then break
            else while (x[i] mod p[j]) = 0 do begin
                add(p[j]);
                x[i]:=x[i] div p[j];
            end;
        if x[i] > 1 then add(x[i]);
    end;
    quick_sort(pX,1,cX);
end;

procedure   solve;
var i,j,k,t,h:longint;
    tmp,res:int64;
    check:boolean;
    s:string;
begin
    init(a,n,pA,cA);
    init(b,m,pB,cB);

    res:=1; check:=false;
    pA[cA+1]:=-1;   pB[cB+1]:=MODUN+1;
    i:=1;   j:=1;
    while (i <= cA) and (j <= cB) do begin
        k:=i;
        while pA[k+1] = pA[i] do inc(k);
        while pB[j] < pA[i] do inc(j);
        if pB[j] = pA[i] then begin
            t:=j;
            while pB[t+1] = pB[j] do inc(t);
            tmp:=pA[i];
            for h:=1 to min(k-i+1,t-j+1) do begin
                res:=res*tmp;
                if res >= MODUN then begin
                    check:=true;
                    res:=res mod MODUN;
                end;
            end;
            j:=t+1;
        end;
        i:=k+1;
    end;
    str(res,s);
    if check = true then while length(s) < 9 do s:='0'+s;
    writeln(fo,s);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    Eratothenes;
    solve;
    close(fo);
    close(fi);
end.