const   MAX_P = 100010;

type    myStr = string[10];

var fi,fo:text;
    nTest,n,res,nP:longint;
    a:array[0..10,0..10] of char;
    is_prime:array[0..MAX_P] of boolean;
    p:array[0..MAX_P] of longint;

procedure   init;
var i,j:longint;
begin
    nP:=0;
    for i:=2 to MAX_P do is_prime[i]:=true;
    is_prime[0]:=false;
    is_prime[1]:=false;
    for i:=2 to MAX_P do
        if is_prime[i] then begin
            inc(nP);
            p[nP]:=i;
            j:=i+i;
            while j < MAX_P do begin
                is_prime[j]:=false;
                j:=j+i;
            end;
        end;
end;

procedure   enter;
var s:myStr;
    i:longint;
begin
    readln(fi,s);
    n:=length(s);
    for i:=1 to n do begin
        a[1][i]:=s[i];
        a[i][1]:=s[i];
    end;
end;

function    find(x:longint):longint;
var l,r,mid,t:longint;
begin
    l:=1;   r:=nP;  t:=nP+1;
    while l <= r do begin
        mid:=(l+r) shr 1;
        if p[mid] < x then l:=mid+1
        else begin
            t:=mid;
            r:=mid-1;
        end;
    end;
    exit(t);
end;

function    check(var t,s:myStr;    l:longint):boolean;
var i:longint;
    ok:boolean;
begin
    ok:=false;
    for i:=1 to length(s)-length(t) do
        if s[i] <> '0' then break
        else begin
            t:='0'+t;
            ok:=true;
        end;
    for i:=1 to l do
        if t[i] <> s[i] then exit(false);
    exit(true);
end;

procedure   tryf(i:longint);
var j,k:longint;
    s,t:myStr;
    ch:char;
begin
    if i > n then begin
        inc(res);
        exit;
    end;

    s:='';
    for j:=1 to i-1 do s:=s+a[i][j];
    for j:=i to n do s:=s+'0';
    val(s,k);
    j:=find(k);
    str(p[j],t);
    while (j <= nP) and (check(t,s,i-1)) do begin
        for k:=i to n do begin
            a[i][k]:=t[k];
            a[k][i]:=t[k];
        end;
        tryf(i+1);
        inc(j);
        str(p[j],t);
    end;
end;

procedure   solve;
begin
    res:=0;
    tryf(2);
    writeln(fo,res);
end;


begin
    assign(fi,'161E.in');   reset(fi);
    assign(fo,'161E.out');  rewrite(fo);
    init;
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.