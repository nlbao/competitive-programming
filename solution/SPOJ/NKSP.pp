const
    INPUT = 'NKSP.inp';
    OUTPUT = 'NKSP.out';
    MAX_N = 1010;

var
    fi,fo:text;
    S:ansiString;
    N:longint;
    g,f:array[0..MAX_N,0..MAX_N] of boolean;

{---------------------------------------------------------------------------}
procedure   enter;
begin
    readln(fi,S);
    N:=length(S);
    S:=S+'0';
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,t,k:longint;
    count:int64;
begin
{tinh_g}
    for i:=1 to N do begin
        g[i,i]:=true;
        if S[i] = S[i+1] then g[i,i+1]:=true;
    end;
    for t:=2 to N-1 do
        for i:=1 to N-t do begin
            j:=i+t;
            if S[i] <> S[j] then g[i,j]:=false
            else g[i,j]:=g[i+1,j-1];
        end;

{tinh_f}
    count:=0;
    for i:=1 to N do f[i,i]:=false;
    for t:=1 to N-1 do
        for i:=1 to N-t do begin
            j:=i+t;
            f[i,j]:=g[i,j];
            if f[i,j] = false then
                for k:=i+1 to j-1 do
                    if (f[i,k] and f[k+1,j]) then begin
                        f[i,j]:=true;
                        break;
                    end;
            if f[i,j] then count:=count+1;
        end;
    writeln(fo,count);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.