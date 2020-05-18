uses    math;

const   MAX_N = 1000010;
        MAX_K = 100010;

var fi,fo:text;
    k,i,j,nRes:longint;
    c,res:array[0..MAX_N] of longint;
    sc,sp:array[0..MAX_N] of int64;
    u,n,minF,sum:int64;

begin
    assign(fi,'haoi5000.in');   reset(fi);
    assign(fo,'haoi5000.out');  rewrite(fo);
    readln(fi,n,k);
    fillchar(c,sizeof(c),0);
    for i:=1 to k do begin
        read(fi,j);
        inc(c[j]);
    end;

    sc[0]:=0;   sp[0]:=0;
    for i:=1 to n do begin
        sc[i]:=sc[i-1]+int64(c[i]);
        sp[i]:=sp[i-1]+int64(i)*c[i];
    end;

    minF:=2000000000000000000;  nRes:=0;
    for j:=1 to n do begin
        u:=j;   sum:=0;


        i:=max(u-(n div 2),1);
        if 2*(u-i) > n then  inc(i);
        while (i > 1) and (2*(u-i+1) <= n) do dec(i);
        sum:=sum + u*(sc[u]-sc[i-1]) - (sp[u]-sp[i-1]);
        sum:=sum + (n-u)*sc[i-1] + sp[i-1];


        if sum >= minF then continue;


        i:=min(u+(n div 2),n);
        if 2*(i-u) > n then dec(i);
        while (i < n) and (2*(i-u+1) <= n) do inc(i);
        sum:=sum + (sp[i]-sp[u]) - u*(sc[i]-sc[u]);
        sum:=sum + (n+u)*(sc[n]-sc[i]) - (sp[n]-sp[i]);


        if sum < minF then begin
            minF:=sum;
            nRes:=1;
            res[1]:=u;
        end
        else if sum = minF then begin
            inc(nRes);
            res[nRes]:=u;
        end;
    end;

    writeln(fo,minF);
    writeln(fo,nRes);
    for i:=1 to nRes do write(fo,res[i],' ');
    close(fo);
    close(fi);
end.
