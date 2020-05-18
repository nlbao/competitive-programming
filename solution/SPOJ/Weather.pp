const
    INPUT = 'Weather.inp';
    OUTPUT = 'Weather.out';
    MAX_N = 100;
    MAX_M = 5000;

var
    N,M,Sum:longint;
    W:array[1..MAX_N,1..MAX_N] of longint;
    head:array[1..MAX_N+1] of longint;
    adj:array[1..MAX_M] of longint;

procedure   Enter;
var
    fi:text;
    i,j,k:longint;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,N);
    readln(fi,M);
    for i:=1 to N do
        for j:=1 to N do
            W[i,j]:=0;
    for k:=1 to M do
        begin
            readln(fi,i,j);
            inc(W[i,j]);
            inc(W[j,i]);
        end;
    close(fi);
    head[1]:=0;
    for i:=1 to N do
        begin
            head[i+1]:=head[i];
            for j:=1 to N do
                if W[i,j] > 0 then
                    begin
                        inc(head[i+1]);
                        adj[head[i+1]]:=j;
                    end;
        end;
end;

procedure   BFS(S:longint);
var
    i,j,u,v,QSize:longint;
    Q:array[1..MAX_N] of longint;
    avail:array[1..MAX_N] of boolean;
begin
    QSize:=1;
    Q[1]:=S;
    for i:=1 to N do avail[i]:=true;
    avail[s]:=false;
    i:=0;
    repeat
        inc(i);
        u:=Q[i];
        for j:=head[u]+1 to head[u+1] do
            begin
                v:=adj[j];
                if (W[u,v] > 0) and (avail[v]) then
                    begin
                        inc(QSize);
                        Q[QSize]:=v;
                        avail[v]:=false;
                    end;
            end;
    until i = QSize;
    for i:=S+1 to N do
        if avail[i] then
            inc(Sum);
end;

procedure   Find;
var
    u,v,i,j:longint;
begin
    Sum:=0;
    for u:=1 to N do
        for i:=1 to N-1 do
            for j:=i+1 to N do
                if W[i,j] = 1 then
                    begin
                        W[i,j]:=0;
                        BFS(u);
                        W[i,j]:=1;
                    end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,Sum);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.