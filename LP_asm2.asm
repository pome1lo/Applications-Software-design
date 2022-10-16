.586P													;������� ������ (��������� Pentium) 
.MODEL FLAT, STDCALL							        ;������ ������, ���������� � ������� 
includelib kernel32.lib									;������������: ����������� � kernel32 
 
ExitProcess PROTO : DWORD							    ;�������� ������� ��� ���������� �������� Windows 
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD    ;�������� API-������� MessageBoxA (����� � ����) 
 
.STACK 4096												;��������� ����� ������� 4 ��������� 
 
.DATA													;������� ������ 
	a dd 3            
	b dd 4 
	str1 db "������������", 0         
	str2 db "a + b = ", 0 
 
 
.CODE													;������� ���� 
main PROC												;����� ����� main 
start:													;����� 
	mov eax, a 
	add eax, b 
	add eax, 30h									
   
	mov str2+8, al										;������� �������� ����������� 
   
	INVOKE MessageBoxA, 0, OFFSET str2, OFFSET str1, 0  ;INVOKE ��������� ���������������� ������� ������ ������� � �������� �� ����������. 
 
	push 0												;��� �������� �������� Windows (�������� ExitProcess) 
	call ExitProcess									;��� ����������� ����� ������� Windows 
 
main ENDP												;����� ��������� 
 
end main