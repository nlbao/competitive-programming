const   INPUT = '31E.in';
        OUTPUT = '31E.out';
        MAX_N = 18;

type    int = qword;

var fi,fo:text;
    n,m:longint;
    s:string;
    a,b,p:array[0..2*MAX_N] of int;
    f:array[0..2*MAX_N,0..MAX_N,0..1] of int;
    trace:array[0..2*MAX_N,0..MAX_N,0..1] of longint;

function    min(x,y:longint):longint;   begin   if x < y then exit(x)   else exit(y);   end;

function    max(x,y:longint):longint;   begin   if x > y then exit(x)   else exit(y);   end;

procedure   update(i,j:longint; x,y:int);   begin   f[i][j][0]:=x;  f[i][j][1]:=y;   end;

procedure   update_trace(i,j,x,y:longint);   begin   trace[i][j][0]:=x;  trace[i][j][1]:=y;   end;

function    cal(l,r,j:longint):int;
var i,k:longint;
    t:int;
begin
    t:=f[r][j][1];
    k:=(m-r+1)-j;
    for i:=r-1 downto l do t:=a[i]*p[k+r-i-1]+t;
    exit(t);
end;

procedure   tryf(i,j,ii,jj:longint;    x,y:int);
begin
    if x+y >= f[i][j][0]+f[i][j][1] then begin
        update(i,j,x,y);
        update_trace(i,j,ii,jj);
    end;
end;

procedure   enter;
var i:longint;
begin
    readln(fi,n);
    readln(fi,s);   m:=length(s);
    for i:=1 to m do a[i]:=ord(s[i])-ord('0');
    p[0]:=1;
    for i:=1 to n do p[i]:=p[i-1]*10;
    b[m]:=a[m];
    for i:=m-1 downto n+1 do b[i]:=a[i]*p[m-i]+b[i+1];
end;

procedure   solve;
var i,j,ii:longint;
    t:int;
begin
    fillchar(f,sizeof(f),0);
    fillchar(trace,sizeof(trace),0);
    update(m,0,0,a[m]);
    update(m,1,a[m],0);
    for i:=m-1 downto 1 do begin
        if i > n then begin
            update(i,0,0,b[i]);
            update(i,m-i+1,b[i],0);
        end;
        for j:=1 to min(m-i,n) do begin
            t:=a[i]*p[j-1];
            for ii:=min(m-j+2,m) downto i+1 do begin
                tryf(i,j,ii,j-1,t+f[ii][j-1][0],cal(i+1,ii,j-1));
                if m-ii+1 >= j then tryf(i,j,ii,j,f[ii][j][0],cal(i,ii,j));
            end;
        end;
    end;
end;

procedure   print_result;
var i,j,k,nH:longint;
    res:array[1..2*MAX_N] of char;
begin
    for i:=1 to m do res[i]:=' ';
    i:=1;   j:=n;
    nH:=0;
    repeat
        if trace[i][j][1] <> j then begin
            res[i]:='H';
            inc(nH);
        end
        else res[i]:='M';
        for k:=i+1 to trace[i][j][0]-1 do res[k]:='M';
        k:=i;
        i:=trace[k][j][0]; j:=trace[k][j][1];
    until (i = 0) or (j = 0);
    if nH < n then for i:=1 to m do if res[i] = ' ' then res[i]:='H';
    if nH >= n then for i:=1 to m do if res[i] = ' ' then res[i]:='M';
    for i:=1 to m do write(fo,res[i]);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    print_result;
    close(fo);
    close(fi);
end.