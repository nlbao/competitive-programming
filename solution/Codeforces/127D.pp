const   INPUT = '127D.in';
        OUTPUT = '127D.out';
        MAX_N = 1000010;

type    str = ansiString;

var fi,fo:text;
    n,i:longint;
    s,res:str;
    t,c:array[0..MAX_N] of longint;

procedure   KMP_table(var w:str;    nW:longint);
var i,j:longint;
begin
    for i:=1 to nW do c[i]:=0;
    t[1]:=0;
    j:=0;
    for i:=2 to nW do begin
        while (j > 0) and (w[j+1] <> w[i]) do j:=t[j];
        if w[j+1] = w[i] then inc(j);
        t[i]:=j;
        inc(c[t[i]]);
    end;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,s);
    n:=length(s);
    KMP_table(s,n);
    res:='Just a legend';
    if (t[n] = n-1) and (n > 2) then res:=copy(s,1,n-2)
    else
        if (t[n] > 0) and (c[t[n]] > 1) then res:=copy(s,1,t[n])
        else begin
            i:=t[t[n]];
            while i > 0 do begin
                if c[i] > 0 then begin
                    res:=copy(s,1,i);
                    break;
                end;
                i:=t[i];
            end;
        end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.