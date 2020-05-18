uses    math;

const   MAX_N = 2*1094790;

var fi,fo:text;
    n,i,j,l:longint;
    a,f:array[0..MAX_N] of int64;
    s,res:int64;

begin
    assign(fi,'ptqmseq.in');    reset(fi);
    assign(fo,'ptqmseq.out');   rewrite(fo);
    res:=-1000000000000000000;
    read(fi,n);
    for i:=1 to n do begin
        read(fi,a[i]);
        a[i+n]:=a[i];
        res:=max(res,a[i]);
    end;

    s:=a[1];    l:=1;
    {for i:=2 to 2*n do begin
        if (i-l+1 >= n) then begin
            s:=s-a[l];
            inc(l);
        end;
        while (s <= 0) and (l < i) do begin
            s:=s-a[l];
            inc(l);
        end;
        s:=s+a[i];
        res:=max(res,s);
    end;}

    {for i:=1 to n do begin
        s:=a[i];
        for j:=i+1 to i+n-2 do begin
            s:=max(s+a[j],a[j]);
            res:=max(res,s);
        end;
    end;}

    fillchar(f,sizeof(f),0);
    s:=0;
    for i:=1 to n-1 do begin
        s:=s+a[i];
        f[i]:=max(f[i-1],s);
        res:=max(res,s);
    end;

    s:=a[2];
    for i:=3 to n do begin
        s:=max(s+a[i],a[i]);
        res:=max(res,s);
    end;

    s:=0;
    for i:=n downto 2 do begin
        s:=s+a[i];
        res:=max(res,s+a[i-2]);
    end;

    if n > 1 then writeln(fo,res);
    close(fo);
    close(fi);
end.
