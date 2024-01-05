Sub find_testcase()

Set where1 = Sheets(4).Range("J2:J1831")
Set from1 = Sheets(2).Range("A2:A3")

For Each where2 In where1.Cells
where02 = Split(where2, Chr(10))


 For Each where3 In where02
  For Each from2 In from1
    If (where3 = "Subset-026-" & from2) Then
     Sheets(2).Cells(from2.Row, "B") = Sheets(2).Cells(from2.Row, "B") & Sheets(4).Cells(where2.Row, "K") & Chr(10)
     End If
  Next
  Next
  Next
  
End Sub
