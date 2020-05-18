const   INPUT = '44H.in';
        OUTPUT = '44H.out';
        MAX_N = 60;

var fi,fo:text;
    n:longint;
    a:array[0..MAX_N] of longint;

procedure   enter;
var i:longint;
    s:string;
begin
    readln(fi,s);
    n:=length(s);
    for i:=1 to length(s) do a[i]:=ord(s[i])-ord('0');
end;

function    check:boolean;
var i,j,k:longint;
begin
    j:=a[1];
    for i:=2 to n do begin
        k:=(j+a[i]) div 2;
        if (k <> a[i]) and (k+1 <> a[i]) then exit(false);
        j:=a[i];
    end;
    exit(true);
end;

procedure   solve;
var i,j,k,r:longint;
    res:int64;
    ok:boolean;
    f:array[0..MAX_N,0..9] of int64;
begin
    if check = true then res:=-1
    else res:=0;

    for j:=0 to 9 do f[n][j]:=1;
    for i:=n-1 downto 1 do
        for j:=0 to 9 do begin
            k:=(j+a[i+1]) div 2;
            if (j+a[i+1]) mod 2 = 0 then f[i][j]:=f[i+1][k]
            else f[i][j]:=f[i+1][k]+f[i+1][k+1];
        end;

    for j:=0 to 9 do begin
        k:=j;   ok:=true;
        for i:=2 to n do
            if (k+a[i]) mod 2 = 1 then begin
                ok:=false;
                break;
            end
            else k:=(k+a[i]) div 2;
        if ok = true then res:=res+1
        else res:=res+f[i-1][k];
    end;
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.