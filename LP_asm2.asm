.586P													;система команд (процессор Pentium) 
.MODEL FLAT, STDCALL							        ;модель памяти, соглашение о вызовах 
includelib kernel32.lib									;компановщику: компоновать с kernel32 
 
ExitProcess PROTO : DWORD							    ;прототип функции для завершения процесса Windows 
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD    ;прототип API-функции MessageBoxA (вывод в окно) 
 
.STACK 4096												;выделение стека объемом 4 мегабайта 
 
.DATA													;сегмент данных 
	a dd 3            
	b dd 4 
	str1 db "Суммирование", 0         
	str2 db "a + b = ", 0 
 
 
.CODE													;сегмент кода 
main PROC												;точка входа main 
start:													;метка 
	mov eax, a 
	add eax, b 
	add eax, 30h									
   
	mov str2+8, al										;младшая половина подрегистра 
   
	INVOKE MessageBoxA, 0, OFFSET str2, OFFSET str1, 0  ;INVOKE позволяет автоматизировать процесс вызова функции и передачи ей параметров. 
 
	push 0												;код возврата процесса Windows (параметр ExitProcess) 
	call ExitProcess									;так завершается любой процесс Windows 
 
main ENDP												;конец процедуры 
 
end main