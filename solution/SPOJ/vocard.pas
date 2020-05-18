{$M 16777216}
uses    math;

const   MAX_N = 2000006;
        oo = 1000000000;

var fi,fo:text;
    n,k:longint;
    a:ansiString;
    s,q,f:array[0..MAX_N] of longint;


procedure   enter();
var i:longint;
begin
    readln(fi,n,k);
    readln(fi,a);
    s[0]:=0;
    for i:=1 to n do
        s[i]:=s[i-1] + longint(a[i] = '1');
end;

procedure   solve();
var i,l,r:longint;
begin
    f[0]:=0;
    l:=1;   r:=1;
    q[1]:=0;
    for i:=1 to n do begin
        if i <= k then f[i]:=s[i]
        else f[i]:=0;
        while (l <= r) and (q[l]+k < i) do inc(l);
        if l <= r then f[i]:=max(f[i], s[i]-f[q[l]]);

        while (l <= r) and (f[q[r]] >= f[i]) do dec(r);
        inc(r); q[r]:=i;
    end;

    if f[n]*2 = s[n] then writeln(fo,'NO')
    else begin
        writeln(fo,'YES');
        writeln(fo,min(s[n]-f[n],f[n]));
    end;
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'VOCARD.in');    reset(fi);
    assign(fo,'VOCARD.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.