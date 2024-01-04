Sub word_open()   ' CreateObject 사용 AP는 Application으로 됨
    Dim Ap As Word.Application
    Dim Dc As Document
     
    Set Ap = CreateObject("Word.Application")
    last_index_row = Cells(Rows.Count, "L").End(xlUp).Row
    
    For current_index = 2 To last_index_row
    
    Set Dc = Ap.Documents.Open(ThisWorkbook.Path & "\" & Cells(current_index, "L").Value)   ' 확장자 입력해야함.
       
     For Each table0 In Dc.Tables
    
            
           If InStr(table0.Cell(1, 1).Range.Text, "IDENTIFICATION") <> 0 Then
             table0.Range.Copy
             Range("A1").Select
             Sheets(6).Range("A1:K100").Clear
             Sheets(6).Paste
             making_data
                  
            End If
            
        Next table0
     
    Dc.Close False
    Set Dc = Nothing
    Cells(current_index, "L").Interior.ColorIndex = 37
    Next
    
    Ap.Quit     ' Quit 해줘야됨
    Set Ap = Nothing
End Sub
 
Function making_data()

    Dim last_index As Long
    Dim fill_index As Integer
    Dim fill_index_last As Integer
    
    With Sheets(4)
     last_index_row = .Cells(.Rows.Count, "A").End(xlUp).Row + 1
     fill_index = 1
     filled_index_start = 3
     
     For current_index = 3 To Sheets(6).Cells(.Rows.Count, "A").End(xlUp).Row + 1
      If Sheets(6).Cells(current_index, "A").Value = .Cells(1, fill_index).Value Then
        Do While filled_index_start < current_index
           .Cells(last_index_row, fill_index - 1).Value = .Cells(last_index_row, fill_index - 1).Value & Chr(10) & Sheets(6).Cells(filled_index_start, "B").Value
            filled_index_start = filled_index_start + 1
        Loop
        
       .Cells(last_index_row, fill_index).Value = Sheets(6).Cells(current_index, "B").Value
       filled_index_start = filled_index_start + 1
       fill_index = fill_index + 1
      End If
     Next
     
     .Cells(last_index_row, fill_index).Value = Sheets(6).Cells(4, "D").Value & "." & Sheets(6).Cells(5, "D").Value
     
     For current_index = Sheets(6).Cells(.Rows.Count, "A").End(xlUp).Row To Sheets(6).Cells(.Rows.Count, "C").End(xlUp).Row
      .Cells(last_index_row, fill_index - 1).Value = .Cells(last_index_row, fill_index - 1).Value & Chr(10) & Sheets(6).Cells(current_index, "C").Value
      a = parsing(Sheets(6).Cells(current_index, "C").Value, .Cells(last_index_row, fill_index).Value)
     Next
    
     
    End With
End Function


Function parsing(input_data, flow_data)

Dim string0 As String
Dim names() As String

names = Split(input_data)
string0 = names(0)
string0 = Mid(input_data, 12)

With Sheets(5)
   Dim where1
   Set where1 = .Range("A2:A3300")
   For Each where2 In where1.Cells
    If StrComp(where2, string0) = 0 Then
        .Cells(where2.Row, "B") = .Cells(where2.Row, "B") & flow_data & Chr(10)
        
        Exit For
        
     End If
     
    Next
    
 End With
 
End Function


Sub check_of()
 With Sheets(6)
   Dim where1
    Set where1 = .Range("A2:A3249")
    Set where01 = Sheets(9).Range("A1:A1920")
    
    For Each where2 In where1.Cells
        For Each where02 In where01.Cells
            Dim where04
            where04 = where02
            
            If InStr(where02, " ") <> 0 Then
                where03 = Split(where02.Value, " ")
                where04 = where03(0)
            End If
            
            If where2 = where04 Then
                where2.Interior.ColorIndex = 37
                 .Cells(where2.Row, "D").Value = "x"
                 
                Exit For
            End If
 
           
        Next
    Next
    
  End With

End Sub


Sub making_list()
 With Sheets(9)
  Set where01 = .Range("A1:A62911")
  For Each where02 In where01.Cells
    If .Cells(where02.Row + 2, "A").Value = "x" Or .Cells(where02.Row + 2, "A").Value = "x " Then
                where02.Interior.ColorIndex = 37
            End If
            
   Next
End With

End Sub


Sub making_list2()
With Sheets(9)
  Set where01 = .Range("A1:A62911")
  For Each where02 In where01.Cells

    If where02.Value = "" Or where02.Value = " " Then
       where02.Interior.ColorIndex = 37
        End If
        
    If where02.Value = "x" Or where02.Value = "x " Then
        where02.Interior.ColorIndex = 37
            End If
            
   Next
End With



End Sub


Sub filling()

With Sheets(7)
 Set where01 = .Range("B1:B3300")
 Set where02 = Sheets(8).Range("A1:A885")
 
 For Each w2 In where02.Cells
  For Each w1 In where01.Cells
   If (w1.Value = "x") Then
     w1.Value = w2.Value
     Exit For
   End If
      
  Next
 Next
  
End With
End Sub


Sub translating()


With Sheets(7)
    
    
    Set where01 = .Range("B1:B3200")

    For Each where02 In where01.Cells
    
    If where02.Value <> "" Then
   
    value0 = WorksheetFunction.EncodeURL(where02.Value)
     
        
    strURL = "https://translate.google.com/m?hl=" & "en" & _
        "&sl=" & "en" & _
        "&tl=" & "ko" & _
        "&ie=UTF-8&prev=_m&q=" & value0
        
        
    Set objHTTP = CreateObject("MSXML2.ServerXMLHTTP")
    objHTTP.Open "GET", strURL, False
    objHTTP.setRequestHeader "User-Agent", "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.0)"
    objHTTP.Send ""
    
    Set objHTML = CreateObject("htmlfile")
    With objHTML
        .Open
        .Write objHTTP.responseText
        .Close
    End With
    
    Set objDivs = objHTML.getElementsByTagName("div")
    For Each objDiv In objDivs
        If objDiv.ClassName = "result-container" Then
            .Cells(where02.Row, "C").Value = objDiv.innerText: Exit For
        End If
    Next objDiv
    
    Set objHTML = Nothing: Set objHTTP = Nothing
    End If
    Next
         
End With
End Sub



Sub hello2()

    With Sheets(8)
        .Cells(3, "S").Value = "hello"
        .Cells(2, "S").Value = "hello"

    End With
End Sub






