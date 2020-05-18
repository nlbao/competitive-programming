const   INPUT = ''{'kompici.in'};
        OUTPUT = ''{'kompici.out'};
        MAX_N = 1000010;
        MAX_X = 1033;

var fi,fo:text;
    n:longint;
    f:array[0..MAX_X] of int64;

function    get_bit(x,k:longint):longint;   begin   exit((x shr (k-1)) and 1);  end;

procedure   enter;
var i,j,k:longint;
    x:int64;
    s:string;
    avail:array[1..10] of boolean;
begin
    for i:=0 to MAX_X do f[i]:=0;
    readln(fi,n);
    for i:=1 to n do begin
        for j:=1 to 10 do avail[j]:=false;
        readln(fi,x);   str(x,s);
        for j:=1 to length(s) do avail[ord(s[j])-ord('0')+1]:=true;
        k:=0;
        for j:=1 to 10 do if avail[j] then k:=k or (1 shl (j-1));
        f[k]:=f[k]+1;
    end;
end;

procedure   solve;
var i,j,k,t:longint;
    res:int64;
    check:boolean;
begin
    res:=0;
    for j:=0 to MAX_X do res:=res+((f[j]*(f[j]-1)) div 2);
    for i:=1 to 10 do
        for j:=0 to MAX_X do if (f[j] > 0) and (get_bit(j,i) = 1) then
            for k:=j+1 to MAX_X do if (f[k] > 0) and (get_bit(k,i) = 1) then begin
                check:=true;
                for t:=1 to i-1 do
                    if (get_bit(k,t) = 1) and (get_bit(j,t) = 1) then begin
                        check:=false;
                        break;
                    end;
                if check = true then res:=res+f[j]*f[k];
            end;
    writeln(fo,res);
end;

begin
    assign(fi,INPUT);   reset(fi);
    assign(fo,OUTPUT);  rewrite(fo);
    enter;
    solve;
    close(fo);
    close(fi);
end.
