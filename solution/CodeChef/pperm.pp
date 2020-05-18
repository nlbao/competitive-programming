const   MAX_N = 5000004;
        MODUN = 1000000007;

var fi,fo:text;
    n,nTest,i,j,id:longint;
    ok:array[0..MAX_N] of boolean;
    c:array[0..MAX_N] of int64;
    res:int64;

begin
    assign(fi,'pperm.in');  reset(fi);
    assign(fo,'pperm.out'); rewrite(fo);
    fillchar(ok,sizeof(ok),true);
    i:=4;
    while i < MAX_N do begin
        ok[i]:=false;
        i:=i*2;
    end;
    i:=3;
    while i*i < MAX_N do begin
        if ok[i] then begin
            j:=i*i;
            while j < MAX_N do begin
                ok[j]:=false;
                j:=j+i;
            end;
        end;
        i:=i+2;
    end;

    c[1]:=1;
    for i:=2 to MAX_N-1 do c[i]:=c[i-1]+longint(ok[i]);

    read(fi,nTest);
    for id:=1 to nTest do begin
        read(fi,n);
        res:=1;
        for i:=1 to n do res:=(res*c[i]) mod MODUN;
        writeln(fo,res);
    end;
    close(fo);
    close(fi);
end.