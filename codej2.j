.class public codej2
.super java/lang/Object
.method public <init>()V
	aload_0
	invokenonvirtual java/lang/Object/<init>()V
	return
.end method

.method public static main([Ljava/lang/String;)V
.limit locals 63
.limit stack 256
	bipush 456 ; copie
	istore 11
	iload 11 ; copie
	istore 4
	bipush 1 ; copie
	istore 12
	iload 4
	iload 12
	iadd
	istore 13
	iload 13 ; copie
	istore 4
	bipush 0 ; copie
	istore 14
	iload 14 ; copie
	istore 3
	bipush 0 ; copie
	istore 15
	iload 15 ; copie
	istore 10
	bipush 0 ; copie
	istore 16
	iload 16 ; copie
	istore 2
	iload 4
	iload 3
	iadd
	istore 17
	iload 17 ; copie
	istore 4
	iload 2
	iload 4
	iadd
	istore 18
	iload 18
	iload 10
	iadd
	istore 19
	iload 19 ; copie
	istore 3
	bipush 56 ; copie
	istore 20
	bipush 7 ; copie
	istore 21
	iload 20
	iload 21
	iadd
	istore 22
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 22 ; conversion d'un entier vers une chaine
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	iload 4
	iload 10
	if_icmpe label_test0
	bipush 0
	goto label_test1
	label_test0:
	bipush 1
label_test1:
	istore 23
	iload 23 ; teste si
	ifeq label_0
	bipush 5 ; copie
	istore 24
	iload 24 ; copie
	istore 4
	goto label_1 ; saut
label_0:
	bipush 6 ; copie
	istore 25
	iload 25 ; copie
	istore 4
label_1:
	bipush 6 ; copie
	istore 26
	iload 4
	iload 26
	if_icmpe label_test2
	bipush 0
	goto label_test3
	label_test2:
	bipush 1
label_test3:
	istore 27
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 27 ; conversion d'un entier vers une chaine
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	iload 4
	iload 4
	if_icmpe label_test4
	bipush 0
	goto label_test5
	label_test4:
	bipush 1
label_test5:
	istore 28
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 28 ; conversion d'un entier vers une chaine
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	iload 4
	iload 4
	if_icmpne label_test6
	bipush 0
	goto label_test7
	label_test6:
	bipush 1
label_test7:
	istore 29
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 29 ; conversion d'un entier vers une chaine
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	iload 4
	iload 4
	if_icmpe label_test8
	bipush 0
	goto label_test9
	label_test8:
	bipush 1
label_test9:
	istore 30
	iload 30 ; teste si
	ifeq label_2
	bipush 1 ; copie
	istore 31
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 31 ; conversion d'un entier vers une chaine
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto label_3 ; saut
label_2:
	bipush 0 ; copie
	istore 32
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 32 ; conversion d'un entier vers une chaine
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
label_3:
	ldc "abc" ; copie
	astore 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	aload 0
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "1<5?"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 1 ; copie
	istore 35
	bipush 5 ; copie
	istore 36
	iload 35
	iload 36
	if_icmplt label_test10
	bipush 0
	goto label_test11
	label_test10:
	bipush 1
label_test11:
	istore 37
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 37 ; conversion d'un entier vers une chaine
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "5<5?"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 5 ; copie
	istore 39
	bipush 5 ; copie
	istore 40
	iload 39
	iload 40
	if_icmplt label_test12
	bipush 0
	goto label_test13
	label_test12:
	bipush 1
label_test13:
	istore 41
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 41 ; conversion d'un entier vers une chaine
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "6<5?"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 6 ; copie
	istore 43
	bipush 5 ; copie
	istore 44
	iload 43
	iload 44
	if_icmplt label_test14
	bipush 0
	goto label_test15
	label_test14:
	bipush 1
label_test15:
	istore 45
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 45 ; conversion d'un entier vers une chaine
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "7>=6?"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 7 ; copie
	istore 47
	bipush 6 ; copie
	istore 48
	iload 47
	iload 48
	if_icmpge label_test16
	bipush 0
	goto label_test17
	label_test16:
	bipush 1
label_test17:
	istore 49
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 49 ; conversion d'un entier vers une chaine
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "6>=6?"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 6 ; copie
	istore 51
	bipush 6 ; copie
	istore 52
	iload 51
	iload 52
	if_icmpge label_test18
	bipush 0
	goto label_test19
	label_test18:
	bipush 1
label_test19:
	istore 53
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 53 ; conversion d'un entier vers une chaine
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "5>=6?"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 5 ; copie
	istore 55
	bipush 6 ; copie
	istore 56
	iload 55
	iload 56
	if_icmpge label_test20
	bipush 0
	goto label_test21
	label_test20:
	bipush 1
label_test21:
	istore 57
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 57 ; conversion d'un entier vers une chaine
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 45 ; copie
	istore 58
	bipush 78 ; copie
	istore 59
	iload 58
	iload 59
	iadd
	istore 60
	iload 60 ; copie
	istore 4
	return
.end method
