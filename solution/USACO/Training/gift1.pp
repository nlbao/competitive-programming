{
    ID: phoenix481
    PROB: gift1
    LANG: PASCAL
}


const
    INPUT = 'gift1.in';
    OUTPUT = 'gift1.out';
    MAX_N = 20;

var
    fi,fo:text;
    N,c,u,v,i,j,x:longint;
    s:string;
    a:array[0..MAX_N] of string;
    sum,f:array[0..MAX_N] of longint;

function    find(var s:string):longint;
var
    i:longint;
begin
    for i:=1 to N do
        if a[i] = s then exit(i);
    exit(-1);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N);
    for i:=1 to N do begin
        readln(fi,a[i]);
        f[i]:=0;
    end;
    for i:=1 to N do begin
        readln(fi,s);
        u:=find(s);
        readln(fi,sum[u],c);
        if c > 0 then x:=sum[u] div c;
        for j:=1 to c do begin
            readln(fi,s);
            v:=find(s);
            inc(f[v],x);
        end;
        inc(f[u],sum[u]-c*x);
    end;
    for i:=1 to N do
        writeln(fo,a[i],' ',f[i]-sum[i]);
    close(fo);
    close(fi);
end.