Uses
        Math;
Const
        Fi = 'NKCNT2.IN';
        Fo = 'NKCNT2.OUT';
        maxn = 3001;
Var
        F: Array[0..maxn, 0..maxn] of Integer;
        a: Array[1..maxn, 1..maxn, 0..1] of Boolean;
        n, k: LongInt;
        res: qword;
Procedure Enter;
Var
        i, x, y, z: LongInt;
Begin
        Assign(Input, Fi); Reset(Input);
        Assign(Output, Fo); Rewrite(Output);
        Readln(n, k);
        For i:=1 to k do
           Begin
              Readln(x, y, z);
              y:=n-y+1;
              a[z, x, (x+y+z) mod 2]:=True;
           End;
End;
Procedure Tren;
Var
        i, j: LongInt;
Begin
        Fillchar(F, SizeOf(F), 0);
        For i:=n downto 1 do
           For j:=n-i+1 downto 1 do
              Begin
                 If (not a[i, j, 1]) and (not a[i, j, 0]) then
                    F[i, j]:=min(F[i, j+1], F[i+1, j])+1
                 Else
                 If (not a[i, j, 1]) then F[i, j]:=1
                 Else F[i, j]:=0;
                 Res:=res + F[i, j];
              End;
           writeln(res);
End;
Procedure Duoi;
Var
        i, j: LongInt;
Begin
        Fillchar(F, SizeOf(F), 0);
        For i:=1 to n do
           For j:=1 to n-i do
              Begin
                 If (not a[i, j, 1]) and (not a[i, j, 0]) then
                    F[i, j]:=min(F[i, j-1], F[i-1, j])+1
                 Else
                 If not a[i, j, 0] then F[i, j]:=1
                 Else F[i, j]:=0;
                 Res:=res + F[i, j];
              End;
End;
BEGIN
        Enter;
        Tren;
        Duoi;
        Writeln(res);
END.
