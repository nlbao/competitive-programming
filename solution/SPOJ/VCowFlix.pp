const
    INPUT = 'VCowFlix.inp';
    OUTPUT = 'VCowFlix.out';
    MAX_N = 16;

var
    N,C,W,Res:longint;
    A:array[1..MAX_N] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,C,N);
    for i:=1 to N do read(fi,A[i]);
    close(fi);
end;

procedure   TryA(i:longint);
var
    j:longint;
begin
    if i > N then
        begin
            if W > Res then Res:=W;
        end
    else
        for j:=0 to 1 do
            begin
                W:=W+j*A[i];
                if W <= C then TryA(i+1);
                W:=W-j*A[i];
            end;
end;

procedure   Find;
begin
    Res:=0;
    W:=0;
    TryA(1);
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,Res);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.
