{$M 16777216}
uses    math;

const   MAX_N = 1003;
        oo = 1000000000;

var fi,fo:text;
    m,n,k:longint;
    a,b:array[0..MAX_N,0..MAX_N] of longint;
    f,g:array[0..2*MAX_N] of longint;


procedure   enter();
var i,j:longint;
begin
    read(fi,m,n,k);
    for i:=1 to m do
        for j:=1 to n do read(fi,b[i][j]);
end;


procedure   row(id,c:longint);
var i:longint;
begin
    g[id]:=c;
    for i:=1 to n do a[id][i]:=(a[id][i]+c) mod k;
end;


procedure   col(id,c:longint);
var i:longint;
begin
    g[id+m]:=c;
    for i:=1 to m do a[i][id]:=(a[i][id]+c) mod k;
end;


function    check():boolean;
var i,j:longint;
begin
    for i:=1 to m do
        for j:=1 to n do
            if a[i][j] <> 0 then exit(false);
    exit(true);
end;



function    solve():longint;
var id,i,t,sum,res:longint;
begin
    res:=oo;
    a:=b;
    if check() then res:=0;
    for id:=0 to k-1 do begin
        a:=b;
        row(1,id);
        sum:=id;
        for i:=1 to n do begin
            t:=(k-a[1][i]) mod k;
            col(i,t);
            sum:=sum+t;
        end;
        for i:=2 to m do begin
            t:=(k-a[i][1]) mod k;
            row(i,t);
            sum:=sum+t;
        end;
        if (check()) and (sum < res) then begin
            res:=sum;
            for i:=1 to m do f[i]:=g[i];
            for i:=1 to n do f[i+m]:=g[i+m];
        end;
    end;

    writeln(fo,res);
    for i:=1 to m do write(fo,f[i],' ');    writeln(fo);
    for i:=1 to n do write(fo,f[i+m],' ');  writeln(fo);
end;



begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'VOBOARD.in');    reset(fi);
    assign(fo,'VOBOARD.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.