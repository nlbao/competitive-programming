{
    ID: storm59061
    PROB: beads
    LANG: PASCAL
}

const
    INPUT = 'beads.in';
    OUTPUT = 'beads.out';
    MAX_N = 400;

var
    fi,fo:text;
    S:ansistring;
    N:longint;

function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;

procedure   enter;
begin
    readln(fi,N);
    readln(fi,S);
    S:=S+S;
end;

procedure   solve;
var
    i,res:longint;
    left,right:array[0..2*MAX_N,0..1] of longint;
begin
    left[1][0]:=0;  left[1][1]:=0;
    for i:=2 to 2*N do
        if S[i-1] = 'r' then begin
            left[i][0]:=left[i-1][0]+1;
            left[i][1]:=0;
        end
        else if S[i-1] = 'b' then begin
            left[i][0]:=0;
            left[i][1]:=left[i-1][1]+1;
        end
        else begin
            left[i][0]:=left[i-1][0]+1;
            left[i][1]:=left[i-1][1]+1;
        end;

    right[2*N][0]:=0;   right[2*N][1]:=0;
    for i:=2*N-1 downto 1 do
        if S[i] = 'r' then begin
            right[i][0]:=right[i+1][0]+1;
            right[i][1]:=0;
        end
        else if S[i] = 'b' then begin
            right[i][0]:=0;
            right[i][1]:=right[i+1][1]+1;
        end
        else begin
            right[i][0]:=right[i+1][0]+1;
            right[i][1]:=right[i+1][1]+1;
        end;

    res:=0;
    for i:=1 to 2*N do
        res:=max(res,max(left[i][0],left[i][1])+max(right[i][0],right[i][1]));
    if res > N then res:=N;
    writeln(fo,res);
end;


begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
