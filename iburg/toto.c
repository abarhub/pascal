typedef struct tree {
	int op;
	struct tree *left, *right;
	int state_label;
} *treepointer;
#define NODEPTR_TYPE treepointer
#define OP_LABEL(p) ((p)->op)
#define LEFT_CHILD(p) ((p)->left)
#define RIGHT_CHILD(p) ((p)->right)
#define STATE_LABEL(p) ((p)->state_label)
#define PANIC printf
#include <limits.h>
#include <stdlib.h>
#ifndef STATE_TYPE
#define STATE_TYPE int
#endif
#ifndef ALLOC
#define ALLOC(n) malloc(n)
#endif
#ifndef burm_assert
#define burm_assert(x,y) if (!(x)) { y; abort(); }
#endif

#define burm_reg_NT 1
#define burm_con_NT 2
#define burm_addr_NT 3
int burm_max_nt = 3;

struct burm_state {
	int op;
	struct burm_state *left, *right;
	short cost[4];
	struct {
		unsigned burm_reg:2;
		unsigned burm_con:2;
		unsigned burm_addr:2;
	} rule;
};

static short burm_nts_0[] = { 0 };
static short burm_nts_1[] = { burm_con_NT, 0 };
static short burm_nts_2[] = { burm_con_NT, burm_reg_NT, 0 };
static short burm_nts_3[] = { burm_addr_NT, 0 };
static short burm_nts_4[] = { burm_addr_NT, burm_reg_NT, 0 };

short *burm_nts[] = {
	0,	/* 0 */
	burm_nts_0,	/* 1 */
	burm_nts_0,	/* 2 */
	burm_nts_1,	/* 3 */
	burm_nts_2,	/* 4 */
	burm_nts_2,	/* 5 */
	burm_nts_3,	/* 6 */
	burm_nts_4,	/* 7 */
};

char burm_arity[] = {
	0,	/* 0 */
	2,	/* 1=Assign */
	0,	/* 2=Constant */
	1,	/* 3=Fetch */
	0,	/* 4=Four */
	2,	/* 5=Mul */
	2,	/* 6=Plus */
};

static short burm_decode_reg[] = {
	0,
	6,
	7,
};

static short burm_decode_con[] = {
	0,
	1,
	2,
};

static short burm_decode_addr[] = {
	0,
	3,
	4,
	5,
};

int burm_rule(STATE_TYPE state, int goalnt) {
	burm_assert(goalnt >= 1 && goalnt <= 3, PANIC("Bad goal nonterminal %d in burm_rule\n", goalnt));
	if (!state)
		return 0;
	switch (goalnt) {
	case burm_reg_NT:	return burm_decode_reg[((struct burm_state *)state)->rule.burm_reg];
	case burm_con_NT:	return burm_decode_con[((struct burm_state *)state)->rule.burm_con];
	case burm_addr_NT:	return burm_decode_addr[((struct burm_state *)state)->rule.burm_addr];
	default:
		burm_assert(0, PANIC("Bad goal nonterminal %d in burm_rule\n", goalnt));
	}
	return 0;
}

static void burm_closure_con(struct burm_state *, int);

static void burm_closure_con(struct burm_state *p, int c) {
	if (c + 0 < p->cost[burm_addr_NT]) {
		p->cost[burm_addr_NT] = c + 0;
		p->rule.burm_addr = 1;
	}
}

