const
    INPUT = 'Vector.inp';
    OUTPUT = 'Vector.out';
    MAX_N = 30;
    MAX_R = 1500;

var
    N,U,V,P1,P2,Sx,Sy,C:longint;
    X,Y:array[1..MAX_N] of longint;
    R:array[-MAX_R..MAX_R,-MAX_R..MAX_R] of longint;

procedure   Enter;
var
    fi:text;
    i:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    for i:=1 to N do
        readln(fi,X[i],Y[i]);
    read(fi,U,V);
    close(fi);
end;

procedure   TryF1(i:longint);
var
    j:longint;
begin
    if i > P1 then inc(R[Sx,Sy])
    else
        for j:=0 to 1 do
            begin
                Sx:=Sx+j*X[i];
                Sy:=Sy+j*Y[i];
                TryF1(i+1);
                Sy:=Sy-j*Y[i];
                Sx:=Sx-j*X[i];
            end;
end;

procedure   TryF2(i:longint);
var
    j,k:longint;
begin
    if i > P2 then
        begin
            j:=U-Sx;
            k:=V-Sy;
            if (abs(j) <= MAX_R) and (abs(k) <= MAX_R) then
                C:=C+R[j,k];
        end
    else
        for j:=0 to 1 do
            begin
                k:=i+P1;
                Sx:=Sx+j*X[k];
                Sy:=Sy+j*Y[k];
                TryF2(i+1);
                Sy:=Sy-j*Y[k];
                Sx:=Sx-j*X[k];
            end;
end;


procedure   Find;
var
    i,j:longint;
begin
    C:=0;
    for i:=-MAX_R to MAX_R do
        for j:=-MAX_R to MAX_R do
            R[i,j]:=0;
    P1:=N div 2;
    P2:=N-P1;
    Sx:=0;  Sy:=0;
    TryF1(1);
    Sx:=0;  Sy:=0;
    TryF2(1);
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
    Find;
    Print_result;
end.
