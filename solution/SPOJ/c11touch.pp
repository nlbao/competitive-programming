uses    math;

const   MAX_N = 16;
        oo = 2000000000;

var fi,fo:text;
    n,i,j,res:longint;
    a,b:array[0..MAX_N,0..MAX_N] of longint;
    ch:char;

procedure   swap(var x:longint);    begin   x:=1-x; end;

procedure   touch(i,j:longint);
begin
    swap(b[i][j]);
    swap(b[i][j-1]);    swap(b[i][j+1]);
    swap(b[i-1][j]);    swap(b[i+1][j]);
end;

function    solve(mask,v:longint):longint;
var i,j,c:longint;
begin
    c:=0;
    fillchar(b,sizeof(b),0);
    for i:=1 to n do
        for j:=1 to n do b[i][j]:=a[i][j];
    for j:=1 to n do
        if ((mask shr (j-1)) and 1) = 1 then begin
            touch(1,j);
            inc(c);
        end;
    for i:=2 to n do
        for j:=1 to n do
            if b[i-1][j] <> v then begin
                touch(i,j);
                inc(c);
            end;
    for j:=1 to n do
        if b[n][j] <> v then exit(oo);
    exit(c);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'c11touch.in');       reset(fi);
    assign(fo,'c11touch.out');      rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    readln(fi,n);
    for i:=1 to n do begin
        for j:=1 to n do begin
            read(fi,ch);
            a[i][j]:=ord(ch)-ord('0');
        end;
        readln(fi);
    end;
    res:=oo;
    for i:=0 to (1 shl n)-1 do
        res:=min(res,min(solve(i,0),solve(i,1)));
    if res >= oo then res:=-1;
    writeln(fo,res);
    close(fo);
    close(fi);
end.


