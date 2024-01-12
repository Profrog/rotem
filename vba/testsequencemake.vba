Sub filling2()
With Sheets(3)
    Set where1 = .Range("E2:E1061")
    For Each where01 In where1.Cells
      str2 = Split(where01, Chr(10))
      For Each str02 In str2
      
         Set where2 = Sheets(2).Range("K2:K1831")
         For Each where02 In where2.Cells
         
            If (where02.Value = str02) Then
              STR3 = Split(str02, ".")
              
              indexa = CInt(STR3(0))
              Sheets(1).Cells(indexa, "A") = str02
              Sheets(1).Cells(indexa, "B") = Sheets(1).Cells(indexa, "B") & Chr(10) & "TC_" & STR3(1) & " " & Sheets(2).Cells(where02.Row, "F").Value
            End If
                  
         Next
            
      Next
    Next

End With

End Sub
