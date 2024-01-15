Sub 내용옮김()

With Sheets(1)

Set where1 = .Range("F2:F163")
For Each where01 In where1.Cells
alpa = Split(where01, Chr(10))
For Each alpa0 In alpa

beta0 = Replace(alpa0, "TC_", ".")
beta = .Cells(where01.Row, "B") & beta0

 Set where2 = Sheets(2).Range("K2:K1831")
         For Each where02 In where2.Cells
         
         If (where02 = beta) Then
         
         .Cells(where01.Row, "G") = .Cells(where01.Row, "G") & alpa0 & Chr(10) & Sheets(2).Cells(where02.Row, "F")
         Exit For
         End If
         Next

Next
Next
End With
End Sub
