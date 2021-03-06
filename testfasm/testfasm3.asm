
; Win32 program template

format PE console
entry start

include 'include\kernel.inc'
include 'include\user.inc'

include 'include\macro\stdcall.inc'
include 'include\macro\import.inc'

section '.data' data readable writeable

  mainhwnd dd 0 			; handle of window
  hinstance dd 0			; handle of module

  ;msg MSG
  ;wc WNDCLASS

  _title db 'Win32 program template',0
  _class db 'FASMWIN32',0


_str_printf_int db "int=%d"
	db 10,0
_str_printf_str db "str=%s"
	db 10,0

	p68_tmp dd ?
	p67_tmp dd ?
	p66_tmp dd ?
	p65_tmp dd ?
	p64_tmp dd ?
	p63_tmp dd ?
	p62_tmp dd ?
	p61_tmp db "coucou",0
	p60_tmp dd ?
	p59_tmp dd ?
	p58_tmp dd ?
	p57_tmp dd ?
	p56_tmp dd ?
	p55_tmp db "a de 3 a 1",0
	p54_tmp dd ?
	p53_tmp dd ?
	p52_tmp dd ?
	p51_tmp dd ?
	p50_tmp dd ?
	p49_tmp db "a de 0 a 2",0
	p48_tmp dd ?
	p47_tmp dd ?
	p46_tmp dd ?
	p45_tmp db "5>=6?",0
	p44_tmp dd ?
	p43_tmp dd ?
	p42_tmp dd ?
	p41_tmp db "6>=6?",0
	p40_tmp dd ?
	p39_tmp dd ?
	p38_tmp dd ?
	p37_tmp db "7>=6?",0
	p36_tmp dd ?
	p35_tmp dd ?
	p34_tmp dd ?
	p33_tmp db "6<5?",0
	p32_tmp dd ?
	p31_tmp dd ?
	p30_tmp dd ?
	p29_tmp db "5<5?",0
	p28_tmp dd ?
	p27_tmp dd ?
	p26_tmp dd ?
	p25_tmp db "1<5?",0
	p24_tmp db "abc",0
	p23_tmp dd ?
	p22_tmp dd ?
	p21_tmp dd ?
	p20_tmp dd ?
	p19_tmp dd ?
	p18_tmp dd ?
	p17_tmp dd ?
	p16_tmp dd ?
	p15_tmp dd ?
	p14_tmp dd ?
	p13_tmp dd ?
	p12_tmp dd ?
	p11_tmp dd ?
	p10_tmp dd ?
	p9_tmp dd ?
	p8_tmp dd ?
	p7_tmp dd ?
	p6_tmp dd ?
	p5_tmp dd ?
	p4_tmp dd ?
	p3_tmp dd ?
	p2_tmp dd ?
	p1_tmp dd ?
	p0_tmp db "debut:",0
	toto1_glob dd ?
	tata_glob db ?
	i_glob db ?
	tutu_glob dd ?
	b_glob dd ?
	u_glob dq ?
	a_glob dd ?
	g_glob dd ?
	j_glob dd ?
	u1_glob dd ?
	s_glob dd ?

	bytes_count dd ?
	buf: times 512 db 0

  _message db 'This message is printed using PEDLL.DLL',0Dh,0Ah,0

section '.code' code readable executable

  start:

	;invoke	GetModuleHandle,0
	;mov	[hinstance],eax


_test1_asm:
	; invoke WriteText, _str_printf_int
	mov	edx, _str_printf_int			;_message			; _str_printf_int
	call	WriteText
	;invoke WriteText
	
	
	push dword p0_tmp
	push dword _str_printf_str
	push dword buf
	call [wsprintf]
	mov edx, buf  ;_str_printf_str
	;mov edx, _str_printf_str
	call  WriteText
	add esp,8
	mov eax,1
	mov dword [p1_tmp],eax
	push dword [p1_tmp]
	push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,456
	mov dword [p2_tmp],eax
	mov eax,dword [p2_tmp]
	mov dword [a_glob],eax
	mov eax,1
	mov dword [p3_tmp],eax
	mov eax,dword [a_glob]
	add eax,dword [p3_tmp]
	mov dword [p4_tmp],eax
	mov eax,dword [p4_tmp]
	mov dword [a_glob],eax
	mov eax,0
	mov dword [p5_tmp],eax
	mov eax,dword [p5_tmp]
	mov dword [g_glob],eax
	mov eax,0
	mov dword [p6_tmp],eax
	mov eax,dword [p6_tmp]
	mov dword [toto1_glob],eax
	mov eax,0
	mov dword [p7_tmp],eax
	mov eax,dword [p7_tmp]
	mov dword [j_glob],eax
	mov eax,dword [a_glob]
	add eax,dword [g_glob]
	mov dword [p8_tmp],eax
	mov eax,dword [p8_tmp]
	mov dword [a_glob],eax
	mov eax,dword [j_glob]
	add eax,dword [a_glob]
	mov dword [p9_tmp],eax
	mov eax,dword [p9_tmp]
	add eax,dword [toto1_glob]
	mov dword [p10_tmp],eax
	mov eax,dword [p10_tmp]
	mov dword [g_glob],eax
	mov eax,56
	mov dword [p11_tmp],eax
	mov eax,7
	mov dword [p12_tmp],eax
	mov eax,dword [p11_tmp]
	add eax,dword [p12_tmp]
	mov dword [p13_tmp],eax
	push dword [p13_tmp]
	push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,dword [a_glob]
	cmp eax,dword [toto1_glob]
	sete al
	and eax,255
	mov dword [p14_tmp],eax
	cmp dword [p14_tmp],0
	je  label_0
	mov eax,5
	mov dword [p15_tmp],eax
	mov eax,dword [p15_tmp]
	mov dword [a_glob],eax
	jmp  label_1
