TITLE QUESTION # 2
Include Irvine32.inc

.data
string1 BYTE "FAST"
string2 BYTE "NUCES"
result BYTE SIZEOF string1 + SIZEOF string2 DUP(?)

.code
main proc
    mov esi, OFFSET string1 ; esi = address of string1
    mov edi, OFFSET result ; edi = address of result
    mov ecx, SIZEOF string1 ; ecx = size of string1
    rep movsb ; copy string1 to result
    mov esi, OFFSET string2 ; esi = address of string2
    mov ecx, SIZEOF string2 ; ecx = size of string2
    rep movsb ; copy string2 to result
    mov edx, OFFSET result
    call WriteString
exit
main endp
END main
