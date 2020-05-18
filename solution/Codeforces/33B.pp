const
    INPUT = '33B.inp';
    OUTPUT = '33B.out';
    MAX_N =  510;
    MAX_LENGTH = 100010;
    MAX_W = 110;
    MAX_INT = MAX_LENGTH*MAX_W;

var
    fi,fo:text;
    S,T:ansiString;
    w:array['a'..'z','a'..'z'] of longint;

{---------------------------------------------------------------------------}
function    min(x,y:longint):longint;
begin
    if x < y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   enter;
var
    N,c:longint;
    i,j:char;
begin
    readln(fi,S);
    readln(fi,T);
    for i:='a' to 'z' do begin
        for j:='a' to 'z' do w[i,j]:=MAX_INT;
        w[i,i]:=0;
    end;
    readln(fi,N);
    while N > 0 do begin
        read(fi,i,j);
        read(fi,j);
        readln(fi,c);
        w[i,j]:=min(w[i,j],c);
        dec(N);
    end;
end;
{---------------------------------------------------------------------------}
procedure   floyd;
var
    i,j,k:char;
begin
    for k:='a' to 'z' do
        for i:='a' to 'z' do
            for j:='a' to 'z' do
                if w[i,k]+w[k,j] < w[i,j] then
                    w[i,j]:=w[i,k]+w[k,j];
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,res:longint;
    ch,x:char;
begin
    if length(S) <> length(T) then begin
        writeln(fo,-1);
        exit;
    end;
    res:=0;
    for i:=1 to length(S) do
        if S[i] <> T[i] then begin
            j:=MAX_INT;
            for ch:='a' to 'z' do
                if w[S[i],ch]+w[T[i],ch] < j then begin
                    j:=w[S[i],ch]+w[T[i],ch];
                    x:=ch;
                end;
            if j < MAX_INT then begin
                res:=res+j;
                S[i]:=x;
            end
            else begin
                writeln(fo,-1);
                exit;
            end;
        end;
    writeln(fo,res);
    writeln(fo,S);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    floyd;
    solve;
    close(fo);
    close(fi);
end.