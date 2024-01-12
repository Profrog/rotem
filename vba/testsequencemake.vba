Sub filling2()
With Sheets(3)
    Set where1 = .Range("E2:E1061")
    For Each where01 In where1.Cells
      str2 = Split(where01, Chr(10))
      For Each str02 In str2
      
         Set where2 = Sheets(2).Range("K2:K1831")
         For Each where02 In where2.Cells
         
            If (where02.Value = str02) Then
              str3 = Split(str02, ".")
              'str4 = Mid(str3(0), 1, 1) & Mid(str3(0), 3, 1) & Mid(str3(0), 5, 1) & Mid(str3(0), 7, 1)
              
              
              Set where3 = Sheets(1).Range("A2:A195") 'a열에는 FEATURE 만 있음 EX 9990600
              For Each where03 In where3.Cells
               If (str3(0) = where03) Then
                Sheets(1).Cells(where03.Row, "B") = Sheets(1).Cells(where03.Row, "B") & Chr(10) & "TC_" & str3(1) & " " & Sheets(2).Cells(where02.Row, "F").Value
               End If
              Next
              
           
            End If
                  
         Next
            
      Next
    Next

End With

End Sub
