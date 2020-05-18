const   INPUT = 'V11STR.in';
        OUTPUT = 'V11STR.out';
        MAX_nP = 1010;
        MAX_nT = 500010;

type    arrP = array[0..MAX_nP] of longint;
        arrT = array[0..MAX_nT] of longint;

var fi,fo:text;
    nP,nT,res:longint;
    pattern:arrP;
    text:arrT;
    t:array[0..MAX_nP,0..1] of longint;
    f:array[0..MAX_nT,0..1] of longint;

{---------------------------------------------------------------------------}
function    max(x,y:longint):longint;
begin
    if x > y then exit(x)
    else exit(y);
end;
{---------------------------------------------------------------------------}
procedure   enter;
var i:longint;
begin
    readln(fi,nP,nT);
    for i:=1 to nP do read(fi,pattern[i]);
    for i:=1 to nT do read(fi,text[i]);
end;
{---------------------------------------------------------------------------}
procedure   KMP_table(var w:arrP;   nW,nErr:longint);
var i,j:longint;
begin
    t[1][nErr]:=0;
    j:=0;
    {writeln(nErr);}
    for i:=2 to nW do begin
        if nErr > 0 then t[i][nErr]:=max(t[i-1][nErr-1]+1,t[i][nErr-1]);
        while (j > 0) and (w[j+1] <> w[i]) do begin
            j:=t[j][nErr];
            if nErr > 0 then t[i][nErr]:=max(t[i][nErr],t[j][nErr-1]+1);
        end;
        if w[j+1] = w[i] then inc(j);
        t[i][nErr]:=max(t[i][nErr],j);
        j:=t[i][nErr];
        {if nErr = 1 then begin
            writeln('    ',i,' ',t[i][nErr]);
            readln;
        end;}
    end;
    if nErr = 1 then begin
        writeln(t[900][1],' ',t[900][0]);
        writeln(t[899][1],' ',t[899][0]);
        writeln(t[898][1]);
        writeln(t[500][1],' ',t[500][0]);
        writeln(t[503][1],' ',t[502][0]);
    end;
end;
{---------------------------------------------------------------------------}
procedure   KMP_search(var  w:arrP; nW:longint; var s:arrT; nS,nErr:longint);
var i,j:longint;
begin
    {writeln(nErr);}
    for i:=1 to nErr do f[i][nErr]:=i;
    j:=nErr;
    for i:=nErr+1 to nT do begin
        if (nErr = 1) and (i = 479701) then writeln('------------> ',j,' ',w[j+1],' ',s[i]);
        if nErr > 0 then f[i][nErr]:=max(f[i-1][nErr-1]+1,f[i][nErr-1]);
        while (j > 0) and (w[j+1] <> s[i]) do begin
            j:=t[j][nErr];
            if nErr > 0 then f[i][nErr]:=max(f[i][nErr],f[j][nErr-1]+1);
        end;
        if w[j+1] = s[i] then inc(j);

        f[i][nErr]:=max(f[i][nErr],j);
        j:=f[i][nErr];
        {if j = nW then writeln('search -> ',i-j+1);}
        if (j = nW) and (i-j+1 < res) then begin
            res:=i-j+1;
            {break;}
        end;
        {if i = 479087+nP-1 then writeln(i,' ',f[i][nErr]);}
        {writeln('   ',i,'  ',f[i][nErr]);}
    end;
    i:=901;
    {writeln(i,' ',f[i][nErr]);
    writeln(pattern[900],'  ',pattern[901]);
    writeln(text[900],'  ',text[901]);}
end;
{---------------------------------------------------------------------------}
procedure   solve;
var i,j:longint;
begin
    res:=MAX_nT;
    for i:=0 to 1 do begin
        KMP_table(pattern,nP,i);
        f[0][i]:=-1;
        KMP_search(pattern,nP,text,nT,i);
    end;
    {for i:=1 to nP do if pattern[i] <> text[i] then begin
        writeln(i,' ',pattern[i],' ',text[i]);
        readln;
    end;}

    if res > nT then res:=-1;
    writeln(fo,res);
end;
{---------------------------------------------------------------------------}
procedure   debug;
var i,j,k:longint;
    a,b:arrT;
begin
    for i:=1 to 900 do write(fo,pattern[i],' ');
    writeln(fo);
    writeln(fo);

    k:=479087;
    i:=0;
    while text[res+i] <> 11 do inc(i);
    writeln(i+1,' ',text[k+i],' ',text[res+i],' ',pattern[1+i]);
    writeln(f[k+i][1],' ',f[res+i][1]);
    writeln(f[k+i-1][1],' ',f[res+i-1][1]);

    writeln;    writeln;

    i:=0;
    while f[res+i][1] <= f[k+i][1] do inc(i);
    writeln(i+1,' ',f[k+i][1],' ',f[res+i][1]);
    writeln(i,' ',f[k+i-1][1],' ',f[res+i-1][1]);
    writeln(t[f[k+i-1][1]][1],' ',t[f[res+i-1][1]][1]);
    writeln(text[k+i],' ',text[res+i],' ',pattern[1+i]);

    {j:=0;
    for i:=1 to nP do
        if pattern[i] <> text[i+k-1] then inc(j);
    if j < 2 then writeln('!!!! ',j);
    writeln(f[k+nP-1][1]);
    writeln(f[res+nP-1][1]);}

    {for i:=1 to nP do a[i]:=text[i+res-1];
    for i:=1 to nP do b[i]:=text[i+k-1];
    for i:=1 to nP do if b[i] <> pattern[i] then writeln(i);

    for i:=501 to 901 do write(fo,pattern[i],' ');
    writeln(fo);    writeln(fo);
    for i:=501 to 901 do write(fo,a[i],' ');
    writeln(fo);    writeln(fo);
    for i:=501 to 901 do write(fo,b[i],' ');
    writeln(fo);    writeln(fo);}
    {for i:=1 to nP do write(fo,pattern[i],' ');
    writeln(fo);    writeln(fo);
    for i:=1 to nT do write(fo,text[i],' ');
    writeln(fo);}
end;
{---------------------------------------------------------------------------}

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    debug;
    close(fo);
    close(fi);
end.
