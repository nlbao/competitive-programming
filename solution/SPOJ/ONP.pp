const
    INPUT = 'ONP.inp';
    OUTPUT = 'ONP.out';
    MAX_N = 410;

var
    fi,fo:text;
    nTest,top:longint;
    S:ansiString;
    operators,operands:set of char;
    stack:array[0..MAX_N] of char;

{---------------------------------------------------------------------------}
procedure   push(x:char);
begin
    inc(top);
    stack[top]:=x;
end;
{---------------------------------------------------------------------------}
function    pop:char;
begin
    pop:=stack[top];
    dec(top);
end;
{---------------------------------------------------------------------------}
procedure   init;
var
    ch:char;
begin
    operators:=['+','-','*','/','^'];
    operands:=[];
    for ch:='a' to 'z' do operands:=operands+[ch];
end;
{---------------------------------------------------------------------------}
procedure   solve;
var
    i:longint;
begin
    top:=0;
    for i:=1 to length(S) do begin
        if S[i] in operators then push(S[i])
        else
            if S[i] in operands then write(fo,S[i])
            else

                if S[i] = ')' then write(fo,pop);
    end;
    writeln(fo);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    init;
    readln(fi,nTest);
    while nTest > 0 do begin
        readln(fi,S);
        solve;
        dec(nTest);
    end;
    close(fo);
    close(fi);
end.