
Sub filling()
 With Sheets(1)
  Dim where1
    Set where1 = .Range("A2:A1444")
    'Set where2 = Sheets(3).Range("B2:B3227")'
    Set where2 = Sheets(2).Range("K2:K1831")
    
    For Each where01 In where1.Cells
     
    
     For Each where02 In where2.Cells
      str2 = Split(where02, ".")
      
      alpa = CStr(where01)
      beta = str2(0)
     
      If (StrComp(alpa, beta) = 0) Then
           Data1 = Split(Sheets(2).Cells(where02.Row, "F").Value, ":")
           .Cells(where01.Row, "B") = .Cells(where01.Row, "B") & Chr(10) & Data1(1)
      End If
    
    Next
    Next

 End With
End Sub

