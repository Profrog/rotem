
Sub filling()
 With Sheets(1)
  Dim where1
    Set where1 = .Range("A2:A1444")
    'Set where2 = Sheets(3).Range("B2:B3227")'
    Set where2 = Sheets(2).Range("K2:K1831")
    
    For Each where01 In where1.Cells
     
    
     For Each where02 In where2.Cells
      str2 = Split(where02, ".")
      
      alpa = CStr(where01)
      beta = str2(0)
     
      If (StrComp(alpa, beta) = 0) Then
           .Cells(where01.Row, "B") = .Cells(where01.Row, "B") & Chr(10) & "TC_" & str2(1) & ":" & Sheets(2).Cells(where02.Row, "F").Value
      End If
    
    Next
    Next

 End With
End Sub



Sub filling2()
With Sheets(3)
    Set where1 = .Range("E2:E1061")
    For Each where01 In where1.Cells
      str2 = Split(where01, Chr(10))
      For Each str02 In str2
      
         Set where2 = Sheets(2).Range("K2:K1831")
         For Each where02 In where2.Cells
         
            If (where02.Value = str02) Then
              str3 = Split(str02, ".")
              'str4 = Mid(str3(0), 1, 1) & Mid(str3(0), 3, 1) & Mid(str3(0), 5, 1) & Mid(str3(0), 7, 1)
              
              
              Set where3 = Sheets(1).Range("A2:A195") 'a열에는 FEATURE 만 있음 EX 9990600
              For Each where03 In where3.Cells
               If (str3(0) = CStr(where03)) Then
                Sheets(1).Cells(where03.Row, "B") = Sheets(1).Cells(where03.Row, "B") & Chr(10) & "TC_" & str3(1) & " " & Sheets(2).Cells(where02.Row, "F").Value
                Exit For
               End If
              Next
              
           
            End If
                  
         Next
            
      Next
    Next

End With

End Sub


Sub arrange0()
With Sheets(1)
    Set where1 = .Range("A2:A1831")
    For Each where01 In where1.Cells
     str3 = Split(where01, ".")
     where01.Value = str3(0)
    Next
    
End With
End Sub

Sub callog()
Sheets(3).Cells(1, "A").Value = "2"


End Sub

Sub data_mate()

Index = 2

With Sheets(4)
 Set where1 = .Range("E2:E1061")
  For Each where01 In where1.Cells
  sr3 = Split(where01, Chr(10))
  For Each SR03 In sr3
  sr04 = Split(SR03, ".")
  
  Sheets(2).Cells(Index, "A").Value = SR03
  
  If (SR03 <> "") Then
   Sheets(2).Cells(Index, "B").Value = sr04(0)
  End If
  
  Index = Index + 1
  Next
  Next

End With

End Sub



Sub filling3()
With Sheets(2)
    Set where1 = .Range("A2:A3935")
    For Each where01 In where1.Cells
      'str2 = Split(where01, Chr(10))
      'For Each str02 In str2
      
         Set where2 = Sheets(3).Range("K2:K1831")
         For Each where02 In where2.Cells
         
            If (where02.Value = where01) Then
              str3 = Split(where01, ".")
              'str4 = Mid(str3(0), 1, 1) & Mid(str3(0), 3, 1) & Mid(str3(0), 5, 1) & Mid(str3(0), 7, 1)
              
              
              Set where3 = Sheets(1).Range("B2:B164") 'a열에는 FEATURE 만 있음 EX 9990600
              For Each where03 In where3.Cells
               If (str3(0) = CStr(where03)) Then
                where02.Interior.ColorIndex = 15
                Sheets(1).Cells(where03.Row, "C") = Sheets(1).Cells(where03.Row, "C") & Chr(10) & "TC_" & str3(1) & " " & Sheets(3).Cells(where02.Row, "F").Value
                Exit For
               End If
              Next
              
           
            End If
                  
         Next
            
      Next
   ' Next

End With

End Sub


Sub searcher4()

With Sheets(2)
Set where1 = .Range("C2:C1043")
For Each where01 In where1.Cells
    sr3 = Split(where01, Chr(10))
    
     For Each SR03 In sr3
     Set where2 = Sheets(3).Range("K2:K1831")
     For Each where02 In where2.Cells
        If (CStr(SR03) = where02) Then
        where02.Interior.Color = 130
        End If
     
     Next
     Next
Next
End With

End Sub

Sub searcher5()

With Sheets(4)
Set where1 = .Range("A2:A886")
For Each where01 In where1.Cells
   
     Set where2 = Sheets(3).Range("K2:K1831")
     For Each where02 In where2.Cells
        
          str3 = Split(where02, ".")
          str33 = Split(str3(0), "0")
          
          'left_letter = Mid(str3(0), 1, 1) & "." & Mid(str3(0), 3, 1) & "." & Mid(str3(0), 5, 1)
          left_letter = str33(0) & "." & str33(1) & "." & str33(2)
          right_letter = Mid(where01, 1, 5)
     
        If (left_letter = right_letter) Then
        where02.Interior.Color = 160
        End If
     
     Next
Next
End With

End Sub







Sub extract추출()

With Sheets(1)

Set where1 = .Range("D2:D163")
For Each where01 In where1.Cells

alpa = Split(where01, Chr(10))
For Each alpa0 In alpa
 If (Len(alpa0) > 3 And Left(alpa0, 2) = "TC") Then
.Cells(where01.Row, "F") = .Cells(where01.Row, "F") & Chr(10) & Left(alpa0, 5)
End If
Next
Next

End With
End Sub


Sub 내용옮김()

With Sheets(1)

Set where1 = .Range("F2:F163")
For Each where01 In where1.Cells
alpa = Split(where01, Chr(10))
For Each alpa0 In alpa

beta0 = Replace(alpa0, "TC_", ".")
beta = .Cells(where01.Row, "B") & beta0

 Set where2 = Sheets(3).Range("K2:K1831")
         For Each where02 In where2.Cells
         
         If (CStr(where02) = CStr(beta)) Then
         
          .Cells(where01.Row, "G") = .Cells(where01.Row, "G") & alpa0 & Chr(10) & Sheets(3).Cells(where02.Row, "F") & Chr(10)
          .Cells(where01.Row, "H") = .Cells(where01.Row, "H") & beta & Chr(10)
         Exit For

         End If
         
        
                 
         Next

Next
Next
End With
End Sub


Sub 내용옮김22()

With Sheets(1)

Set where1 = .Range("H2:H163")
For Each where01 In where1.Cells

alpa = Split(where01, Chr(10))
For Each alpa0 In alpa

beta = Split(alpa0, ".")

If alpa0 <> "" Then
.Cells(where01.Row, "I") = .Cells(where01.Row, "I") & "F" & beta(0) & "_TC" & beta(1) & Chr(10)
End If

Next
Next


End With
End Sub


Sub word_open()   ' CreateObject 사용 AP는 Application으로 됨
        
    Dim Ap As Word.Application
    Dim Dc As Document
    Set Ap = CreateObject("Word.Application")
    
    filea = Dir(ThisWorkbook.Path & ".doc")
    take_index = 2
    
    Do While filea <> ""
    
        
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
    
    Loop
    
    
    Ap.Quit     ' Quit 해줘야됨
     
    Set Dc = Nothing
    Set Ap = Nothing

    
End Sub





Sub EST()
With Sheets(2)

 take_index = 1
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
End With


End Sub






