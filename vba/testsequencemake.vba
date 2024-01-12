
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
           .Cells(where01.Row, "B") = .Cells(where01.Row, "B") & Chr(10) & "TC_" & str2(1) & ":" & Sheets(2).Cells(where02.Row, "F").Value
      End If
    
    Next
    Next

 End With
End Sub



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
              str4 = Mid(str3(0), 1, 1) & Mid(str3(0), 3, 1) & Mid(str3(0), 5, 1) & Mid(str3(0), 7, 1)
              indexa = CInt(str4)
              Sheets(1).Cells(indexa, "A") = "ETCS-BL3 Onboard_TP_" & str3(0)
              Sheets(1).Cells(indexa, "B") = Sheets(1).Cells(indexa, "B") & Chr(10) & "TC_" & str3(1) & " " & Sheets(2).Cells(where02.Row, "F").Value
            End If
                  
         Next
            
      Next
    Next

End With

End Sub
