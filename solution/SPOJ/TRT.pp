const
    INPUT = 'TRT.inp';
    OUTPUT = 'TRT.out';
    MAX_N = 2001;

var
    fi,fo:text;
    N:longint;
    v:array[0..MAX_N] of longint;
    f:array[0..1,0..MAX_N] of longint;

{---------------------------------------------------------------------------}
procedure   enter;
var
    i:longint;
begin
    readln(fi,N);
    for i:=1 to N do read(fi,v[i]);
end;
{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;   inline;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i,j,k,turn,pre_turn,time:longint;
begin
    for i:=1 to N do f[0,i]:=N*v[i];
    turn:=0;
    for k:=1 to N-1 do begin
        pre_turn:=turn;
        turn:=turn xor 1;
        for i:=1 to N-k do begin
            j:=i+k;
            time:=N-j+i;
            f[turn,i]:=max(f[pre_turn,i]+time*v[j],f[pre_turn,i+1]+time*v[i]);
        end;
    end;
    writeln(fo,f[turn,1]);
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