; file code.asm
; Fri Apr 05 19:18:59 2002

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
	mov eax,1
	mov dword [p1_tmp],eax
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	mov eax,456
	mov dword [p2_tmp],eax
	mov dword [a_glob],eax
	mov eax,1
	mov dword [p3_tmp],eax
	mov eax,dword [a_glob]
	add eax,dword [p3_tmp]
	mov dword [p4_tmp],eax
	mov dword [a_glob],eax
	mov eax,0
	mov dword [p5_tmp],eax
	mov dword [g_glob],eax
	mov eax,0
	mov dword [p6_tmp],eax
	mov dword [toto1_glob],eax
	mov eax,0
	mov dword [p7_tmp],eax
	mov dword [j_glob],eax
	mov eax,dword [a_glob]
	add eax,dword [g_glob]
	mov dword [p8_tmp],eax
	mov dword [a_glob],eax
	mov eax,dword [j_glob]
	add eax,dword [a_glob]
	mov dword [p9_tmp],eax
	add eax,dword [toto1_glob]
	mov dword [p10_tmp],eax
	mov dword [g_glob],eax
	mov eax,56
	mov dword [p11_tmp],eax
	mov eax,7
	mov dword [p12_tmp],eax
	mov eax,dword [p11_tmp]
	add eax,dword [p12_tmp]
	mov dword [p13_tmp],eax
	push eax
	push dword _str_printf_int
	call  _printf
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
	mov dword [a_glob],eax
	jmp  label_1
label_0:
	mov eax,6
	mov dword [p16_tmp],eax
	mov dword [a_glob],eax
label_1:
	mov eax,6
	mov dword [p17_tmp],eax
	mov eax,dword [a_glob]
	cmp eax,dword [p17_tmp]
	sete al
	and eax,255
	mov dword [p18_tmp],eax
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	mov eax,dword [a_glob]
	cmp eax,dword [a_glob]
	sete al
	and eax,255
	mov dword [p19_tmp],eax
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	mov eax,dword [a_glob]
	cmp eax,dword [a_glob]
	setne al
	and eax,255
	mov dword [p20_tmp],eax
	push eax
	push dword _str_printf_int
	call  _printf
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
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	jmp  label_3
label_2:
	mov eax,0
	mov dword [p23_tmp],eax
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
label_3:
	mov eax,dword [p24_tmp]
	mov dword [s_glob],eax
	push dword s_glob
	push dword _str_printf_str
	call  _printf
	add esp,8
	push dword p25_tmp
	push dword _str_printf_str
	call  _printf
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
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	push dword p29_tmp
	push dword _str_printf_str
	call  _printf
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
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	push dword p33_tmp
	push dword _str_printf_str
	call  _printf
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
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	push dword p37_tmp
	push dword _str_printf_str
	call  _printf
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
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	push dword p41_tmp
	push dword _str_printf_str
	call  _printf
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
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	push dword p45_tmp
	push dword _str_printf_str
	call  _printf
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
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	push dword p49_tmp
	push dword _str_printf_str
	call  _printf
	add esp,8
	mov eax,0
	mov dword [p50_tmp],eax
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
	call  _printf
	add esp,8
	mov eax,1
	mov dword [p53_tmp],eax
	mov eax,dword [a_glob]
	add eax,dword [p53_tmp]
	mov dword [p54_tmp],eax
	mov dword [a_glob],eax
	jmp  label_4
label_5:
	push dword p55_tmp
	push dword _str_printf_str
	call  _printf
	add esp,8
	mov eax,3
	mov dword [p56_tmp],eax
	mov dword [a_glob],eax
