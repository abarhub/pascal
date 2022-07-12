	.386p
	ifdef ??version
	if    ??version GT 500H
	.mmx
	endif
	endif
	model flat
	ifndef	??version
	?debug	macro
	endm
	endif
	?debug	S "test4.c"
	?debug	T "test4.c"
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
_DATA	segment dword public use32 'DATA'
_DATA	ends
_BSS	segment dword public use32 'BSS'
_BSS	ends
DGROUP	group	_BSS,_DATA
_TEXT	segment dword public use32 'CODE'
_main	proc	near
?live1@0:
   ;	
   ;	int main(int argc,char *argv) 
   ;	
	push      ebp
	mov       ebp,esp
	push      ecx
	push      ebx
   ;	
   ;	{
   ;		float f=8.6;
   ;	
@1:
	mov       dword ptr [ebp-4],1091148186
   ;	
   ;		int i=73;
   ;	
	mov       ebx,73
   ;	
   ;	
   ;		printf("Test pascal asm\n");
   ;	
?live1@48: ; EBX = i
	push      offset s@
	call      _printf
	pop       ecx
   ;	
   ;	
   ;		//test1_asm();
   ;		printf("int=%d\n",i);
   ;	
	push      ebx
	push      offset s@+17
	call      _printf
	add       esp,8
   ;	
   ;		printf("float=%f\n",f);
   ;	
?live1@80: ; 
	fld       dword ptr [ebp-4]
	add       esp,-8
	fstp      qword ptr [esp]
	push      offset s@+25
	call      _printf
	add       esp,12
   ;	
   ;		printf("Fin du test\n");
   ;	
	push      offset s@+35
	call      _printf
	pop       ecx
   ;	
   ;		return 0;
   ;	
	xor       eax,eax
   ;	
   ;	
   ;	}
   ;	
@3:
@2:
	pop       ebx
	pop       ecx
	pop       ebp
	ret 
_main	endp
_TEXT	ends
_DATA	segment dword public use32 'DATA'
s@	label	byte
	;	s@+0:
	db	"Test pascal asm",10,0
	;	s@+17:
	db	"int=%d",10,0
	;	s@+25:
	db	"float=%f",10,0
	;	s@+35:
	db	"Fin du test",10,0
	align	4
_DATA	ends
_TEXT	segment dword public use32 'CODE'
_TEXT	ends
	public	_main
 extrn   __setargv__:near
 extrn   _printf:near
	extrn	__turboFloat:word
	?debug	D "c:\Bcc55\include\_nfile.h" 10303 10240
	?debug	D "c:\Bcc55\include\_null.h" 10303 10240
	?debug	D "c:\Bcc55\include\_defs.h" 10303 10240
	?debug	D "c:\Bcc55\include\_stddef.h" 10303 10240
	?debug	D "c:\Bcc55\include\stdio.h" 10303 10240
	?debug	D "test4.c" 11397 40014
	end
