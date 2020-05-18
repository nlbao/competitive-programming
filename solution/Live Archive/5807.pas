uses    math;

const   MAX_N = 20;
        oo = 1000000000;

type    ll = int64;


var fi,fo:text;
    n,m,nTest,test_id:longint;
    f:array[0..MAX_N] of ll;
    c:array[0..MAX_N,0..MAX_N] of ll;



procedure   init();
var i,j:longint;
begin
    f[0]:=1;
    for i:=1 to MAX_N do
        f[i]:=f[i-1]*int64(i);

    fillchar(c,sizeof(c),0);
    c[0][0]:=1;
    for i:=1 to MAX_N do begin
        c[i][0]:=1;
        for j:=1 to i do
            c[i][j]:=c[i-1][j-1]+c[i-1][j];
    end;
end;


function    solve():ll;
var i:longint;
    res:ll;
begin
    if m = 1 then exit(f[n-1]);
    res:=0;
    for i:=0 to m-2 do
        res:=res + c[m-2][i]*f[i+1]*f[n-i-2];
    exit(res);
end;


begin
    assign(fi,'5807.in');    reset(fi);
    assign(fo,'5807.out');   rewrite(fo);
    init();
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,test_id,n,m);
        writeln(fo,test_id,' ',solve());
        dec(nTest);
    end;
    close(fi);
    close(fo);
end.