{$M+ 2000000}
uses    math;

const   MAX_N = 100005;
        MAX_M = 3*100005;
        oo = 1000000000;
        BASE = 100000000;
        DIGIT = 8;
        MAX_LEN = 11;

type    ll = qword;
        recE = record
            cost:ll;
            time:ll;
            id:longint;
            d:double;
        end;
        bigNum = array[0..MAX_LEN] of ll;

var fi,fo:text;
    n:longint;
    m,head,list:array[0..MAX_N] of longint;
    bcost,btime:array[0..MAX_M] of longint;
    a:array[0..MAX_M] of recE;
    newID:array[0..MAX_M] of longint;


operator + (var a,b:bigNum) c:bigNum;
var i:longint;
    r:ll;
begin
    fillchar(c,sizeof(c),0);
    if a[0] > b[0] then c[0]:=a[0]
    else c[0]:=b[0];
    r:=0;
    for i:=1 to c[0] do begin
        c[i]:=a[i]+b[i]+r;
        r:=c[i] div BASE;
        c[i]:=c[i] mod BASE;
    end;
    while r > 0 do begin
        inc(c[0]);
        c[c[0]]:=r mod BASE;
        r:=r div BASE;
    end;
end;


operator := (x:ll) a:bigNum;
begin
    fillchar(a,sizeof(a),0);
    while x > 0 do begin
        inc(a[0]);
        a[a[0]]:=x mod BASE;
        x:=x div BASE;
    end;
    if a[0] = 0 then a[0]:=1;
end;


function    toString(var a:bigNum):ansiString;
var i:longint;
    s,t:ansiString;
begin
    s:='';
    for i:=1 to a[0] do begin
        str(a[i],t);
        while length(t) < DIGIT do t:='0'+t;
        s:=t+s;
    end;
    if length(s) = 0 then s:='0';
    while (length(s) > 1) and (s[1] = '0') do delete(s,1,1);
    exit(s);
end;



procedure   enter();
var i,j:longint;
begin
    readln(fi,n);
    fillchar(head,sizeof(head),0);
    m[0]:=0;
    for i:=1 to n do begin
        read(fi,m[i]);
        head[i]:=head[i-1]+m[i-1];
        for j:=1 to m[i] do read(fi,btime[head[i]+j]);
        for j:=1 to m[i] do read(fi,bcost[head[i]+j]);
    end;
    head[n+1]:=head[n]+m[n];
end;


procedure   swap(var x,y:ll);
var t:ll;
begin   t:=x;   x:=y;   y:=t;   end;


function    cmp(i,j:longint):longint;
var tmp:double;
begin
    tmp:=a[i].d - a[j].d;
    if tmp < 0 then exit(1);
    if tmp > 0 then exit(-1);
    exit(a[i].id-a[j].id);
end;


procedure   sort(l,r:longint);
var i,j:longint;
    t:recE;
begin
    if l >= r then exit;
    i:=l+random(r-l);
    a[0]:=a[i];
    i:=l;   j:=r;
    repeat
        while cmp(i,0) < 0 do inc(i);
        while cmp(j,0) > 0 do dec(j);
        if i <= j then begin
            t:=a[i];
            a[i]:=a[j];
            a[j]:=t;
            inc(i); dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;


procedure   solve();
var i,j,k,u:longint;
    sum:ll;
    tmp,res:bigNum;
begin
    for i:=1 to n do begin
        with a[i] do begin
            cost:=0;
            time:=0;
            id:=i;
        end;
        for j:=head[i]+1 to head[i+1] do begin
            a[i].cost:=a[i].cost + ll(bcost[j]);
            a[i].time:=a[i].time + ll(btime[j]);
        end;
        with a[i] do d:=cost/time;
    end;
    randomize;
    sort(1,n);
    for i:=1 to n do list[i]:=a[i].id;


    sum:=0;
    res:=0;
    for i:=1 to n do begin
        u:=list[i];  k:=0;
        for j:=head[u]+1 to head[u+1] do begin
            inc(k);
            with a[k] do begin
                cost:=bcost[j];
                time:=btime[j];
                d:=double(cost)/double(time);
                id:=k;
            end;
        end;

        randomize;
        sort(1,k);

        for j:=1 to k do with a[j] do begin
            sum:=sum + time;
            tmp:=sum*cost;
            res:=res + tmp;
            newId[j+head[u]]:=id;
        end;
    end;


    writeln(fo,toString(res));
    for i:=1 to n do begin
        u:=list[i];
        writeln(fo,u);
        for j:=head[u]+1 to head[u+1] do
            write(fo,newID[j],' ');
        writeln(fo);
    end;
end;


begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'subd.inp');  reset(fi);
    assign(fo,'subd.out');  rewrite(fo);
{$ELSE}
    assign(fi,'');  reset(fi);
    assign(fo,'');  rewrite(fo);
{$ENDIF}
    enter();
    solve();
    close(fo);
    close(fi);
end.