const   MAX_N = 1004;
        MAX_P = 2*MAX_N;
        MODUN = 1000000;

var fi,fo:text;
    n,nP,i,j,k:longint;
    ok:array[0..MAX_P] of boolean;
    pos:array[0..MAX_P] of longint;
    p,c,f:array[0..MAX_N] of longint;

{procedure   init;
var
    i,j:longint;
begin
    f[0]:=0;
    f[1]:=1;
    res[1]:=1;
    for i:=2 to MAX_N do begin
        f[i]:=0;
        res[i]:=0;
        for j:=1 to i do begin
            f[j]:=(f[j-1]+f[j]) mod MODUN;
            res[i]:=(res[i]+f[j]) mod MODUN;
        end;
    end;
end;  }



procedure   add(n,d:longint);
var i,j:longint;
begin
    for i:=2 to n do
        if i*i > n then break
        else if n mod i = 0 then begin
            j:=pos[i];
            while n mod i = 0 do begin
                c[j]:=c[j]+d;
                n:=n div i;
            end;
        end;
    if n > 1 then begin
        j:=pos[n];
        c[j]:=c[j]+d;
    end;
end;

begin
    assign(fi,'skyline.in');    reset(fi);
    assign(fo,'skyline.out');   rewrite(fo);

    fillchar(ok,sizeof(ok),true);
    nP:=0;
    for i:=2 to MAX_P do
        if ok[i] then begin
            inc(nP);
            p[nP]:=i;
            pos[i]:=nP;
            j:=i*i;
            while j < MAX_P do begin
                ok[j]:=false;
                j:=j+i;
            end;
        end;

    fillchar(c,sizeof(c),0);
    f[0]:=1;
    f[1]:=1;
    for i:=2 to MAX_N do begin
        add(2*i-1,1);
        add(2*i,1);
        add(i,-1);
        add(i+1,-1);
        f[i]:=1;
        for j:=1 to nP do
            for k:=1 to c[j] do
                f[i]:=(f[i]*p[j]) mod MODUN;
        //catalan i-th number
    end;

    repeat
        read(fi,n);
        if n = 0 then break;
        writeln(fo,f[n]);
    until false;

    close(fo);
    close(fi);
end.