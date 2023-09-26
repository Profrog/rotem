Sub translating()


With Sheets(5)
    
     .Cells(1, "F").Value = "START"
    Set where01 = .Range("E1:E1900")
   
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
            .Cells(where02.Row, "F").Value = objDiv.innerText: Exit For
        End If
    Next objDiv
    
    Set objHTML = Nothing: Set objHTTP = Nothing
    End If
    Next
         
End With
End Sub
