const   INPUT = 'SubStr.inp';
        OUTPUT = 'SubStr.out';
        MAX_N = 1000010;
        MAX_M = 1000010;

type    str = ansiString;

var fi,fo:text;
    s,w:str;
    t:array[0..MAX_M] of longint;

procedure   enter;
begin
    readln(fi,s);
    readln(fi,w);
end;

procedure   KMP_table(var w:str);
var i,j,m:longint;
begin
    m:=length(w);
    j:=0;   t[1]:=0;
    for i:=2 to m do begin
        while (j > 0) and (w[j+1] <> w[i]) do j:=t[j];
        if w[j+1] = w[i] then inc(j);
        t[i]:=j;
    end;
end;

procedure   KMP_search(var s,w:str);
var i,j,n,m:longint;
begin
    KMP_table(w);
    n:=length(s);   m:=length(w);
    j:=0;
    for i:=1 to n do begin
        while (j > 0) and (w[j+1] <> s[i]) do j:=t[j];
        if w[j+1] = s[i] then inc(j);
        if j = m then begin
            write(fo,i-m+1,' ');
            j:=t[m];
        end;
    end;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    KMP_search(s,w);
    close(fo);
    close(fi);
end.