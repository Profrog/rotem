Sub find_list()

With Sheets(4)

 Set where1 = .Range("B2:B2000")
 .Cells(1, "h").Interior.ColorIndex = 34
 
For Each where01 In where1.Cells

If (where01.Value = .Cells(1, "h").Value) Then
 where01.Interior.ColorIndex = 34
End If
Next

End With
End Sub
