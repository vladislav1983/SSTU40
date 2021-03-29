{$F+,N+}
{------------------------------------------------------------------}
{ Beispiel fuer den Aufbau ein DLL fuer Anwenderbloecke fuer DS88W }
{------------------------------------------------------------------}

LIBRARY AW1;  {Name kann geaendert werden, sollte vereinbartem
               Dateinamen (*.DLL) entsprechen}

USES DLLHelp, RVarDef;                     {muss immer vorhanden sein}

PROCEDURE runDLL;EXPORT;FORWARD;  {-"-}

EXPORTS                           {-"-}
  runDLL,                         {-"-}
  werte_bereitstellen,            {-"-}
  werte_rueckschreiben;           {-"-}

PROCEDURE runDLL;                 {-"-}
BEGIN
  {Hier Quellcode fuer Anwenderblock einfuegen}
  if anlaufrechnung then begin
    if ep[1]<=0.0 then begin
      fehlermeldung('Unzulaessige Zeitkonstante');
      ep[1]:=1.0;
    end;
    realz[1]:=0.0;
    aus[1]:=anf[1];
  end;
  realz[2]:=ein[1]-aus[1]-2*ep[1]*ep[2]*realz[1];
  integral(realz[1],1.0,aus[1]);
  integral(realz[2],sqr(ep[1]),realz[1]);
end;

BEGIN                             {muss immer vorhanden sein}
END.                              {-"-}