const   MAX_N = 22;
        MAX_M = 1000010;

type    ll = longint;

var fi,fo:text;
    n,m,i,j,k:longint;
    a:array[0..MAX_N] of longint;
    f,g:array[0..MAX_M] of ll;
    res:int64;

procedure   tryf(i:longint);
var x:longint;
begin
    if i > (k div 2)+(k mod 2) then begin
        x:=0;
        for i:=1 to k do
            x:=(x*10+a[i]) mod m;

        g[x]:=g[x]+1;
        if a[1] <> 0 then begin
            for i:=1 to k do
                x:=(x*10) mod m;
            f[x]:=f[x]+1;
        end;
        exit;
    end;

    for x:=0 to 9 do begin
        a[i]:=x;
        a[k-i+1]:=x;
        tryf(i+1);
    end;
end;


begin
    assign(fi,'mbipalin.in');   reset(fi);
    assign(fo,'mbipalin.out');  rewrite(fo);
    readln(fi,n,m);
    fillchar(f,sizeof(f),0);
    fillchar(g,sizeof(g),0);
    k:=n div 2;
    tryf(1);

    res:=0;
    for i:=0 to m-1 do begin
        j:=(m-i) mod m;
        res:=res + int64(f[i])*int64(g[j]);
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.