char *clearString(char *str);
char *strmul(char *str, int n);
struct ast *orr(struct ast *value1, struct ast *value2);
struct ast *and(struct ast *value1, struct ast *value2);
struct ast *not(struct ast *tree);
struct ast *negateValue(struct ast *tree);
struct ast *compare(int type, struct ast *l, struct ast *r);
struct ast *sum(struct ast *value1, struct ast *value2);
struct ast *sub(struct ast *value1, struct ast *value2);
struct ast *mul(struct ast *value1, struct ast *value2);
struct ast *rdiv(struct ast *value1, struct ast *value2);
struct ast *mod(struct ast *value1, struct ast *value2);
struct ast *abss(struct ast *tree);