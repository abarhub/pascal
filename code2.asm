	BITS 32
	GLOBAL _test1_asm
	EXTERN _printf

	SECTION .text


_test1_asm:
	mov eax,456
	mov dword [p9],eax
	mov eax,dword [p9]
	mov dword [p2],eax
	mov eax,1
	mov dword [p10],eax
	mov eax,dword [p2]
	add dword [p2],eax
	mov dword [p2],eax
	mov eax,dword [p11]
	mov dword [p2],eax
	mov eax,0
	mov dword [p12],eax
	mov eax,dword [p12]
	mov dword [p1],eax
	mov eax,0
	mov dword [p13],eax
	mov eax,dword [p13]
	mov dword [p8],eax
	mov eax,0
	mov dword [p14],eax
	mov eax,dword [p14]
	mov dword [p0],eax
	mov eax,dword [p2]
	add dword [p2],eax
	mov dword [p2],eax
	mov eax,dword [p15]
	mov dword [p2],eax
	mov eax,dword [p0]
	add dword [p0],eax
	mov dword [p0],eax
	mov eax,dword [p16]
	add dword [p16],eax
	mov dword [p16],eax
	mov eax,dword [p17]
	mov dword [p1],eax
	mov eax,56
	mov dword [p18],eax
	mov eax,7
	mov dword [p19],eax
	mov eax,dword [p18]
	add dword [p18],eax
	mov dword [p18],eax
	push dword [p20]
	push _str_printf
	call _printf
	add esp,8
	mov eax,dword [p2]
	cmp eax,dword [p8]
	je label_test0
	mov dword [p21],1
	jmp label_test1
label_test0:
	mov dword [p21],0
label_test1:
	cmp dword [p21],0
	jne label_0
	mov eax,5
	mov dword [p22],eax
	mov eax,dword [p22]
	mov dword [p2],eax
label_0:
	mov eax,6
	mov dword [p23],eax
	mov eax,dword [p23]
	mov dword [p2],eax
label_1:
	mov eax,6
	mov dword [p24],eax
	mov eax,dword [p2]
	cmp eax,dword [p24]
	je label_test2
	mov dword [p25],1
	jmp label_test3
label_test2:
	mov dword [p25],0
label_test3:
	push dword [p25]
	push _str_printf
	call _printf
	add esp,8
	mov eax,dword [p2]
	cmp eax,dword [p2]
	je label_test4
	mov dword [p26],1
	jmp label_test5
label_test4:
	mov dword [p26],0
label_test5:
	push dword [p26]
	push _str_printf
	call _printf
	add esp,8
	mov eax,dword [p2]
	cmp eax,dword [p2]
	jne label_test6
	mov dword [p27],1
	jmp label_test7
label_test6:
	mov dword [p27],0
label_test7:
	push dword [p27]
	push _str_printf
	call _printf
	add esp,8
	mov eax,dword [p2]
	cmp eax,dword [p2]
	je label_test8
	mov dword [p28],1
	jmp label_test9
label_test8:
	mov dword [p28],0
label_test9:
	cmp dword [p28],0
	jne label_2
	mov eax,1
	mov dword [p29],eax
	push dword [p29]
	push _str_printf
	call _printf
	add esp,8
label_2:
	mov eax,0
	mov dword [p30],eax
	push dword [p30]
	push _str_printf
	call _printf
	add esp,8
label_3:
	mov eax,45
	mov dword [p31],eax
	mov eax,78
	mov dword [p32],eax
	mov eax,dword [p31]
	add dword [p31],eax
	mov dword [p31],eax
	mov eax,dword [p33]
	mov dword [p2],eax
	ret
	SECTION .data

_str_printf db "int=%d"
	db 10,0
	SECTION .bss

	p0  resd 4
	p1  resd 4
	p2  resd 4
	p3  resd 4
	p4  resd 4
	p5  resd 4
	p6  resd 4
	p7  resd 4
	p8  resd 4
	p9  resd 4
	p10  resd 4
	p11  resd 4
	p12  resd 4
	p13  resd 4
	p14  resd 4
	p15  resd 4
	p16  resd 4
	p17  resd 4
	p18  resd 4
	p19  resd 4
	p20  resd 4
	p21  resd 4
	p22  resd 4
	p23  resd 4
	p24  resd 4
	p25  resd 4
	p26  resd 4
	p27  resd 4
	p28  resd 4
	p29  resd 4
	p30  resd 4
	p31  resd 4
	p32  resd 4
	p33  resd 4
