{$R+, $I+}
{$M 16777216}

uses    math;

const   MAX_N = 1010;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    n,i,j:longint;
    a,d:array[0..MAX_N] of ll;
    p,res,sum,t:ll;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'241A.in');    reset(fi);
    assign(fo,'241A.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n,p);
    for i:=1 to n do read(fi,d[i]);
    for i:=1 to n do read(fi,a[i]);
    inc(n);

    res:=0;
    j:=1;   sum:=a[1];
    for i:=2 to n do begin
        if sum < d[i-1] then begin
            t:=d[i-1]-sum;
            if t mod a[j] > 0 then t:=(t div a[j]) + 1
            else t:=t div a[j];
        end
        else t:=0;
        sum:=sum + t*a[j] - d[i-1] + a[i];
        res:=res + t*p + d[i-1];
        if a[i] > a[j] then j:=i;
    end;
    writeln(fo,res);
    close(fi);
    close(fo);
end.


