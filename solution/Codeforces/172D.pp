const   MAX_N = 10000010;

var fi,fo:text;
    a,n,i,j:longint;
    t:double;
    f:array[0..MAX_N] of longint;
    res:int64;

begin
    assign(fi,'172D.in');   reset(fi);
    assign(fo,'172D.out');  rewrite(fo);
    readln(fi,a,n);
    res:=0;
    fillchar(f,sizeof(f),0);
    for i:=1 to MAX_N do begin
        t:=sqrt(i);
        if t = trunc(t) then begin
            j:=i;
            while j < MAX_N do begin
                f[j]:=i;
                j:=j+i;
            end;
        end;
        if (a <= i) and (i <= a+n-1) then
            if f[i] = 0 then res:=res+1
            else res:=res+int64(i div f[i]);
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.