label_0:
	mov eax,6
	mov dword [p16_tmp],eax
	mov eax,dword [p16_tmp]
	mov dword [a_glob],eax
label_1:
	mov eax,6
	mov dword [p17_tmp],eax
	mov eax,dword [a_glob]
	cmp eax,dword [p17_tmp]
	sete al
	and eax,255
	mov dword [p18_tmp],eax
	push dword [p18_tmp]
	push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,dword [a_glob]
	cmp eax,dword [a_glob]
	sete al
	and eax,255
	mov dword [p19_tmp],eax
	push dword [p19_tmp]
		push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,dword [a_glob]
	cmp eax,dword [a_glob]
	setne al
	and eax,255
	mov dword [p20_tmp],eax
	push dword [p20_tmp]
		push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,dword [a_glob]
	cmp eax,dword [a_glob]
	sete al
	and eax,255
	mov dword [p21_tmp],eax
	cmp dword [p21_tmp],0
	je  label_2
	mov eax,1
	mov dword [p22_tmp],eax
	push dword [p22_tmp]
		push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	jmp  label_3
label_2:
	mov eax,0
	mov dword [p23_tmp],eax
	push dword [p23_tmp]
		push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
label_3:
	mov eax,dword [p24_tmp]
	mov dword [s_glob],eax
	push dword s_glob
		push dword _str_printf_str
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	push dword p25_tmp
		push dword _str_printf_str
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,1
	mov dword [p26_tmp],eax
	mov eax,5
	mov dword [p27_tmp],eax
	mov eax,dword [p26_tmp]
	cmp eax,dword [p27_tmp]
	setl al
	and eax,255
	mov dword [p28_tmp],eax
	push dword [p28_tmp]
		push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	push dword p29_tmp
		push dword _str_printf_str
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,5
	mov dword [p30_tmp],eax
	mov eax,5
	mov dword [p31_tmp],eax
	mov eax,dword [p30_tmp]
	cmp eax,dword [p31_tmp]
	setl al
	and eax,255
	mov dword [p32_tmp],eax
	push dword [p32_tmp]
		push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	push dword p33_tmp
		push dword _str_printf_str
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,6
	mov dword [p34_tmp],eax
	mov eax,5
	mov dword [p35_tmp],eax
	mov eax,dword [p34_tmp]
	cmp eax,dword [p35_tmp]
	setl al
	and eax,255
	mov dword [p36_tmp],eax
	push dword [p36_tmp]
		push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	push dword p37_tmp
		push dword _str_printf_str
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,7
	mov dword [p38_tmp],eax
	mov eax,6
	mov dword [p39_tmp],eax
	mov eax,dword [p38_tmp]
	cmp eax,dword [p39_tmp]
	setge al
	and eax,255
	mov dword [p40_tmp],eax
	push dword [p40_tmp]
		push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	push dword p41_tmp
		push dword _str_printf_str
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,6
	mov dword [p42_tmp],eax
	mov eax,6
	mov dword [p43_tmp],eax
	mov eax,dword [p42_tmp]
	cmp eax,dword [p43_tmp]
	setge al
	and eax,255
	mov dword [p44_tmp],eax
	push dword [p44_tmp]
		push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	push dword p45_tmp
		push dword _str_printf_str
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,5
	mov dword [p46_tmp],eax
	mov eax,6
	mov dword [p47_tmp],eax
	mov eax,dword [p46_tmp]
	cmp eax,dword [p47_tmp]
	setge al
	and eax,255
	mov dword [p48_tmp],eax
	push dword [p48_tmp]
		push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	push dword p49_tmp
		push dword _str_printf_str
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,0
	mov dword [p50_tmp],eax
	mov eax,dword [p50_tmp]
	mov dword [a_glob],eax
