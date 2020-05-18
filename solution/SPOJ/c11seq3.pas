uses    math;

const   MAX_N = 1000006;

var fi,fo:text;
    n,len,id,i,j,f:longint;
    s:string;
    ch:char;

begin
{$IFNDEF ONLINE_JUDGE}
    assign(fi,'C11SEQ3.in');    reset(fi);
    assign(fo,'C11SEQ3.out');   rewrite(fo);
{$ELSE}
    assign(fi,'');    reset(fi);
    assign(fo,'');    rewrite(fo);
{$ENDIF}
    read(fi,n);
    if n > 24 then begin
        n:=(n-24) mod 6;
        if n = 0 then n:=6;
        n:=n+24;
    end;

    f:=1;
    for id:=2 to n do begin
        str(f*2,s);
        len:=length(s);
        for i:=1 to len do
            for j:=i+1 to len do
                if s[i] > s[j] then begin
                    ch:=s[i];
                    s[i]:=s[j];
                    s[j]:=ch;
                end;
        val(s,f);
    end;
    writeln(fo,f);
    writeln(fo);
    close(fi);
    close(fo);
end.