label_6:
	push dword [a_glob]
	push dword _str_printf_int
	call  _printf
	add esp,8
	mov eax,1
	mov dword [p57_tmp],eax
	mov eax,dword [a_glob]
	sub eax,dword [p57_tmp]
	mov dword [p58_tmp],eax
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
	call  _printf
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
	xor eax,eax
	cmp dword [p64_tmp],0
	sete al
	mov dword [p65_tmp],eax
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	mov eax,1
	mov dword [p66_tmp],eax
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	mov eax,0
	mov dword [p67_tmp],eax
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	mov eax,1
	mov dword [p68_tmp],eax
	xor eax,eax
	cmp dword [p68_tmp],0
	sete al
	mov dword [p69_tmp],eax
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	mov eax,0
	mov dword [p70_tmp],eax
	xor eax,eax
	cmp dword [p70_tmp],0
	sete al
	mov dword [p71_tmp],eax
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	mov eax,8
	mov dword [p72_tmp],eax
	mov dword [a_glob],eax
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	mov eax,dword [a_glob]
	neg eax
	mov dword [p73_tmp],eax
	push eax
	push dword _str_printf_int
	call  _printf
	add esp,8
	fld dword [p75_tmp]
	wait
	fstp dword [p74_tmp]
	wait
	fld dword [p74_tmp]
	wait
	;fstp qword [tmp_float]
	;push qword [tmp_float]
	add       esp,-8
	fstp      qword [esp]
	;fstp dword [u_glob]
	;wait
	;mov eax, [p75_tmp]
	;mov dword [u_glob], eax
	;mov eax, -1
	;push eax  ;dword [u_glob]
	;push dword [p75_tmp]
	push dword _str_printf_float
	call  _printf
	add esp,12
	mov eax,45
	mov dword [p76_tmp],eax
	mov eax,78
	mov dword [p77_tmp],eax
	mov eax,dword [p76_tmp]
	add eax,dword [p77_tmp]
	mov dword [p78_tmp],eax
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

	tmp_float dq 0.0

	; nb de variable: 90
	p78_tmp resb 4
	p77_tmp resb 4
	p76_tmp resb 4
	p75_tmp dd -8.6e13
	p74_tmp resb 4
	p73_tmp resb 4
	p72_tmp resb 4
	p71_tmp resb 4
	p70_tmp resb 4
	p69_tmp resb 4
	p68_tmp resb 4
	p67_tmp resb 4
	p66_tmp resb 4
	p65_tmp resb 4
	p64_tmp resb 4
	p63_tmp resb 4
	p62_tmp resb 4
	p61_tmp db "coucou",0
	p60_tmp resb 4
	p59_tmp resb 4
	p58_tmp resb 4
	p57_tmp resb 4
	p56_tmp resb 4
	p55_tmp db "a de 3 a 1",0
	p54_tmp resb 4
	p53_tmp resb 4
	p52_tmp resb 4
	p51_tmp resb 4
	p50_tmp resb 4
	p49_tmp db "a de 0 a 2",0
	p48_tmp resb 4
	p47_tmp resb 4
	p46_tmp resb 4
	p45_tmp db "5>=6?",0
	p44_tmp resb 4
	p43_tmp resb 4
	p42_tmp resb 4
	p41_tmp db "6>=6?",0
	p40_tmp resb 4
	p39_tmp resb 4
	p38_tmp resb 4
	p37_tmp db "7>=6?",0
	p36_tmp resb 4
	p35_tmp resb 4
	p34_tmp resb 4
	p33_tmp db "6<5?",0
	p32_tmp resb 4
	p31_tmp resb 4
	p30_tmp resb 4
	p29_tmp db "5<5?",0
	p28_tmp resb 4
	p27_tmp resb 4
	p26_tmp resb 4
	p25_tmp db "1<5?",0
	p24_tmp db "abc",0
	p23_tmp resb 4
	p22_tmp resb 4
	p21_tmp resb 4
	p20_tmp resb 4
	p19_tmp resb 4
	p18_tmp resb 4
	p17_tmp resb 4
	p16_tmp resb 4
	p15_tmp resb 4
	p14_tmp resb 4
	p13_tmp resb 4
	p12_tmp resb 4
	p11_tmp resb 4
	p10_tmp resb 4
	p9_tmp resb 4
	p8_tmp resb 4
	p7_tmp resb 4
	p6_tmp resb 4
	p5_tmp resb 4
	p4_tmp resb 4
	p3_tmp resb 4
	p2_tmp resb 4
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
