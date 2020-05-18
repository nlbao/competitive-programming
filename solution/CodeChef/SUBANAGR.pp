const   INPUT = 'SUBANAGR.in';
        OUTPUT = 'SUBANAGR.out';
        MAX_N = 110;
        MAX_M = 110;

type    str = ansiString;

var fi,fo:text;
    n:longint;
    s:array[0..MAX_N] of str;
    f,tf:array[0..MAX_M,0..MAX_M] of longint;
    pos,tp:array[0..MAX_M,0..MAX_N] of longint;

procedure   quick_sort(var  x:str;  l,r:longint);
var i,j:longint;
    p,tmp:char;
begin
    if l >= r then exit;
    i:=l;   j:=r;
    p:=x[(i+j) shr 1];
    repeat
        while x[i] < p do inc(i);
        while x[j] > p do dec(j);
        if i <= j then begin
            tmp:=x[i]; x[i]:=x[j];  x[j]:=tmp;
            inc(i); dec(j);
        end;
    until i >= j;
    quick_sort(x,l,j);  quick_sort(x,i,r);
end;

procedure   enter;
var i,j:longint;
    tmp:str;
begin
    readln(fi,n);
    for i:=1 to n do begin
        readln(fi,s[i]);
        quick_sort(s[i],1,length(s[i]));
    end;
    for i:=1 to n-1 do
        for j:=i+1 to n do
            if length(s[i]) > length(s[j]) then begin
                tmp:=s[i];  s[i]:=s[j]; s[j]:=tmp;
            end;
end;

function    check(i,j:longint;  ch:char):longint;
begin
    while (pos[i][j] <= length(s[j])) and (s[j][pos[i][j]] <> ch) do inc(pos[i][j]);
    if pos[i][j] > length(s[j]) then exit(-1)
    else exit(0);
end;

function    solve:str;
var m,i,j,k,len:longint;
    ok:boolean;
    res:str;
begin
    if n = 1 then exit(s[1]);
    m:=length(s[1]);
    ok:=false;
    for i:=1 to m do begin
        for j:=2 to n do begin
            pos[i][j]:=1;
            f[1][i]:=check(i,j,s[1][i]);
            if f[1][i] = -1 then break;
        end;
        if f[1][i] > -1 then ok:=true;
    end;
    if not ok then exit('no such string');
    for len:=2 to m do begin
        ok:=false;
        tf:=f;  tp:=pos;
        for i:=1 to m do f[len][i]:=-1;
        for i:=len to m do begin
            for k:=len-1 to i-1 do if f[len-1][k] > -1 then begin
                for j:=2 to n do begin
                    pos[k][j]:=tp[k][j]+1;
                    f[len][i]:=check(k,j,s[1][i]);
                    if f[len][i] = -1 then break;
                end;
                if f[len][i] > -1 then begin
                    ok:=true;
                    f[len][i]:=k;
                    break;
                end;
            end;
        end;
        if ok = false then break;
    end;
    if not ok then dec(len);
    res:='';
    for i:=1 to m do if f[len][i] > -1 then break;
    repeat
        res:=s[1][i]+res;
        i:=f[len][i];
        dec(len);
    until i < 1;
    exit(res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    writeln(fo,solve);
    close(fo);
    close(fi);
end.