const
    INPUT = 'PBCWRI.inp';
    OUTPUT = 'PBCWRI.out';
    MAX_N = 3000;
    MAX_M = 3000000;

var
    N,M,C,L,R:longint;
    A,B:ansistring;
    cS,S:array['A'..'z'] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
    s:ansistring;
begin
    A:='';  B:='';
    assign(fi,INPUT);   reset(fi);
    readln(fi,N,M);
    while length(A) < N do
        begin
            readln(fi,s);
            A:=A+s;
        end;
    while length(B) < M do
        begin
            readln(fi,s);
            B:=B+s;
        end;
    close(fi);
end;

procedure   Init;
var
    ch:char;
    i:longint;
begin
    for ch:='A' to 'z' do
        cS[ch]:=0;
    for i:=1 to N do
        inc(cS[A[i]]);
end;

function    check:boolean;
var
    i:char;
begin
    for i:='A' to 'z' do
        if S[i] <> cS[i] then
            exit(false);
    exit(true);
end;

procedure   Count;
var
    i:longint;
    ch:char;
begin
    C:=0;
    if M < N then exit;
    for ch:='A' to 'z' do
        S[ch]:=0;
    for i:=1 to N do
        inc(S[B[i]]);
    if check = true then inc(C);
    for i:=N+1 to M do
        begin
            dec(S[B[i-N]]);
            inc(S[B[i]]);
            if check = true then inc(C);
        end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,C);
    close(fo);
end;

begin
    Enter;
    Init;
    Count;
    Print_result;
end.
