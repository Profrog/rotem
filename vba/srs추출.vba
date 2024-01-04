Sub word_open()   ' CreateObject 사용 AP는 Application으로 됨
    Dim Ap As Word.Application
    Dim Dc As Document
     
    Set Ap = CreateObject("Word.Application")
    Set Dc = Ap.Documents.Open(ThisWorkbook.Path & "\" & "b.doc")    ' 확장자 입력해야함.
    Count = 1
       
     For Each table0 In Dc.Tables
           If InStr(table0.Cell(1, 1).Range.Text, "SRS_ATPU") <> 0 Then
             table0.Range.Copy
             Range("A1").Select
             Sheets(1).Range("A1:K50").Clear
             Sheets(1).Paste
             Sheets(2).Cells(Count, "A").Value = Sheets(1).Cells(1, "C").Value
             Count = Count + 1
                         
            End If
            
        Next table0
     
    Dc.Close False
    Ap.Quit     ' Quit 해줘야됨
     
    Set Dc = Nothing
    Set Ap = Nothing
End Sub
