Sub get_filelist()


Dim file_dir As String
file_dir = Dir(ThisWorkbook.Path & "\" & "*.*")
array0 = Split(file_dir, ".")
Sheets(1).Range("A1") = array0(1)

Do While file_dir <> ""

j = UBound(array0)

If array0(j) = "docx" Or array0(j) = "doc" Then
    Sheets(1).Range("A1") = array0(j)
    method_rpa (file_dir)
End If

file_dir = Dir

If file_dir <> "" Then
array0 = Split(file_dir, ".")
Sheets(1).Range("B1") = array0(1)
End If

Loop

End Sub


Sub method_rpa(link As String)   ' CreateObject 사용 AP는 Application으로 됨
    
    On Error GoTo end0
    Dim Ap As Word.Application
    Dim Dc As Document
    Dim title As Integer
    title = 0
    
    Sheets(1).Range("E2") = link
    lastRow = Sheets(3).Cells(Rows.Count, "A").End(xlUp).Row + 1
    revesion3 = Split(Sheets(1).Cells(2, "E").Value, "_")
    Sheets(3).Cells(lastRow, "A").Value = revesion3(0) 'id(file)
    
    Set Ap = CreateObject("Word.Application")
    Set Dc = Ap.Documents.Open(ThisWorkbook.Path & "\" & link)
    'Set Dc = Ap.Documents.Open(ThisWorkbook.Path & "\" & "OUTPUT\target.docx")
    '첫 헤더 컨트롤
        
    Set tb = Dc.Sections(1).Headers(1)
    tb.Range.Copy
    clear0
    first_header
    
    '두번째 헤더 컨트롤
    Set tb = Dc.Sections(2).Headers(1)
    tb.Range.Copy
    clear0
    second_header
    
    '첫 테이블 컨트롤
    Set tb = Dc.Tables(1)
    tb.Range.Copy
    clear0
    control_table
    
    '두 번째 테이블 컨트롤
    Set tb = Dc.Tables(2)
    tb.Range.Copy
    clear0
    control_table
    
    '세 번째 테이블 컨트롤
    Set tb = Dc.Tables(3)
    tb.Range.Copy
    clear0
    control_table

    
   
    Dc.Close False
    Ap.Quit     ' Quit 해줘야됨
     
    Set Dc = Nothing
    Set Ap = Nothing
    
end0:
    
  '  Application.SendKeys ("{Enter}")
   ' MsgBox "end"

End Sub

Sub clear0()
   '페이지 클리어
   Sheets(5).Select
   Sheets(5).Range("A1:R100").Clear
   ActiveSheet.Range("A1").Select
   ActiveSheet.Range("A1").Select
   Sheets(5).Paste
   
End Sub


Sub first_header()
    '첫번째 헤더 값 입력
    lastRow = Sheets(3).Cells(Rows.Count, "A").End(xlUp).Row
    lastcol = Sheets(5).Cells(1, Columns.Count).End(xlToLeft).Column
    
    revesion3 = Split(Sheets(1).Cells(2, "E").Value, "_")
    Sheets(3).Cells(lastRow, "A").Value = revesion3(0) 'id(file)
    
    size_arr = UBound(revesion3) - LBound(revesion3)
    data_arr = revesion3(size_arr)
    
    revesion3_1 = Split(data_arr, ".")
    Sheets(3).Cells(lastRow, "F").Value = revesion3_1(0) 'revision 3
    
    
    Sheets(3).Cells(lastRow, "B").Value = Sheets(5).Cells(1, lastcol).Value 'id
    Sheets(3).Cells(lastRow, "G").Value = Sheets(5).Cells(2, lastcol).Value 'Date
    Sheets(3).Cells(lastRow, "D").Value = Sheets(5).Cells(3, lastcol).Value 'revision 1

   
End Sub


Sub second_header()
    '두번째 헤더 값 입력
    lastRow = Sheets(3).Cells(Rows.Count, "A").End(xlUp).Row
    lastcol = Sheets(5).Cells(1, Columns.Count).End(xlToLeft).Column
    
    Sheets(3).Cells(lastRow, "E").Value = Sheets(5).Cells(3, lastcol).Value 'revision 2
    

End Sub
Sub control_table()
    '첫 번째 테이블 값 입력
    
    Set Rng = ActiveSheet.Range("A1:A50")
   
    lastrow1 = 1
    lastrow0 = 0
   
    Do While lastrow1 <> lastrow0
    lastrow1 = Sheets(5).Cells(Rows.Count, "A").End(xlUp).Row
   
    For Each rCell In Rng.Cells
         If rCell.Value = "" Then
            rCell.EntireRow.Delete
        End If
    Next rCell
    
    lastrow0 = Sheets(5).Cells(Rows.Count, "A").End(xlUp).Row
    Loop
    
    lastRow = Sheets(3).Cells(Rows.Count, "A").End(xlUp).Row
    lastcol0 = Sheets(5).Cells(1, Columns.Count).End(xlToLeft).Column
    lastrow0 = Sheets(5).Cells(Rows.Count, "A").End(xlUp).Row
    
    
    logcheck = 0
    

    If (Sheets(3).Cells(lastRow, "C").Value = "") Then
     namecheck = 0
     
    Else
     namecheck = 1
     End If
     
    
    
    For Count = 1 To lastrow0
       
    If logcheck < 1 Then
      If namecheck < 1 Then
      Sheets(3).Cells(lastRow, "C").Value = Sheets(3).Cells(lastRow, "C").Value + " " + Sheets(5).Cells(Count, "A").Value 'doc name
      title = title + 1
      End If
      
        If (InStr(Sheets(5).Cells(Count, "A").Value, "Writ") > 0) Or (InStr(Sheets(5).Cells(Count, "A").Value, "작") > 0) Then
        namecheck = 1
        If Sheets(3).Cells(lastRow, "H") = "" Then
        Sheets(3).Cells(lastRow, "H") = Sheets(5).Cells(Count, "C").Value 'writter
        Else
        Sheets(3).Cells(lastRow, "H") = Sheets(3).Cells(lastRow, "H") & Chr(10) & Sheets(5).Cells(Count, "C").Value 'writter
        End If
        End If
      
        If (InStr(Sheets(5).Cells(Count, "A").Value, "Revi") > 0) Or (InStr(Sheets(5).Cells(Count, "A").Value, "검") > 0) Then
        namecheck = 1
        If Sheets(3).Cells(lastRow, "I") = "" Then
        Sheets(3).Cells(lastRow, "I") = Sheets(5).Cells(Count, "C").Value 'reviewer
        Else
        Sheets(3).Cells(lastRow, "I") = Sheets(3).Cells(lastRow, "I") & Chr(10) & Sheets(5).Cells(Count, "C").Value
        End If
        End If
      
      
        If (InStr(Sheets(5).Cells(Count, "A").Value, "Appr") > 0) Or (InStr(Sheets(5).Cells(Count, "A").Value, "승") > 0) Then
        namecheck = 1
        If Sheets(3).Cells(lastRow, "J") = "" Then
        Sheets(3).Cells(lastRow, "J") = Sheets(5).Cells(Count, "C").Value 'writter
        Else
        Sheets(3).Cells(lastRow, "J") = Sheets(3).Cells(lastRow, "J") & Chr(10) & Sheets(5).Cells(Count, "C").Value 'writter
        End If
        End If

     End If
          
    
'    If (InStr(Sheets(5).Cells(Count, "A").Value, "Rev") > 0) Or (InStr(Sheets(5).Cells(Count, "A").Value, "개정") > 0) Then
'      logcheck = 1
'      namecheck = 1
'
'      ElseIf (logcheck > 0) Then
'      logrow = Sheets(4).Cells(Rows.Count, "A").End(xlUp).Row
'      Sheets(4).Cells(logrow, "A").Value = Sheets(1).Cells(2, "E").Value
'      Sheets(4).Cells(logrow, "B").Value = Sheets(5).Cells(Count, "A").Value
'      Sheets(4).Cells(logrow, "C").Value = Sheets(5).Cells(Count, "B").Value
'      Sheets(4).Cells(logrow, "D").Value = Sheets(5).Cells(Count, "C").Value
'      Sheets(4).Cells(logrow, "E").Value = Sheets(5).Cells(Count, "D").Value
'      Sheets(4).Cells(logrow, "F").Value = Sheets(5).Cells(Count, "E").Value
'      Sheets(4).Cells(logrow, "G").Value = Sheets(5).Cells(Count, "F").Value
'      Sheets(4).Cells(logrow, "H").Value = Sheets(5).Cells(Count, "G").Value
'    End If
      
    Next
    

End Sub



