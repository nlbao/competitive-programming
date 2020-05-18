const
    INPUT = 'VBoard.inp';
    OUTPUT = 'VBoard.out';
    MAX_N = 500;
    MAX_Q = 10000;

var
    fi,fo:text;
    N,Q,i,j,i1,j1,i2,j2,Res:longint;
    A:array[1..MAX_N,1..MAX_N] of longint;
    Sw,Sb:array[0..MAX_N,0..MAX_N] of longint;

procedure   Init;
var
    i,j:longint;
    color:array[1..MAX_N,1..MAX_N] of boolean;
begin
    color[1,1]:=true;   {white}
    for i:=2 to N do color[i,1]:=not color[i-1,1];
    for i:=1 to N do
        for j:=2 to N do
            color[i,j]:=not color[i,j-1];
    for i:=0 to N do
        begin
            Sw[0,i]:=0; Sb[0,i]:=0;
            Sw[i,0]:=0; Sb[i,0]:=0;
        end;
    for i:=1 to N do
        for j:=1 to N do
            begin
                Sw[i,j]:=Sw[i,j-1]+Sw[i-1,j]-Sw[i-1,j-1];
                Sb[i,j]:=Sb[i,j-1]+Sb[i-1,j]-Sb[i-1,j-1];
                if color[i,j] = true then Sw[i,j]:=Sw[i,j]+A[i,j]  {white}
                else Sb[i,j]:=Sb[i,j]+A[i,j];
            end;
end;

procedure   Find(i1,j1,i2,j2:longint);
var
    W,B:longint;
begin
    W:=Sw[i2,j2]-Sw[i1-1,j2]-Sw[i2,j1-1]+Sw[i1-1,j1-1];
    B:=Sb[i2,j2]-Sb[i1-1,j2]-Sb[i2,j1-1]+Sb[i1-1,j1-1];
    Res:=abs(W-B);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N);
    for i:=1 to N do
        for j:=1 to N do
            read(fi,A[i,j]);
    Init;
    readln(fi,Q);
    for i:=1 to Q do
        begin
            read(fi,i1,j1,i2,j2);
            Find(i1,j1,i2,j2);
            writeln(fo,Res);
        end;
    close(fo);
    close(fi);
end.