uses    math;

type    int = longint;
        arr = array[0..5,0..5] of longint;
        arr5 = array[1..5] of longint;

var fi,fo:text;
    n,i,j,k,t,left,right,mid,tr:longint;
    s:string;
    a,l,r,pl,pr:arr;
    ok:array[0..30] of boolean;
    f:array[0..5,0..5,0..5,0..5,0..5] of longint;
    x,res:int;

procedure   push(v,x,y:longint);
var i,j:longint;
begin
    a[x][y]:=v; ok[v]:=false;
    for i:=1 to x do
        for j:=1 to y do r[i][j]:=min(r[i][j],v-1);
    for i:=x to 5 do
        for j:=y to 5 do l[i][j]:=max(l[i][j],v+1);
end;

procedure   init();
var i,j:longint;
begin
    fillchar(ok,sizeof(ok),true);
    for i:=1 to 5 do
        for j:=1 to 5 do begin
            a[i][j]:=0;
            l[i][j]:=1;
            r[i][j]:=25;
        end;
    push(1,1,1);
    push(25,5,5);
end;


function    getf(c:arr5):int;    begin   exit(f[c[1]][c[2]][c[3]][c[4]][c[5]]);  end;

procedure   update(c:arr5);
var i,s:longint;
    ck:arr5;
    t:int;
begin
    s:=0;
    for i:=1 to 5 do s:=s+c[i];
    if (s = 25) or (getf(c) = 0) then exit;

    inc(s);
    t:=getf(c);
    if not ok[s] then begin
        for i:=1 to 5 do
            if (c[i] < 5) and (a[c[i]+1][i] = s) then inc(c[i]);
        f[c[1]][c[2]][c[3]][c[4]][c[5]]:=getf(c)+t;
        exit;
    end;

    ck[5]:=c[5];
    for i:=4 downto 1 do ck[i]:=max(c[i],ck[i+1]);
    for i:=1 to 5 do
        if (c[i] < 5) and (ck[i] = c[i]) and (l[c[i]+1][i] <= s) and (r[c[i]+1][i] >= s) then begin
            inc(c[i]);
            f[c[1]][c[2]][c[3]][c[4]][c[5]]:=getf(c)+t;
            dec(c[i]);
        end;
end;

function    cal_f():int;
var c1,c2,c3,c4,c5:longint;
    c:arr5;
begin
    fillchar(f,sizeof(f),0);
    f[1][0][0][0][0]:=1;
    for c1:=1 to 5 do
        for c2:=0 to 5 do
            for c3:=0 to 5 do
                for c4:=0 to 5 do
                    for c5:=0 to 5 do begin
                        c[1]:=c1;   c[2]:=c2;   c[3]:=c3;   c[4]:=c4;   c[5]:=c5;
                        update(c);
                    end;
    exit(f[5][5][5][5][5]);
end;

procedure   gen_test();
begin
    for i:=1 to 5 do
        for j:=1 to 5 do begin
            read(fi,k);
            write(fo,char(k+ord('A')-1));
        end;
    close(fo);
    close(fi);
    halt;
end;

procedure   check();
begin
    for i:=1 to 5 do
        for j:=2 to 5 do
            if a[i][j] < a[i][j-1] then writeln(fo,'R: ',i,' ',j);
    for j:=1 to 5 do
        for i:=2 to 5 do
            if a[i][j] < a[i-1][j] then writeln(fo,'C: ',i,' ',j);
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'table5x5.in');       reset(fi);
    assign(fo,'table5x5.out');      rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    //gen_test;

//solve1;
    readln(fi,res);
    init();
    for i:=1 to 5 do
        for j:=1 to 5 do begin
            k:=5*(i-1)+j;
            if (k = 1) or (k = 25) then continue;
            for k:=l[i][j] to r[i][j] do if ok[k] then begin
                pl:=l;  pr:=r;
                push(k,i,j);
                x:=cal_f();
                if x >= res then break;
                res:=res-x;
                a[i][j]:=0; ok[k]:=true;
                l:=pl;  r:=pr;
            end;
        end;

    for i:=1 to 5 do
        for j:=1 to 5 do write(fo,char(a[i][j]+ord('A')-1));
    writeln(fo);

    //check();

//solve2;
    readln(fi,s);
    res:=1;
    init();
    for i:=1 to 5 do
        for j:=1 to 5 do begin
            k:=5*(i-1)+j;
            if (k = 1) or (k = 25) then continue;
            x:=ord(s[k])-ord('A')+1;
            r[i][j]:=min(r[i][j],x-1);
            res:=res+cal_f();
            push(x,i,j);
        end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.
