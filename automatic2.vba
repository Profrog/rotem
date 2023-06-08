Sub word_open()   ' CreateObject 사용 AP는 Application으로 됨
    Dim Ap As Word.Application
    Dim Dc As Document
     
    Set Ap = CreateObject("Word.Application")
    Set Dc = Ap.Documents.Open(ThisWorkbook.Path & "\" & Cells(1, "P").Value & ".doc")   ' 확장자 입력해야함.
       
     For Each table0 In Dc.Tables
    
            
           If InStr(table0.Cell(1, 1).Range.Text, "IDENTIFICATION") <> 0 Then
             table0.Range.Copy
             Range("A1").Select
             Sheets(7).Range("A1:K50").Clear
             Sheets(7).Paste
            End If
            
        Next table0
     
    Dc.Close False
    Ap.Quit     ' Quit 해줘야됨
     
    Set Dc = Nothing
    Set Ap = Nothing
End Sub


Sub extract()

Dim where1
Set where1 = ActiveSheet.Range("A4680:A5000")

For Each where2 In where1.Cells
    If where2.Value = "x " Or where2.Value = " " Or where2.Value = "" Then
        where2.Delete
        
        
        
        
        
Sub extract2()

Dim where1
Set where1 = ActiveSheet.Range("A1:A200")

For Each where2 In where1.Cells
    If where2.Value = " " Or where2.Value = "" Then
        where2.Delete
    
    End If
 Next where2
 

End Sub

Sub parsing2()

Dim string0 As String
Dim names() As String

names = Split(Cells(1, "F"))
string0 = names(0)
string0 = Mid(string0, 12)
Cells(2, "F").Value = string0

With Sheets(5)
   Dim where1
   Set where1 = .Range("A2:A3300")
   For Each where2 In where1.Cells
    If StrComp(where2, string0) = 0 Then
        .Cells(where2.Row, "B") = "here"
        
        
        Exit For
        
     End If
     
    Next
    
 End With
 
End Sub


Sub retitle()

With Sheets(4)
 Dim where1
 Dim names() As String
 Dim string0 As String
 

 Set where1 = .Range("A1850:A1850")
 For Each where2 In where1.Cells
  names = Split(where2.Value)
  string0 = names(0)
  where2.Value = string0
  
 Next
 
End With

End Sub








 
