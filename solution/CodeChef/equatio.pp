const   LIMIT = 1000010;

type    int = int64;

var fi,fo:text;
    nTest:int;
    a,b,c:int;
    is_prime:array[0..LIMIT] of boolean;
    p,f:array[0..LIMIT] of longint;

procedure   init;
var i,j:longint;
begin
    fillchar(f,sizeof(f),0);
    for i:=1 to LIMIT do begin
        j:=i;
        while j < LIMIT do begin
            inc(f[j]);
            inc(j,i);
        end;
    end;
end;

function    check(v:int):longint;
var u:int;
begin
    if (v = b) or ((a+c*v) mod (v-b) <> 0) then exit(0);
    u:=(a+c*v) div (v-b);
    if u < 1 then exit(0);
    if a = 2 then writeln(u,' ',v,' ',u*v,' ',f[u*v]);
    exit(f[u*v]);
end;

function    solve:longint;
var i,res:longint;
begin
    if a = 0 then exit(-1);
    res:=0;
    for i:=1 to abs(a) do
        if i*i > a then break
        else begin
            res:=res+check(i);
            res:=res+check(a div i);
        end;
    exit(res);
end;

begin
    assign(fi,'equatio.in');    reset(fi);
    assign(fo,'equatio.out');   rewrite(fo);
    init;
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,a,b,c);
        writeln(fo,solve);
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
