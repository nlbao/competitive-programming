const
    INPUT = 'Potato.inp';
    OUTPUT = 'Potato.out';
    MAX_N = 1000000000;

var
    fi,fo:text;
    S:string;
    N:longint;
    F:array[0..5] of longint;

procedure    Init;
var
    i:longint;
begin
    F[0]:=1;
    F[1]:=0;
    F[2]:=1;
    F[3]:=0;
    F[4]:=0;
    F[5]:=1;
end;

begin
    Init;
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,S);
    while S <> '[END]' do
        begin
            if S = '[CASE]' then
                begin
                    readln(fi,N);
                    N:=N mod 5;
                    if F[N] = 1 then writeln(fo,'Hanako')
                    else writeln(fo,'Taro');
                end;
            readln(fi,S);
        end;
    close(fo);
    close(fi);
end.