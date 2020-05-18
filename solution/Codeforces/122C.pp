const
    INPUT = '122C.inp';
    OUTPUT = '122C.out';
    MAX_R = 1000000000;
    MAX_N = 1050;
    num:array[1..2] of char = ('4','7');

var
    fi,fo:text;
    L,R,N,err:longint;
    s:string;
    a:array[0..MAX_N] of int64;

{---------------------------------------------------------------------------}
procedure   sinh(i,k:longint);
var
    j:longint;
begin
    if i > k then begin
        inc(N);
        val(s,a[N],err);
        exit;
    end;
    for j:=1 to 2 do begin
        s:=s+num[j];
        sinh(i+1,k);
        delete(s,i,1);
    end;
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    i:longint;
begin
    N:=0;
    for i:=1 to 9 do begin
        s:='';
        sinh(1,i);
    end;
    a[0]:=0;   a[N+1]:=4444444444;
end;
{---------------------------------------------------------------------------}
function    solve(x:int64):int64;
var
    i:longint;
    sum:int64;
begin
    if x = 0 then exit(0);
    sum:=0;
    i:=1;
    while (a[i] <= x) and (i <= N) do begin
        sum:=sum+(a[i]-a[i-1])*a[i];
        inc(i);
    end;
    sum:=sum+(x-a[i-1])*a[i];
    exit(sum);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,L,R);
    init;
    writeln(fo,solve(R)-solve(L-1));
    close(fo);
    close(fi);
end.