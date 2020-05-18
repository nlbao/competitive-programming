const
    INPUT = 'input.txt';
    OUTPUT = 'output.txt';
    MAX_N = 200;
    MAX_M = 20000;

var
    fi,fo:text;
    N,M,T,front,rear:longint;
    a,b:array[0..MAX_N,1..2] of longint;
    word:array[0..MAX_M] of string[25];
    c:array[0..MAX_M] of longint;
    turn,s:array[0..MAX_N] of longint;
    d,res:array[0..MAX_N,0..MAX_M] of longint;
    queue:array[0..MAX_M] of longint;

procedure   enter;
var
    i:longint;
begin
    readln(fi,N,T);
    for i:=1 to N do
        readln(fi,a[i][1],b[i][1]);
    readln(fi,M);
    for i:=1 to M do begin
        readln(fi,word[i]);
        readln(fi,c[i]);
    end;
end;

function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;

procedure   push(x:longint);
begin
    {rear:=(rear+1) mod MAX_M;}
    inc(rear);
    queue[rear]:=x;
end;

function    pop:longint;
begin
    pop:=queue[front];
    {front:=(front+1) mod MAX_M;}
    inc(front);
end;

procedure   init;
var
    i,j:longint;
begin
    front:=0;   rear:=-1;
    for i:=1 to M do push(i);
    for i:=1 to N do begin
        turn[i]:=2;
        s[i]:=0;
        res[i][0]:=0;
        for j:=1 to M do d[i,j]:=0;
    end;
end;

procedure   solve;
var
    i,j,k,q,time:longint;
begin
    i:=0;
    repeat
        if i = N then i:=1
        else inc(i);
        q:=turn[i];
        if turn[i] = 1 then turn[i]:=2
        else turn[i]:=1;
        j:=turn[i];
        k:=pop;
        writeln(k);

        time:=max(1,c[k]-(a[i][j]+b[i][q])-d[i][k]);
        if time <= T then begin
            inc(s[i]);
            inc(res[i][0]);
            res[i][res[i][0]]:=k;
        end
        else begin
            push(k);
            inc(d[i][k],time);
        end;
    until front > rear;
end;

procedure   print_result;
var
    i,j:longint;
begin
    for i:=1 to N do begin
        write(fo,s[i],' ');
        for j:=1 to res[i][0] do
            write(fo,word[res[i][j]],' ');
        writeln(fo);
    end;
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    init;
    solve;
    print_result;
    close(fo);
    close(fi);
end.