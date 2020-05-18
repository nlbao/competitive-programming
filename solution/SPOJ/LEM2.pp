const
    INPUT = 'LEM2.inp';
    OUTPUT = 'LEM2.out';
    MAX_N = 20;
    QUEUE_SIZE = 1050000;

var
    fi,fo:text;
    N,K,S,T,nQueue:longint;
    p2:array[0..MAX_N] of longint = (1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576);
    button:array[0..MAX_N] of longint;
    queue:array[1..QUEUE_SIZE] of longint;
    count:array[0..QUEUE_SIZE] of longint;
    avail:array[0..QUEUE_SIZE] of boolean;

{---------------------------------------------------------------------------}
procedure   Enter;
var
    i,j,m,x,tmp:longint;
begin
    readln(fi,N,K);
    T:=p2[K-1];
    tmp:=0;
    for i:=0 to N-1 do tmp:=tmp+p2[i];
    for i:=0 to N-1 do begin
        button[i]:=tmp;
        read(fi,m);
        for j:=1 to m do begin
            read(fi,x);
            button[i]:=button[i]-p2[x-1];
        end;
    end;
    S:=0;
    for i:=1 to N do begin
        read(fi,j);
        S:=S+j*p2[i-1];
    end;
end;
{---------------------------------------------------------------------------}
procedure   Solve;
var
    i,j,u,v:longint;
begin
    for i:=1 to p2[N] do begin
        avail[i]:=true;
        count[i]:=0;
    end;
    nQueue:=1;
    queue[1]:=S;
    avail[S]:=false;

    i:=0;
    repeat
        inc(i);
        u:=queue[i];
        for j:=0 to N-1 do begin
            v:=(u and button[j]) or (1 shl j);
            if avail[v] then begin
                inc(nQueue);
                queue[nQueue]:=v;
                count[v]:=count[u]+1;
                avail[v]:=false;
                if v = T then break;
            end;
        end;
    until (nQueue = i) or (queue[nQueue] = T);

    if queue[nQueue] = T then writeln(fo,count[T])
    else writeln(fo,-1);
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    Enter;
    Solve;
    close(fo);
    close(fi);
end.
