.source codej.j
.class public codej
.super java/lang/Object

.field public static final toto1_glob I
.field public static final tata_glob C
.field public static final i_glob C
.field public static final tutu_glob Z
.field public static final b_glob Z
.field public static final u_glob F
.field public static final a_glob I
.field public static final g_glob I
.field public static final j_glob I
.field public static final u1_glob I
.field public static final s_glob Ljava/lang/String;

.method public <init>()V
	aload_0
	invokenonvirtual java/lang/Object/<init>()V
	return
.end method

.method public static main([Ljava/lang/String;)V
.limit locals 115
.limit stack 256
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "debut:"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 1
	istore 12
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 12
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 456
	istore 13
	iload 13
	putstatic codej/a_glob I
	bipush 1
	istore 14
	getstatic codej/a_glob I
	iload 14
	iadd
	istore 15
	iload 15
	putstatic codej/a_glob I
	bipush 0
	istore 16
	iload 16
	putstatic codej/g_glob I
	bipush 0
	istore 17
	iload 17
	putstatic codej/toto1_glob I
	bipush 0
	istore 18
	iload 18
	putstatic codej/j_glob I
	getstatic codej/a_glob I
	getstatic codej/g_glob I
	iadd
	istore 19
	iload 19
	putstatic codej/a_glob I
	getstatic codej/j_glob I
	getstatic codej/a_glob I
	iadd
	istore 20
	iload 20
	getstatic codej/toto1_glob I
	iadd
	istore 21
	iload 21
	putstatic codej/g_glob I
	bipush 56
	istore 22
	bipush 7
	istore 23
	iload 22
	iload 23
	iadd
	istore 24
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 24
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic codej/a_glob I
	getstatic codej/toto1_glob I
	if_icmpeq label_test0
	bipush 0
	goto label_test1
label_test0:
	bipush 1
label_test1:
	istore 25
	iload 25
	ifeq label_0
	bipush 5
	istore 26
	iload 26
	putstatic codej/a_glob I
	goto label_1
label_0:
	bipush 6
	istore 27
	iload 27
	putstatic codej/a_glob I
label_1:
	bipush 6
	istore 28
	getstatic codej/a_glob I
	iload 28
	if_icmpeq label_test2
	bipush 0
	goto label_test3
label_test2:
	bipush 1
label_test3:
	istore 29
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 29
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic codej/a_glob I
	getstatic codej/a_glob I
	if_icmpeq label_test4
	bipush 0
	goto label_test5
label_test4:
	bipush 1
label_test5:
	istore 30
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 30
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic codej/a_glob I
	getstatic codej/a_glob I
	if_icmpne label_test6
	bipush 0
	goto label_test7
label_test6:
	bipush 1
label_test7:
	istore 31
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 31
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic codej/a_glob I
	getstatic codej/a_glob I
	if_icmpeq label_test8
	bipush 0
	goto label_test9
label_test8:
	bipush 1
label_test9:
	istore 32
	iload 32
	ifeq label_2
	bipush 1
	istore 33
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 33
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto label_3
label_2:
	bipush 0
	istore 34
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 34
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
label_3:
	ldc "abc"
	putstatic codej/s_glob Ljava/lang/String;
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic codej/s_glob Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "1<5?"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 1
	istore 37
	bipush 5
	istore 38
	iload 37
	iload 38
	if_icmplt label_test10
	bipush 0
	goto label_test11
label_test10:
	bipush 1
label_test11:
	istore 39
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 39
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "5<5?"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 5
	istore 41
	bipush 5
	istore 42
	iload 41
	iload 42
	if_icmplt label_test12
	bipush 0
	goto label_test13
label_test12:
	bipush 1
label_test13:
	istore 43
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 43
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "6<5?"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 6
	istore 45
	bipush 5
	istore 46
	iload 45
	iload 46
	if_icmplt label_test14
	bipush 0
	goto label_test15
label_test14:
	bipush 1
label_test15:
	istore 47
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 47
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "7>=6?"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 7
	istore 49
	bipush 6
	istore 50
	iload 49
	iload 50
	if_icmpge label_test16
	bipush 0
	goto label_test17
label_test16:
	bipush 1
label_test17:
	istore 51
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 51
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "6>=6?"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 6
	istore 53
	bipush 6
	istore 54
	iload 53
	iload 54
	if_icmpge label_test18
	bipush 0
	goto label_test19
label_test18:
	bipush 1
label_test19:
	istore 55
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 55
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "5>=6?"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 5
	istore 57
	bipush 6
	istore 58
	iload 57
	iload 58
	if_icmpge label_test20
	bipush 0
	goto label_test21
label_test20:
	bipush 1
label_test21:
	istore 59
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 59
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "a de 0 a 2"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 0
	istore 61
	iload 61
	putstatic codej/a_glob I
label_4:
	bipush 3
	istore 62
	getstatic codej/a_glob I
	iload 62
	if_icmplt label_test22
	bipush 0
	goto label_test23
label_test22:
	bipush 1
label_test23:
	istore 63
	iload 63
	ifeq label_5
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic codej/a_glob I
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 1
	istore 64
	getstatic codej/a_glob I
	iload 64
	iadd
	istore 65
	iload 65
	putstatic codej/a_glob I
	goto label_4
label_5:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "a de 3 a 1"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 3
	istore 67
	iload 67
	putstatic codej/a_glob I
label_6:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic codej/a_glob I
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 1
	istore 68
	getstatic codej/a_glob I
	iload 68
	isub
	istore 69
	iload 69
	putstatic codej/a_glob I
	bipush 0
	istore 70
	getstatic codej/a_glob I
	iload 70
	if_icmple label_test24
	bipush 0
	goto label_test25
label_test24:
	bipush 1
label_test25:
	istore 71
	iload 71
	ifeq label_6
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc "coucou"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 6
	istore 73
	bipush 6
	istore 74
	iload 73
	iload 74
	if_icmpeq label_test26
	bipush 0
	goto label_test27
label_test26:
	bipush 1
label_test27:
	istore 75
	iload 75
	iconst_1
	ixor
	istore 76
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 76
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 1
	istore 77
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 77
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 0
	istore 78
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 78
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 1
	istore 79
	iload 79
	iconst_1
	ixor
	istore 80
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 80
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 0
	istore 81
	iload 81
	iconst_1
	ixor
	istore 82
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 82
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 8
	istore 83
	iload 83
	putstatic codej/a_glob I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic codej/a_glob I
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic codej/a_glob I
	ineg
	istore 84
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 84
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 8.600000
	fstore 85
	fload 85
	putstatic codej/u_glob F
	getstatic java/lang/System/out Ljava/io/PrintStream;
	getstatic codej/u_glob F
	invokestatic java/lang/String/valueOf(F)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 0.000950
	fstore 87
	getstatic java/lang/System/out Ljava/io/PrintStream;
	fload 87
	invokestatic java/lang/String/valueOf(F)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 1.400000
	fstore 89
	fload 89
	putstatic codej/u_glob F
	getstatic codej/u_glob F
	getstatic codej/u_glob F
	fadd
	fstore 91
	getstatic java/lang/System/out Ljava/io/PrintStream;
	fload 91
	invokestatic java/lang/String/valueOf(F)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 4.700000
	fstore 92
	ldc 8.300000
	fstore 94
	fload 92
	fload 94
	fadd
	fstore 96
	getstatic java/lang/System/out Ljava/io/PrintStream;
	fload 96
	invokestatic java/lang/String/valueOf(F)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 1.600000
	fstore 97
	ldc 9.700000
	fstore 99
	fload 97
	fload 99
	fcmpg
	iconst_1
	if_icmple label_test28
	bipush 0
	goto label_test29
label_test28:
	bipush 1
label_test29:
	istore 101
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 101
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 1.600000
	fstore 102
	ldc 9.700000
	fstore 104
	fload 102
	fload 104
	fcmpg
	iconst_1
	if_icmpeq label_test30
	bipush 0
	goto label_test31
label_test30:
	bipush 1
label_test31:
	istore 106
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 106
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 1.600000
	fstore 107
	ldc 9.700000
	fstore 109
	fload 107
	fload 109
	fcmpg
	iconst_1
	if_icmpge label_test32
	bipush 0
	goto label_test33
label_test32:
	bipush 1
label_test33:
	istore 111
	getstatic java/lang/System/out Ljava/io/PrintStream;
	iload 111
	invokestatic java/lang/String/valueOf(I)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	bipush 45
	istore 112
	bipush 78
	istore 113
	iload 112
	iload 113
	iadd
	istore 114
	iload 114
	putstatic codej/a_glob I
	return
.end method
