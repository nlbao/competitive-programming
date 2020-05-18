uses    math;

const   MAX_M = 10;
        MAX_N = 10;
        MAX_P = 200010;

var fi,fo:text;
    nTest,m,n,nP:longint;
    a,head:array[0..MAX_M,0..MAX_N] of longint;
    p:array[0..MAX_P] of longint;

function    get_bit_a(r,c:longint):longint;
var i,j,x:longint;
begin
    x:=0;
    for i:=1 to r do
        for j:=1 to c do
            if a[i][j] > 0 then
                x:=x or (1 shl (c*(i-1)+j-1));
    exit(x);
end;

function    check(r,c:longint):boolean;
var len,k,i,rr,cc:longint;
    s:array[0..1] of longint;
begin
    len:=min(r,c);
    s[0]:=0;    s[1]:=0;
    for k:=1 to len do begin
        rr:=r-k+1;  cc:=c-k+1;
        for i:=rr to r do inc(s[a[i][cc]]);
        for i:=cc+1 to c do inc(s[a[rr][i]]);
        if abs(s[0]-s[1]) > 2 then exit(false);
    end;
    exit(true);
end;

procedure   tryf(r,c:longint);
var i:longint;
begin
    if r > m then begin
        inc(nP);
        p[nP]:=get_bit_a(m,n);
        exit;
    end;
    if c > n then begin
        tryf(r+1,1);
        exit;
    end;
    for i:=0 to 1 do begin
        a[r][c]:=i;
        if check(r,c) = true then tryf(r,c+1);
        a[r][c]:=-1;
    end;
end;

procedure   init();
begin
    nP:=0;
    fillchar(head,sizeof(head),0);
    for m:=1 to 5 do begin
        for n:=1 to 5 do begin
            tryf(1,1);
            head[m][n]:=nP;
        end;
        head[m+1][0]:=head[m][5];
    end;
end;

procedure   enter();
var i,j:longint;
    ch:char;
begin
    fillchar(a,sizeof(a),0);
    readln(fi,m,n);
    for i:=1 to m do begin
        for j:=1 to n do begin
            read(fi,ch);
            if ch = 'B' then a[i][j]:=0
            else if ch = 'R' then a[i][j]:=1
            else a[i][j]:=-1;
        end;
        readln(fi);
    end;
end;

function    solve():longint;
var i,j,k,t1,t2,res:longint;
begin
    res:=0;
    t1:=get_bit_a(m,n);
    t2:=0;
    for i:=1 to m do
        for j:=1 to n do
            if a[i][j] >= 0 then t2:=t2 or (1 shl (n*(i-1)+j-1));

    for k:=head[m][n-1]+1 to head[m][n] do
        if ((p[k] xor t1) and t2) = 0 then inc(res);
    exit(res);
end;

begin
    assign(fi,'eurocard.in');   reset(fi);
    assign(fo,'eurocard.out');  rewrite(fo);
    init();
    read(fi,nTest);
    while nTest > 0 do begin
        enter();
        writeln(fo,solve());
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.
