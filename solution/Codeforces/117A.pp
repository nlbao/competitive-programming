const
    INPUT = '117A.inp';
    OUTPUT = '117A.out';
    MAX_N = 100000;
    MAX_M = 100000000;

var
    fi,fo:text;
    N,M,s,f,t,crr:int64;
    up:boolean;

function    time(i,j:int64):int64;
begin
    if i = j then exit(0);
    if up = true then begin
        if j > i then exit(j-i)
        else begin
            up:=not up;
            exit(2*M-i-j);
        end;
    end
    else begin
        if j > i then begin
            up:=not up;
            exit(i+j-2);
        end
        else exit(i-j);
    end;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    readln(fi,N,M);
    repeat
        readln(fi,s,f,t);
        if (t div (M-1)) mod 2 = 0 then begin
            up:=true;
            crr:=(t mod (M-1))+1;
        end
        else begin
            up:=false;
            crr:=M-(t mod (M-1));
        end;
        if s = f then writeln(fo,t)
        else writeln(fo,t+time(crr,s)+time(s,f));
        dec(N);
    until N = 0;
    close(fo);
    close(fi);
end.