const
    INPUT = 'NKLetter.inp';
    OUTPUT = 'NKLetter.out';

var
    Sb,Se:string;
    S:ansiString;

procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,Sb);
    readln(fi,Se);
    close(fi);
end;

function    check(s1,s2:string):boolean;
var
    i:longint;
begin
    for i:=1 to length(s1) do
        if upcase(s1[i]) <> upcase(s2[i]) then
            exit(false);
    exit(true);
end;

procedure   Find;
var
    i,j,N,M,min:longint;
begin
    S:=Sb+Se;
    N:=length(Sb);
    M:=length(Se);
    if M < N then min:=N-M+1
    else min:=1;
    for i:=min to N do
        if check(copy(Sb,i,N-i+1),copy(Se,1,N-i+1)) = true then
            begin
                S:=copy(Sb,1,i-1)+Se;
                break;
            end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,length(S));
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.