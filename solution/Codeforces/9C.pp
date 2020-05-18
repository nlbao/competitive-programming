const   INPUT = '9C.in';
        OUTPUT = '9C.out';
        MAX_N = 1000000010;

var fi,fo:text;
    n,i,j,k,err,res:longint;
    s:string;

procedure   tryS(i,k:longint);
var ch:char;
begin
    if i > k then begin
        val(s,j,err);
        if j <= n then inc(res);
        exit;
    end;
    for ch:='0' to '1' do begin
        s:=s+ch;
        tryS(i+1,k);
        delete(s,i,1);
    end;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,n);
    str(n,s);
    k:=length(s);
    res:=0;
    for i:=1 to k do begin
        s:='1';
        tryS(2,i);
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.