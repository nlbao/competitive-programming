
var fi,fo:text;
    n1,n2,t,i,j:longint;
    s1,s2,res:ansiString;
    a:array[0..1000000] of boolean;

procedure   swap(i,j:longint);
var t:boolean;
    ch:char;
begin
    t:=a[i];    a[i]:=a[j];     a[j]:=t;
    ch:=res[i]; res[i]:=res[j]; res[j]:=ch;
end;

begin
    assign(fi,'kolone.in');     reset(fi);
    assign(fo,'kolone.out');    rewrite(fo);
    readln(fi,n1,n2);
    readln(fi,s1);
    readln(fi,s2);
    readln(fi,t);
    res:=s2;
    for i:=1 to n1 do res:=s1[i]+res;
    for i:=1 to n1 do a[i]:=true;
    for i:=n1+1 to n1+n2 do a[i]:=false;
    for j:=1 to t do begin
        i:=n1+n2;
        while (i > 1) do
            if (a[i] = false) and (a[i-1] = true) then begin
                swap(i-1,i);
                i:=i-2;
            end
            else i:=i-1;
        //writeln(res);
        //for i:=1 to n1+n2 do write(longint(a[i]));
        //writeln;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.