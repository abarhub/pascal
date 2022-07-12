; file code.asm
; Tue Dec 24 16:38:35 2002

	BITS 32
	GLOBAL _test1_asm
	EXTERN _printf

	SECTION _TEXT align=4 public class=CODE USE32


_test1_asm:
	finit
	push dword p0_tmp
	push dword _str_printf_str
	call  _printf
	add esp,8
	fld dword [p2_tmp]
	wait
	fstp dword [p1_tmp]
	wait
	fld dword [p1_tmp]
	wait
	fstp dword [u_glob]
	wait
	fld dword [u_glob]
	wait
	add esp,-8
	fstp qword [esp]
	push dword _str_printf_float
	call  _printf
	add esp,12
	fld dword [p4_tmp]
	wait
	fstp dword [p3_tmp]
	wait
	fld dword [p3_tmp]
	wait
	add esp,-8
	fstp qword [esp]
	push dword _str_printf_float
	call  _printf
	add esp,12
	fld dword [p6_tmp]
	wait
	fstp dword [p5_tmp]
	wait
	fld dword [p5_tmp]
	wait
	fstp dword [u_glob]
	wait
	fld dword [u_glob]
	fadd dword [u_glob]
	fstp dword [p7_tmp]
	fld dword [p7_tmp]
	wait
	add esp,-8
	fstp qword [esp]
	push dword _str_printf_float
	call  _printf
	add esp,12
	fld dword [p9_tmp]
	wait
	fstp dword [p8_tmp]
	wait
	fld dword [p8_tmp]
	ftst
	fstsw ax
	fincstp
	sahf
	je  label_0
	push dword p10_tmp
	push dword _str_printf_str
	call  _printf
	add esp,8
	jmp  label_1
label_0:
	push dword p11_tmp
	push dword _str_printf_str
	call  _printf
	add esp,8
label_1:
	mov eax,0
	mov dword [p12_tmp],eax
	cmp dword [p12_tmp],0
	je  label_2
	push dword p13_tmp
	push dword _str_printf_str
	call  _printf
	add esp,8
	jmp  label_3
label_2:
	push dword p14_tmp
	push dword _str_printf_str
	call  _printf
	add esp,8
label_3:
	mov eax,45
	mov dword [p15_tmp],eax
	mov eax,78
	mov dword [p16_tmp],eax
	mov eax,dword [p15_tmp]
	add eax,dword [p16_tmp]
	mov dword [p17_tmp],eax
	mov dword [a_glob],eax
	ret
	SECTION _DATA align=4 public class=DATA USE32

_str_printf_int db "int=%d"
	db 10,0
_str_printf_str db "str=%s"
	db 10,0
_str_printf_float db "flt=%g"
	db 10,0
;	SECTION _BBS align=4 public class=code USE32

	; nb de variable: 29
	p17_tmp resb 4
	p16_tmp resb 4
	p15_tmp resb 4
	p14_tmp db "differrent",0
	p13_tmp db "egal",0
	p12_tmp resb 4
	p11_tmp db "differrent",0
	p10_tmp db "egal",0
	p9_tmp dd 1.000000
	p8_tmp resb 4
	p7_tmp resb 4
	p6_tmp dd 1.400000
	p5_tmp resb 4
	p4_tmp dd 0.000950
	p3_tmp resb 4
	p2_tmp dd 8.600000
	p1_tmp resb 4
	p0_tmp db "debut:",0
	toto1_glob resb 4
	tata_glob resb 1
	i_glob resb 1
	tutu_glob resb 4
	b_glob resb 4
	u_glob resb 4
	a_glob resb 4
	g_glob resb 4
	j_glob resb 4
	u1_glob resb 4
	s_glob resb 256
