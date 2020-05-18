const   INPUT = 'SPSEQ.in';
        OUTPUT = 'SPSEQ.out';
        MAX_N = 100010;

var fi,fo:text;
    n,top:longint;
    a,s,f,g:array[0..MAX_N] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x)   else exit(y);   end;

function    max(x,y:longint):longint;   begin   if x > y then exit(x)   else exit(y);   end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    for i:=1 to n do read(fi,a[i]);
end;

function    find(x:longint):longint;
var l,r,mid,t:longint;
begin
    l:=1;   r:=top; t:=0;
    while l <= r do begin
        mid:=(l+r) shr 1;
        if s[mid] < x then begin
            t:=mid;
            l:=mid+1;
        end
        else r:=mid-1;
    end;
    exit(t);
end;

procedure   cal_f;
var i,j:longint;
begin
    top:=1; s[1]:=a[1];
    f[1]:=1;
    for i:=2 to n do begin
        j:=find(a[i])+1;
        if j > top then inc(top);
        s[j]:=a[i];
        f[i]:=j;
    end;
end;

procedure   cal_g;
var i,j:longint;
begin
    top:=1; s[1]:=a[n];
    g[n]:=1;
    for i:=n-1 downto 1 do begin
        j:=find(a[i])+1;
        if j > top then inc(top);
        s[j]:=a[i];
        g[i]:=j;
    end;
end;

procedure   solve;
var i,res:longint;
begin
    cal_f;
    cal_g;
    res:=1;
    for i:=1 to n do
        res:=max(res,2*min(f[i],g[i])-1);
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.