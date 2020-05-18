var n,m,i,j,c:longint;
    names:array[0..200] of ansiString;
    lyric:array[0..17] of ansiString;


begin
    readln(n);
    for i:=0 to n-1 do readln(names[i]);
    m:=16;
    for i:=0 to m-1 do
        case (i mod 4) of
            0: lyric[i]:='Happy';
            1: lyric[i]:='birthday';
            2: lyric[i]:='to';
            3: lyric[i]:='you';
        end;
    lyric[11]:='Rujia';

    i:=0;   j:=0;   c:=0;
    repeat
        writeln(names[i],': ',lyric[j]);
        i:=(i+1) mod n;
        j:=(j+1) mod m;
        c:=c+1;
    until (c >= n) and (j = 0);
end.
