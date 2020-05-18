uses    math;

const   MAX_N = 15010;
        oo = 10000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,k,i:longint;
    l,r,mid,res:ll;
    a,s:array[0..MAX_N] of ll;
    f:array[0..1,0..MAX_N] of ll;


procedure   enter();
begin
    read(fi,n,k);
    for i:=1 to n do read(fi,a[i]);
end;


function    check(limit:ll):boolean;
var i,c:longint;
    sum:ll;
begin
    c:=1;
    sum:=a[1];
    for i:=2 to n do
        if sum <= limit then begin
            if a[i] < 0 then begin
                if c < k then begin
                    sum:=a[i];
                    inc(c);
                end
                else sum:=sum+a[i];
            end
            else if (sum+a[i] <= limit) and (n-i >= k-c) then sum:=sum+a[i]
            else if c < k then begin
                sum:=a[i];
                inc(c);
            end
            else sum:=sum+a[i];
        end
        else sum:=sum+a[i];
    if (sum > limit) or (c < k) then exit(false);
    exit(true);
end;


procedure   solve_1();
var l,r,mid:ll;
    i:longint;
begin
    l:=0;   r:=0;
    for i:=1 to n do
        if a[i] < 0 then l:=l+a[i]
        else r:=r+a[i];
    while l <= r do begin
        mid:=(l+r) div 2;
        writeln(l,' ',r,'  ',mid,'        ',res);
        if check(mid) then begin
            res:=mid;
            r:=mid-1;
        end
        else l:=mid+1;
    end;
end;

procedure   solve_2();
var i,j,jj,t,tt:longint;
begin
    s[0]:=0;
    for i:=1 to n do s[i]:=s[i-1]+a[i];

    t:=0;
    for i:=0 to n do begin
        f[0][i]:=s[i];
        f[1][i]:=oo;
    end;

    for i:=2 to k do begin
        tt:=t;
        t:=(t+1) and 1;
        for j:=i to n do begin
            f[t][j]:=oo;
            for jj:=i-1 to j-1 do
                f[t][j]:=min(f[t][j], max(f[tt][jj], s[j]-s[jj]));
        end;
    end;
    res:=min(res,f[t][n]);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'QBSEGPAR.in');   reset(fi);
    assign(fo,'QBSEGPAR.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    enter();
    res:=oo;
    solve_1();
    if n <= 700 then solve_2();
    writeln(fo,res);
    close(fi);
    close(fo);
end.