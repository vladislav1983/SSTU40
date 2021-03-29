{$F+,N+}
LIBRARY AW0;  {Name kann geaendert werden}

USES DLLHelp, RVarDef; {muss immer vorhanden sein}

{------------------------------------------------------------------}
{ Beispiel fuer den Aufbau ein DLL fuer Anwenderbloecke fuer DS88W }
{------------------------------------------------------------------}

PROCEDURE runDLL;EXPORT;FORWARD;  {muss immer vorhanden sein}

EXPORTS                           {-"-}
  runDLL,                         {-"-}
  werte_bereitstellen,            {-"-}
  werte_rueckschreiben;           {-"-}

PROCEDURE runDLL;                 {-"-}
BEGIN
  {Hier Quellcode fuer Anwenderblock einfuegen}
  if zeit>=schaltzeit(ep[1]) then aus[1]:=ep[2]
                             else aus[1]:=0.0;
END;

BEGIN                             {muss immer vorhanden sein}
END.                              {-"-}