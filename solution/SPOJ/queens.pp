const   MAX_N = 100;

var fi,fo:text;
    n,i,j:longint;
    a,b:array[0..MAX_N] of boolean;
    c,d:array[-2*MAX_N..2*MAX_N] of boolean;
    f:array[0..MAX_N,0..MAX_N] of boolean;
    res:boolean;

procedure   tryf(i:longint);
var j:longint;
begin
    if i > n then res:=true;
    if res then exit;
    for j:=1 to n do begin
        if (a[i]) and (b[j]) and (c[i-j]) and (d[i+j]) then begin
            f[i][j]:=true;
            a[i]:=false;    b[j]:=false;
            c[i-j]:=false;  d[i+j]:=false;
            tryf(i+1);
            if res then exit;
            c[i-j]:=true;   d[i+j]:=true;
            a[i]:=true;     b[j]:=true;
            f[i][j]:=false;
        end;
    end;
end;

begin
    assign(fi,'queens.in');     reset(fi);
    assign(fo,'queens.out');    rewrite(fo);
    readln(fi,n);
    fillchar(a,sizeof(a),true);
    fillchar(b,sizeof(b),true);
    fillchar(c,sizeof(c),true);
    fillchar(d,sizeof(d),true);
    fillchar(f,sizeof(f),false);
    res:=false;
    tryf(1);
    for i:=1 to n do
        for j:=1 to n do
            if f[i][j] then begin
                writeln(fo,i,' ',j);
                break;
            end;
    close(fo);
    close(fi);
end.