const   MAX_N = 1000010;
        MAX_P = 1010;

var fi,fo:text;
    i,j,nTest,id,n,nP,res:longint;
    ok:array[0..MAX_P] of boolean;
    p:array[0..MAX_P] of longint;

begin
    assign(fi,'etf.in');    reset(fi);
    assign(fo,'etf.out');   rewrite(fo);
    fillchar(ok,sizeof(ok),true);
    ok[1]:=false;
    nP:=0;
    for i:=2 to MAX_P do
        if ok[i] then begin
            inc(nP);
            p[nP]:=i;
            j:=i+i;
            while j < MAX_P do begin
                ok[j]:=false;
                j:=j+i;
            end;
        end;

    read(fi,nTest);
    for id:=1 to nTest do begin
        read(fi,n);
        res:=n;
        for i:=1 to nP do begin
            j:=p[i];
            if j*j > n then break;
            if n mod j <> 0 then continue;
            res:=res-(res div j);
            while n mod j = 0 do n:=n div j;
        end;
        if n > 1 then res:=res-(res div n);
        writeln(fo,res);
    end;
    close(fo);
    close(fi);
end.