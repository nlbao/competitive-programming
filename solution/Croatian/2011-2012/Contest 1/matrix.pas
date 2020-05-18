const
    INPUT = ''{'matrix.inp'};
    OUTPUT = ''{'matrix.out'};
    MAX_N = 410;

var
    fi,fo:text;
    N:longint;
    a,sum:array[0..MAX_N,0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i,j:longint;
begin
    readln(fi,N);
    for i:=1 to N do begin
        for j:=1 to N do read(fi,a[i,j]);
        readln(fi);
    end;
end;
{---------------------------------------------------------------------------}
procedure   cal_sum;
var
    i,j:longint;
begin
    for j:=1 to N+1 do sum[0,j]:=0;
    for i:=0 to N+1 do sum[i,N+1]:=0;
    for i:=1 to N do
        for j:=1 to N do
            sum[i,j]:=sum[i-1,j+1]+a[i,j];
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,k,t:longint;
    s,res:longint;
begin
    res:=0;
    for i:=1 to N do
        for j:=1 to N do begin
            s:=a[i,j];
            t:=j;
            for k:=i+1 to N do begin
                inc(t);
                if t > N then break;
                s:=s+a[k,t];
                if s-sum[k,j]+sum[i-1,t+1] > res then
                    res:=s-sum[k,j]+sum[i-1,t+1];
            end;
        end;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    cal_sum;
    solve;
    close(fo);
    close(fi);
end.