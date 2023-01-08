Include Irvine32.inc
Include macros.inc

.data
	Number DWORD ?
.code
MAIN PROC
	mWrite "Enter the Number: "
	call ReadInt
	mov Number,eax
	call LocalSquare
	mWrite "The Square Of the Given number is: "
	call WriteDec
	exit
MAIN ENDP

LocalSquare PROC
	Enter 0,0
	mov eax,Number
	mov edx,0
	mov [ebp],eax
	mov ebx,[ebp]
	mul ebx
	Leave
	ret
LocalSquare ENDP
END MAIN