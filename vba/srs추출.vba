Sub word_open()   ' CreateObject 사용 AP는 Application으로 됨
    

    
    Dim Ap As Word.Application
    Dim Dc As Document
     
    Set Ap = CreateObject("Word.Application")
    Set Dc = Ap.Documents.Open(ThisWorkbook.Path & "\" & "b.doc")    ' 확장자 입력해야함.
    Count = 1
       
    With Sheets(1)
     For Each table0 In Dc.Tables
           If InStr(table0.Cell(1, 1).Range.Text, "SRS_ATPU") <> 0 Then
             table0.Range.Copy
             table0.Range.Copy
             Sheets(1).Select
             Cells(1, "A").Select
             .Range("A1:M100").Clear
             Cells(1, "A").Select
             
try:
             .Paste
                 Application.SendKeys ("{Enter}")
             
catch:
             .Paste
             
         
             Sheets(2).Cells(Count, "A").Value = Sheets(1).Cells(1, "C").Value
             Count = Count + 1
            
            End If
        
            
        Next table0
        
        End With
     
    Dc.Close False
    Ap.Quit     ' Quit 해줘야됨
     
    Set Dc = Nothing
    Set Ap = Nothing
    

    Dc.Close False
    Ap.Quit     ' Quit 해줘야됨
    Return
    
End SubSub word_open()   ' CreateObject 사용 AP는 Application으로 됨
    

    
    Dim Ap As Word.Application
    Dim Dc As Document
     
    Set Ap = CreateObject("Word.Application")
    Set Dc = Ap.Documents.Open(ThisWorkbook.Path & "\" & "b.doc")    ' 확장자 입력해야함.
    Count = 1
       
    With Sheets(1)
     For Each table0 In Dc.Tables
           If InStr(table0.Cell(1, 1).Range.Text, "SRS_ATPU") <> 0 Then
             table0.Range.Copy
             table0.Range.Copy
             Sheets(1).Select
             Cells(1, "A").Select
             .Range("A1:M100").Clear
             Cells(1, "A").Select
             
try:
             .Paste
                 Application.SendKeys ("{Enter}")
             
catch:
             .Paste
             
         
             Sheets(2).Cells(Count, "A").Value = Sheets(1).Cells(1, "C").Value
             Count = Count + 1
            
            End If
        
            
        Next table0
        
        End With
     
    Dc.Close False
    Ap.Quit     ' Quit 해줘야됨
     
    Set Dc = Nothing
    Set Ap = Nothing
    

    Dc.Close False
    Ap.Quit     ' Quit 해줘야됨
    Return
    
End Sub
