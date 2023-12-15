Sub filling()
 With Sheets(3)
  Dim where1
    Set where1 = .Range("A2:A1444")
    'Set where2 = Sheets(3).Range("B2:B3227")'
    Set where2 = Sheets(2).Range("A2:A1060")
    
    For Each where01 In where1.Cells
     
     str1 = "SRS_ATPU_" + where01.Value
    
     For Each where02 In where2.Cells
      If (str1 = where02.Value) Then
           Sheets(2).Cells(where02.Row, "D") = .Cells(where01.Row, "B")
           Sheets(2).Cells(where02.Row, "E") = .Cells(where01.Row, "C")
           Exit For
      End If
    
    Next
    Next

 End With
End Sub

