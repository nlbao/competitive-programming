uses    math;

const   MAX_N =1010;
        MAX_K = 100;

var fi,fo:text;
    n,k,a,i,j,jj,t,tt:longint;
    f:array[0..1,0..MAX_K] of longint;

begin
    assign(fi,'qbseq.in');  reset(fi);
    assign(fo,'qbseq.out'); rewrite(fo);
    fillchar(f,sizeof(f),0);
    readln(fi,n,k);
    t:=0;
    for i:=1 to n do begin
        read(fi,a);
        a:=a mod k;
        tt:=t;
        t:=(t+1) mod 2;
        for j:=0 to k-1 do f[t][j]:=f[tt][j];
        for j:=0 to k-1 do
            if f[tt][j] > 0 then begin
                jj:=(j+a) mod k;
                f[t][jj]:=max(f[t][jj],f[tt][j]+1);
            end;
        f[t][a]:=max(f[t][a],1);
    end;
    writeln(fo,f[t][0]);
    close(fo);
    close(fi);
end.