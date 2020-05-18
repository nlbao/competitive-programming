const
    INPUT = 'ChatChit.inp';
    OUTPUT = 'ChatChit.out';

var
    S:string;

procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    read(fi,S);
    close(fi);
end;

procedure   replace(var S:string; u,v:string);
var
    i:longint;
begin
    i:=pos(u,S);
    while i > 0 do
        begin
            delete(S,i,length(u));
            insert(v,S,i);
            i:=pos(u,S);
        end;
end;

procedure   Translate(var S:string);
begin
    S:=' '+S+' ';
    replace(S,' k ',' khong ');
    replace(S,' ko ',' khong ');
    replace(S,' ng ',' nguoi ');
    replace(S,' n ',' nhieu ');
    replace(S,' dc ',' duoc ');
    replace(S,' hok ',' khong ');
    replace(S,' ntn ',' nhu the nao ');
    replace(S,' kq ',' ket qua ');
    replace(S,'j','gi');
    replace(S,'w','qu');
    replace(S,'f','ph');
    replace(S,'dz','d');
    replace(S,'z','d');
    while S[1] = ' ' do delete(S,1,1);
    while S[length(S)] = ' ' do delete(S,length(S),1);
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    write(fo,S);
    close(fo);
end;

begin
    Enter;
    Translate(S);
    Print_result;
end.