label_4:
	mov eax,3
	mov dword [p51_tmp],eax
	mov eax,dword [a_glob]
	cmp eax,dword [p51_tmp]
	setl al
	and eax,255
	mov dword [p52_tmp],eax
	cmp dword [p52_tmp],0
	je  label_5
	push dword [a_glob]
		push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,1
	mov dword [p53_tmp],eax
	mov eax,dword [a_glob]
	add eax,dword [p53_tmp]
	mov dword [p54_tmp],eax
	mov eax,dword [p54_tmp]
	mov dword [a_glob],eax
	jmp  label_4
label_5:
	push dword p55_tmp
		push dword _str_printf_str
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,3
	mov dword [p56_tmp],eax
	mov eax,dword [p56_tmp]
	mov dword [a_glob],eax
label_6:
	push dword [a_glob]
		push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,1
	mov dword [p57_tmp],eax
	mov eax,dword [a_glob]
	sub eax,dword [p57_tmp]
	mov dword [p58_tmp],eax
	mov eax,dword [p58_tmp]
	mov dword [a_glob],eax
	mov eax,0
	mov dword [p59_tmp],eax
	mov eax,dword [a_glob]
	cmp eax,dword [p59_tmp]
	setle al
	and eax,255
	mov dword [p60_tmp],eax
	cmp dword [p60_tmp],0
	je  label_6
	push dword p61_tmp
		push dword _str_printf_str
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,6
	mov dword [p62_tmp],eax
	mov eax,6
	mov dword [p63_tmp],eax
	mov eax,dword [p62_tmp]
	cmp eax,dword [p63_tmp]
	sete al
	and eax,255
	mov dword [p64_tmp],eax
	mov eax,dword [p64_tmp]
	not eax
	mov dword [p65_tmp],eax
	push dword [p65_tmp]
		push dword _str_printf_int
	push dword buf
	call [wsprintf]
	mov edx, buf
	call  WriteText
	add esp,8
	mov eax,45
	mov dword [p66_tmp],eax
	mov eax,78
	mov dword [p67_tmp],eax
	mov eax,dword [p66_tmp]
	add eax,dword [p67_tmp]
	mov dword [p68_tmp],eax
	mov eax,dword [p68_tmp]
	mov dword [a_glob],eax

	;invoke	ExitProcess, 0 ;[msg.wParam]
	
	push	0
	call	[ExitProcess]

WriteText:				; edx must point to zero padded text
	push	-11
	call	[GetStdHandle]
	mov	ebx,eax
	mov	edi,edx
	or	ecx,-1
	xor	al,al
	repne	scasb
	neg	ecx
	sub	ecx,2
	push	0
	push	bytes_count
	push	ecx
	push	edx
	push	ebx
	call	[WriteFile]
	ret


section '.idata' import data readable writeable

;  dd 0,0,0,rva kernel_name,rva kernel_table
;  dd 0,0,0,rva user_name,rva kernel_table
;  dd 0,0,0,0,0

;  kernel_table:
;    ExitProcess dd rva _ExitProcess
;    GetStdHandle dd rva _GetStdHandle
;    WriteFile dd rva _WriteFile
;    dd 0

;  user_table:
;    wsprintf dd rva _wsprintf
;    dd 0

;  kernel_name db 'KERNEL32.DLL',0

;  _ExitProcess dw 0
;    db 'ExitProcess',0

;  _GetStdHandle dw 0
;    db 'GetStdHandle',0
;  _WriteFile dw 0
;    db 'WriteFile',0
   
;  user_name db 'USER32.DLL',0
;  _wsprintf dw 0
;    db 'wsprintf',0

;section '.reloc' fixups data readable discardable


  library kernel,'KERNEL32.DLL',\
	  user,'USER32.DLL'

  kernel:
  import GetModuleHandle,'GetModuleHandleA',\
	 ExitProcess,'ExitProcess', \;
	 WriteFile, 'WriteFile',\
	 GetStdHandle, 'GetStdHandle'

  user:
  import RegisterClass,'RegisterClassA',\
	 CreateWindowEx,'CreateWindowExA',\
	 DefWindowProc,'DefWindowProcA',\
	 GetMessage,'GetMessageA',\
	 TranslateMessage,'TranslateMessage',\
	 DispatchMessage,'DispatchMessageA',\
	 LoadCursor,'LoadCursorA',\
	 LoadIcon,'LoadIconA',\
	 PostQuitMessage,'PostQuitMessage', \
	 wsprintf,'wsprintfA'
