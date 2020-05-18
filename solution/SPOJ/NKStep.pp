const
    INPUT = 'NKStep.inp';
    OUTPUT = 'NKStep.out';

var
    fi,fo:text;
    i,T:longint;
    X,Y,Res:int64;

procedure   Solve(X,Y:longint);
var
    S,l,r,mid,a,k:int64;
begin
    Res:=0;
    S:=abs(X-Y);
    if S = 0 then exit;
    l:=0;   r:=100000;
    while l <= r do
        begin
            mid:=(l+r) div 2;
            if S-sqr(mid) < 0 then r:=mid-1
            else l:=mid+1;
        end;
    a:=r;
    while (a > 0) and (S-sqr(a) > 2*a) do dec(a);
    if a = 0 then exit;
    k:=S-sqr(a);
    if k = 0 then Res:=2*a-1
    else
        if k <= a then Res:=2*a
        else Res:=2*a+1;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,T);
    for i:=1 to T do
        begin
            readln(fi,X,Y);
            Solve(X,Y);
            writeln(fo,Res);
        end;
    close(fo);
    close(fi);
end.