const   INPUT = 'Buying.in';
        OUTPUT = 'Buying.out';
        MAX_N = 50010;
        MAX_M = 50010;
        MAX_K = 30;

function    min(x,y:int64):int64;   begin if x < y then exit(x) else exit(y);   end;

procedure   enter;
var i:longint;
begin
    readln(fi,n,m,k);
    for i:=1 to n do read(fi,a[i]);

end;

function    solve:longint;
begin
    if m > n then exit(-1);
    fillchar(f,sizeof(f),0);
    for i:=1 to n do
        for j:=1 to k do begin
            t:=(a[i]+f[

        end;


end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,nTest);
    while nTest > 0 do begin
        enter;
        writeln(fo,solve);
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.