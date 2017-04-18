program programa;
  function laimetojas(s1, s2, s3 : integer) : integer;
  begin
  laimetojas := 0;
  if (s1 > s2) AND (s1 > s3) then laimetojas := 1
  else if (s2 > s1) AND (s2 > s3) then laimetojas := 2
       else if (s3 > s1) AND (s3 > s2) then laimetojas := 3;
  end;
//----
  procedure skirtiTaskus(t1, t2, t3 : integer; var s1, s2, s3, b1, b2, b3 : integer);
  begin
    b1 := b1 + t1;
    b2 := b2 + t2;
    b3 := b3 + t3;
    //--
     if (t1 > t2) AND (t1 > t3) then s1 := s1 + 4
     else if (t2 > t1) AND (t2 > t3) then s2 := s2 + 4
          else if (t3 > t1) AND (t3 > t2) then s3 := s3 + 4;
     //--
     if (t1 = t2) AND (t1 > t3) then
       begin
         s1 := s1 + 2;
         s2 := s2 + 2;
       end;
     if (t1 = t3) AND (t1 > t2) then
       begin
         s1 := s1 + 2;
         s3 := s3 + 2;
       end;
     if (t2 = t3) AND (t2 > t1) then
       begin
         s2 := s2 + 2;
         s3 := s3 + 2;
       end;
  end;
//----
  var t1, t2, t3,                   // Skyriaus ar direktoriaus skirti taðkai
      s1, s2, s3,                   // Kiekvieno logotipo surinkti taðkai
      b1, b2, b3 : integer;         // Visø skyriø skirtø balsø suma (kiekvienam logo)
      i, k : integer;
      duom, rez : text;
begin
  assign(duom, 'U1.txt');
  reset(duom);
  readLn(duom, k);
  b1 := 0; b2 := 0; b3 := 0;
  s1 := 0; s2 := 0; s3 := 0;
  for i := 1 to k do
    begin
      readLn(duom, t1, t2, t3);
      skirtiTaskus(t1, t2, t3, s1, s2, s3, b1, b2, b3);
    end;
  readLn(duom, t1, t2, t3);
  if (laimetojas(s1, s2, s3) = 0) then
    begin
      s1 := s1 + t1;
      s2 := s2 + t2;
      s3 := s3 + t3;
    end;
  close(duom);
  assign(rez, 'U1rez.txt');
  rewrite(rez);
  writeLn(rez, b1, ' ', b2, ' ', b3);
  writeLn(rez, s1, ' ', s2, ' ', s3);
  writeLn(rez, laimetojas(s1, s2, s3));
  close(rez);
end.
