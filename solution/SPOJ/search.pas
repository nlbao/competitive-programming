{$M 16777216}
uses    math;

const   MAX_N = 100005;
        MAX_A = 100005;
        oo = 1000000000;


var fi,fo:text;
    nA,nB,nC,m:longint;
    c,t:array[0..MAX_N] of longint;
    inA,inB:array[0..MAX_N] of boolean;


procedure   enter();
var i,a,b:longint;
begin
    for i:=0 to MAX_A do begin
        inA[i]:=false;
        inB[i]:=false;
    end;
    read(fi,nA,nB,nC);
    for i:=1 to nA do begin
        read(fi,a);
        inA[a]:=true;
    end;
    for i:=1 to nB do begin
        read(fi,b);
        inB[b]:=true;
    end;
    for i:=1 to nC do read(fi,c[i]);
    m:=0;
    for i:=1 to MAX_A do m:=m+longint(inA[i]);
end;


function    solve_0():longint;
var i,j,f,res:longint;
begin
    for i:=0 to MAX_A do
        if (inA[i]) and (inB[i]) then exit(0);
    res:=0;
    fillchar(t,sizeof(f),0);
    for i:=1 to nC do begin
        f:=0;
        for j:=i to nC do begin
            if inB[c[j]] then break
            else if (inA[c[j]]) and (t[c[j]] <> i) then begin
                t[c[j]]:=i;
                inc(f);
            end;
            if f = m then res:=max(res,j-i+1);
        end;
    end;
    exit(res);
end;


function    solve():longint;
var i,j,f,res:longint;
begin
    for i:=0 to MAX_A do begin
        if (inA[i]) and (inB[i]) then exit(0);
        t[i]:=0;
    end;
    res:=0;
    i:=1;
    while i <= nC do begin
        if inB[c[i]] then begin
            inc(i);
            continue;
        end;
        j:=i;   f:=0;
        while (j <= nC) and (not inB[c[j]]) do begin
            if (inA[c[j]]) and (t[c[j]] <> i) then begin
                t[c[j]]:=i;
                inc(f);
            end;
            inc(j);
        end;
        if f = m then res:=max(res,j-i);
        i:=j;
    end;
    exit(res);
end;



procedure   gen_test();
var i,x,y:longint;
begin
    randomize;
    nA:=random(10)+1;
    nB:=random(10)+1;
    nC:=random(10)+1;
    for i:=0 to MAX_A do begin
        inA[i]:=false;
        inB[i]:=false;
    end;
    read(fi,nA,nB,nC);
    for i:=1 to nA do begin
        x:=random(MAX_N)+1;
        inA[x]:=true;
    end;
    y:=x;
    for i:=1 to nB do begin
        x:=y;
        while inA[x] do x:=random(MAX_N)+1;
        inB[x]:=true;
    end;
    for i:=1 to nC do c[i]:=random(MAX_N)+1;
end;


begin
    assign(fi,'SEARCH.inp');   reset(fi);
    assign(fo,'SEARCH.out');   rewrite(fo);
    enter();
    //gen_test();
    //writeln(fo,solve_0());
    writeln(fo,solve());
    close(fi);
    close(fo);
end.