const
    INPUT = 'Bones.inp';
    OUTPUT = 'Bones.out';
    MAX_S = 80;

var
    fi,fo:text;
    S1,S2,S3,i,j,k,maxF:longint;
    F:array[3..MAX_S] of longint;

begin
    assign(fi,INPUT);   reset(fi);
    read(fi,S1,S2,S3);
    close(fi);
    for i:=3 to (S1+S2+S3) do F[i]:=0;
    for i:=1 to S1 do
        for j:=1 to S2 do
            for k:=1 to S3 do
                inc(F[i+j+k]);
    maxF:=3;
    for i:=4 to (S1+S2+S3) do
        if F[i] > F[maxF] then
            maxF:=i;
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,maxF);
    close(fo);
end.