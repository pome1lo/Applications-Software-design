.586P													
.MODEL FLAT, STDCALL							        
includelib kernel32.lib									
 
ExitProcess PROTO : DWORD
 
.STACK 4096												
 
.DATA													
	myBytes		BYTE	10h, 20h, 30h, 40h
	myWords		Word	8Ah, 3Bh, 44h, 5Fh, 99h
	myDoubles	DWORD	1, 2, 3, 4, 5, 6
	myPointer	DWORD	myDoubles

	Array dd 1, 2, 3, 4, 5, 6, 7
 
.CODE													
main PROC												
START:													
	mov EBX, OFFSET myWords    
	mov AX, [ESI + 0]        
	mov BX, [ESI + 2]
 
	mov ECX, 7			
	mov ESI, OFFSET Array
	mov EAX, [ESI]				
		
  CIKL:
	
	add ESI, 4			
	add EAX, [ESI]		
  loop CIKL				

	  mov al, 0			
	  mov ESI, OFFSET Array		
	  mov EBX, 1				
	  mov ECX, 0

	PERV_CIKL:

			cmp al, [ESI] 
			jne VTOR_CIKL 
			mov EBX, 0    
			jmp BREAK     
	  
    VTOR_CIKL:
			
			add ESI, 1
			add ECX, 1
			cmp ECX, [EDX]
			jne PERV_CIKL
			jmp BREAK

	BREAK:
	push 0											
	call ExitProcess								
 
main ENDP										
 
end main