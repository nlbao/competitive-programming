uses    math;

const	MAX_M = 153;
		MAX_N = 45155;


var	fi,fo:text;
    n,m,i,j,k,t,h,res,limit:longint;
    c:array[0..2*MAX_M] of longint;
    a,b:array[0..MAX_N] of longint;
    g:array[0..MAX_M,0..MAX_N] of longint;


procedure	swap(var x,y:longint);
var	t:longint;
begin	t:=x;	x:=y;	y:=t;	end;


procedure	sort(l,r:longint);
var	i,j,p1,p2:longint;
begin
	if l >= r then exit;
    i:=l+random(r-l);
    p1:=a[i];	p2:=b[i];
    i:=l;	j:=r;
	repeat
    	while (a[i] < p1) or ((a[i] = p1) and (b[i] > p2)) do inc(i);
        while (a[j] > p1) or ((a[j] = p1) and (b[j] < p2)) do dec(j);
        if i <= j then begin
        	swap(a[i],a[j]);
            swap(b[i],b[j]);
            inc(i);	dec(j);
        end;
    until i >= j;
    sort(l,j);
    sort(i,r);
end;

procedure   up(k,i,v:longint);
begin
    if (i < 1) or (i > m) then exit;
    g[k][i]:=max(g[k][i],v);
    up(k,i+(i and (-i)),v);
end;

function    get(k,i:longint):longint;
begin
    if (i < 1) or (i > m) then exit(0);
    exit(max(get(k,i-(i and (-i))),g[k][i]));
end;


begin
	assign(fi,'kseq1.in');	reset(fi);
    assign(fo,'kseq1.out');	rewrite(fo);
    read(fi,n);
    for i:=1 to n do read(fi,c[i]);

    m:=0;
    for i:=1 to n do
    	for j:=i+1 to n do
        	if c[i] < c[j] then begin
            	inc(m);
                a[m]:=i;
                b[m]:=j;
            end;
	swap(n,m);
    randomize;
    sort(1,n);

    res:=0;
    limit:=m div 2;
    fillchar(g,sizeof(g),0);
    i:=1;
    while i <= n do begin
        j:=i;
        while (j < n) and (a[j+1] = a[i]) do inc(j);
        for h:=min(j,limit) downto 2 do
            for k:=max(i,h) to j do begin
                t:=get(h-1,b[k]-1);
                if a[k] < t then begin
                    up(h,b[k],t);
                    res:=max(res,h);
                end
            end;
        for k:=i to j do up(1,b[k],b[k]);
        i:=j+1;
    end;
    writeln(fo,res);
    close(fo);
    close(fi);
end.
