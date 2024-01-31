Sub word_open()   ' CreateObject 사용 AP는 Application으로 됨
        
    
    filea = Dir(ThisWorkbook.Path & "\" & "*.doc")
    take_index = 2
    
    Do While filea <> ""
               
        Dim Ap As Word.Application
        Dim Dc As Document
        Set Ap = CreateObject("Word.Application")
    
        Set Dc = Ap.Documents.Open(filea)    ' 확장자 입력해야함.
        Count = 1
        beta = Split(filea, "_")
        
         Sheets(3).Cells(take_index, "A") = beta(1) & "_" & beta(2)
        
        With Sheets(2)
         For Each table0 In Dc.Tables
               If InStr(table0.Cell(1, 1).Range.Text, "SEQUENCE") <> 0 Then
                 table0.Range.Copy
                 table0.Range.Copy
                 Sheets(2).Select
                 Cells(2, "A").Select
                 .Range("A1:S1000").Clear
                 Cells(2, "A").Select
                 
try:
                 .Paste
                     Application.SendKeys ("{Enter}")
                 
catch:
                 .Paste
                 
                
                 
                 
                 
             Set where1 = .Range("B2:B3000")
    
                 For Each where01 In where1.Cells
                 
                 If (InStr(where01, "Feature") <> 0) Then
                    beta = Split(where01.Value, " ")
                    gama = Split(beta(1), ":")
                    
                    
                    Sheets(3).Cells(take_index, "B") = Sheets(3).Cells(take_index, "B") & gama(0) & "."
                 
                 
                 End If
                 
                  If (InStr(where01, "Test") <> 0) Then
                  
                    beta = Split(where01.Value, " ")
                    gama = Split(beta(2), ":")
                    
                    
                    Sheets(3).Cells(take_index, "B") = Sheets(3).Cells(take_index, "B") & gama(0) & Chr(10)
                 
                  End If
                 
                  If (InStr(where01, "Distance") <> 0) Then
                 
                    Exit For
                    
                  End If
                 
                 Next
                  
                 
                End If
            
                
            Next table0
            
            End With
            
            
        
        Dc.Close False
        
         take_index = take_index + 1
         filea = Dir
         
           Ap.Quit     ' Quit 해줘야됨
     
    Set Dc = Nothing
    Set Ap = Nothing
    
    Loop

End Sub
