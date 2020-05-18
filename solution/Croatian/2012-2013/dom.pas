const   MAX_N = 200;

var fi,fo:text;
    s,t:ansiString;
    n,i,j:longint;
    ok:array[0..MAX_N] of boolean;




begin
    assign(fi,''{'dom.in'});    reset(fi);
    assign(fo,''{'dom.out'});   rewrite(fo);
    readln(fi,s);
    t:='CAMBRIDGE';
    n:=length(s);
    for i:=1 to n do ok[i]:=true;
    for i:=1 to n do
        for j:=1 to 9 do
            if s[i] = t[j] then begin
                ok[i]:=false;
                break;
            end;
    for i:=1 to n do if ok[i] then write(fo,s[i]);
    close(fo);
    close(fi);
end.
