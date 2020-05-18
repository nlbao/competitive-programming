


procedure   add_edge(u,v,t0:longint);
begin
    inc(m);
    with e[m] do begin
        x:=u; y:=v;
        types:=t0;


    end;
end;

procedure   enter;
var i,j,k,u,v:longint;
    ch:char;
begin
    readln(fi,n,j);
    m:=0;
    for i:=1 to n do head[i]:=0;
    for i:=1 to j do begin
        read(fi,u,v,ch);
        readln(fi,ch);
        if ch = 'S' then k:=0;
        else k:=1;
        add_edge(u,v,k);
        add_edge(v,u,k);
    end;
end;


begin
    assign(fi,'141E.in');   reset(fi);
    assign(fo,'141E.out');  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.