{$R+, $I+}
{$M 16777216}

uses    math;

const   MAX_N = 33;
        MAX_P = 3010;
        oo = 1000000000;

type    ll = int64;
        recEdge = record
            x,y:longint;
            link:longint;
        end;

var fi,fo:text;
    nTest,n:longint;
    a,dau,s,c:array[0..MAX_N] of longint;
    ok:array[0..MAX_N,-MAX_P..MAX_P] of boolean;
    p:array[0..MAX_N,0..2*MAX_P] of longint;


function    get_dau(x:char):longint;
begin
    if x = '+' then exit(1);
    if x = '-' then exit(-1);
    exit(0);
end;


procedure   enter();
var i,j,len,err:longint;
    s:ansiString;
begin
    n:=0;
    a[0]:=0;
    dau[0]:=1;
    readln(fi,s);
    len:=length(s);
    i:=1;
    while i <= len do begin
        j:=i;
        while (j < len) and (get_dau(s[j+1]) = 0) do inc(j);
        inc(n);
        val(copy(s,i,j-i+1),a[n],err);
        if j < len then dau[n]:=get_dau(s[j+1]);
        i:=j+2;
    end;
end;



procedure   push(x,i:longint);
begin
    if ok[i][x] then exit;
    inc(c[i]);
    p[i][c[i]]:=x;
    ok[i][x]:=true;
end;


procedure   solve();
var i,j,k,sum,x,y:longint;
begin
    fillchar(ok,sizeof(ok),false);
    fillchar(c,sizeof(c),0);
    push(a[1],1);

    for i:=2 to n do begin
        sum:=0;
        for j:=i downto 1 do begin
            sum:=sum + a[j];
            x:=sum*dau[j-1];
            for k:=1 to c[j-1] do begin
                y:=x + p[j-1][k];
                push(y,i);
            end;
            sum:=sum - a[j] + a[j]*dau[j-1];
        end;
    end;
    writeln(fo,c[n]);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'C11FBR.in');    reset(fi);
    assign(fo,'C11FBR.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    for nTest:=1 to 5 do begin
        enter();
        solve();
    end;
    close(fi);
    close(fo);
end.

