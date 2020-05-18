const
    INPUT = 'MMaxPER.inp';
    OUTPUT = 'MMaxPER.out';
    MAX_N = 1000;

var
    fi,fo:text;
    N,i:longint;
    a,b:array[0..MAX_N] of longint;
    f:array[0..MAX_N,0..1] of longint;

function    max(x,y:longint):longint;   inline;
begin
    if x > y then exit(x)
    else exit(y);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N);
    readln(fi,a[1],b[1]);
    f[1,0]:=a[1];   f[1,1]:=b[1];
    for i:=2 to N do begin
        readln(fi,a[i],b[i]);
        f[i,0]:=max(f[i-1,0]+abs(b[i]-b[i-1]),f[i-1,1]+abs(b[i]-a[i-1]))+a[i];
        f[i,1]:=max(f[i-1,0]+abs(a[i]-b[i-1]),f[i-1,1]+abs(a[i]-a[i-1]))+b[i];
    end;
    writeln(fo,max(f[N,0],f[N,1]));
    close(fo);
    close(fi);
end.