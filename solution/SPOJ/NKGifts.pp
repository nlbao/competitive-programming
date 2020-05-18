const
    INPUT = 'NKGifts.inp';
    OUTPUT = 'NKGifts.out';
    MAX_K = 40;

type
    recF = record
        x,y,z:int64;
    end;

var
    K:longint;
    P,Q,U,V,N,M,H:int64;
    F1,F2:recF;

procedure   Enter;
var
    fi:text;
begin
    assign(fi,INPUT);   reset(fi);
    readln(fi,K,P,Q,U,V);
    close(fi);
end;

procedure   UpdateF(var F:recF; typeC:byte; C:int64);
begin
    case typeC of
        1:  begin
                if C >= F.y then
                    F.z:=F.z+H
                else
                    begin
                        F.y:=2*C-F.y+1;
                        F.z:=H-F.z+1;
                    end;
            end;
        2:  begin
                if C < F.x then
                    F.z:=F.z+H
                else
                    begin
                        F.x:=C-F.x+1;
                        F.z:=H-F.z+1;
                    end;
            end;
    end;
end;

procedure   Find;
var
    i:longint;
    C:int64;
    tmp:recF;
begin
    F1.x:=Q+1;    F1.y:=P+1;    F1.z:=1;
    F2.x:=V+1;    F2.y:=U+1;    F2.z:=1;
    M:=1;
    for i:=1 to K do M:=M*2;
    N:=M;
    H:=1;
    for i:=1 to K do
        begin
            C:=M div 2;
            UpdateF(F1,1,C);
            UpdateF(F2,1,C);
            M:=C;
            H:=H*2;
            UpdateF(F1,2,C);
            UpdateF(F2,2,C);
            N:=C;
            H:=H*2;
        end;
    if F1.z > F2.z then
        begin
            tmp:=F1;
            F1:=F2;
            F2:=tmp;
        end;
end;

procedure   Print_result;
var
    fo:text;
begin
    assign(fo,OUTPUT);  rewrite(fo);
    writeln(fo,F1.z,' ',F2.z);
    close(fo);
end;

begin
    Enter;
    Find;
    Print_result;
end.