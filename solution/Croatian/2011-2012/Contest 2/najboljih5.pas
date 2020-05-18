const   INPUT = ''{'najboljih5.in'};
        OUTPUT = ''{'najboljih5.out'};
        N = 8;

var fi,fo:text;
    i,j,tmp,s:longint;
    a,id:array[0..N] of longint;
    res:array[0..N] of boolean;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    for i:=1 to N do begin
        read(fi,a[i]);
        id[i]:=i;   res[i]:=false;
    end;
    for i:=1 to N-1 do
        for j:=i+1 to N do
            if a[id[i]] < a[id[j]] then begin
                tmp:=id[i]; id[i]:=id[j];   id[j]:=tmp;
            end;
    s:=0;
    for i:=1 to 5 do begin
        s:=s+a[id[i]];
        res[id[i]]:=true;
    end;
    writeln(fo,s);
    for i:=1 to N do
        if res[i] then write(fo,i,' ');
    close(fo);
    close(fi);
end.
