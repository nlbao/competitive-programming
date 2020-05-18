{
    PROB: digits
    LANG: PASCAL
    ID: storm59061
}
const   INPUT = 'digits.in';
        OUTPUT = 'digits.out';
        MAX_N = 31;

type    arr = array[0..MAX_N] of int64;

var fi,fo:text;
    n2,n3:longint;
    a2,a3:arr;
    p:array[2..3] of arr;

procedure   enter(var a:arr;    var n:longint);
var i:longint;
    s:string;
begin
    readln(fi,s);
    n:=length(s);
    for i:=1 to n do
        a[i]:=ord(s[i])-ord('0');
end;

function    convert(var a:arr;  n:longint;  base:longint):int64;
var i,j:longint;
    s:int64;
begin
    s:=0;   j:=0;
    for i:=n downto 1 do begin
        s:=s+a[i]*p[base][j];
        inc(j);
    end;
    exit(s);
end;

function    solve:int64;
var i,j,k,t:longint;
    s2:int64;
begin
    p[2][0]:=1; p[3][0]:=1;
    for i:=1 to n2-1 do p[2][i]:=p[2][i-1]*2;
    for i:=1 to n3-1 do p[3][i]:=p[3][i-1]*3;
    for i:=1 to n2 do begin
        a2[i]:=a2[i] xor 1;
        s2:=convert(a2,n2,2);
        for j:=1 to n3 do
            for k:=0 to 2 do
                if k <> a3[j] then begin
                    t:=a3[j]; a3[j]:=k;
                    if convert(a3,n3,3) = s2 then exit(s2);
                    a3[j]:=t;
                end;
        a2[i]:=a2[i] xor 1;
    end;
    exit(-1);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter(a2,n2);
    enter(a3,n3);
    writeln(fo,solve);
    close(fo);
    close(fi);
end.