STATE_TYPE burm_state(int op, STATE_TYPE left, STATE_TYPE right) {
	int c;
	struct burm_state *p, *l = (struct burm_state *)left,
		*r = (struct burm_state *)right;

	assert(sizeof (STATE_TYPE) >= sizeof (void *));
	if (burm_arity[op] > 0) {
		p = ALLOC(sizeof *p);
		burm_assert(p, PANIC("ALLOC returned NULL in burm_state\n"));
		p->op = op;
		p->left = l;
		p->right = r;
		p->rule.burm_reg = 0;
		p->cost[1] =
		p->cost[2] =
		p->cost[3] =
			32767;
	}
	switch (op) {
	case 1: /* Assign */
		assert(l && r);
		{	/* reg: Assign(addr,reg) */
			c = l->cost[burm_addr_NT] + r->cost[burm_reg_NT] + 1;
			if (c + 0 < p->cost[burm_reg_NT]) {
				p->cost[burm_reg_NT] = c + 0;
				p->rule.burm_reg = 2;
			}
		}
		break;
	case 2: /* Constant */
		{
			static struct burm_state z = { 2, 0, 0,
				{	0,
					32767,
					0,	/* con: Constant */
					0,	/* addr: con */
				},{
					0,
					1,	/* con: Constant */
					1,	/* addr: con */
				}
			};
			return (STATE_TYPE)&z;
		}
	case 3: /* Fetch */
		assert(l);
		{	/* reg: Fetch(addr) */
			c = l->cost[burm_addr_NT] + 1;
			if (c + 0 < p->cost[burm_reg_NT]) {
				p->cost[burm_reg_NT] = c + 0;
				p->rule.burm_reg = 1;
			}
		}
		break;
	case 4: /* Four */
		{
			static struct burm_state z = { 4, 0, 0,
				{	0,
					32767,
					0,	/* con: Four */
					0,	/* addr: con */
				},{
					0,
					2,	/* con: Four */
					1,	/* addr: con */
				}
			};
			return (STATE_TYPE)&z;
		}
	case 5: /* Mul */
		assert(l && r);
		break;
	case 6: /* Plus */
		assert(l && r);
		if (	/* addr: Plus(con,Mul(Four,reg)) */
			r->op == 5 && /* Mul */
			r->left->op == 4 /* Four */
		) {
			c = l->cost[burm_con_NT] + r->right->cost[burm_reg_NT] + 0;
			if (c + 0 < p->cost[burm_addr_NT]) {
				p->cost[burm_addr_NT] = c + 0;
				p->rule.burm_addr = 3;
			}
		}
		{	/* addr: Plus(con,reg) */
			c = l->cost[burm_con_NT] + r->cost[burm_reg_NT] + 0;
			if (c + 0 < p->cost[burm_addr_NT]) {
				p->cost[burm_addr_NT] = c + 0;
				p->rule.burm_addr = 2;
			}
		}
		break;
	default:
		burm_assert(0, PANIC("Bad operator %d in burm_state\n", op));
	}
	return (STATE_TYPE)p;
}

#ifdef STATE_LABEL
static void burm_label1(NODEPTR_TYPE p) {
	burm_assert(p, PANIC("NULL tree in burm_label\n"));
	switch (burm_arity[OP_LABEL(p)]) {
	case 0:
		STATE_LABEL(p) = burm_state(OP_LABEL(p), 0, 0);
		break;
	case 1:
		burm_label1(LEFT_CHILD(p));
		STATE_LABEL(p) = burm_state(OP_LABEL(p),
			STATE_LABEL(LEFT_CHILD(p)), 0);
		break;
	case 2:
		burm_label1(LEFT_CHILD(p));
		burm_label1(RIGHT_CHILD(p));
		STATE_LABEL(p) = burm_state(OP_LABEL(p),
			STATE_LABEL(LEFT_CHILD(p)),
			STATE_LABEL(RIGHT_CHILD(p)));
		break;
	}
}

STATE_TYPE burm_label(NODEPTR_TYPE p) {
	burm_label1(p);
	return ((struct burm_state *)STATE_LABEL(p))->rule.burm_reg ? STATE_LABEL(p) : 0;
}

NODEPTR_TYPE *burm_kids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	burm_assert(p, PANIC("NULL tree in burm_kids\n"));
	burm_assert(kids, PANIC("NULL kids in burm_kids\n"));
	switch (eruleno) {
	case 2: /* con: Four */
	case 1: /* con: Constant */
		break;
	case 3: /* addr: con */
		kids[0] = p;
		break;
	case 7: /* reg: Assign(addr,reg) */
	case 4: /* addr: Plus(con,reg) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 5: /* addr: Plus(con,Mul(Four,reg)) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(RIGHT_CHILD(p));
		break;
	case 6: /* reg: Fetch(addr) */
		kids[0] = LEFT_CHILD(p);
		break;
	default:
		burm_assert(0, PANIC("Bad external rule number %d in burm_kids\n", eruleno));
	}
	return kids;
}

int burm_op_label(NODEPTR_TYPE p) {
	burm_assert(p, PANIC("NULL tree in burm_op_label\n"));
	return OP_LABEL(p);
}

STATE_TYPE burm_state_label(NODEPTR_TYPE p) {
	burm_assert(p, PANIC("NULL tree in burm_state_label\n"));
	return STATE_LABEL(p);
}

NODEPTR_TYPE burm_child(NODEPTR_TYPE p, int index) {
	burm_assert(p, PANIC("NULL tree in burm_child\n"));
	switch (index) {
	case 0:	return LEFT_CHILD(p);
	case 1:	return RIGHT_CHILD(p);
	}
	burm_assert(0, PANIC("Bad index %d in burm_child\n", index));
	return 0;
}

#endif
